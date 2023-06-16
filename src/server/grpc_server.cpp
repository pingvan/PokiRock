#include "grpc_server.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include "DataBase_connector.h"


grpc::Status authorization_service::Login(grpc::ServerContext *context, const game::LoginRequest *request, game::LoginResponse *response) {
    if (request->has_login_request_first()) {
        bool error = false;
        auto *login_response_first = new game::LoginResponseFirst;
        auto *error_message = new game::ErrorMessage;
        auto client_login = request->login_request_first().name();
        std::string salt;
        try {
            salt = data::DataBase_connector::get_salt(client_login);
        } catch(std::exception &e) {
            error = true;
            error_message->set_error(game::error::ERROR_EXCEPTION);
            error_message->set_message_string(e.what());
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
            error_message->set_message_string(e.what());
        }
        if (!error && hash == hash_from_data_base) {
            auto *player_info = new game::PlayerInfo;
            try {
                data::DataBase_connector::get_client_info(client_login, player_info);
            } catch (std::exception &e) {
                error = true;
                error_message->set_error(game::error::ERROR_EXCEPTION);
                error_message->set_message_string(e.what());
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


grpc::Status lobby_service::LobbyFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::LobbyResponses, game::LobbyRequests> *stream) {
    game::LobbyRequests request;
    while (stream->Read(&request)) {
        game::LobbyResponses response;
        if (request.has_create_game_request()) {
            auto *create_game_response = new game::CreateGameResponse;
            auto *error_message = new game::ErrorMessage;

            const auto& create_game_request = request.create_game_request();
            const auto *game_parameters = &create_game_request.game_parameters();

            std::unique_ptr<server::Game> new_game(new server::Game(create_game_request.game_owner_id(), game_parameters));
            auto game_id = generate_id();
            std::unique_lock<std::mutex> lock(game_service::get_mutex());
            game_service::get_all_games()[game_id] = std::move(new_game); //TODO::replace with one
            lock.unlock();
            //TODO::new game get parameters

            create_game_response->set_game_id(game_id);

            response.set_allocated_create_game_response(create_game_response);
            stream->Write(response);

        } else { //if it has search game request
            auto *search_game_response = new game::SearchGameResponse;
            auto *error_message = new game::ErrorMessage;

            const auto &search_game_request = request.search_game_request();
            const auto& game_parameters = search_game_request.game_parameters();
            std::unique_lock<std::mutex> lock(game_service::get_mutex());
            uint32_t game_id_found = -1;
            for (const auto &[id, game] : game_service::get_all_games()) { //TODO::repeated game parameters so we can choose few parameters
                if (compare_parameters(game->get_game_parameters(), game_parameters) && game->is_owner_connected()) {
                   game_id_found = id;
                   break;
                }
            }
            lock.unlock();
            if (game_id_found != -1) {
                delete error_message;
                search_game_response->set_game_id(game_id_found);
            } else {
                error_message->set_error(game::error::ERROR_GAME_NOT_FOUND);
                search_game_response->set_allocated_msg(error_message);
            }

            response.set_allocated_search_game_response(search_game_response);
            stream->Write(response);
        }
    }
    return grpc::Status::OK;
}

grpc::Status game_service::GameFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::GameResponses, game::GameRequests> *stream) {
    game::GameRequests request;
    while (stream->Read(&request)) {
        if (request.has_make_move_request()) {

        } else if (request.has_join_game_request()) {
            auto game_id_to_connect = request.join_game_request().game_id();
            std::unique_lock<std::mutex> lock(game_service::get_mutex());
            auto game_enter_balance = get_all_games()[game_id_to_connect]->get_game_enter_balance();
            std::unique_ptr<player> new_player(new player(request.join_game_request().player_name(), &request.join_game_request().player_info(), game_enter_balance, stream));
            get_all_games()[game_id_to_connect]->join_game(std::move(new_player));
            lock.unlock();
        } else { //if join game as owner request
            auto game_id_to_connect = request.join_game_as_owner_request().game_id();
            std::unique_lock<std::mutex> lock(game_service::get_mutex());
            auto game_enter_balance = get_all_games()[game_id_to_connect]->get_game_enter_balance();
            std::unique_ptr<player> new_player(new player(request.join_game_as_owner_request().player_name(), &request.join_game_as_owner_request().player_info(), game_enter_balance, stream));
            get_all_games()[game_id_to_connect]->join_game_as_owner(std::move(new_player));
            lock.unlock();
        }
    }
    return grpc::Status::OK;
}

bool lobby_service::compare_parameters(const game::GameParameters &game_params_lhs, const game::GameParameters &game_params_rhs) {
    if (game_params_lhs.number_of_players() == game_params_rhs.number_of_players() &&
        game_params_lhs.minimal_bet() == game_params_rhs.minimal_bet() &&
        game_params_lhs.game_enter_balance() == game_params_rhs.game_enter_balance()) {
        return true;
    }
    return false;
}


int lobby_service::generate_id() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 291203);
    auto new_game_id = distrib(gen);
    std::unique_lock<std::mutex> lock(game_service::get_mutex());
    while (game_service::get_all_games().find(new_game_id) == game_service::get_all_games().end()) {
        new_game_id = distrib(gen);
    }
    lock.unlock();
    return new_game_id;
}

