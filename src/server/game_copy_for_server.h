#pragma once

#include <unordered_map>
#include <memory>
#include <random>
#include <grpcpp/grpcpp.h>

#include "player.hpp"
#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"
#include "Card.hpp"
#include "DataBase_connector.h"

enum Which_turn { Preflop, Flop, Turn, River };
enum game_condition { Playing, Waiting };

struct Blinds {
    int big_blind = 10; //TODO::make const and static
    int small_blind = 5;
};

namespace server {
struct Game {
private:
    Which_turn current_turn = Which_turn::Preflop;


    uint32_t button;
    uint32_t last_player;
    Blinds blinds;


    std::vector<int> available_cards;
    std::vector<Card> board_cards;
    uint32_t total_of_bets;



    game_condition condition;

    const uint32_t game_owner_id_;
    const std::string game_name_;
    const uint32_t players_max_;
    uint32_t current_players_;
    const uint32_t minimal_bet_;
    const uint32_t game_enter_balance_;

    bool owner_connected;

    mutable std::mutex m_mutex;

    std::unordered_map<uint32_t, std::shared_ptr<player>> players_in_room_;
    std::vector<uint32_t> players_in_round_;

public:
    explicit Game(uint32_t game_owner_id, const game::GameParameters *game_parameters);

    void join_game_as_owner(std::unique_ptr<player> owner);
    void join_game(std::unique_ptr<player> player);
    void quit_game(uint32_t player_id);

    void start_game();

    void bets();
    uint32_t next_position(uint32_t position);
    void preflop();
    void flop();
    void make_a_bet(uint32_t player_id, uint32_t bet_amount);
    void turn();
    void river();
    Card get_enum_card();
    void who_won();
    void new_round();

//private:
    game::GameParameters get_game_parameters() const;
    bool is_owner_connected() const;
    uint32_t get_game_enter_balance() const;

    void cards_to_proto(Card &card, game::Card *first);
    void suit_to_proto(Suit &suit, game::Card *card);
    void value_to_proto(Value &value, game::Card *card);

    void broadcast_for_all_players_in_lobby(game::GameResponses *response);
    void broadcast_for_round(game::GameResponses *response);

    template <typename T>
    void increase_iterator(T &iterator) {
        iterator++;
        if (iterator == players_in_round_.end()) {
            iterator = players_in_round_.begin();
        }
    }
};

}  // namespace server