#ifndef GAME_H
#define GAME_H

#include "../client/Client.h"
#include "../rename_later.h"
#include "DataBase_connector.h"

namespace client {
struct Client;
}

enum Which_turn { Preflop, Flop, Turn, River };

struct Blinds {
    int big_blind = 10;
    int small_blind = 5;
};

struct Card {
private:
    enum class Value {
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
        Ace
    };
    enum class Suit { DIAMONDS, HEARTS, CLUBS, SPADES };
    Suit suit;
    Value value;
    int index;

public:
    explicit Card(int num) : index(num) {
        static const std::vector<Value> values_of_cards = {
            Value::Two,   Value::Three, Value::Four, Value::Five, Value::Six,
            Value::Seven, Value::Eight, Value::Nine, Value::Ten,  Value::Jack,
            Value::Queen, Value::King,  Value::Ace};
        static const std::vector<Suit> suits_of_cards = {
            Suit::HEARTS, Suit::DIAMONDS, Suit::SPADES, Suit::CLUBS};
        auto num_of_value = num / 4;
        value = values_of_cards[num_of_value];
        suit = suits_of_cards[num % 4];
    }

    int get_index() const {
        return index;
    }

    std::string ValueToString() noexcept {
        auto e = this->value;
        switch (e) {
            case Value::Two:
                return "Two";
            case Value::Three:
                return "Three";
            case Value::Four:
                return "Four";
            case Value::Five:
                return "Five";
            case Value::Six:
                return "Six";
            case Value::Seven:
                return "Seven";
            case Value::Eight:
                return "Eight";
            case Value::Nine:
                return "Nine";
            case Value::Ten:
                return "Ten";
            case Value::Jack:
                return "Jack";
            case Value::Queen:
                return "Queen";
            case Value::King:
                return "King";
            case Value::Ace:
                return "Ace";
        }
    }

    std::string SuitToString() noexcept {
        auto e = this->suit;
        switch (e) {
            case Suit::HEARTS:
                return "of HEARTS";
            case Suit::DIAMONDS:
                return "of DIAMONDS";
            case Suit::SPADES:
                return "of SPADES";
            case Suit::CLUBS:
                return "of CLUBS";
        }
    }

    bool operator<(const Card &card) const {
        return value < card.value;
    }

    void print_cards_card();
};

namespace server {
struct Game {
private:
    Which_turn current_turn = Which_turn::Preflop;
    std::vector<client::Client> players;
    std::vector<client::client> round_players;
    int button;
    int last_player;
    Blinds blinds;
    std::map<client::Client, std::pair<Card, Card>> cards_enum;
    std::map<client::Client, int> balance;
    std::vector<int> available_cards;
    std::vector<Card> board_cards;
    int total_of_bets;

public:
    explicit Game(std::vector<client::Client> lobby);
    void bets();
    int next_position(int position);
    void preflop();
    void flop();
    void make_a_bet(const client::Client &player, int bet_amount);
    void turn();
    void river();
    Card get_enum_card();
    void print_cards();
    void who_won();
    void new_round();

    template <typename T>
    void increase_iterator(T &iterator) {
        iterator++;
        if (iterator == round_players.end()) {
            iterator = round_players.begin();
        }
    }
};

}  // namespace server

#endif  // GAME_H
