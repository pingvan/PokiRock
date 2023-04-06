#include "Game.h"
#include "Win_check.h"

void Card::print_cards_card() {
    std::cout << ValueToString() << ' ' << SuitToString() << '\n';
}

namespace server {
int Game::next_position(int position) {
    return (position + 1) % static_cast<int>(round_players.size());
}

Game::Game(std::vector<client::Client> lobby)
    : players(std::move(lobby)),
      round_players(players),
      available_cards(52),
      total_of_bets(0),
      button(static_cast<int>(lobby.size()) - 1),
      last_player(button) {
    std::iota(available_cards.begin(), available_cards.end(), 0);
    std::cout << "Starting game with: ";
    for (const client::Client &player : players) {
        // demand to preflop
        balance[player] = 100;
        std::cout << player.name() << " ";
    }
    std::cout << "\n";
}

void Game::preflop() {
    std::cout << "Preflop\n";
    for (const auto &player : players) {
        cards_enum.emplace(
            std::piecewise_construct, std::forward_as_tuple(player),
            std::forward_as_tuple(get_enum_card(), get_enum_card())
        );
        std::string optional_move = player.optional_move();
        if (optional_move == "balance") {
            std::cout << "Your balance is: " << balance[player] << "\n";
        } else if (optional_move == "cards") {
            cards_enum.at(player).first.print_cards_card();
            cards_enum.at(player).second.print_cards_card();
        }
    }
    bets();
    flop();
}

void Game::flop() {
    current_turn = Flop;
    for (const auto &c : players) {
        data::DataBase_connector connect;
        connect.insert_games(c.name());
    }
    if (players.size() > 1) {
        std::cout << "Flop\n";
        for (int i = 0; i < 3; i++) {
            board_cards.push_back(get_enum_card());
        }
        print_cards();
        bets();
    }
    turn();
}

void Game::turn() {
    current_turn = Turn;
    if (players.size() > 1) {
        std::cout << "Turn\n";
        board_cards.push_back(get_enum_card());
        print_cards();
        bets();
    }
    river();
}

void Game::river() {
    current_turn = River;
    if (players.size() > 1) {
        std::cout << "River\n";
        board_cards.push_back(get_enum_card());
        print_cards();
        bets();
    }
    who_won();
}

void Game::bets() {
    int must_bet = 0;
    if (current_turn == Preflop) {
        must_bet = blinds.big_blind;
    }
    bool big_blind_flag = false;
    bool small_blind_flag = false;
    std::map<client::Client, int> have_beted;
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
                    const int bet_amount = must_bet - have_beted[player];
                    make_a_bet(player, bet_amount);
                    balance[player] -= must_bet - have_beted[player];
                    have_beted[player] = must_bet;
                    some_counter += 1;
                    increase_iterator(it);
                    break;
                } else if (move == "raise") {
                    std::cout << "How much would you like to bet?\n";
                    int bet = 0;
                    std::cin >> bet;
                    // must_bet += bet;
                    if (bet > balance[player]) {
                        std::cout << "A lack of money, operation denied.\n";
                    } else {
                        some_counter = 1;

                        if (bet < must_bet) {
                            bet = must_bet;
                        } else {
                            some_counter = 1;
                        }
                        must_bet = bet;
                        const int bet_amount =
                            must_bet -
                            have_beted[player];  // TODO::if balance <
                        make_a_bet(player, bet_amount);
                        have_beted[player] = must_bet;
                        increase_iterator(it);
                        break;
                    }
                } else if (move == "all-in") {
                    int bet = balance[player];
                    if (must_bet < bet) {
                        some_counter = 1;
                        must_bet = bet;
                    }
                    make_a_bet(player, bet);
                    have_betted[player] += bet;
                    increase_iterator(it);
                } else if (move == "fold") {
                    if (it - round_players.begin() <= last_player) {
                        last_player--;
                        if (last_player < 0) {
                            last_player =
                                static_cast<int>(round_players.size());
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

Card Game::get_enum_card() {
    std::random_device rand;
    std::mt19937 mt_rand(rand());
    int size = static_cast<int>(available_cards.size());
    std::uniform_int_distribution<int> range(0, size);
    auto index = range(mt_rand);
    auto card = available_cards[index];
    available_cards.erase(available_cards.begin() + index);
    return Card(card);
}

void Game::print_cards() {
    for (auto num_of_card : board_cards) {
        std::cout << num_of_card.ValueToString() << " "
                  << num_of_card.SuitToString() << " ";
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
        for (const auto &player : players) {
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
                            combination_cards.push_back(
                                cards_enum.at(player).first.get_index()
                            );
                        } else if (q == j) {
                            combination_cards.push_back(
                                cards_enum.at(player).second.get_index()
                            );
                        } else {
                            combination_cards.push_back(
                                board_cards[q - 1].get_index()
                            );
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
        data::DataBase_connector connect;
        balance[*winner] += total_of_bets;
        std::cout << "Player " << winner->name() << " have won!!!\n";
        connect.insert_win(winner->name());
        std::cout << "Winning combination is:";
        for (const auto &c : balance) {
            connect.update_balance(
                c.first.name(), (c.first.get_balance() - c.second)
            );
        }
        for (int card_num : winning_combination_cards) {
            auto c = Card(card_num);
            std::cout << " " << c.ValueToString() << ' ' << c.SuitToString();
        }
    }
    new_round();
}

void Game::new_round() {
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

void Game::make_a_bet(const client::Client &player, int bet_amount) {
    balance[player] -= bet_amount;
    total_of_bets += bet_amount;
}

}  // namespace server