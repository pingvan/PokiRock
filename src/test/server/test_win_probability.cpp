#include "../../server/Win_probability.h"
#include "../doctest.h"
TEST_CASE("obvious_winner") {
    auto test_case = [](const char *test_name, const std::vector<std::pair<Card, Card>>& players,
                        const std::vector<Card>& board_cards) {
        SUBCASE(test_name) {
            server::Win_chance test;
            CHECK((test.chances_for_players(players, board_cards)[0] == 1));
        }
    };
    test_case(
        "first_wins",
        std::vector{
            std::pair<Card, Card>
                {Card{Suit::HEARTS, Value::ACE}, Card{Suit::HEARTS, Value::KING}},
            std::pair<Card, Card>
                {Card{Suit::HEARTS, Value::TWO}, Card{Suit::HEARTS, Value::THREE}}},
        std::vector{
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::HEARTS, Value::JACK},
            Card{Suit::HEARTS, Value::TEN},
            Card{Suit::HEARTS, Value::NINE},
            Card{Suit::HEARTS, Value::EIGHT}
        }

    );
}