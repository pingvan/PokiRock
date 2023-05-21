#include "grpc_server.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include "DataBase_connector.h"

//completed login and register from server side on review

grpc::Status Poker_server::PokerFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::Responses, game::Requests> *stream) {
    game::Requests request;
    while(stream->Read(&request)) {
        game::Responses response;
        if (request.has_login_request()) {
            const auto& login_request = request.login_request();
            auto *login_response = new game::login_response;
            if (login_request.has_login_request_first()) {
                bool error = false;
                auto *login_response_first = new game::login_response_first;
                auto *error_message = new game::error_message;
                auto client_login = login_request.login_request_first().name();
                std::string salt;
                try {
                    salt = data::DataBase_connector::get_salt(client_login);
                } catch(std::exception &e) {
                    error = true;
                    error_message->set_error(game::errors::exception);
                    error_message->set_error_message(e.what());
                }
                if (salt.empty() && !error) {
                    error = true;
                    error_message->set_error(game::errors::no_user_with_this_login);
                }
                if (!error) {
                    delete error_message;
                    login_response_first->set_salt(salt);
                } else {
                    login_response_first->set_allocated_error_message(error_message);
                }
                login_response->set_allocated_login_response_first(login_response_first);
                response.set_allocated_login_response(login_response);
            } else {
                auto *login_response_second = new game::login_response_second;
                auto *error_message = new game::error_message;
                auto client_login = login_request.login_request_second().name();
                auto hash = login_request.login_request_second().hashed();
                bool error = false;
                std::string hash_from_data_base;
                try {
                    hash_from_data_base = data::DataBase_connector::get_hash(client_login);
                } catch(std::exception &e) {
                    error = true;
                    error_message->set_error(game::errors::exception);
                    error_message->set_error_message(e.what());
                }
                if (!error && hash == hash_from_data_base) {
                    auto *player_info = new game::player_info;
                    try {
                        data::DataBase_connector::get_client_info(client_login, player_info);
                    } catch(std::exception &e) {
                        error = true;
                        error_message->set_error(game::errors::exception);
                        error_message->set_error_message(e.what());
                    }
                    if (!error) {
                        delete error_message;
                        login_response_second->set_allocated_player_info(player_info);
                    }
                } else {
                    error_message->set_error(game::errors::uncorrect_password);
                    login_response_second->set_allocated_error_message(error_message);
                }
                login_response->set_allocated_login_response_second(login_response_second);
                response.set_allocated_login_response(login_response);
            }
        } else if (request.has_register_request()) {
            const auto& register_request = request.register_request();
            auto *register_response = new game::register_response;
            auto *status_message = new game::status_message;
            auto *error_message = new game::error_message;
            bool error = false;
            if (!data::DataBase_connector::check_login_correctness(register_request.name())) {
                error = true;
                error_message->set_error(game::errors::user_with_this_login_already_exists);
            }
            if (!error) {
                delete error_message;
                auto *player_info = new game::player_info;
                data::DataBase_connector::insert_new_client(register_request.name(), register_request.salt_hash().salt(), register_request.salt_hash().hash(), player_info);
                register_response->set_allocated_player_info(player_info);
            } else {
                register_response->set_allocated_error_message(error_message);
            }
            response.set_allocated_register_response(register_response);
        } else if (request.has_create_game_request()) {
            const auto& create_game_request = request.create_game_request();
            const auto *player_info = &create_game_request.player_info();
            const auto *game_parameters = &create_game_request.game_parameters();
            const auto& client_name = create_game_request.game_owner();
            std::unique_ptr<player> game_owner(new player(client_name, player_info, game_parameters->game_enter_balance(), stream));
            std::unique_ptr<server::Game> new_game(new server::Game(player_info->client_id(), game_parameters, std::move(game_owner)));
            auto game_id = generate_id();
            std::unique_lock<std::mutex> lock(m_mutex);
            all_games[game_id] = std::move(new_game);
            game_id_to_parameter[game_id] = *game_parameters;
            lock.unlock();
        } else { //search game_request
            const auto &search_game_request = request.search_game_request();
            const auto& game_parameters = search_game_request.game_parameters();
            const auto *player_info = &search_game_request.player_info();
            std::unique_lock<std::mutex> lock(m_mutex);
            int game_id_found = -1;
            for (const auto &[id, parameter] : game_id_to_parameter) { //TODO::repeated game parameters so we can choose few parameters
                if (parameter.game_name() == game_parameters.game_name() &&
                    parameter.number_of_players() == game_parameters.number_of_players() &&
                    parameter.minimal_bet() == game_parameters.minimal_bet() &&
                    parameter.game_enter_balance() == game_parameters.game_enter_balance()) {
                    game_id_found = id;
                    break;
                }
            }
            if (game_id_found != -1) {
                std::unique_ptr<player> new_player(new player(search_game_request.name(), player_info, game_parameters.game_enter_balance(), stream));
                all_games[game_id_found]->join_game(std::move(new_player));
            }
            lock.unlock();
        }
    }
    return grpc::Status::OK;
}

int Poker_server::generate_id() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 291203);
    auto new_game_id = distrib(gen);
    std::unique_lock<std::mutex> lock(m_mutex);
    while (all_games.find(new_game_id) == all_games.end()) {
        new_game_id = distrib(gen);
    }
    lock.unlock();
    return new_game_id;
}


