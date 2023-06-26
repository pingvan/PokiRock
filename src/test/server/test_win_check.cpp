#include <algorithm>
#include "../../server/Win_check.h"
#include "../doctest.h"

TEST_CASE("test_straight_flush") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            // Card::vector_sort(const_cast<std::vector<Card> &>(cards));
            CHECK(server::Win_check::is_straight_flush(cards));
        }
    };
    test_case(
        "simple",
        std::vector{
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::HEARTS, Value::KING},
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::HEARTS, Value::JACK},
            Card{Suit::HEARTS, Value::TEN}}
    );

    test_case(
        "with ace",
        std::vector{
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::HEARTS, Value::FIVE},
            Card{Suit::HEARTS, Value::FOUR},
            Card{Suit::HEARTS, Value::THREE},
            Card{Suit::HEARTS, Value::TWO},
        }

    );
}

TEST_CASE("test_quad") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            // Card::vector_sort(const_cast<std::vector<Card> &>(cards));
            CHECK(server::Win_check::is_quad(cards));
        }
    };
    test_case(
        "ace_quad",
        std::vector{
            Card{Suit::SPADES, Value::ACE},
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::DIAMONDS, Value::ACE},
            Card{Suit::HEARTS, Value::TWO}}
    );
    test_case(
        "jack_quad",
        std::vector{
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::SPADES, Value::JACK},
            Card{Suit::CLUBS, Value::JACK},
            Card{Suit::HEARTS, Value::JACK},
            Card{Suit::DIAMONDS, Value::JACK}}
    );
}

TEST_CASE("test_full_house") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            // Card::vector_sort(const_cast<std::vector<Card> &>(cards));
            CHECK(server::Win_check::is_full_house(cards));
        }
    };
    test_case(
        "triple_ace_pair_king",
        std::vector{
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::DIAMONDS, Value::ACE},
            Card{Suit::SPADES, Value::KING},
            Card{Suit::HEARTS, Value::KING}}
    );
    test_case(
        "triple_ten_pair_queen",
        std::vector{
            Card{Suit::CLUBS, Value::QUEEN},
            Card{Suit::HEARTS, Value::QUEEN},
            Card{Suit::SPADES, Value::TEN},
            Card{Suit::HEARTS, Value::TEN},
            Card{Suit::DIAMONDS, Value::TEN}

        }
    );
}

TEST_CASE("test_flush") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            // Card::vector_sort(const_cast<std::vector<Card> &>(cards));
            CHECK(server::Win_check::is_flush(cards));
        }
    };
    test_case(
        "diamonds_flush",
        std::vector{
            Card{Suit::DIAMONDS, Value::KING},
            Card{Suit::DIAMONDS, Value::TEN},
            Card{Suit::DIAMONDS, Value::SEVEN},
            Card{Suit::DIAMONDS, Value::FIVE},
            Card{Suit::DIAMONDS, Value::TWO}}
    );
    test_case(
        "clubs_flush",
        std::vector{
            Card{Suit::CLUBS, Value::KING},
            Card{Suit::CLUBS, Value::QUEEN},
            Card{Suit::CLUBS, Value::NINE},
            Card{Suit::CLUBS, Value::SIX},
            Card{Suit::CLUBS, Value::FOUR},
        }
    );
}

TEST_CASE("test_straight") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            // Card::vector_sort(const_cast<std::vector<Card> &>(cards));
            CHECK(server::Win_check::is_straight(cards));
        }
    };
    test_case(
        "simple_straight",
        std::vector{
            Card{Suit::CLUBS, Value::KING},
            Card{Suit::DIAMONDS, Value::QUEEN},
            Card{Suit::CLUBS, Value::JACK},
            Card{Suit::HEARTS, Value::TEN},
            Card{Suit::CLUBS, Value::NINE}
        }
    );
    test_case(
        "ace_straight",
        std::vector{
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::HEARTS, Value::FIVE},
            Card{Suit::SPADES, Value::FOUR},
            Card{Suit::HEARTS, Value::THREE},
            Card{Suit::DIAMONDS, Value::TWO}
        }
    );
}
TEST_CASE("test_triple") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            // Card::vector_sort(const_cast<std::vector<Card> &>(cards));
            CHECK(server::Win_check::is_triple(cards));
        }
    };
    test_case(
        "high_triple",
        std::vector{
            Card{Suit::CLUBS, Value::KING},
            Card{Suit::HEARTS, Value::KING},
            Card{Suit::DIAMONDS, Value::KING},
            Card{Suit::HEARTS, Value::TEN},
            Card{Suit::CLUBS, Value::NINE}
        }
    );
    test_case(
        "mid_triple",
        std::vector{
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::SPADES, Value::FIVE},
            Card{Suit::CLUBS, Value::FIVE},
            Card{Suit::HEARTS, Value::FIVE},
            Card{Suit::DIAMONDS, Value::TWO}
        }
    );
    test_case(
        "low_triple",
        std::vector{
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::SPADES, Value::KING},
            Card{Suit::CLUBS, Value::FIVE},
            Card{Suit::HEARTS, Value::FIVE},
            Card{Suit::DIAMONDS, Value::FIVE}
        }
    );
}
TEST_CASE("two_pair") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            // Card::vector_sort(const_cast<std::vector<Card> &>(cards));
            CHECK(server::Win_check::is_two_pair(cards));
        }
    };
    test_case(
        "aces_&_kings",
        std::vector{
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::DIAMONDS, Value::ACE},
            Card{Suit::CLUBS, Value::KING},
            Card{Suit::HEARTS, Value::KING},
            Card{Suit::CLUBS, Value::NINE}
        }
    );
    test_case(
        "aces_&_twos",
        std::vector{
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::SPADES, Value::FOUR},
            Card{Suit::HEARTS, Value::TWO},
            Card{Suit::DIAMONDS, Value::TWO}
        }
    );
}
TEST_CASE("test_pair") {
    auto test_case = [](const char *test_name, const std::vector<Card> &cards) {
        SUBCASE(test_name) {
            CHECK(server::Win_check::is_pair(cards));
        }
    };
    test_case(
        "ace_pair",
        std::vector{
            Card{Suit::CLUBS, Value::ACE},
            Card{Suit::HEARTS, Value::ACE},
            Card{Suit::SPADES, Value::FOUR},
            Card{Suit::HEARTS, Value::THREE},
            Card{Suit::DIAMONDS, Value::TWO}
        }
    );
}
