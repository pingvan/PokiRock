#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "../client/Client.h"
#include "Game.h"

namespace server {
struct Server {
private:
    std::queue<client::Client> players;
    std::vector<server::Game> games;

public:
    void add(const client::Client &client);
    void start_game();
};

}  // namespace Server
#endif  // SERVER_H
