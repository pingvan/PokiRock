#pragma once

#include <string>
#include <memory>
#include <grpcpp/grpcpp.h>

#include "../proto/game.pb.h"
#include "../proto/game.grpc.pb.h"
#include "Card.hpp"


namespace server {
    struct Game;
}

enum status {
    waiting, fold, playing, win
};

struct player {
//    Player(std::string player_name, int player_id, int in_game_balance, int current_balance);
    player(std::string  player_name, const game::PlayerInfo *player_info, int game_enter_balance,
           grpc::ServerReaderWriter<game::GameResponses, game::GameRequests> *stream);

    void process_responses();

    friend struct server::Game;
private:
    std::string player_name_;
    uint32_t player_id_;
    uint32_t player_games_;
    uint32_t player_wins_;
    uint32_t in_game_balance_;
    uint32_t current_balance_;
    status player_status; //maybe we don't need it
    std::pair<Card, Card> player_cards;
    std::shared_ptr<grpc::ServerReaderWriter<game::GameResponses, game::GameRequests>> stream_;
};
