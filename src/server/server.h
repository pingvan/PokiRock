#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <iostream>
#include <unordered_set> //I hope it will be DB in next versions
#include <map>
#include <vector>
#include <queue>

namespace client {
    struct client;
}
namespace server {
    struct game{
    private:
        std::vector<client::client> players;
        std::map<client::client, std::pair<int, int>> cards;
        std::vector<int> availible_cards;
    public:
        game(std::vector<client::client> lobbi);
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
