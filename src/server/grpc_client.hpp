#pragma once

#include <string>
#include <memory>
#include <grpcpp/grpcpp.h>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

struct client {
    client(std::shared_ptr<grpc::Channel> new_channel);
    void login(const std::string &client_name, const std::string &password);
    void registration(const std::string &client_name, const std::string &password);
private:
    std::shared_ptr<grpc::Channel> channel_;
    std::unique_ptr<game::lobby::Stub> lobby_stub;

    static std::string sha_hash(const std::string &phrase);
    static std::string generate_salt(int length);
};
