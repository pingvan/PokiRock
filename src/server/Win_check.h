#pragma once

#include <utility>
#include <vector>

#include "Card.hpp"

namespace server {
struct Win_check {
//    static bool is_straight_flush(
//        const std::vector<int> &suits,
//        const std::vector<int> &values
//    );
    static bool is_straight_flush(const std::vector<Card> &cards);
    static bool is_quad(const std::vector<Card> &cards);
    static bool is_full_house(const std::vector<Card> &cards);
    static bool is_flush(const std::vector<Card> &cards);
    static bool is_straight(const std::vector<Card> &cards);
    static bool is_triple(const std::vector<Card> &cards);
    static bool is_two_pair(const std::vector<Card> &cards);
    static bool is_pair(const std::vector<Card> &cards);
    static int pair_id(const std::vector<Card> &cards);
    static std::pair<int, int> check(const std::vector<int> &combination);
};
}  // namespace server

