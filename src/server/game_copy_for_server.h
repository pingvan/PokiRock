#ifndef GAME_H
#define GAME_H

#include <unordered_map>
#include <memory>
#include "../client/client.h"
#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"
#include "Card.hpp"
#include "DataBase_connector.h"

enum Which_turn { Preflop, Flop, Turn, River };

struct Blinds {
    int big_blind = 10; //TODO::make const and static
    int small_blind = 5;
};

namespace server {
struct Game {
private:
    Which_turn current_turn = Which_turn::Preflop;
    std::vector<client::Client> players;
    std::vector<client::Client> round_players;
    int button;
    int last_player;
    Blinds blinds;
    std::unordered_map<client::Client, std::pair<Card, Card>, client::ClientHash> cards_enum;
    //std::map<client::Client, std::pair<Card, Card>> cards_enum;
    std::unordered_map<client::Client, int, client::ClientHash> balance;
//    std::map<client::Client, int> balance;
    std::vector<int> available_cards;
    std::vector<Card> board_cards;
    int total_of_bets;


    //new

    std::string gama_owner;
    int players_max;
    int current_players;
    int minimal_bet;
    std::mutex m_mutex;
    std::unordered_map<int, std::unique_ptr<grpc::ServerAsyncReaderWriter<game::move_request, game::move_response>>> players_;

public:
    explicit Game(std::vector<client::Client> lobby);
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

    template <typename T>
    void increase_iterator(T &iterator) {
        iterator++;
        if (iterator == round_players.end()) {
            iterator = round_players.begin();
        }
    }
};

}  // namespace server

#endif  // GAME_H