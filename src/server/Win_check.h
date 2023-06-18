#pragma once

#include <utility>
#include <vector>

#include "Card.hpp"

namespace server {
struct Win_check {
    static bool is_straight_flush(
        const std::vector<int> &suits,
        const std::vector<int> &values
    );
    static bool is_straight_flush(const std::vector<Card> &cards);
    static std::pair<int, int> check(const std::vector<int> &combination);
};
}  // namespace server

