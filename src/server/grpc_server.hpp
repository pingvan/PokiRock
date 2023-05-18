#pragma once

#include <grpcpp/grpcpp.h>
#include <unordered_map>
#include <memory>
#include <mutex>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

#include "game_copy_for_server.h"

struct lobby_events final : public game::lobby::Service {
    grpc::Status Login([[maybe_unused]] grpc::ServerContext *context, const game::login_request *request, game::login_response *response) override;
    grpc::Status Register([[maybe_unused]] grpc::ServerContext *context, const game::register_request *request, game::register_response *response) override;
};

struct [[maybe_unused]] game_events final : public game::game::AsyncService {

};

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

struct all_types final : public game::all_types_of_calls::Service {
    grpc::Status PokerFunc([[maybe_unused]] grpc::ServerContext *context, grpc::ServerReaderWriter<game::all_responses, game::all_requests> *stream) override;
private:
    std::mutex m_mutex;
    std::unordered_map<int, std::unique_ptr<game_room>> m_all_games;

    std::unordered_map<int, std::unique_ptr<server::Game>> all_games;
};
