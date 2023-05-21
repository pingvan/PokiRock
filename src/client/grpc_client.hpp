#pragma once

#include <string>
#include <memory>
#include <grpcpp/grpcpp.h>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

struct client {
    client(const std::shared_ptr<grpc::Channel>& new_channel);
    void login(const std::string &client_name, const std::string &password);
    void registration(const std::string &client_name, const std::string &password);

    ~client() = default;
private:
    std::unique_ptr<game::PokerGame::Stub> lobby_stub_;
    std::shared_ptr<grpc::ClientAsyncReaderWriter<game::Requests, game::Responses>> stream;

    uint32_t client_id;
    uint32_t client_games;
    uint32_t client_wins;
    uint32_t client_balance;

    static std::string sha_hash(const std::string &phrase);
    static std::string generate_salt(int length);
};
