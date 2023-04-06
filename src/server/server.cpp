#include "server.h"
#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include "../client/client.h"
#include "win_check.h"

namespace server {

std::string num2card(int num) {
    static constexpr std::array<const char *, 13> values_of_cards = {
        "2", "3",  "4",    "5",     "6",    "7",  "8",
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

void server::add(const client::client &client) {
    players.push(client);
}

void server::start_game() {
    std::vector<client::client> lobby;
    for (int i = 0; i < 5; i++) {
        if (!players.empty()) {
            auto player = players.front();
            players.pop();
            lobby.emplace_back(player);
        }
    }
    games.emplace_back(lobby);
    auto &our_game = games.back();
    our_game.preflop();
}

int game::next_position(int position) {
    return (position + 1) % static_cast<int>(round_players.size());
}

game::game(std::vector<client::client> lobby)
    : players(std::move(lobby)),
      round_players(players),
      total_of_bets(0),
      button(static_cast<int>(lobby.size()) - 1),
      last_player(button) {
    for (int i = 0; i < 52; i++) {
        available_cards.push_back(i);
    }
    std::cout << "Starting game with: ";
    for (const client::client &player : players) {
        balance[player] = 100;
        std::cout << player.name() << " ";
    }
    std::cout << "\n";
}

void game::preflop() {
    std::cout << "Preflop\n";
    for (const auto &player : round_players) {
        cards[player] = {get_card(), get_card()};
        std::string optional_move = player.optional_move();
        if (optional_move == "balance") {
            std::cout << "Your balance is: " << balance[player] << "\n";
        } else if (optional_move == "cards") {
            std::cout << num2card(cards[player].first) << " "
                      << num2card(cards[player].second) << "\n";
        }
    }
    bets();
    flop();
}

void game::flop() {
    current_turn = Flop;
    if (round_players.size() > 1) {
        std::cout << "Flop\n";
        for (int i = 0; i < 3; i++) {
            board_cards.push_back(get_card());
        }
        print_cards();
        bets();
    }
    turn();
}

void game::turn() {
    current_turn = Turn;
    if (round_players.size() > 1) {
        std::cout << "Turn\n";
        board_cards.push_back(get_card());
        print_cards();
        bets();
    }
    river();
}

void game::river() {
    current_turn = Which_turn::River;
    if (round_players.size() > 1) {
        std::cout << "River\n";
        board_cards.push_back(get_card());
        print_cards();
        bets();
    }
    who_won();
}

void game::bets() {
    int must_bet = 0;
    if (current_turn == Preflop) {
        must_bet = blinds.big_blind;
    }
    bool big_blind_flag = false;
    bool small_blind_flag = false;
    std::map<client::client, int> have_betted;
    bool state = true;
    int some_counter = 0;
    while (state) {
        for (auto it = round_players.begin() + next_position(last_player);;) {
            const auto &player = *it;
            if (current_turn == Which_turn::Preflop) {
                if (!small_blind_flag) {
                    make_a_bet(player, blinds.small_blind);
                    have_betted[player] = blinds.small_blind;
                    small_blind_flag = true;
                    increase_iterator(it);
                    continue;
                } else if (!big_blind_flag) {
                    make_a_bet(player, blinds.big_blind);
                    have_betted[player] = blinds.big_blind;
                    big_blind_flag = true;
                    increase_iterator(it);
                    continue;
                }
            }
            if (balance[player] == 0) {
                some_counter += 1;
                increase_iterator(it);
                if (some_counter == round_players.size()) {
                    state = false;
                    break;
                }
                if (it == round_players.begin() + next_position(last_player)) {
                    break;
                }
                continue;
            }
            while (true) {
                std::string move = player.move(balance[player]);
                if (move == "call") {
                    auto bet_amount = must_bet - have_betted[player];
                    make_a_bet(player, bet_amount);
                    have_betted[player] = must_bet;
                    some_counter += 1;
                    increase_iterator(it);
                    break;
                } else if (move == "raise") {
                    std::cout << "How much would you like to bet?\n";
                    int bet = 0;
                    std::cin >> bet;
                    if (bet > balance[player]) {
                        std::cout << "A lack of money, operation denied.\n";
                    } else {
                        if (bet < must_bet) {
                            bet = must_bet;
                        } else {
                            some_counter = 1;
                        }
                        must_bet = bet;
                        auto bet_amount = must_bet - have_betted[player];
                        make_a_bet(player, bet_amount);
                        have_betted[player] = must_bet;
                        increase_iterator(it);
                        break;
                    }
                } else if (move == "all-in") {
                    int bet = balance[player];
                    if (must_bet < bet) {
                        must_bet = bet;
                    }
                    make_a_bet(player, bet);
                    have_betted[player] += bet;
                    increase_iterator(it);
                    break;
                } else if (move == "fold") {
                    if (it - round_players.begin() <= last_player) {
                        last_player--;
                        if (last_player < 0) {
                            last_player = static_cast<int>(round_players.size());
                        }
                    }
                    it = round_players.erase(it);
                    break;
                } else if (move == "check") {
                    if (must_bet > have_betted[player]) {
                        std::cout
                            << "You can not check here, operation denied.\n";
                    } else {
                        some_counter += 1;
                        increase_iterator(it);
                        break;
                    }
                }
                std::cout << "Incorrect input, try again\n";
            }
            if (some_counter == round_players.size()) {
                state = false;
                break;
            }
            if (it == round_players.begin() + next_position(last_player)) {
                break;
            }
        }
    }
}

int game::get_card() {
    std::mt19937 mt_rand(time(nullptr));
    auto index = mt_rand() % available_cards.size();
    auto card = available_cards[index];
    available_cards.erase(available_cards.begin() + index);
    return card;
}

void game::print_cards() {
    for (auto num_of_card : board_cards) {
        std::cout << num2card(num_of_card) << " ";
    }
    std::cout << "\n";
}

void game::who_won() {
    if (players.size() == 1) {
        const auto &player = *players.begin();
        balance[player] += total_of_bets;
        std::cout << "Player " << player.name() << " have won!!!\n";
    } else {
        std::vector<const client::client *> tied_players;
        const client::client *winner = nullptr;
        std::pair<int, int> winning_combination;
        std::vector<int> winning_combination_cards;
        for (const auto &player : players) {
            std::pair<int, int> best_combination;
            std::vector<int> best_combination_cards;
            for (int i = 0; i < 6; i++) {
                for (int j = i; j < 6; j++) {
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
                    auto combination = win_check::check(combination_cards);
                    if (best_combination < combination) {
                        best_combination = combination;
                        best_combination_cards = combination_cards;
                    }
                }
            }
            if (winning_combination < best_combination) {
                winning_combination = best_combination;
                winning_combination_cards = best_combination_cards;
                tied_players.clear();
                winner = &player;
            } else if (winning_combination == best_combination) {
                if (winner != nullptr) {
                    tied_players.push_back(winner);
                }
                tied_players.push_back(&player);
                winner = nullptr;
            }
        }
        if (winner == nullptr) {
            auto prize = total_of_bets / tied_players.size();
            std::cout << "Tie between";
            for (const auto *player : tied_players) {
                balance[*player] += prize;
                std::cout << " " << player->name();
            }
            std::cout << "!\n";
        }
        balance[*winner] += total_of_bets;
        std::cout << "Player " << winner->name() << " have won!!!\n";
        std::cout << "Winning combination is:";
        for (int card_num : winning_combination_cards) {
            std::cout << " " << num2card(card_num);
        }
    }
    new_round();
}

void game::new_round() {
    current_turn = Preflop;
    button = next_position(button);
    for (auto it = players.begin(); it != players.end();) {
        if (balance[*it] == 0) {
            if (it - players.begin() <= button) {
                button--;
                if (button < 0) {
                    button = static_cast<int>(players.size());
                }
                it = players.erase(it);
            } else {
                it++;
            }
        } else {
            it++;
        }
    }
    available_cards.clear();
    for (int i = 0; i < 52; i++) {
        available_cards.push_back(i);
    }
    board_cards.clear();
    round_players = players;
    last_player = button;
    total_of_bets = 0;
    preflop();
}

void game::make_a_bet(const client::client &player, int bet_amount) {
    balance[player] -= bet_amount;
    total_of_bets += bet_amount;
}
}  // namespace server
