#include "grpc_client.hpp"

const std::string server_address = "127.0.0.1:2912";

client create_client() {
    return client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
}


int main() {
    client new_client = create_client();

    std::string l, p;
    std::cin >> l >> p;
    new_client.registration(l, p);
    std::string l_, p_;
    std::cin >> l_ >> p_;
    new_client.login(l_, p_);
}