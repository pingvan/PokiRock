#ifndef WIN_CHECK_H
#define WIN_CHECK_H

#include "Card.hpp"
#include <utility>
#include <vector>

namespace server {
struct Win_check {
    static bool is_straight_flush(
        const std::vector<int> &suits,
        const std::vector<int> &values
    );
    static std::pair<int, int> check(const std::vector<int> &combination);
};
}  // namespace Server

#endif  // WIN_CHECK_H
