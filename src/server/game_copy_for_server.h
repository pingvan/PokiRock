#pragma once

#include <unordered_map>
#include <memory>
#include <random>
#include <grpcpp/grpcpp.h>

#include "player.hpp"
#include "../client/client.h"
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
//    friend struct player;
private:
    Which_turn current_turn = Which_turn::Preflop; //doesn't need to be replaced

    std::vector<client::Client> players; //replaced with class_players
    std::vector<client::Client> round_players; //replaced with map of round_players
    int button; //doesn't need to be replaced
    int last_player; //doesn't need to be replaced
    Blinds blinds; //doesn't need to be replaced
    std::unordered_map<client::Client, std::pair<Card, Card>, client::ClientHash> cards_enum; //now player class contains this info
    //std::map<client::Client, std::pair<Card, Card>> cards_enum;
    std::unordered_map<client::Client, int, client::ClientHash> balance; //now player class contains this info
//    std::map<client::Client, int> balance;
    std::vector<int> available_cards;  //doesn't need to be replaced
    std::vector<Card> board_cards; //doesn't need to be replaced (I think)
    int total_of_bets; //doesn't need to be replaced



    //new
    game_condition condition;

    const uint32_t game_owner_id_;
    const std::string game_name_;
    const uint32_t players_max_;
    uint32_t current_players_;
    const uint32_t minimal_bet_;
    const uint32_t game_enter_balance_;
    mutable std::mutex m_mutex;
//    std::unordered_map<int, std::unique_ptr<grpc::ServerAsyncReaderWriter<game::move_request, game::move_response>>> players_;
//    std::unordered_map<int, std::pair<Card, Card>> players_cards;
//    std::unordered_map<int, int> players_balance;

    //TODO::map with players on this round
    std::unordered_map<uint32_t, std::shared_ptr<player>> class_players;
    std::unordered_map<uint32_t, std::shared_ptr<player>> round_players_;

public:
    explicit Game(std::vector<client::Client> lobby);
    explicit Game(uint32_t game_owner_id, const game::game_parameters *game_parameters, std::unique_ptr<player> owner);

    void join_game(std::unique_ptr<player> player);
    void quit_game(int player_id);

    void start_game();

    void bets();
    int next_position(int position);
    void preflop();
    void flop();
    void make_a_bet(const client::Client &player, int bet_amount);
    void turn();
    void river();
    Card get_enum_card();
    void print_cards();
    void who_won();
    void new_round();

private:
    template <typename T>
    void increase_iterator(T &iterator) {
        iterator++;
        if (iterator == round_players.end()) {
            iterator = round_players.begin();
        }
    }
};

}  // namespace server