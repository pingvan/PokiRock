#include "../../server/Card.hpp"
#include "../doctest.h"
#include <sstream>

TEST_CASE("test_card") {
    std::stringstream ss;
    auto test_case = [&ss](int num, const std::string &value, const std::string &suit) {
        SUBCASE(std::to_string(num).c_str()) {
            const Card card(num);
            ss << card;
            CHECK_EQ(ss.str(), value + "_of_" + suit);
            CHECK_EQ(card.get_index(), num);
        }
    };
    test_case(0, "2", "DIAMONDS");
    test_case(1, "2", "HEARTS");
    test_case(2, "2", "CLUBS");
    test_case(3, "2", "SPADES");
    test_case(4, "3", "DIAMONDS");
    test_case(8, "4", "DIAMONDS");
    test_case(12, "5", "DIAMONDS");
    test_case(16, "6", "DIAMONDS");
    test_case(20, "7", "DIAMONDS");
    test_case(24, "8", "DIAMONDS");
    test_case(28, "9", "DIAMONDS");
    test_case(32, "10", "DIAMONDS");
    test_case(36, "Jack", "DIAMONDS");
    test_case(40, "Queen", "DIAMONDS");
    test_case(44, "King", "DIAMONDS");
    test_case(48, "Ace", "DIAMONDS");
    test_case(49, "Ace", "HEARTS");
    test_case(50, "Ace", "CLUBS");
    test_case(51, "Ace", "SPADES");
}
