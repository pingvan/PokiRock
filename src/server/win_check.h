#ifndef POKIROCK_WIN_CHECK_H
#define POKIROCK_WIN_CHECK_H

#include <utility>
#include <vector>

namespace server {
struct win_check {
    static bool is_straight_flush(
        const std::vector<int> &suits,
        const std::vector<int> &values
    );
    static std::pair<int, int> check(const std::vector<int> &combination);
};
}  // namespace server

#endif  // POKIROCK_WIN_CHECK_H
