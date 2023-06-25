#pragma once
#include "Card.hpp"
#include "player.hpp"

namespace server {
struct unfair_plays {

    static void change_a_card(player &our_player, Card old_card, Card new_card);
    static Card look_at_opponents_card(player &opponent );
};
}  // namespace server
