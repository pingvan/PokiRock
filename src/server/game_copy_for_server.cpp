#include "game_copy_for_server.h"
#include "Win_check.h"

namespace server {
int Game::next_position(int position) {
    return (position + 1) % static_cast<int>(round_players.size());
}

/*Game::Game(std::vector<client::Client> lobby)
    : players(std::move(lobby)),
      round_players(players),
      button(static_cast<int>(lobby.size()) - 1),
      last_player(button),
      available_cards(52),
        total_of_bets(0) {
    std::iota(available_cards.begin(), available_cards.end(), 0);
    std::cout << "Starting game with: ";
    for (const client::Client &Player : players) {
        // demand to preflop
        balance[Player] = 100;
        std::cout << Player.name() << " ";
    }
    std::cout << "\n";
}*/


Game::Game(uint32_t game_owner_id, const game::game_parameters *game_parameters,
           std::unique_ptr<player> owner)
:  condition(Waiting), game_owner_id_(game_owner_id), game_name_(game_parameters->game_name()), players_max_(game_parameters->number_of_players()), current_players_(0),
minimal_bet_(game_parameters->minimal_bet()), game_enter_balance_(game_parameters->game_enter_balance()), m_mutex()
{
    const uint32_t owner_id = owner->player_id_;
    auto lock = std::lock_guard(m_mutex); //TODO::maybe replace with std::lock_guard
    class_players[owner_id] = std::move(owner);
    current_players_++;
}

void Game::join_game(std::unique_ptr<player> player) {
    auto player_id = player->player_id_;
    auto lock = std::lock_guard(m_mutex);
    if (condition != Waiting) {

    }
    class_players[player_id] = std::move(player);
    current_players_++;
    if (current_players_ == players_max_) {
        //TODO::start game;
        condition = Playing;
    }
}

void Game::quit_game(int player_id) { //TODO::replace with switch cases
    if (condition == Playing) {
        //TODO::fold
    }
    auto lock = std::lock_guard(m_mutex);
    class_players.erase(player_id);
    //TODO::update DB data
}

void Game::start_game() {
    preflop();
    //TODO::
}

void Game::preflop() {
    std::cout << "Preflop\n";
    for (const auto &player : players) {
        auto [iter, created] = cards_enum.emplace(
            std::piecewise_construct, std::forward_as_tuple(player),
            std::forward_as_tuple(get_enum_card(), get_enum_card())
        );
        auto optional_move = player.optional_move();
        if (optional_move == "balance") {
            std::cout << "Your balance is: " << balance[player] << "\n";
        } else if (optional_move == "cards") {
            std::cout << iter->second.first << " " << iter->second.second << '\n';
        }
    }
    bets();
    flop();


    for (auto &[id, player] : class_players) {
        player->player_cards = {get_enum_card(), get_enum_card()}; //maybe separate setter functions which then will call graphic
         //here we should do working on requests
        //graphic buttons always working or separate function to process responses
        //balance and cards will be always able on screen
    }
}

void Game::flop() {
    current_turn = Flop;
    for (const auto &c : players) {
        data::DataBase_connector::insert_games(c.name());
    }
    if (players.size() > 1) {
        std::cout << "Flop\n";
        for (int i = 0; i < 3; i++) {
            board_cards.push_back(get_enum_card());
        }
        print_cards();
        bets();
    }
    turn();
}

void Game::turn() {
    current_turn = Turn;
    if (players.size() > 1) {
        std::cout << "Turn\n";
        board_cards.push_back(get_enum_card());
        print_cards();
        bets();
    }
    river();
}

void Game::river() {
    current_turn = River;
    if (players.size() > 1) {
        std::cout << "River\n";
        board_cards.push_back(get_enum_card());
        print_cards();
        bets();
    }
    who_won();
}

void Game::bets() {
    int must_bet = 0;
    if (current_turn == Preflop) {
        must_bet = blinds.big_blind;
    }
    bool big_blind_flag = false;
    bool small_blind_flag = false;
//    std::map<client::Client, int> have_betted;
    std::unordered_map<client::Client, int, client::ClientHash> have_betted;
    bool state = true;
    std::size_t done_players_counter = 0;
    while (state) {
        for (auto it = round_players.begin() + next_position(last_player);;) {
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

void Game::print_cards() {
    for (auto num_of_card : board_cards) {
        std::cout << num_of_card << " " << num_of_card << " ";
    }
    std::cout << "\n";
}

void Game::who_won() {
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
}

void Game::new_round() {
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
    round_players = players;
    last_player = button;
    total_of_bets = 0;
    preflop();
}

void Game::make_a_bet(const client::Client &player, int bet_amount) {
    balance[player] -= bet_amount;
    total_of_bets += bet_amount;
}

}  // namespace server