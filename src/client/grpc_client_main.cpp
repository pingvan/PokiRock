#include "grpc_client.hpp"

const std::string server_address = "127.0.0.1:2912";

int main() {
    client new_client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
    //new_client.registration("test", "testpwd");
    new_client.login("test", "testpwd");
    new_client.make_lobby_requests(client::lobby_requests::CREATE_GAME, "aa", 10, 2, 3);
    return 0;
}