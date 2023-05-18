#include "grpc_server.hpp"
#include <iostream>
#include <memory>
#include <string>
#include "DataBase_connector.h"

server::server(const std::string &server_address) {
    grpc::ServerBuilder builder;
    lobby_events service;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    server_ = builder.BuildAndStart();
    std::cout << server_address << '\n';
    server_->Wait();
}

grpc::Status all_types::PokerFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::all_responses, game::all_requests> *stream) {
    game::all_requests request;
    while(stream->Read(&request)) {
        game::all_responses response;
        if (request.has_login_request()) {
            auto *login_response = new game::login_response_;
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
                game::player_info *player_info = new game::player_info;
                data::DataBase_connector::get_client_info(login, player_info);
                login_response->set_allocated_player_info(player_info);
            } else {
                status_message->set_status(false);
                status_message->set_message("Uncorrect password!\nTry again!\n");
            }
            login_response->set_allocated_status_message(status_message);
            response.set_allocated_login_response(login_response);
        } else if (request.has_register_request()) {
            //TODO::copy register
        } else { //if create game request

        }
    }
    return grpc::Status::OK;
}

/*grpc::Status lobby_events::Login(
    [[maybe_unused]] grpc::ServerContext *context,
    const game::login_request *request,
    game::login_response *response
) {
    if (request->has_name()) {
        const std::string client_name = request->name();
        auto salt_hash_pair =
            data::DataBase_connector::log_in_client(client_name);
        game::salt_hash *salt_hash = new game::salt_hash;
        salt_hash->set_hash(salt_hash_pair.first);
        salt_hash->set_salt(salt_hash_pair.second);
        response->set_allocated_salt_hash(salt_hash);
        std::cout << "Salt and Hash sent for " << request->name() << '\n';
        std::cout << salt_hash_pair.first << '\n';
        std::cout << salt_hash_pair.second << '\n';
    } else {
        game::status_message *status_msg = new game::status_message;
        if (request->after_compare()) {
            std::cout << "Logged In\n";
            status_msg->set_status(true);
            status_msg->set_message("Correct");
        } else {
            std::cout << "Incorrect login\n";
            status_msg->set_status(false);
            status_msg->set_message("Incorrect login or password!\nTry again!");
        }
        response->set_allocated_status_message(status_msg);
    }
    return grpc::Status::OK;
}


grpc::Status lobby_events::Register(
    [[maybe_unused]] grpc::ServerContext *context,
    const game::register_request *request,
    game::register_response *response
) {
    game::status_message *status_msg = new game::status_message;
    if (!data::DataBase_connector::check_login_correctness(request->name())) {
        data::DataBase_connector::insert_new_client(
            request->name(), request->salt_hash().salt(),
            request->salt_hash().hash()
        );
        status_msg->set_status(true);
        status_msg->set_message("You successfully registered!");
        std::cout << request->name() << " WAS SUCCESSFULLY REGISTERED\n";
    } else {
        status_msg->set_status(false);
        status_msg->set_message(
            "User with this login already exists!\nLogin or try another user "
            "name!"
        );
        response->set_allocated_status_message(status_msg);
        std::cout << request->name() << " ERROR\n";
    }
    response->set_allocated_status_message(status_msg);
    return grpc::Status::OK;
}*/
