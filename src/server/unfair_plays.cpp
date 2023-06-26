#include "unfair_plays.h"
#include "player.hpp"
namespace server {
void unfair_plays::change_a_card(player &our_player,Card old_card, Card new_card) {
    if (our_player.player_cards.first == old_card){
        our_player.player_cards.first = new_card;
    } else {
        our_player.player_cards.second = new_card;
    }
}
Card unfair_plays::look_at_opponents_card( player &opponent) {
    return opponent.player_cards.first;
}
}