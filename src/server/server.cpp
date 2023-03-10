#include "server.h"
#include "../client/client.h"

namespace server {

    void server::add(const client::client& client) {
        players.push(client);
    }

    void server::start_game(){
        std::vector<client::client> lobbi(5);
        for (int i = 0; i < 5; i++){
            auto player = this->players.front();
            this->players.pop();
            lobbi[i] = player;
        }
        game new_game(lobbi);
        this->games.push_back(new_game);
    }

    game::game(std::vector<client::client> lobbi) : players(std::move(lobbi)){
        for (int i = 0; i < 52; i++){
            availible_cards.push_back(i);
        }
        for (const client::client& player : players){
            size_t index1 = rand() % availible_cards.size();
            int first_card = availible_cards[index1];
            availible_cards.erase(availible_cards.begin() +index1);
            size_t index2 = rand() % availible_cards.size();
            int second_card = availible_cards[index2];
            availible_cards.erase(availible_cards.begin() +index2);
            cards[player]  = {first_card, second_card};
        }
    }
}