#pragma once

#include <cstdint>
#include <iosfwd>
#include <string_view>
#include <vector>

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

struct Card  {
private:
    Suit suit = Suit::SUIT_SIZE;
    Value value = Value::VALUE_SIZE;

    [[nodiscard]] std::string_view value_to_string() const;

    [[nodiscard]] std::string_view suit_to_string() const;

public:
    Card() = default;
    Card(Suit suit, Value value);
    explicit Card(int num);

    [[nodiscard]] int get_index() const;

    [[nodiscard]] Suit get_suit() const;

    [[nodiscard]] Value get_value() const;

    bool operator>=(const Card &card) const;

    bool operator==(const Card &card) const;

//    Card& operator=(const Card &card) = default;

    friend std::ostream &operator<<(std::ostream &os, const Card &card);
    static void vector_sort(std::vector<Card>& cards);
};

