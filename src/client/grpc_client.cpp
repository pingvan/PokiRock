#include "grpc_client.hpp"
#include <thread>
#include <utility>

#include "salt_hash.hpp"


client::client(std::shared_ptr<grpc::Channel>& new_channel)
: channel_(std::move(new_channel)),
      authorization_stub_(game::Authorization::NewStub(new_channel))
{}

template <typename T>
bool handle_errr_for_log(const T* mess) {

}

void client::init_player_info(const game::PlayerInfo &player_info) {
    client_id = player_info.client_id();
    client_games = player_info.client_games();
    client_wins = player_info.client_wins();
    client_balance = player_info.client_balance();
}

void client::lobby_init() {
    lobby_stub_ = game::Lobby::NewStub(channel_); //or to another func
    lobby_context_ = new grpc::ClientContext;
    lobby_stream_ = lobby_stub_->LobbyFunc(lobby_context_);
    std::thread reader(&client::process_lobby_responses, this);
    reader.detach();
}

void client::make_lobby_requests() { //will be called in GUI

}


void client::process_lobby_responses() {
    game::LobbyResponses response;
    while(lobby_stream_->Read(&response)) {
        if (response.has_create_game_response()) {

        } else { //if it has search game response

        }
    }
}


void client::game_init() {
    poker_game_stub_ = game::PokerGame::NewStub(channel_);
    poker_game_context = new grpc::ClientContext;
    poker_game_stream = poker_game_stub_->GameFunc(poker_game_context);
    in_game = true;
    std::thread reader(&client::process_game_responses, this);
    reader.detach();
}

void client::make_game_requests() { //will be called in GUI

}


void client::process_game_responses() {
    game::GameResponses response;
    while (poker_game_stream->Read(&response)) {

    }
}



void client::login(const std::string &client_name, const std::string &password) {
    game::LoginRequest login_request;
    auto *login_response = new game::LoginResponse;
    {
        grpc::ClientContext context_first;
        auto *login_request_first = new game::LoginRequestFirst;
        login_request_first->set_name(client_name);
        login_request.set_allocated_login_request_first(login_request_first);
        grpc::Status status = authorization_stub_->Login(&context_first, login_request, login_response);
        if (!status.ok()) {
            //handle connection error
        } else if (!login_response->has_login_response_first()) {
            //handle server error
        } else if (login_response->login_response_first().has_msg()) {
            if (login_response->login_response_first().msg().has_message_string()) {
                //handle exception with its message
            } else {
                //handle custom error
            }
        }
    }
    //TODO::know about release
    auto salt = login_response->login_response_first().salt();
    auto hashed_password = salt_hash::sha_hash(salt + password);
    {
        grpc::ClientContext context_second;
        auto login_request_second = new game::LoginRequestSecond;
        login_request_second->set_name(client_name);
        login_request_second->set_hashed(hashed_password);
        login_request.set_allocated_login_request_second(login_request_second);
        grpc::Status status = authorization_stub_->Login(&context_second, login_request, login_response);
        if (!status.ok()) {
            //handle connection error
        } else if (!login_response->has_login_response_second()) {
            //handle server error
        } else if (login_response->login_response_second().has_msg()) {
            if (login_response->login_response_second().msg().has_message_string()) {
                //handle exception with its message
            } else {
                //handle custom error
            }
        }
    }
    init_player_info(login_response->login_response_second().player_info());
}

void client::registration(const std::string &client_name, const std::string &password) {
    game::RegisterRequest register_request;
    auto *register_response = new game::RegisterResponse;
    std::string salt = salt_hash::generate_salt(std::max(static_cast<int>(password.size()), 5));
    std::string hashed_password = salt_hash::sha_hash(salt + password);
    register_request.set_name(client_name);
    auto *salt_hash = new game::SaltHash;
    salt_hash->set_salt(salt); salt_hash->set_hash(hashed_password);
    register_request.set_allocated_salt_hash(salt_hash);
    grpc::ClientContext context;
    grpc::Status status = authorization_stub_->Registration(&context, register_request, register_response);
    if (!status.ok()) {

    } else if (!register_response->has_player_info()) {

    } else if (register_response->has_msg()) {
        if (register_response->msg().has_message_string()) {

        } else {

        }
    }
    init_player_info(register_response->player_info());
}


