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
            const auto& login_request = request.login_request();
            auto *login_response = new game::login_response;
            auto *status_message = new game::status_message;
            if (login_request.has_login_request_first()) {
                auto *login_response_first = new game::login_response_first;
                auto client_login = login_request.login_request_first().name();
                auto salt = data::DataBase_connector::get_salt(client_login); //
                login_response_first->set_salt(salt);
                status_message->set_status(true);
                status_message->set_message("User exists");
            } else {

            }
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


