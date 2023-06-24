#pragma once

#include <utility>
#include <map>
#include <algorithm>
#include <vector>
#include <numeric>
#include <random>
#include "Card.hpp"
namespace server {
struct Win_chance {
    Win_chance(): available_cards(52){
        std::iota(available_cards.begin(), available_cards.end(), 0);
    }
private:
    const uint32_t amount_of_repetitions = 10000;
    std::vector<int> available_cards;
public:
     std::vector<double> chances_for_players(
        const std::vector<std::pair<Card, Card>>& players,
        const std::vector<Card>& board_cards
    );
     static uint32_t decide_winner(
         std::map<uint32_t, std::pair<Card, Card>> & players,
         std::vector<Card> board_cards);
     Card get_enum_card();
};
}  // namespace server