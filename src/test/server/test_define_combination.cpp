#include "../../server/Win_check.h"
#include "../doctest.h"

TEST_CASE("define_type_of_combination") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards, int combination_type) {
        SUBCASE(test_name) {
            // Card::vector_sort(const_cast<std::vector<Card> &>(cards));
            std::vector<int> combination(cards.size());
            for (size_t i = 0; i < cards.size(); i++) {
                combination[i] = cards[i].get_index();
            }
            CHECK((server::Win_check::check(combination).first == combination_type));
        }
    };
    test_case(
        "simple",
        std::vector{
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::HEARTS, Value::KING},
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::HEARTS, Value::JACK},
            Card{Suit::HEARTS, Value::TEN}},
        8
    ); //TODO: make combinations' types enum
}