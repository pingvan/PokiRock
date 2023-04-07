#include "Card.hpp"
#include <iostream>
#include <stdexcept>

Card::Card(int num)
    : suit(static_cast<Suit>(num % 4)),
      value(static_cast<Value>(num / 4)),
      index(num) {
    if (num > static_cast<int>(Suit::SUIT_SIZE) *
                  static_cast<int>(Value::VALUE_SIZE)) {
        throw std::runtime_error("too big card number");
    }
}

[[nodiscard]] int Card::get_index() const {
    return index;
}

std::string_view Card::value_to_string() const {
    switch (value) {
        case Value::TWO:
            return "2";
        case Value::THREE:
            return "3";
        case Value::FOUR:
            return "4";
        case Value::FIVE:
            return "5";
        case Value::SIX:
            return "6";
        case Value::SEVEN:
            return "7";
        case Value::EIGHT:
            return "8";
        case Value::NINE:
            return "9";
        case Value::TEN:
            return "10";
        case Value::JACK:
            return "Jack";
        case Value::QUEEN:
            return "Queen";
        case Value::KING:
            return "King";
        case Value::ACE:
            return "Ace";
        default:
            throw std::runtime_error("too big card number");
    }
}

std::string_view Card::suit_to_string() const {
    switch (suit) {
        case Suit::HEARTS:
            return "HEARTS";
        case Suit::DIAMONDS:
            return "DIAMONDS";
        case Suit::SPADES:
            return "SPADES";
        case Suit::CLUBS:
            return "CLUBS";
        default:
            throw std::runtime_error("too big card number");
    }
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.value_to_string() << " of " << card.suit_to_string();
    return os;
}
