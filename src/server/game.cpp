#include "game.h"
#include <algorithm>
#include <array>
#include <functional>
#include <random>
#include "../client/client.h"

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

game::game(std::vector<client::client> lobby)
    : players(std::move(lobby)), total_of_bets(0) {
    for (int i = 0; i < 52; i++) {
        available_cards.push_back(i);
    }
    std::cout << "Starting game with: ";
    for (const client::client &player : players) {
        cards[player] = {get_card(), get_card()};  // demand to preflop
        balance[player] = 100;
        std::cout << player.name() << " ";
    }
    std::cout << "\n";
}

void game::preflop() {
    std::cout << "Preflop\n";
    for (const auto &player : players) {
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
    std::map<client::client, int> have_beted;
    bool state = true;
    int some_counter = 0;
    while (state) {
        for (auto it = players.begin(); it != players.end();) {
            const auto &player = *it;
            some_counter += 1;
            while (true) {
                std::string move = player.move(balance[player]);
                if (move == "call") {
                    auto bet_amount = must_bet - have_beted[player];
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
                    auto bet_amount = must_bet - have_beted[player];
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

int game::get_card() {
    std::mt19937 mt_rand(time(nullptr));  // TODO std::random_device
    auto index = mt_rand() %
                 available_cards.size();  // TODO std::uniform_int_distribution
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
        const client::client *winner = nullptr;
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
                    auto combination = rank_combination(combination_cards);
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
    }
}

void game::make_a_bet(const client::client &player, int bet_amount) {
    balance[player] -= bet_amount;
    total_of_bets += bet_amount;
}

std::pair<int, int> game::rank_combination(const std::vector<int> &combination
) {
    std::vector<int> suits(5);
    std::vector<int> values(5);
    for (int i = 0; i < 5; i++) {
        suits[i] = combination[i] % 4;
        values[i] = combination[i] / 4;
    }

    {  // straight-flush checking
        bool is_straight_flush = true;
        for (int i = 2; i < 5; i++) {
            if (suits[i - 1] != suits[i] || (values[i] != values[i - 1] - 1)) {
                is_straight_flush = false;
                break;
            }
        }
        is_straight_flush *= static_cast<int>(
            suits[0] == suits[1] && ((values[1] == values[0] - 1) ||
                                     (values[0] == 12 && values[4] == 0))
        );
        if (is_straight_flush) {
            if (values[0] == 12 && values[4] == 0) {
                return {8, values[1]};
            } else {
                return {8, values[0]};
            }
        }
    }  // straight-flush checking_end

    {  // quads checking
        bool is_quad = true;
        std::map<int, int> values_counter;
        for (int i = 0; i < 5; i++) {
            values_counter[values[0]]++;
        }
        int max_entry = 0;
        for (auto &element : values_counter) {
            if (element.second > max_entry) {
                max_entry = element.second;
            }
        }
        if (max_entry < 4) {
            is_quad = false;
        }
        if (is_quad) {
            if (values[0] == values[1]) {
                return {7, values[0] * 13 + values[4]};
            } else {
                return {7, values[0] + values[4] * 13};
            }
        }
    }  // quads checking_end

    {  // full_house checking
        bool full_house = values[0] == values[1] && values[3] == values[4] &&
                          (values[2] == values[1] || values[2] == values[3]);
        if (full_house) {
            if (values[2] == values[0]) {
                return {6, values[0] * 13 + values[4]};
            } else {
                return {6, values[0] + values[4] * 13};
            }
        }
    }  // full_house checking_end
    {  // flush checking
        bool is_flush = true;
        std::map<int, int> values_counter;
        for (int i = 1; i < 5; i++) {
            if (suits[i] != suits[0]) {
                is_flush = false;
                break;
            }
        }
        if (is_flush) {
            int secondary_comparator = 0;
            int multiplier = 1;
            for (int i = 4; i >= 0; i--) {
                secondary_comparator += values[i] * multiplier;
                multiplier *= 13;
            }
            return {5, secondary_comparator};
        }
    }  // flush checking_end
    {  // straight checking
        bool is_straight = true;
        std::map<int, int> values_counter;
        for (int i = 2; i < 5; i++) {
            if (values[i] != values[i - 1] - 1) {
                is_straight = false;
                break;
            }
        }
        is_straight *= static_cast<int>((
            (values[1] == values[0] - 1) || (values[0] == 12 && values[4] == 0)
        ));
        if (is_straight) {
            if (values[0] == 12 && values[4] == 0) {
                return {4, values[1]};
            } else {
                return {4, values[0]};
            }
        }
    }  // straight checking_end
    {  // triple checking
        bool is_triple = (values[0] == values[1] && values[1] == values[2]) ||
                         (values[1] == values[2] && values[2] == values[3]) ||
                         (values[2] == values[3] && values[3] == values[4]);
        if (is_triple) {
            int secondary_comparator = 0;
            if (values[0] == values[1] && values[2] == values[1]) {
                secondary_comparator =
                    13 * 13 * values[0] + 13 * values[3] + values[4];
            } else if (values[1] == values[2] && values[2] == values[3]) {
                secondary_comparator =
                    13 * 13 * values[3] + 13 * values[0] + values[4];
            } else {
                secondary_comparator =
                    13 * 13 * values[3] + 13 * values[0] + values[1];
            }
            return {3, secondary_comparator};
        }

    }  // triple checking_end
    {  // two_pair checking
        bool is_two_pair = (values[0] == values[1] && values[2] == values[3]) ||
                           (values[1] == values[2] && values[3] == values[4]) ||
                           (values[0] == values[1] && values[3] == values[4]);
        if (is_two_pair) {
            int secondary_comparator = 0;
            if (values[0] == values[1] && values[2] == values[3]) {
                secondary_comparator =
                    13 * 13 * values[0] + 13 * values[3] + values[4];
            } else if (values[1] == values[2] && values[3] == values[4]) {
                secondary_comparator =
                    13 * 13 * values[1] + 13 * values[3] + values[0];
            } else {
                secondary_comparator =
                    13 * 13 * values[1] + 13 * values[3] + values[2];
            }
            return {2, secondary_comparator};
        }
    }  // two_pair checking_end
    {  // pair checking
        bool is_pair = false;
        int pair_id = 0;
        for (int i = 1; i < 5; i++) {
            if (values[i] == values[i - 1]) {
                is_pair = true;
                pair_id = i - 1;
                break;
            }
        }
        if (is_pair) {
            int secondary_comparator = 0;
            int multiplier = 1;
            for (int i = 4; i >= 0; i--) {
                if (i != pair_id && i != pair_id + 1) {
                    secondary_comparator += values[i] * multiplier;
                    multiplier *= 13;
                }
            }
            secondary_comparator += values[pair_id] * multiplier;
            return {1, secondary_comparator};
        }
    }  // pair checking_end
    {  // high_card
        int secondary_comparator = 0;
        int multiplier = 1;
        for (int i = 4; i >= 0; i--) {
            secondary_comparator += values[i] * multiplier;
            multiplier *= 13;
        }
        return {0, secondary_comparator};
    }  // high_card end
}
}  // namespace server