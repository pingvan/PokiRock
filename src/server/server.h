#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <iostream>
#include <unordered_set> //I hope it will be DB in next versions
#include <map>
#include <set>
#include <vector>
#include <queue>

namespace client {
    struct client;
}
namespace server {
    struct game{
    private:
        std::set<client::client> players;
        std::map<client::client, std::pair<int, int>> cards;
        std::map<client::client, int> balance;
        std::vector<int> available_cards;
        std::vector<int> board_cards;
        int total_of_bets;

    public:
        game(std::set<client::client> lobbi);
        void preflop();
        void bets();
        void flop();
        void turn();
        void river();
        int get_card();
        void print_cards();
        void who_won();
    };

    struct server{
    private:
        std::queue<client::client> players;
        std::vector<game> games;
    public:
        void add(const client::client& client);
        void start_game();
    };


}
#endif //SERVER_H
