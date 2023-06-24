#include "Win_probability.h"
#include "Card.hpp"
#include "Win_check.h"
namespace server {
Card Win_chance::get_enum_card() {
    std::random_device rand;
    std::mt19937 mt_rand(rand());
    std::uniform_int_distribution<std::size_t> range(0, available_cards.size()-1);
    auto index = static_cast<std::ptrdiff_t>(range(mt_rand));
    auto card = available_cards[index];
    available_cards.erase(available_cards.begin() + index);
    return Card(card);
}

std::vector<double> Win_chance::chances_for_players(const std::vector<std::pair<Card, Card>>& players, const std::vector<Card>& board_cards) {
    std::vector<double> results(players.size());
    std::map<uint32_t, std::pair<Card, Card>> players_club;
    uint32_t cnt = 0;
    for (const auto &[card1, card2] : players){
        players_club[cnt] = {card1, card2};
        cnt++;
        available_cards.erase(std::find(available_cards.begin(), available_cards.end(), card1.get_index()));
        available_cards.erase(std::find(available_cards.begin(), available_cards.end(), card2.get_index()));
    }
    for (const auto &card: board_cards){
        available_cards.erase(std::find(available_cards.begin(), available_cards.end(), card.get_index()));
    }
    std::vector<Card> board_card_simulations;
    board_card_simulations.reserve(board_cards.size());
for (Card const card : board_cards){
        board_card_simulations.emplace_back(card);
    }
    uint32_t const cards_missing_in_board_cards = 5 - board_cards.size();
    for (uint32_t i = 0; i < amount_of_repetitions; i++){
        for(uint32_t j = 0; j < cards_missing_in_board_cards; j++){
            board_card_simulations.emplace_back(get_enum_card());
        }
        results[decide_winner(players_club, board_card_simulations)]++;
    }
    for (auto &result : results){
        result /= amount_of_repetitions;
    }
    return results;
}

uint32_t Win_chance::decide_winner(std::map<uint32_t, std::pair<Card, Card>> &players, const std::vector<Card> board_cards) {
    uint32_t winner_id = 0;
    std::pair<int, int> winning_combination;
    for (const auto &[player_id, cards] : players) {
        std::pair<int, int> best_combination;
        for (int i = 0; i < 6; i++) {
            for (int j = i; j < 6; j++) {
                if (j == i) {
                    j = 0;
                }
                std::vector<int> combination_cards;
                for (int q = 1; q < 6; q++) {
                    if (q == i) {
                        combination_cards.push_back(
                            cards.first.get_index()
                        );
                    } else if (q == j) {
                        combination_cards.push_back(
                            cards.second.get_index()
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
                }
                if (j == 0){
                    j = i;
                }
            }
        }
        if (winning_combination < best_combination) {
            winning_combination = best_combination;
            winner_id = player_id;
        }
    }
    return winner_id;
}
}