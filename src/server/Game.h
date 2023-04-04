#ifndef POKIROCK_GAME_H
#define POKIROCK_GAME_H

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
#include "../client/Client.h"

struct Card {
private:
    enum class Value {
        Two,Three,Four,Five,Six,
        Seven,Eight,Nine,Ten,Jack,Queen,King,Ace
    };
    enum class Suit { DIAMONDS, HEARTS, CLUBS, SPADES };
    Suit suit;
    Value value;

public:
    explicit Card(int num) {
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

    bool operator<(const Card &card) const {
        return value < card.value;
    }
};

namespace server {
struct Game {
private:
    std::vector<client::Client> players;
    std::map<client::Client, std::pair<Card, Card>> cards_enum;
    //std::map<client::Client, std::pair<int, int>> cards;  // TODO make enum class Value, Suit & struct Card
    std::map<client::Client, int> balance;
    std::vector<int> available_cards;
    std::vector<int> board_cards;
    int total_of_bets;

public:
    explicit Game(std::vector<client::Client> lobby);
    void bets();
    void preflop();
    void flop();
    void make_a_bet(const client::Client &player, int bet_amount);
    void turn();
    void river();
    Card get_enum_card();

    void print_cards();
    void who_won();
};

}  // namespace server

#endif  // POKIROCK_GAME_H
