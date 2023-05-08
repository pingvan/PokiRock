#include "grpc_server.hpp"
#include <string>
#include <iostream>
#include <grpcpp/grpcpp.h>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

#include "DataBase_connector.h"

struct lobby_events final : public game::lobby::Service {
    grpc::Status Login([[maybe_unused]] grpc::ServerContext *context, const game::login_request *request, game::login_response *response) override {
        if (request->has_name()) {
            const std::string client_name = request->name().name();
            auto salt_hash_pair = data::DataBase_connector::log_in_client(client_name);
            game::salt_hash *salt_hash = new game::salt_hash;
            salt_hash->set_salt(salt_hash_pair.first);
            salt_hash->set_hash(salt_hash_pair.second);
            response->set_allocated_salt_hash(salt_hash);
        } else {
            game::status_message *status_msg = new game::status_message;
            if (request->after_compare()) {
                status_msg->set_status(true);
                status_msg->set_message("");
            } else {
                status_msg->set_status(false);
                status_msg->set_message("Incorrect login or password!\nTry again!");
            }
            response->set_allocated_status_message(status_msg);
        }
        return grpc::Status::OK;
    }

    grpc::Status Register([[maybe_unused]] grpc::ServerContext *context, const game::register_request *request, game::register_response *response) override {
        game::status_message *status_msg = new game::status_message;
        if (!data::DataBase_connector::check_login_correctness(request->name().name())) {
            data::DataBase_connector::insert_new_client(request->name().name(), request->salt_hash().salt(), request->salt_hash().hash());
            status_msg->set_status(true);
            status_msg->set_message("You successfully registered!");
        } else {
            status_msg->set_status(false);
            status_msg->set_message("User with this login already exists!\nLogin or try another user name!");
            response->set_allocated_status_message(status_msg);
        }
        return grpc::Status::OK;
    }
};

struct game_events final : public game::game::Service {

};