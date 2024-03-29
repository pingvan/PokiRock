#include "game_copy_for_server.h"
#include "Win_check.h"

namespace server {

uint32_t Game::next_position(uint32_t position) {
    return (position + 1) % static_cast<uint32_t>(players_in_round_.size());
}


void Game::suit_to_proto(Suit &suit, game::Card *card) {
    switch (suit) {
        case Suit::DIAMONDS:
            card->set_suit(game::Suits::SUITS_DIAMONDS);
            break;
        case Suit::HEARTS:
            card->set_suit(game::Suits::SUITS_HEARTS);
            break;
        case Suit::CLUBS:
            card->set_suit(game::Suits::SUITS_CLUBS);
            break;
        case Suit::SPADES:
            card->set_suit(game::Suits::SUITS_SPADES);
            break;
        default:
            assert(false);
    }
}

void Game::value_to_proto(Value &value, game::Card *card) {
    switch (value) {
        case Value::TWO:
            card->set_value(game::Values::VALUES_TWO);
            break;
        case Value::THREE:
            card->set_value(game::Values::VALUES_THREE);
            break;
        case Value::FOUR:
            card->set_value(game::Values::VALUES_FOUR);
            break;
        case Value::FIVE:
            card->set_value(game::Values::VALUES_FIVE);
            break;
        case Value::SIX:
            card->set_value(game::Values::VALUES_SIX);
            break;
        case Value::SEVEN:
            card->set_value(game::Values::VALUES_SEVEN);
            break;
        case Value::EIGHT:
            card->set_value(game::Values::VALUES_EIGHT);
            break;
        case Value::NINE:
            card->set_value(game::Values::VALUES_NINE);
            break;
        case Value::TEN:
            card->set_value(game::Values::VALUES_TEN);
            break;
        case Value::JACK:
            card->set_value(game::Values::VALUES_JACK);
            break;
        case Value::QUEEN:
            card->set_value(game::Values::VALUES_QUEEN);
            break;
        case Value::KING:
            card->set_value(game::Values::VALUES_KING);
            break;
        case Value::ACE:
            card->set_value(game::Values::VALUES_ACE);
            break;
        default:
            assert(false);
    }
}

void Game::cards_to_proto(Card &card, game::Card *first) {
    auto suit = card.get_suit();
    auto value = card.get_value();

    suit_to_proto(suit, first);
    value_to_proto(value, first);
}

game::GameParameters Game::get_game_parameters() const {
    game::GameParameters game_parameters;
    game_parameters.set_game_name(game_name_);
    game_parameters.set_number_of_players(players_max_);
    game_parameters.set_minimal_bet(minimal_bet_);
    game_parameters.set_game_enter_balance(game_enter_balance_);
    return game_parameters;
}


Game::Game(const uint32_t game_owner_id, const game::GameParameters *game_parameters)
:  condition(Waiting), game_owner_id_(game_owner_id), game_name_(game_parameters->game_name()), players_max_(game_parameters->number_of_players()), current_players_(0),
minimal_bet_(game_parameters->minimal_bet()), game_enter_balance_(game_parameters->game_enter_balance()), owner_connected(false), m_mutex(),
   available_cards(52), last_player(button), button(players_max_), total_of_bets(0)
{
    std::iota(available_cards.begin(), available_cards.end(), 0);
}

void Game::broadcast_for_all_players_in_lobby(game::GameResponses *response) {
    for (const auto &[id, player] : players_in_room_) {
        player->stream_->Write(*response);
    }
}

void Game::broadcast_for_round(game::GameResponses *response) {
    for (const auto &[id, player] : players_in_round_) {
        player->stream_->Write(*response);
    }
}

[[nodiscard]] uint32_t Game::get_game_enter_balance() const {
    return game_enter_balance_;
}

[[nodiscard]] bool Game::is_owner_connected() const {
    return owner_connected;
}

void Game::join_game_as_owner(std::unique_ptr<player> owner) {
    auto lock = std::lock_guard(m_mutex);
    players_in_room_[game_owner_id_] = std::move(owner);
    current_players_++;
    owner_connected = true;
    std::cout << "owner joined the game\n";
}

void Game::join_game(std::unique_ptr<player> player) {
    auto player_id = player->player_id_;
    auto lock = std::lock_guard(m_mutex);
    if (condition != Waiting) { //TODO::is players > max
        players_in_room_[player_id] = std::move(player);
        return;
    }
    current_players_++;
    if (current_players_ == players_max_) {
        start_game();
    }
}

void Game::quit_game(uint32_t player_id) { //TODO::replace with switch cases
    if (condition == Playing) {
        //TODO::fold
    }
    auto lock = std::lock_guard(m_mutex);
    players_in_room_.erase(player_id);
    //TODO::update DB data
}

void Game::start_game() {
    condition = Playing;
    players_in_round_ = players_in_room_;
    preflop();
}

void Game::preflop() {
    for (auto &[id, player] : players_in_room_) {
        game::GameResponses response;
        auto *game_state = new game::GameState;
        player->player_cards = {get_enum_card(), get_enum_card()}; //maybe separate setter functions which then will call graphic
        auto *player_card_first = game_state->add_player_cards();
        auto *player_card_second = game_state->add_player_cards();
        cards_to_proto(player->player_cards.first, player_card_first);
        cards_to_proto(player->player_cards.second, player_card_second);
        response.set_allocated_game_state(game_state);
        player->stream_->Write(response);
    }
//    bets();
    flop();
}

void Game::flop() {
    current_turn = Flop;
    game::GameResponses response;
    auto *game_state = new game::GameState;
    if (players_in_round_.size() > 1) {
        for (int i = 0; i < 3; i++) {
            board_cards.push_back(get_enum_card());
            auto *new_board_card = game_state->add_board_cards();
            cards_to_proto(board_cards.back(), new_board_card);
        }
        response.set_allocated_game_state(game_state);
        broadcast_for_all_players_in_lobby(&response);
//        bets();
    }
    turn();
}

void Game::turn() {
    current_turn = Turn;
    game::GameResponses response;
    auto *game_state = new game::GameState;
    if (players_in_round_.size() > 1) {
        board_cards.push_back(get_enum_card());
        auto *new_board_card = game_state->add_board_cards();
        cards_to_proto(board_cards.back(), new_board_card);
        response.set_allocated_game_state(game_state);
        broadcast_for_all_players_in_lobby(&response);
//        bets();
    }

    river();
}

void Game::river() {
    current_turn = River;
    game::GameResponses response;
    auto *game_state = new game::GameState;
    if (players_in_round_.size() > 1) {
        board_cards.push_back(get_enum_card());
        auto *new_board_card = game_state->add_board_cards();
        cards_to_proto(board_cards.back(), new_board_card);
        response.set_allocated_game_state(game_state);
        broadcast_for_all_players_in_lobby(&response);
    }
//    who_won();
}

void Game::bets() {
    int must_bet = 0;
    if (current_turn == Preflop) {
        must_bet = blinds.big_blind;
    }
    bool big_blind_flag = false;
    bool small_blind_flag = false;

    std::unordered_map<uint32_t, uint32_t> have_betted_; //id to ...
    bool state = true;
    std::size_t done_players_counter = 0;
    while (state) {
        for (auto it = players_in_round_.begin() + next_position(last_player);;) {
            const auto &player = *it;
            if (current_turn == Which_turn::Preflop) {
                if (!small_blind_flag) {
                    make_a_bet(player, blinds.small_blind);
                    have_betted[player] = blinds.small_blind;
                    small_blind_flag = true;
                    increase_iterator(it);
                    continue;
                } else if (!big_blind_flag) {
                    make_a_bet(player, blinds.big_blind);
                    have_betted[player] = blinds.big_blind;
                    big_blind_flag = true;
                    increase_iterator(it);
                    continue;
                }
            }
            if (balance[player] == 0) {
                done_players_counter += 1;
                increase_iterator(it);
                if (done_players_counter == round_players.size()) {
                    state = false;
                    break;
                }
                if (it == round_players.begin() + next_position(last_player)) {
                    break;
                }
                continue;
            }
            some_func();
            while (true) {
                auto move = player.move(balance[player]);
                if (move == "call") {
                    const int bet_amount = must_bet - have_betted[player];
                    make_a_bet(player, bet_amount);
                    have_betted[player] = must_bet;
                    done_players_counter += 1;
                    increase_iterator(it);
                    break;
                } else if (move == "raise") {
                    std::cout << "How much would you like to bet?\n";
                    int bet = 0;
                    std::cin >> bet;
                    // must_bet += bet;
                    if (bet > balance[player]) {
                        std::cout << "A lack of money, operation denied.\n";
                    } else {
                        done_players_counter = 1;

                        if (bet < must_bet) {
                            bet = must_bet;
                            done_players_counter++;
                        } else {
                            done_players_counter = 1;
                        }
                        must_bet = bet;
                        const int bet_amount =
                            must_bet - have_betted[player];
                        make_a_bet(player, bet_amount);
                        have_betted[player] = must_bet;
                        increase_iterator(it);
                        break;
                    }
                } else if (move == "all-in") {
                    auto bet = balance[player];
                    if (must_bet < bet) {
                        done_players_counter = 1;
                        must_bet = bet;
                    }
                    make_a_bet(player, bet);
                    have_betted[player] += bet;
                    increase_iterator(it);
                    break;
                } else if (move == "fold") {
                    if (it - round_players.begin() <= last_player) {
                        last_player--;
                        if (last_player < 0) {
                            last_player =
                                static_cast<int>(round_players.size())-2;
                        }
                    }
                    it = round_players.erase(it);
                    break;
                } else if (move == "check") {
                    if (must_bet > have_betted[player]) {
                        std::cout
                            << "You can not check here, operation denied.\n";
                    } else {
                        done_players_counter += 1;
                        increase_iterator(it);
                        break;
                    }
                }
                std::cout << "Incorrect input, try again\n";
            }
            if (done_players_counter == round_players.size()) {
                state = false;
                break;
            }
            if (it == round_players.begin() + next_position(last_player)) {
                break;
            }
        }
    }
}

Card Game::get_enum_card() {
    std::random_device rand;
    std::mt19937 mt_rand(rand());
    std::uniform_int_distribution<std::size_t> range(0, available_cards.size()-1);
    auto index = static_cast<std::ptrdiff_t>(range(mt_rand));
    auto card = available_cards[index];
    available_cards.erase(available_cards.begin() + index);
    return Card(card);
}


/*void Game::who_won() {
    if (round_players.size() == 1) {
        const auto &player = *round_players.begin();
        balance[player] += total_of_bets;
        std::cout << "Player " << player.name() << " have won!!!\n";
    } else {
        const client::Client *winner = nullptr;
        std::pair<int, int> winning_combination;
        std::vector<int> winning_combination_cards;
        for (const auto &player : round_players) {
            std::pair<int, int> best_combination;
            std::vector<int> best_combination_cards;
            for (int i = 0; i < 6; i++) {
                for (int j = i; j < 6; j++) {
                    if (j == i) {
                        j = 0;
                    }
                    std::vector<int> combination_cards;
                    for (int q = 1; q < 6; q++) {
                        if (q == i) {
                            combination_cards.push_back(
                                cards_enum.at(player).first.get_index()
                            );
                        } else if (q == j) {
                            combination_cards.push_back(
                                cards_enum.at(player).second.get_index()
                            );
                        } else {
                            combination_cards.push_back(
                                board_cards[q - 1].get_index()
                            );
                        }
                    }
                    std::sort(
                        combination_cards.begin(), combination_cards.end(),
                        std::greater<>()
                    );
                    auto combination = Win_check::check(combination_cards);
                    if (best_combination < combination) {
                        best_combination = combination;
                        best_combination_cards = combination_cards;
                    }
                    if (j == 0){
                        j = i;
                    }
                }
            }
            if (winning_combination < best_combination) {
                winning_combination = best_combination;
                winning_combination_cards = best_combination_cards;
                winner = &player;
            }
        }
        balance[*winner] += total_of_bets;
        std::cout << "Player " << winner->name() << " have won!!!\n";
        data::DataBase_connector::insert_win(winner->name());
        std::cout << "Winning combination is:";
        for (const auto &c : balance) {
            data::DataBase_connector::update_balance(
                c.first.name(), (c.first.get_balance() - c.second)
            );
        }
        for (int const card_num : winning_combination_cards) {
            auto c = Card(card_num);
            std::cout << " " << c;
        }
    }
    new_round();
}*/

/*void Game::new_round() {
    current_turn = Preflop;
    button = next_position(button);
    for (auto it = players.begin(); it != players.end();) {
        if (balance[*it] == 0) {
            if (it - players.begin() <= button) {
                button--;
                if (button < 0) {
                    button = static_cast<int>(players.size());
                }
                it = players.erase(it);
            } else {
                it++;
            }
        } else {
            it++;
        }
    }
    available_cards.clear();
    for (int i = 0; i < 52; i++) {
        available_cards.push_back(i);
    }
    board_cards.clear();
    players_in_round_ = players_in_room_;
    last_player = button;
    total_of_bets = 0;
    preflop();
}*/

void Game::make_a_bet(const uint32_t player_id, uint32_t bet_amount) {
    players_in_round_[player_id]->in_game_balance_ -= bet_amount;
    total_of_bets += bet_amount;
}

}  // namespace server