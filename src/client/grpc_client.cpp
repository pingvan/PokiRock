#include "grpc_client.hpp"
#include <thread>
#include <type_traits>
#include <utility>

#include "salt_hash.hpp"

//we can't move channel

client::client(const std::shared_ptr<grpc::Channel>& new_channel)
: channel_(new_channel),
      authorization_stub_(game::Authorization::NewStub(new_channel))
{}

//bool or void or return some custom error
template <typename response_type>
bool client::handle_error_for_each_type(const grpc::Status &status, const response_type * response) {
    if (!status.ok()) {
        return false;
    } else {
        handle(response);
    }
    return true;
}

template <typename T>
bool client::handle(const T *response) {
    return false;
}

template <>
bool client::handle<game::LoginResponseFirst>(const game::LoginResponseFirst *response) {
    if (!response->has_salt()) {

    }
    handle_error(response);
    return true;
}

template<>
bool client::handle<game::LoginResponseSecond>(const game::LoginResponseSecond *response) {
    if (!response->has_player_info()) {

    }
    handle_error(response);
    return true;
}

template<>
bool client::handle<game::RegisterResponse>(const game::RegisterResponse *response) {
    if (!response->has_player_info()) {

    }
    handle_error(response);
    return true;
}


template<typename response_type>
bool client::handle_error(const response_type *response) {
    if (response->has_msg()) {
        if (response->msg().has_message_string()) {
            //handle exception
        } else {
            //handle custom error
        }
    }
    return true;
}

void client::init_player_info(const game::PlayerInfo &player_info) {
    client_id = player_info.client_id();
    client_games = player_info.client_games();
    client_wins = player_info.client_wins();
    client_balance = player_info.client_balance();
}

void client::init_proto_player_info_message(game::PlayerInfo *player_info) const {
    player_info->set_client_id(client_id);
    player_info->set_client_games(client_games);
    player_info->set_client_wins(client_wins);
    player_info->set_client_balance(client_balance);
}

void client::init_proto_game_parameters(game::GameParameters *game_parameters, const std::string &game_name, const uint32_t number_of_players, const uint32_t minimal_bet, const uint32_t game_enter_balance) {
    game_parameters->set_game_name(game_name);
    game_parameters->set_game_enter_balance(game_enter_balance);
    game_parameters->set_minimal_bet(minimal_bet);
    game_parameters->set_number_of_players(number_of_players);
}

void client::lobby_init() {
    lobby_stub_ = game::Lobby::NewStub(channel_);
    lobby_context_ = new grpc::ClientContext;
    lobby_stream_ = lobby_stub_->LobbyFunc(lobby_context_);
    std::thread reader(&client::process_lobby_responses, this);
    reader.detach();
    std::cout << "lobby inited\n";
}

void client::make_lobby_requests(client::lobby_requests request_type, const std::string &game_name, const uint32_t number_of_players, const uint32_t minimal_bet, const uint32_t game_enter_balance) { //will be called in GUI
    game::LobbyRequests request;
    if (request_type == CREATE_GAME) {
        std::cout << "creating\n";
        auto *create_request = new game::CreateGameRequest;
        auto *game_parameters = new game::GameParameters;
        init_proto_game_parameters(game_parameters,game_name, number_of_players, minimal_bet, game_enter_balance);
        create_request->set_allocated_game_parameters(game_parameters);
        request.set_allocated_create_game_request(create_request);
    } else {
        std::cout << "searching\n";
        auto *search_request = new game::SearchGameRequest;
        auto *game_parameters = new game::GameParameters;
        init_proto_game_parameters(game_parameters,game_name, number_of_players, minimal_bet, game_enter_balance);
        search_request->set_allocated_game_parameters(game_parameters);
        request.set_allocated_search_game_request(search_request);
    }
    lobby_stream_->Write(request);
    std::cout << "WRITTEN LOBBY\n";
}


void client::process_lobby_responses() {
    game::LobbyResponses response;
    std::cout << "THREAD STARTED\n";
    while(lobby_stream_->Read(&response)) {
        std::cout << "READ LOBBY\n";
        if (response.has_create_game_response()) {
            std::cout << "HAS GAME RESPONSE\n";
            if (response.create_game_response().has_msg()) {
                std::cout << "has msg\n";
            } else {
                std::cout << "STARTING GAME INIT\n";
                auto game_id_to_connect = response.create_game_response().game_id();
                game_init();
                make_game_requests(client::game_requests::JOIN_GAME_AS_OWNER, game_id_to_connect);
            }
        } else { //if it has search game response
            if (response.search_game_response().has_msg()) {

            } else {
                auto game_id_to_connect = response.search_game_response().game_id();
                game_init();
                make_game_requests(client::game_requests::JOIN_GAME, game_id_to_connect);
            }
        }
    }
}


