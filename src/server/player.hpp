#pragma once

#include <string>
#include <memory>
#include <grpcpp/grpcpp.h>
#include "../proto/game.pb.h"
#include "../proto/game.grpc.pb.h"
#include "Card.hpp"

namespace server {
    struct Game;
    struct unfair_plays;
}

enum status {
    waiting, fold, playing, win
};

struct player {
    friend server::unfair_plays;
    player(std::string player_name, const game::PlayerInfo *player_info, uint32_t game_enter_balance,
           grpc::ServerReaderWriter<game::GameResponses, game::GameRequests> *stream);

    friend struct server::Game;
    std::string player_name_;
public:
    uint32_t stream_;
    uint32_t player_id_;
    uint32_t player_games_;
    uint32_t player_wins_;
    uint32_t in_game_balance_;
    uint32_t current_balance_;
    status player_status; //maybe we don't need it
    std::pair<Card, Card> player_cards;
    std::shared_ptr<grpc::ServerReaderWriter<game::GameResponses, game::GameRequests>> stream_;
};
