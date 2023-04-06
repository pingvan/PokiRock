#include "Server.h"

namespace server {

void Server::add(const client::Client &client) {
    players.push(client);
}

void Server::start_game() {
    std::vector<client::Client> lobby;
    for (int i = 0; i < 5; i++) {
        if (!players.empty()) {
            auto player = (players.front());
            players.pop();
            lobby.emplace_back(player);
        }
    }
    games.emplace_back(lobby);
    auto &our_game = games.back();
    our_game.preflop();
}
}  // namespace server