void client::game_init() {
    std::cout << "calling game init\n";
    poker_game_stub_ = game::PokerGame::NewStub(channel_);
    poker_game_context = new grpc::ClientContext;
    poker_game_stream = poker_game_stub_->GameFunc(poker_game_context);
    in_game = true;
    std::thread reader(&client::process_game_responses, this);
    reader.detach();
    std::cout << "game inited\n";
}

void client::make_game_requests(client::game_requests request_type, const uint32_t game_id) { //will be called in GUI
    game::GameRequests request;
    if (request_type == JOIN_GAME) {
        auto *join_game_request = new game::JoinGameRequest;
        auto *player_info = new game::PlayerInfo;

        init_proto_player_info_message(player_info);

        join_game_request->set_player_name(client_name);
        join_game_request->set_game_id(game_id);
        join_game_request->set_allocated_player_info(player_info);

        request.set_allocated_join_game_request(join_game_request);

        in_game = true;
    } else if (request_type == JOIN_GAME_AS_OWNER) {
        auto *join_game_as_owner_request = new game::JoinGameAsOwnerRequest;
        auto *player_info = new game::PlayerInfo;

        init_proto_player_info_message(player_info);

        join_game_as_owner_request->set_player_name(client_name);
        join_game_as_owner_request->set_game_id(game_id);
        join_game_as_owner_request->set_allocated_player_info(player_info);

        request.set_allocated_join_game_as_owner_request(join_game_as_owner_request);

        in_game = true;
    } else {

    }
    poker_game_stream->Write(request);
}


void client::process_game_responses() {
    game::GameResponses response;
    while (poker_game_stream->Read(&response)) {
        std::cout << "READ GAME\n";
        if (response.has_game_state()) {
            //update graphic
        } else if (response.has_join_game_response()) {

        } else if (response.has_join_game_as_owner_response()) {

        } else { //has make_move response

        }
    }
}



void client::login(const std::string &client_login, const std::string &password) {
    game::LoginRequest login_request;
    auto *login_response = new game::LoginResponse;
    {
        grpc::ClientContext context_first;
        auto *login_request_first = new game::LoginRequestFirst;
        login_request_first->set_name(client_login);
        login_request.set_allocated_login_request_first(login_request_first);
        grpc::Status status = authorization_stub_->Login(&context_first, login_request, login_response);
        handle_error_for_each_type(status, login_response);
    }
    //TODO::know about release
    auto salt = login_response->login_response_first().salt();
    auto hashed_password = salt_hash::sha_hash(salt + password);
    std::cout << "hashed " << hashed_password << '\n';
    {
        grpc::ClientContext context_second;
        auto login_request_second = new game::LoginRequestSecond;
        login_request_second->set_name(client_login);
        login_request_second->set_hashed(hashed_password);
        login_request.set_allocated_login_request_second(login_request_second);
        grpc::Status status = authorization_stub_->Login(&context_second, login_request, login_response);
        handle_error_for_each_type(status, login_response);
    }
    init_player_info(login_response->login_response_second().player_info());
    lobby_init();
}

void client::registration(const std::string &client_login, const std::string &password) {
    game::RegisterRequest register_request;
    auto *register_response = new game::RegisterResponse;
    std::string salt = salt_hash::generate_salt(std::max(static_cast<int>(password.size()), 5));
    std::string hashed_password = salt_hash::sha_hash(salt + password);
    register_request.set_name(client_login);
    auto *salt_hash = new game::SaltHash;
    salt_hash->set_salt(salt); salt_hash->set_hash(hashed_password);
    register_request.set_allocated_salt_hash(salt_hash);
    grpc::ClientContext context;
    std::cout << "send to server\n";
    grpc::Status status = authorization_stub_->Registration(&context, register_request, register_response);
    handle_error_for_each_type(status, register_response);
    init_player_info(register_response->player_info());
    lobby_init();
}
