#pragma once

#include <grpcpp/grpcpp.h>

#include "../proto/game.grpc.pb.h"
#include "../proto/game.pb.h"

struct lobby_events final : public game::lobby::Service {
    grpc::Status Login([[maybe_unused]] grpc::ServerContext *context, const game::login_request *request, game::login_response *response) override;
    grpc::Status Register([[maybe_unused]] grpc::ServerContext *context, const game::register_request *request, game::register_response *response) override;
};

/*struct [[maybe_unused]] game_events final : public game::game::AsyncService {

};*/
