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
    enum lobby_requests {CREATE_GAME, SEARCH_GAME};
    enum game_requests {JOIN_GAME, JOIN_GAME_AS_OWNER};
//    enum responses {LOGIN_RESPONSE_FIRST, LOGIN_RESPONSE_SECOND, REGISTER_RESPONSE};

    explicit client(std::shared_ptr<grpc::Channel> new_channel);

    void init_player_info(const game::PlayerInfo &player_info);
    void init_proto_player_info_message(game::PlayerInfo *player_info) const;
    static void init_proto_game_parameters(game::GameParameters *game_parameters, const std::string &game_name, uint32_t number_of_players, uint32_t minimal_bet, uint32_t game_enter_balance) ;

    void login(const std::string &client_login, const std::string &password);
    void registration(const std::string &client_login, const std::string &password);

    void lobby_init();
    void make_lobby_requests(client::lobby_requests request_type, const std::string &game_name, uint32_t number_of_players, uint32_t minimal_bet, uint32_t game_enter_balance);
    void process_lobby_responses();

    void game_init();

    void make_game_requests(client::game_requests request_type, const uint32_t game_id);
    void process_game_responses();

    //bool or void or return some custom error

    template<typename T>
    bool handle(const T *response);

    template <typename response_type>
    bool handle_error_for_each_type(const grpc::Status &status, const response_type * response);

    template <typename response_type>
    bool handle_error(const response_type *response);
private:
    std::shared_ptr<grpc::Channel> channel_;

    grpc::ClientContext *lobby_context_;
    grpc::ClientContext *poker_game_context;

    std::unique_ptr<game::Authorization::Stub> authorization_stub_;
    std::unique_ptr<game::Lobby::Stub> lobby_stub_;
    std::unique_ptr<game::PokerGame::Stub> poker_game_stub_;

    std::shared_ptr<grpc::ClientReaderWriter<game::LobbyRequests, game::LobbyResponses>> lobby_stream_;
    std::shared_ptr<grpc::ClientReaderWriter<game::GameRequests, game::GameResponses>> poker_game_stream;

    std::string client_name;
    uint32_t client_id;
    uint32_t client_games;
    uint32_t client_wins;
    uint32_t client_balance;

    bool in_game = false;
};
