#include "Server.h"
#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include "Win_check.h"

namespace server {

    std::string num2card(int num) {
        static constexpr std::array<const char *, 13> values_of_cards = {
                "2", "3", "4", "5", "6", "7", "8",
                "9", "10", "Jack", "Queen", "King", "Ace"};
        std::string card;
        card += values_of_cards[num / 4];
        if (num % 4 == 0) {
            card += "_of_hearts";
        } else if (num % 4 == 1) {
            card += "_of_diamonds";
        } else if (num % 4 == 2) {
            card += "_of_spades";
        } else if (num % 4 == 3) {
            card += "_of_clubs";
        }
        return card;
    }

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
        our_game.flop();
        our_game.turn();
        our_game.river();
    }
}  // namespace Server
