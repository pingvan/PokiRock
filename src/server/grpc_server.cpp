#include "grpc_server.hpp"
#include <iostream>
#include <memory>
#include <string>
#include "DataBase_connector.h"

grpc::Status lobby_events::Login(
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
}
