#include "grpc_client.hpp"

int main() {
    const std::string server_address = "127.0.0.1:2912";
    client new_client(
        grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials())
    );
    std::string l, p;
    std::cin >> l >> p;
    new_client.registration(l, p);
    std::string l_, p_;
    std::cin >> l_ >> p_;
    new_client.login(l_, p_);
}