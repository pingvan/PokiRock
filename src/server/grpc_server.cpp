#include "grpc_server.hpp"
#include <iostream>
#include <memory>
#include <string>
#include "DataBase_connector.h"

grpc::Status Poker_server::PokerFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::all_responses, game::all_requests> *stream) {
    game::Requests request;
    while(stream->Read(&request)) {
        game::Responses response;
        if (request.has_login_request()) {
            auto *login_response = new game::login_response;
            auto *status_message = new game::status_message;
            auto login = request.login_request().name();
            auto password = request.login_request().password();
            auto salt_hash_pair = data::DataBase_connector::log_in_client(login);
            auto hash = salt_hash_pair.first;
            auto salt = salt_hash_pair.second;
            auto hashed_password = data::DataBase_connector::sha_hash(salt + password);
            if (hash == hashed_password) {
                status_message->set_status(true);
                status_message->set_message("Password correct\n");
                auto *player_info = new game::player_info;
                data::DataBase_connector::get_client_info(login, player_info);
                login_response->set_allocated_player_info(player_info);
            } else {
                status_message->set_status(false);
                status_message->set_message("Uncorrect password!\nTry again!\n");
            }
            login_response->set_allocated_status_message(status_message);
            response.set_allocated_login_response(login_response);
        } else if (request.has_register_request()) {
            auto *register_response = new game::register_response;
            auto *status_message = new game::status_message;
            if (!data::DataBase_connector::check_login_correctness(request.register_request().name())) {
                data::DataBase_connector::insert_new_client(
                    request.register_request().name(), request.register_request().salt_hash().salt(),
                    request.register_request().salt_hash().hash()
                );
                //get client info
                status_message->set_status(true);
                status_message->set_message("You successfully registered!");
                std::cout << request.register_request().name() << " WAS SUCCESSFULLY REGISTERED\n";
            } else {
                status_message->set_status(false);
                status_message->set_message(
                    "User with this login already exists!\nLogin or try another user "
                    "name!"
                );
                register_response->unsafe_arena_set_allocated_status_message(status_message);
                std::cout << request.register_request().name() << " ERROR\n";
            }
            response.set_allocated_register_response(register_response);
        } else { //if create game request

        }
    }
    return grpc::Status::OK;
}


