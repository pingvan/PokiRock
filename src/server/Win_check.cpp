#include "Win_check.h"
#include <map>

namespace server {
// bool Win_check::is_straight_flush(
//     const std::vector<int> &suits,
//     const std::vector<int> &values
//) {
//     bool result = true;
//     for (int i = 2; i < 5; i++) {
//         if (suits[i - 1] != suits[i] || (values[i] != values[i - 1] - 1)) {
//             result = false;
//             break;
//         }
//     }
//     result *= static_cast<int>(
//         suits[0] == suits[1] &&
//         ((values[1] == values[0] - 1) || (values[0] == 12 && values[4] == 0))
//     );
//     return result;
// }

bool Win_check::is_straight_flush(const std::vector<Card> &cards) {
    bool result = true;
    for (std::size_t i = 2; i < cards.size(); i++) {
        result &= cards[i - 1].get_suit() == cards[i].get_suit() &&
                  static_cast<int>(cards[i].get_value()) ==
                      static_cast<int>(cards[i - 1].get_value()) - 1;
    }
    result &= cards[0].get_suit() == cards[1].get_suit() &&
              (static_cast<int>(cards[1].get_value()) ==
                   static_cast<int>(cards[0].get_value()) - 1 ||
               (cards[0].get_value() == Value::ACE &&
                cards[4].get_value() == Value::TWO));
    return result;
}

bool Win_check::is_quad(const std::vector<Card> &cards) {
    bool result = true;
    std::map<int, int> values_counter;
    for (int i = 0; i < 5; i++) {
        values_counter[static_cast<int>(cards[i].get_value())]++;
    }
    int max_entry = 0;
    for (auto &element : values_counter) {
        if (element.second > max_entry) {
            max_entry = element.second;
        }
    }
    if (max_entry < 4) {
        result = false;
    }
    return result;
}

bool Win_check::is_full_house(const std::vector<Card> &cards) {
    return cards[0].get_value() == cards[1].get_value() && cards[3].get_value() == cards[4].get_value() &&
           (cards[2].get_value() == cards[1].get_value() || cards[2].get_value() == cards[3].get_value());
}

bool Win_check::is_flush(const std::vector<Card> &cards) {
    bool result = true;
    for (int i = 1; i < 5; i++) {
        if (cards[i].get_suit() != cards[0].get_suit()) {
            result = false;
            break;
        }
    }
    return result;
}

bool Win_check::is_straight(const std::vector<Card> &cards) {
    bool result = true;
    for (int i = 2; i < 5; i++) {
        if (static_cast<int>(cards[i].get_value()) != static_cast<int>(cards[i - 1].get_value()) - 1) {
            result = false;
            break;
        }
    }
    result = result && static_cast<bool>((
                           (static_cast<int>(cards[1].get_value()) == static_cast<int>(cards[0].get_value()) - 1) ||
                           (static_cast<int>(cards[0].get_value()) == 12 && static_cast<int>(cards[4].get_value()) == 0)
                       ));
    return result;
}

bool Win_check::is_triple(const std::vector<Card> &cards) {
    return (cards[0].get_value() == cards[1].get_value() &&
            cards[1].get_value() == cards[2].get_value()) ||
           (cards[1].get_value() == cards[2].get_value() &&
            cards[2].get_value() == cards[3].get_value()) ||
           (cards[2].get_value() == cards[3].get_value() &&
            cards[3].get_value() == cards[4].get_value());
}

bool Win_check::is_two_pair(const std::vector<Card> &cards) {
    return (cards[0].get_value() == cards[1].get_value() &&
            cards[2].get_value() == cards[3].get_value()) ||
           (cards[1].get_value() == cards[2].get_value() &&
            cards[3].get_value() == cards[4].get_value()) ||
           (cards[0].get_value() == cards[1].get_value() &&
            cards[3].get_value() == cards[4].get_value());
}

bool Win_check::is_pair(const std::vector<Card> &cards) {
    bool result = false;
    for (int i = 1; i < 5; i++) {
        if (cards[i].get_value() == cards[i - 1].get_value()) {
            result = true;
            break;
        }
    }
    return result;
}

int Win_check::pair_id(const std::vector<Card> &cards) {
    int result = 0;
    for (int i = 1; i < 5; i++) {
        if (cards[i].get_value() == cards[i - 1].get_value()) {
            result = i - 1;
            break;
        }
    }
    return result;
}

std::pair<int, int> Win_check::check(const std::vector<int> &combination) {
    std::vector<int> suits(5);
    std::vector<int> values(5);
    std::vector<Card> cards(5);
    for (int i = 0; i < 5; i++) {
        cards[i] = Card(combination[i]);
        suits[i] = combination[i] % 4;
        values[i] = combination[i] / 4;
    }

    if (is_straight_flush(cards)) {
        if (values[0] == 12 && values[4] == 0) {
            return {8, values[1]};
        } else {
            return {8, values[0]};
        }
    }

    if (is_quad(cards)) {
        if (values[0] == values[1]) {
            return {7, values[0] * 13 + values[4]};
        } else {
            return {7, values[0] + values[4] * 13};
        }
    }

    if (is_full_house(cards)) {
        if (values[2] == values[0]) {
            return {6, values[0] * 13 + values[4]};
        } else {
            return {6, values[0] + values[4] * 13};
        }
    }

    if (is_flush(cards)) {
        int secondary_comparator = 0;
        int multiplier = 1;
        for (int i = 4; i >= 0; i--) {
            secondary_comparator += values[i] * multiplier;
            multiplier *= 13;
        }
        return {5, secondary_comparator};
    }

    if (is_straight(cards)) {
        if (values[0] == 12 && values[4] == 0) {
            return {4, values[1]};
        } else {
            return {4, values[0]};
        }
    }

    if (is_triple(cards)) {
        int secondary_comparator = 0;
        if (values[0] == values[1] && values[2] == values[1]) {
            secondary_comparator =
                13 * 13 * values[0] + 13 * values[3] + values[4];
        } else if (values[1] == values[2] && values[2] == values[3]) {
            secondary_comparator =
                13 * 13 * values[3] + 13 * values[0] + values[4];
        } else {
            secondary_comparator =
                13 * 13 * values[3] + 13 * values[0] + values[1];
        }
        return {3, secondary_comparator};
    }

    if (is_two_pair(cards)) {
        int secondary_comparator = 0;
        if (values[0] == values[1] && values[2] == values[3]) {
            secondary_comparator =
                13 * 13 * values[0] + 13 * values[3] + values[4];
        } else if (values[1] == values[2] && values[3] == values[4]) {
            secondary_comparator =
                13 * 13 * values[1] + 13 * values[3] + values[0];
        } else {
            secondary_comparator =
                13 * 13 * values[1] + 13 * values[3] + values[2];
        }
        return {2, secondary_comparator};
    }

    {  // pair checking

        if (is_pair(cards)) {
            const int id = pair_id(cards);
            int secondary_comparator = 0;
            int multiplier = 1;
            for (int i = 4; i >= 0; i--) {
                if (i != id && i != id + 1) {
                    secondary_comparator += values[i] * multiplier;
                    multiplier *= 13;
                }
            }
            secondary_comparator += values[id] * multiplier;
            return {1, secondary_comparator};
        }
    }  // pair checking_end
    {  // high_card
        int secondary_comparator = 0;
        int multiplier = 1;
        for (int i = 4; i >= 0; i--) {
            secondary_comparator += values[i] * multiplier;
            multiplier *= 13;
        }
        return {0, secondary_comparator};
    }  // high_card end
}

}  // namespace server