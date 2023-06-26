#include "grpc_client.hpp"

const std::string server_address = "127.0.0.1:2912";

int main() {
    client new_client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
}