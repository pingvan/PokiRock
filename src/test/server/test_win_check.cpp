#include "../../server/Win_check.h"
#include "../doctest.h"

TEST_CASE("test_straight_flush") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            CHECK(server::Win_check::is_straight_flush(cards));
        }
    };
    test_case(
        "simple",
        std::vector{
            Card{Suit::HEARTS, Value::TEN}, Card{Suit::HEARTS, Value::JACK},
            Card{Suit::HEARTS, Value::QUEEN}, Card{Suit::HEARTS, Value::KING},
            Card{Suit::HEARTS, Value::ACE}}
    );

    test_case(
        "with ace",
        std::vector{
            Card{Suit::HEARTS, Value::TWO}, Card{Suit::HEARTS, Value::THREE},
            Card{Suit::HEARTS, Value::FOUR}, Card{Suit::HEARTS, Value::FIVE},
            Card{Suit::HEARTS, Value::ACE}}
    );
    /*std::vector<int> combination{48, 44, 40, 36, 32};
    std::vector<int> suits(5);
    std::vector<int> values(5);
    for (int i = 0; i < 5; i++) {
        suits[i] = combination[i] % 4;
        values[i] = combination[i] / 4;
    }
    CHECK(server::Win_check::is_straight_flush(cards));*/
}
