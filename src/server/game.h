
#ifndef POKIROCK_GAME_H
#define POKIROCK_GAME_H
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>  //I hope it will be DB in next versions
#include <vector>

namespace client {
struct client;
}

namespace server {
struct game {
private:
    std::vector<client::client> players;
    std::map<client::client, std::pair<int, int>>
        cards;  // TODO make enum class Value, Suit & struct Card
    std::map<client::client, int> balance;
    std::vector<int> available_cards;
    std::vector<int> board_cards;
    int total_of_bets;

public:
    explicit game(std::vector<client::client> lobby);
    void bets();
    void preflop();
    void flop();
    void make_a_bet(const client::client &player, int bet_amount);
    void turn();
    void river();
    int get_card();
    void print_cards();
    void who_won();
    static std::pair<int, int> rank_combination(
        const std::vector<int> &combination
    );
};

}  // namespace server

#endif  // POKIROCK_GAME_H
