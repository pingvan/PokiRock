#pragma once

#include <grpcpp/grpcpp.h>
#include <unordered_map>
#include <memory>
#include <mutex>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

#include "game_copy_for_server.h"

struct authorization_service final : public game::Authorization::Service {
    grpc::Status Login(grpc::ServerContext *context, const game::LoginRequest *request, game::LoginResponse *response) override;
    grpc::Status Registration(grpc::ServerContext *context, const game::RegisterRequest *request, game::RegisterResponse *response) override;
};

struct lobby_service final : public game::Lobby::Service {
    grpc::Status LobbyFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::LobbyResponses, game::LobbyRequests> *stream) override;

    [[nodiscard]] static bool compare_parameters(const game::GameParameters &game_params_lhs, const game::GameParameters &game_params_rhs);
private:
    static int generate_id();
    static std::unordered_map<uint32_t, std::unique_ptr<grpc::ServerAsyncReaderWriter<game::LobbyResponses, game::LobbyRequests>>> clients_online;
};

struct game_service final : public game::PokerGame::Service {
    grpc::Status GameFunc(grpc::ServerContext *context, grpc::ServerReaderWriter<game::GameResponses, game::GameRequests> *stream) override;
private:
    friend struct lobby_service;

    //TODO::maybe shit...

    static inline std::mutex m_mu;

    static std::mutex &get_mutex() {
        static std::mutex m_mutex;
        return m_mutex;
    }

    static std::unordered_map<uint32_t, std::unique_ptr<server::Game>> &get_all_games() {
        static std::unordered_map<uint32_t, std::unique_ptr<server::Game>> all_games;
        return all_games;
    }
};

