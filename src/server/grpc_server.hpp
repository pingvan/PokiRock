#pragma once

#include <grpcpp/grpcpp.h>
#include <unordered_map>
#include <memory>
#include <mutex>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

#include "game_copy_for_server.h"

struct server_pok {
    explicit server_pok(const std::string &server_address);

private:
    std::unique_ptr<grpc::Server> server_;
};


struct game_room {

private:
    int game_id;
    std::mutex m_mutex;
    std::unordered_map<int, std::unique_ptr<grpc::ServerAsyncReaderWriter<game::move_request, game::move_response>>> players_;
};

struct Poker_server final : public game::PokerGame::Service {
    grpc::Status PokerFunc([[maybe_unused]] grpc::ServerContext *context, grpc::ServerReaderWriter<game::Responses, game::Requests> *stream) override;
private:
    std::mutex m_mutex;
    std::unordered_map<int, std::unique_ptr<game_room>> m_all_games;

    std::unordered_map<int, std::unique_ptr<server::Game>> all_games;
};
