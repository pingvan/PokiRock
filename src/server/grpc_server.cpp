#include "grpc_server.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include "DataBase_connector.h"


grpc::Status authorization_service::Login(grpc::ServerContext *context, const game::LoginRequest *request, game::LoginResponse *response) {
    if (request->has_login_request_first()) {
        bool error = false;
        auto *login_response_first = new game::LoginResponseFirst; //FIXME::if we create it on client...
        auto *error_message = new game::ErrorMessage;
        auto client_login = request->login_request_first().name();
        std::string salt;
        try {
            salt = data::DataBase_connector::get_salt(client_login);
        } catch(std::exception &e) {
            error = true;
            error_message->set_error(game::error::ERROR_EXCEPTION);
            error_message->set_msg(e.what());
        }
        if (salt.empty() && !error) {
            error = true;
            error_message->set_error(game::error::ERROR_NO_USER_WITH_THIS_LOGIN);
        }
        if (!error) {
            delete error_message;
            login_response_first->set_salt(salt);
        } else {
            login_response_first->set_allocated_msg(error_message);
        }
        response->set_allocated_login_response_first(login_response_first);
    } else {
        auto *login_response_second = new game::LoginResponseSecond;
        auto *error_message = new game::ErrorMessage;
        auto client_login = request->login_request_second().name();
        auto hash = request->login_request_second().hashed();
        bool error = false;
        std::string hash_from_data_base;
        try {
            hash_from_data_base = data::DataBase_connector::get_hash(client_login);
        } catch (std::exception &e) {
            error = true;
            error_message->set_error(game::error::ERROR_EXCEPTION);
            error_message->set_msg(e.what());
        }
        if (!error && hash == hash_from_data_base) {
            auto *player_info = new game::PlayerInfo;
            try {
                data::DataBase_connector::get_client_info(client_login, player_info);
            } catch (std::exception &e) {
                error = true;
                error_message->set_error(game::error::ERROR_EXCEPTION);
                error_message->set_msg(e.what());
            }
            if (!error) {
                delete error_message;
                login_response_second->set_allocated_player_info(player_info);
            }
        } else {
            error_message->set_error(game::error::ERROR_UNCORRECT_PASSWORD);
            login_response_second->set_allocated_msg(error_message);
        }
        response->set_allocated_login_response_second(login_response_second);
    }
    return grpc::Status::OK;

}


grpc::Status authorization_service::Registration(grpc::ServerContext *context, const game::RegisterRequest *request, game::RegisterResponse *response) {
    auto *status_message = new game::StatusMessage;
    auto *error_message = new game::ErrorMessage;
    bool error = false;
    if (!data::DataBase_connector::check_login_correctness(request->name())) {
        error = true;
        error_message->set_error(game::error::ERROR_USER_WITH_THIS_LOGIN_ALREADY_EXISTS);
    }
    if (!error) {
        delete error_message;
        auto *player_info = new game::PlayerInfo;
        data::DataBase_connector::insert_new_client(request->name(), request->salt_hash().salt(), request->salt_hash().hash(), player_info);
        response->set_allocated_player_info(player_info);
    } else {
        response->set_allocated_msg(error_message);
    }
    return grpc::Status::OK;
}

//can we return status from lobby function, which call GameFunc from client,
//so we'll create new stub and game and our connection now will be pointing at Game
//

grpc::Status lobby_service::LobbyFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::LobbyResponses, game::LobbyRequests> *stream) {
    game::LobbyRequests request;
    while (stream->Read(&request)) {
        game::LobbyResponses response;
        if (request.has_create_game_request()) {
            const auto& create_game_request = request.create_game_request();
            const auto *player_info = &create_game_request.player_info();
            const auto *game_parameters = &create_game_request.game_parameters();
            const auto& client_name = create_game_request.game_owner();
            std::unique_ptr<player> game_owner(new player(client_name, player_info, game_parameters->game_enter_balance(), stream));
            std::unique_ptr<server::Game> new_game(new server::Game(player_info->client_id(), game_parameters, std::move(game_owner)));
            auto game_id = generate_id();
            std::unique_lock<std::mutex> lock(m_mutex);
            all_games[game_id] = std::move(new_game); //TODO::replace with one
            game_id_to_parameter[game_id] = *game_parameters;
            lock.unlock();
        } else { //if it has search game request
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
}

grpc::Status game_service::GameFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::GameResponses, game::GameRequests> *stream) {

}

int lobby_service::generate_id() {
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