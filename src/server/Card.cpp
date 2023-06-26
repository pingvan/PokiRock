#include "Card.hpp"
#include <iostream>
#include <stdexcept>

Card::Card(Suit suit, Value value) : suit(suit), value(value) {
    if (get_index() > static_cast<int>(Suit::SUIT_SIZE) *
                          static_cast<int>(Value::VALUE_SIZE)) {
        throw std::runtime_error("too big card number");
    }
    if (suit == Suit::SUIT_SIZE || value == Value::VALUE_SIZE) {
        throw std::runtime_error("incorrect card initialization");
    }
}

Card::Card(int num)
    : suit(static_cast<Suit>(num % 4)), value(static_cast<Value>(num / 4)) {
    if (get_index() > static_cast<int>(Suit::SUIT_SIZE) *
                          static_cast<int>(Value::VALUE_SIZE)) {
        throw std::runtime_error("too big card number");
    }
    if (suit == Suit::SUIT_SIZE || value == Value::VALUE_SIZE) {
        throw std::runtime_error("incorrect card initialization");
    }
}

int Card::get_index() const {
    return static_cast<int>(value) * static_cast<int>(Suit::SUIT_SIZE) +
           static_cast<int>(suit);
}

Suit Card::get_suit() const {
    return suit;
}

Value Card::get_value() const {
    return value;
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

bool Card::operator>=(const Card &card) const {
    return get_index() >= card.get_index();
}

std::ostream &operator<<(std::ostream &os, const Card &card) {
    os << card.value_to_string() << "_of_" << card.suit_to_string();
    return os;
}

void Card::vector_sort(std::vector<Card> &cards) {
    return void(cards);
    //TODO
}

bool Card::operator==(const Card &card) const {
    return (value == card.value) && (suit == card.suit);
}
