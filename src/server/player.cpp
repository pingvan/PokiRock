#include "player.hpp"

#include <utility>

/*player::player(std::string player_name, int player_id, int in_game_balance, int current_balance)
: player_name_(std::move(player_name)), player_id_(player_id), in_game_balance_(in_game_balance), current_balance_(current_balance),
      player_cards({Card({}), Card({})})
{

}*/

player::player(const std::string& player_name, const game::player_info *player_info, const int game_enter_balance, grpc::ServerReaderWriter<game::Responses, game::Requests> *stream)
: player_name_(player_name), player_id_(player_info->client_id()), player_games_(player_info->client_games()),
      player_wins_(player_info->client_wins()), in_game_balance_(game_enter_balance),
      current_balance_(player_info->client_balance()), player_status(status::waiting), player_cards({Card(), Card()})
{
    stream_ = std::make_shared<grpc::ServerReaderWriter<game::Responses, game::Requests>>(*stream);
}

void player::process_responses() {

}