#pragma once

#include <grpcpp/grpcpp.h>
#include <unordered_map>
#include <memory>
#include <mutex>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

#include "game_copy_for_server.h"

struct Poker_server final : public game::PokerGame::Service {
    grpc::Status PokerFunc([[maybe_unused]] grpc::ServerContext *context, grpc::ServerReaderWriter<game::Responses, game::Requests> *stream) override;
private:
    int generate_id();

    std::mutex m_mutex;
    std::unordered_map<int, std::unique_ptr<server::Game>> all_games;
    std::unordered_map<int, game::game_parameters> game_id_to_parameter;

    std::unordered_map<int, std::unique_ptr<grpc::ServerAsyncReaderWriter<game::Responses, game::Requests>>> clients_online;
};
