#ifndef CARD_H
#define CARD_H

#include <cstdint>
#include <iosfwd>
#include <string_view>

struct Card {
private:
    enum class Suit : std::size_t {
        DIAMONDS = 0,
        HEARTS,
        CLUBS,
        SPADES,
        SUIT_SIZE
    };
    enum class Value : std::size_t {
        TWO = 0,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
        VALUE_SIZE
    };
    static_assert(static_cast<std::size_t>(Suit::SUIT_SIZE) == 4UL);
    static_assert(static_cast<std::size_t>(Value::VALUE_SIZE) == 13UL);
    Suit suit;
    Value value;
    int index;

    [[nodiscard]] std::string_view value_to_string() const;

    [[nodiscard]] std::string_view suit_to_string() const;

public:
    explicit Card(int num);

    [[nodiscard]] int get_index() const;

    //    bool operator<(const Card &card) const {
    //        return value < card.value;
    //    }

    friend std::ostream &operator<<(std::ostream &os, const Card &card);
};

#endif  // CARD_H
