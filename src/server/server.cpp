#include "server.h"
#include "../client/client.h"

namespace server {
    std::string num2card(int num) {
        std::vector<std::string> values_of_cards;
        for (int i = 2; i <= 14; i++) {
            if (i < 11) {
                values_of_cards.push_back(std::to_string(i));
            } else if (i == 11) {
                values_of_cards.emplace_back("Jack");
            } else if (i == 12) {
                values_of_cards.emplace_back("Queen");
            } else if (i == 13) {
                values_of_cards.emplace_back("King");
            } else if (i == 14) {
                values_of_cards.emplace_back("Ace");
            }
        }
        std::string card;
        card += values_of_cards[num / 4];
        if (num % 4 == 0) {
            card += " of hearts";
        } else if (num % 4 == 1) {
            card += " of diamonds";
        } else if (num % 4 == 2) {
            card += " of spades";
        } else if (num % 4 == 3) {
            card += " of clubs";
        }
        return card;
    }

    void server::add(const client::client &client) {
        players.push(client);
    }

    void server::start_game() {
        std::set<client::client> lobbi;
        for (int i = 0; i < 5; i++) {
            if (!players.empty()) {
                auto player = players.front();
                players.pop();
                lobbi.emplace(player);
            }
        }
        games.emplace_back(lobbi);
        auto &our_game = games.back();
        our_game.preflop();
        our_game.flop();
        our_game.turn();
        our_game.river();
    }

    game::game(std::set<client::client> lobbi) : players(std::move(lobbi)) {
        for (int i = 0; i < 52; i++) {
            available_cards.push_back(i);
        }
        std::cout << "Starting game with: ";
        for (const client::client &player: players) {
            cards[player] = {get_card(), get_card()};
            balance[player] = 100;
            std::cout << player.name() << " ";
        }
        std::cout << "\n";
    }

    void game::preflop() {
        std::cout << "Preflop\n";
        for (const auto &player: players) {
            std::string optional_move = player.optional_move();
            if (optional_move == "balance") {
                std::cout << "Your balance is: " << balance[player] << "\n";
            } else if (optional_move == "cards") {
                std::cout << num2card(cards[player].first) << " " << num2card(cards[player].second) << "\n";
            }
        }
        bets();
    }

    void game::flop() {
        if (players.size() > 1) {
            std::cout << "Flop\n";
            for (int i = 0; i < 3; i++) {
                board_cards.push_back(get_card());
            }
            print_cards();
            bets();
        }
    }

    void game::turn() {
        if (players.size() > 1) {
            std::cout << "Turn\n";
            board_cards.push_back(get_card());
            print_cards();
            bets();
        }
    }

    void game::river() {
        if (players.size() > 1) {
            std::cout << "River\n";
            board_cards.push_back(get_card());
            print_cards();
            bets();
        }
        who_won();
    }

    void game::bets() {
        int must_bet = 0;
        bool state = true;
        int some_counter = 0;
        while (state) {
            int since_must_bet_increased = 0;
            for (const auto &player: players) {
                some_counter += 1;
                while (true) {
                    std::string move = player.move(balance[player]);

                    if (move == "call") {
                        balance[player] -= must_bet;
                        since_must_bet_increased++;
                        break;
                    } else if (move == "raise") {
                        std::cout << "How much would you like to bet?\n";
                        int bet = 0;
                        std::cin >> bet;
                        if (bet < must_bet) {
                            bet = must_bet;
                            since_must_bet_increased++;
                        } else {
                            some_counter = 1;
                        }
                        must_bet = bet;
                        balance[player] -= must_bet;
                        break;
                    } else if (move == "fold") {
                        players.erase(player);
                        since_must_bet_increased++;
                        break;
                    } else if (move == "check") {
                        since_must_bet_increased++;
                        break;
                    }
                    std::cout << "Incorrect input, try again\n";
                }
                if(some_counter == players.size()) {
                    state = false;
                    break;
                }

            }
        }
    }

    int game::get_card() {
        size_t index = rand() % available_cards.size();
        auto card = available_cards[index];
        available_cards.erase(available_cards.begin() + index);
        return card;
    }

    void game::print_cards() {
        for (auto num_of_card: board_cards) {
            std::cout << num2card(num_of_card) << " ";
        }
        std::cout << "\n";
    }

    void game::who_won() {
        if (players.size() == 1) {
            const auto &player = *players.begin();
            balance[player] += total_of_bets;
            std::cout << "Player " << player.name() << " have won!!!\n";
        }
    }
}