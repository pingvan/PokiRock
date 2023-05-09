#include "grpc_server.hpp"

int main() {
    const std::string server_address = "127.0.0.1:2912";
    grpc::ServerBuilder builder;
    lobby_events service;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server_ = builder.BuildAndStart();
    std::cout << server_address << '\n';
    server_->Wait();
}