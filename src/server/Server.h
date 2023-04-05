#ifndef SERVER_H
#define SERVER_H

#include "../rename_later.h"
#include "Game.h"
#include "../client/Client.h"

namespace server {
    struct Game;

struct Server {
private:
    std::queue<client::Client> players{};
    std::vector<server::Game> games{};

public:
    void add(const client::Client &client);
    void start_game();
};

}  // namespace Server
#endif  // SERVER_H
