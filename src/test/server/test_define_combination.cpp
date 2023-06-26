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
        "straight_flush",
        std::vector{
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::HEARTS, Value::KING},
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::HEARTS, Value::JACK},
            Card{Suit::HEARTS, Value::TEN}},
        8
    ); //TODO: make combinations' types enum

    test_case(
        "quad",
        std::vector{
            Card{Suit::SPADES, Value::ACE},
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::DIAMONDS, Value::ACE},
            Card{Suit::HEARTS, Value::TEN}},
        7
    );

    test_case(
        "full_house",
        std::vector{
            Card{Suit::SPADES, Value::ACE},
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::SPADES, Value::JACK},
            Card{Suit::HEARTS, Value::JACK}},
        6
    );

    test_case(
        "flush",
        std::vector{
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::HEARTS, Value::KING},
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::HEARTS, Value::JACK},
            Card{Suit::HEARTS, Value::NINE}},
        5
    );

    test_case(
        "straight",
        std::vector{
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::HEARTS, Value::FIVE},
            Card{Suit::HEARTS, Value::FOUR},
            Card{Suit::SPADES, Value::THREE},
            Card{Suit::HEARTS, Value::TWO}},
        4
    );

    test_case(
        "triple",
        std::vector{
            Card{Suit::SPADES, Value::QUEEN},
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::DIAMONDS, Value::QUEEN},
            Card{Suit::SPADES, Value::JACK},
            Card{Suit::HEARTS, Value::SEVEN}},
        3
    );
    test_case(
        "two_pair",
        std::vector{
            Card{Suit::SPADES, Value::ACE},
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::DIAMONDS, Value::QUEEN},
            Card{Suit::SPADES, Value::JACK},
            Card{Suit::HEARTS, Value::JACK}},
        2
    );
    test_case(
        "pair",
        std::vector{
            Card{Suit::SPADES, Value::QUEEN},
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::DIAMONDS, Value::TEN},
            Card{Suit::SPADES, Value::SEVEN},
            Card{Suit::HEARTS, Value::FOUR}},
        1
    );
    test_case(
        "high_card",
        std::vector{
            Card{Suit::SPADES, Value::QUEEN},
            Card{Suit::HEARTS, Value::JACK},
            Card{Suit::DIAMONDS, Value::TEN},
            Card{Suit::SPADES, Value::SEVEN},
            Card{Suit::HEARTS, Value::FOUR}},
        0
    );



}