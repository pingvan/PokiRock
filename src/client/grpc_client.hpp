#pragma once

#include <string>
#include <memory>
#include <grpcpp/grpcpp.h>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

//in main will be created new client, and then we'll call processes on it
//create derived class from client, which will be logged in client with initialized fields



struct client {
    //enum requests {NO_REQUEST, LOGIN, REGISTRATION, CREATE_GAME, SEARCH_GAME, ENTER_GAME, MAKE_MOVE};

    explicit client(std::shared_ptr<grpc::Channel>& new_channel);
    void init_player_info(const game::PlayerInfo &player_info);

    void login(const std::string &client_name, const std::string &password);
    void registration(const std::string &client_name, const std::string &password);

    void lobby_init();
    void make_lobby_requests();
    void process_lobby_responses();

    void game_init();
    void make_game_requests();
    void process_game_responses();
private:
    std::shared_ptr<grpc::Channel> channel_;

    grpc::ClientContext *lobby_context_;
    grpc::ClientContext *poker_game_context;

    std::unique_ptr<game::Authorization::Stub> authorization_stub_;
    std::unique_ptr<game::Lobby::Stub> lobby_stub_;
    std::unique_ptr<game::PokerGame::Stub> poker_game_stub_;

    std::shared_ptr<grpc::ClientReaderWriter<game::LobbyRequests, game::LobbyResponses>> lobby_stream_;
    std::shared_ptr<grpc::ClientReaderWriter<game::GameRequests, game::GameResponses>> poker_game_stream;

    uint32_t client_id;
    uint32_t client_games;
    uint32_t client_wins;
    uint32_t client_balance;

    bool in_game = false;
};
