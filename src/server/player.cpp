#include "player.hpp"

#include <utility>

player::player(std::string player_name, const game::PlayerInfo *player_info, const uint32_t game_enter_balance, grpc::ServerReaderWriter<game::GameResponses, game::GameRequests> *stream)
: player_name_(std::move(player_name)), player_id_(player_info->client_id()), player_games_(player_info->client_games()),
      player_wins_(player_info->client_wins()), in_game_balance_(game_enter_balance),
      current_balance_(player_info->client_balance()), player_status(status::waiting)
{
    stream_ = std::make_shared<grpc::ServerReaderWriter<game::GameResponses, game::GameRequests>>(*stream);
}
