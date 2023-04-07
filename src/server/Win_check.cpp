#include "Win_check.h"

namespace server {
bool Win_check::is_straight_flush(
    const std::vector<int> &suits,
    const std::vector<int> &values
) {
    bool result = true;
    for (int i = 2; i < 5; i++) {
        if (suits[i - 1] != suits[i] || (values[i] != values[i - 1] - 1)) {
            result = false;
            break;
        }
    }
    result *= static_cast<int>(
        suits[0] == suits[1] &&
        ((values[1] == values[0] - 1) || (values[0] == 12 && values[4] == 0))
    );
    return result;
}

std::pair<int, int> Win_check::check(const std::vector<int> &combination) {
    std::vector<int> suits(5);
    std::vector<int> values(5);
    for (int i = 0; i < 5; i++) {
        suits[i] = combination[i] % 4;
        values[i] = combination[i] / 4;
    }

    if (is_straight_flush(suits, values)) {
        if (values[0] == 12 && values[4] == 0) {
            return {8, values[1]};
        } else {
            return {8, values[0]};
        }
    }

    {  // quads checking
        bool is_quad = true;
        std::unordered_map<int, int> values_counter;
        for (int i = 0; i < 5; i++) {
            values_counter[values[i]]++;
        }
        int max_entry = 0;
        for (auto &element : values_counter) {
            if (element.second > max_entry) {
                max_entry = element.second;
            }
        }
        if (max_entry < 4) {
            is_quad = false;
        }
        if (is_quad) {
            if (values[0] == values[1]) {
                return {7, values[0] * 13 + values[4]};
            } else {
                return {7, values[0] + values[4] * 13};
            }
        }
    }  // quads checking_end

    {  // full_house checking
        bool full_house = values[0] == values[1] && values[3] == values[4] &&
                          (values[2] == values[1] || values[2] == values[3]);
        if (full_house) {
            if (values[2] == values[0]) {
                return {6, values[0] * 13 + values[4]};
            } else {
                return {6, values[0] + values[4] * 13};
            }
        }
    }  // full_house checking_end
    {  // flush checking
        bool is_flush = true;
        std::unordered_map<int, int> values_counter;
        for (int i = 1; i < 5; i++) {
            if (suits[i] != suits[0]) {
                is_flush = false;
                break;
            }
        }
        if (is_flush) {
            int secondary_comparator = 0;
            int multiplier = 1;
            for (int i = 4; i >= 0; i--) {
                secondary_comparator += values[i] * multiplier;
                multiplier *= 13;
            }
            return {5, secondary_comparator};
        }
    }  // flush checking_end
    {  // straight checking
        bool is_straight = true;
        std::unordered_map<int, int> values_counter;
        for (int i = 2; i < 5; i++) {
            if (values[i] != values[i - 1] - 1) {
                is_straight = false;
                break;
            }
        }
        is_straight *= static_cast<int>((
            (values[1] == values[0] - 1) || (values[0] == 12 && values[4] == 0)
        ));
        if (is_straight) {
            if (values[0] == 12 && values[4] == 0) {
                return {4, values[1]};
            } else {
                return {4, values[0]};
            }
        }
    }  // straight checking_end
    {  // triple checking
        bool is_triple = (values[0] == values[1] && values[1] == values[2]) ||
                         (values[1] == values[2] && values[2] == values[3]) ||
                         (values[2] == values[3] && values[3] == values[4]);
        if (is_triple) {
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

    }  // triple checking_end
    {  // two_pair checking
        bool is_two_pair = (values[0] == values[1] && values[2] == values[3]) ||
                           (values[1] == values[2] && values[3] == values[4]) ||
                           (values[0] == values[1] && values[3] == values[4]);
        if (is_two_pair) {
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
    }  // two_pair checking_end
    {  // pair checking
        bool is_pair = false;
        int pair_id = 0;
        for (int i = 1; i < 5; i++) {
            if (values[i] == values[i - 1]) {
                is_pair = true;
                pair_id = i - 1;
                break;
            }
        }
        if (is_pair) {
            int secondary_comparator = 0;
            int multiplier = 1;
            for (int i = 4; i >= 0; i--) {
                if (i != pair_id && i != pair_id + 1) {
                    secondary_comparator += values[i] * multiplier;
                    multiplier *= 13;
                }
            }
            secondary_comparator += values[pair_id] * multiplier;
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
}  // namespace Server