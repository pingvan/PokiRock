#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include "grpc_server.hpp"

const std::string server_address = "127.0.0.1:2912";

/*std::string read_from_files(const std::string &file_name) {
    std::ifstream file;
    file.open(file_name, std::ios_base::in);
    std::stringstream file_stringstream;
    file_stringstream << file.rdbuf();
    file.close();
    return file_stringstream.str();
}*/

void run_server() { //TODO::make the struct
    grpc::ServerBuilder builder;
    Poker_server service;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server_ = builder.BuildAndStart();
    std::cout << server_address << '\n';
    server_->Wait();
}

/*void run_server_secure() {
    grpc::ServerBuilder builder;
    lobby_events service;

    grpc::SslServerCredentialsOptions::PemKeyCertPair keyCertPair;
    keyCertPair.private_key = read_from_files("connection_serts/server.key");
    keyCertPair.cert_chain = read_from_files("connection_serts/server.crt");


    //as for TODO::create root key, self signed for localhost and do the same for the client

    grpc::SslServerCredentialsOptions ssl_options;
    ssl_options.pem_key_cert_pairs.push_back(keyCertPair);
    std::shared_ptr<grpc::ServerCredentials> server_credentials = grpc::SslServerCredentials(ssl_options);

    builder.AddListeningPort(server_address, server_credentials);
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server_ = builder.BuildAndStart();
    std::cout << server_address << '\n';
    server_->Wait();
}*/

void run_server_with_google_credentials() {}

int main() {
    run_server();
}