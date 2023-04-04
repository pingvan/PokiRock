#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include <chrono>
#include <numeric>
#include "Game.h"
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

    Game::Game(std::vector<client::Client> lobby)
            : players(std::move(lobby)), total_of_bets(0), available_cards(52) {
        std::iota(available_cards.begin(), available_cards.end(), 0);
        std::cout << "Starting game with: ";
        for (const client::Client &player: players) {
            cards_enum.emplace(std::piecewise_construct, std::forward_as_tuple(player),
                               std::forward_as_tuple(get_enum_card(), get_enum_card())); //demand to preflop
            balance[player] = 100;
            std::cout << player.name() << " ";
        }
        std::cout << "\n";
    }

    void Game::preflop() {
        std::cout << "Preflop\n";
        for (const auto &player: players) {
            std::string optional_move = player.optional_move();
            if (optional_move == "balance") {
                std::cout << "Your balance is: " << balance[player] << "\n";
            } else if (optional_move == "cards") {
                std::cout << num2card(cards[player].first) << " "
                          << num2card(cards[player].second) << "\n";
            }
        }
        bets();
    }

    void Game::flop() {
        if (players.size() > 1) {
            std::cout << "Flop\n";
            for (int i = 0; i < 3; i++) {
                board_cards.push_back(get_card());
            }
            print_cards();
            bets();
        }
    }

    void Game::turn() {
        if (players.size() > 1) {
            std::cout << "Turn\n";
            board_cards.push_back(get_card());
            print_cards();
            bets();
        }
    }

    void Game::river() {
        if (players.size() > 1) {
            std::cout << "River\n";
            board_cards.push_back(get_card());
            print_cards();
            bets();
        }
        who_won();
    }

    void Game::bets() {
        int must_bet = 0;
        std::map<client::Client, int> have_beted;
        bool state = true;
        int some_counter = 0;
        while (state) {
            for (auto it = players.begin(); it != players.end();) {
                const auto &player = *it;
                some_counter += 1;
                while (true) {
                    std::string move = player.move(balance[player]);
                    if (move == "call") {
                        int const bet_amount = must_bet - have_beted[player];
                        make_a_bet(player, bet_amount);
                        balance[player] -= must_bet - have_beted[player];
                        have_beted[player] = must_bet;
                        it++;
                        break;
                    } else if (move == "raise") {
                        std::cout << "How much would you like to bet?\n";
                        int bet = 0;
                        std::cin >> bet;
                        // must_bet += bet;
                        if (bet < must_bet) {
                            bet = must_bet;
                        } else {
                            some_counter = 1;
                        }
                        must_bet = bet;
                        int const bet_amount = must_bet - have_beted[player]; //TODO::if balance <
                        make_a_bet(player, bet_amount);
                        have_beted[player] = must_bet;
                        it++;
                        break;
                    } else if (move == "fold") {
                        it = players.erase(it);
                        break;
                    } else if (move == "check") {
                        it++;
                        break;
                    }
                    std::cout << "Incorrect input, try again\n";
                }
                if (some_counter == players.size()) {
                    state = false;
                    break;
                }
            }
        }
    }

    Card Game::get_enum_card() {
        std::mt19937 mt_rand(std::chrono::steady_clock::now().time_since_epoch().count());
//        std::random_device rand; //of course we can use this
        std::uniform_int_distribution<int> range(0, static_cast<int>(available_cards.size()));
        auto index = range(mt_rand);
        auto card = available_cards[index];
        available_cards.erase(available_cards.begin() + index);
        return Card(card);
    }

    void Game::print_cards() {
        for (auto num_of_card: board_cards) {
            std::cout << num2card(num_of_card) << " ";
        }
        std::cout << "\n";
    }

    void Game::who_won() {
        if (players.size() == 1) {
            const auto &player = *players.begin();
            balance[player] += total_of_bets;
            std::cout << "Player " << player.name() << " have won!!!\n";
        } else {
            const client::Client *winner = nullptr;
            std::pair<int, int> winning_combination;
            std::vector<int> winning_combination_cards;
            for (const auto &player: players) {
                std::pair<int, int> best_combination;
                std::vector<int> best_combination_cards;
                for (int i = 0; i < 6; i++) {
                    for (int j = i; j < 6; j++) {
                        if (j == i) {
                            j = 0;
                        }
                        std::vector<int> combination_cards;
                        for (int q = 1; q < 6; q++) {
                            if (q == i) {
                                combination_cards.push_back(cards[player].first);
                            } else if (q == j) {
                                combination_cards.push_back(cards[player].second);
                            } else {
                                combination_cards.push_back(board_cards[q - 1]);
                            }
                        }
                        std::sort(
                                combination_cards.begin(), combination_cards.end(),
                                std::greater<>()
                        );
                        auto combination = Win_check::check(combination_cards);
                        if (best_combination < combination) {
                            best_combination = combination;
                            best_combination_cards = combination_cards;
                        }
                    }
                }
                if (winning_combination < best_combination) {
                    winning_combination = best_combination;
                    winning_combination_cards = best_combination_cards;
                    winner = &player;
                }
            }
            balance[*winner] += total_of_bets;
            std::cout << "Player " << winner->name() << " have won!!!\n";
            std::cout << "Winning combination is:";
            for (int card_num: winning_combination_cards) {
                std::cout << " " << num2card(card_num);
            }
        }
    }

    void Game::make_a_bet(const client::Client &player, int bet_amount) {
        balance[player] -= bet_amount;
        total_of_bets += bet_amount;
    }

}  // namespace server