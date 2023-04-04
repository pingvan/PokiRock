#include "../../src/server/Win_check.h"
#include "../doctest.h"

TEST_CASE("test_straight_flush") {
    std::vector<int> combination{48, 44, 40, 36, 32};
    std::vector<int> suits(5);
    std::vector<int> values(5);
    for (int i = 0; i < 5; i++) {
        suits[i] = combination[i] % 4;
        values[i] = combination[i] / 4;
    }
    CHECK(server::win_check::is_straight_flush(suits, values));
}