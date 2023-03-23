#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>  //I hope it will be DB in next versions
#include <vector>

namespace client {
struct client;
}

namespace server {
/*
enum Value {
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

enum Suit { DIAMONDS, HEARTS, CLUBS, SPADES };

struct Card {
private:
    Suit suit;
    Value value;

public:
    explicit Card(int num) {
        static constexpr std::array<Value, 13> values_of_cards = {
            Two,  Three, Four, Five,  Six,  Seven, Eight,
            Nine, Ten,   Jack, Queen, King, Ace};
        static constexpr std::array<Suit, 4> suits_of_cards = {
            hearts, diamonds, spades, clubs};
        auto num_of_value = num / 4;
        value = values_of_cards[num_of_value];
        suit = suits_of_cards[num%4];
    }
    bool operator<(const Card &card) const {
        return value < card.value;
    }
};
*/
struct game {
private:
    std::vector<client::client> players;
    std::map<client::client, std::pair<int, int>>
        cards;  // TODO make enum class Value, Suit & struct Card
    std::map<client::client, int> balance;
    std::vector<int> available_cards;
    std::vector<int> board_cards;
    int total_of_bets;

public:
    explicit game(std::vector<client::client> lobby);
    void bets();
    void preflop();
    void flop();
    void make_a_bet(const client::client &player, int bet_amount);
    void turn();
    void river();
    int get_card();
    void print_cards();
    void who_won();
    static std::pair<int, int> rank_combination(const std::vector<int> &combination);
};

struct game;
struct server {
private:
    std::queue<client::client> players;
    std::vector<game> games;

public:
    void add(const client::client &client);
    void start_game();
};

}  // namespace server
#endif  // SERVER_H
