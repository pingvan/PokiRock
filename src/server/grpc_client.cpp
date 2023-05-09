#include "grpc_client.hpp"
#include <openssl/sha.h>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>


client::client(std::shared_ptr<grpc::Channel> new_channel)
    : channel_(new_channel), lobby_stub(game::lobby::NewStub(channel_)) {
}

void client::login(
    const std::string &client_name,
    const std::string &password
) {
    grpc::ClientContext context_first;
    grpc::Status status_first;
    grpc::Status status_second;
    game::login_request request_first;
    auto *response_first = new game::login_response;
    request_first.set_name(client_name);
    status_first =
        lobby_stub->Login(&context_first, request_first, response_first);
    std::cout << "AFTER FIRST RESP\n";
    if (status_first.ok() && response_first->has_salt_hash()) {
        std::cout << "GET SALT_HASH\n";
        game::login_request request_second;
        auto *response_second = new game::login_response;
        const std::string hashed_password =
            sha_hash(response_first->salt_hash().salt() + password);
        if (hashed_password == response_first->salt_hash().hash()) {
            std::cout << hashed_password << '\n'
                      << response_first->salt_hash().hash() << '\n';
            std::cout << "GOOD COMPARE\n";
            request_second.set_after_compare(true);
        } else {
            std::cout << hashed_password << '\n'
                      << response_first->salt_hash().hash() << '\n';
            std::cout << "BAD COMPARE\n";
            request_second.set_after_compare(false);
        }
        grpc::ClientContext context_second;
        status_second =
            lobby_stub->Login(&context_second, request_second, response_second);
        std::cout << "AFTER SECOND RESP\n";
        if (status_second.ok() && response_second->has_status_message()) {
            if (response_second->status_message().status()) {
                // show lobby
                std::cout << "SUCCESS\n";
            } else {
                std::cout << "Incorrect login or password\nTry again!\n";
            }
        }
    } else {
        std::cout << "Try again!\n";
    }
}

void client::registration(
    const std::string &client_name,
    const std::string &password
) {
    grpc::ClientContext context;
    const std::string salt = generate_salt(static_cast<int>(password.size()));
    const std::string hashed = sha_hash(salt + password);
    game::register_request request;
    auto *response = new game::register_response;
    auto *salt_hash = new game::salt_hash;
    salt_hash->set_salt(salt);
    salt_hash->set_hash(hashed);
    request.set_name(client_name);
    request.set_allocated_salt_hash(salt_hash);
    grpc::Status const status =
        lobby_stub->Register(&context, request, response);
    if (status.ok() && response->status_message().status()) {
        // show lobby
        std::cout << "SUCCESS\n";
    } else if (status.ok() && !response->status_message().status()) {
        std::cout << response->status_message().message() << '\n';
        std::cout << "ANOTHER ERR\n";
    } else {
        // some error
        std::cout << "ERROR " << status.error_message() << '\n';
    }
}

std::string client::sha_hash(const std::string &phrase) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(
        reinterpret_cast<const unsigned char *>(phrase.data()), phrase.length(),
        hash
    );
    std::stringstream ss;
    for (const unsigned char i : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(i);
    }
    return ss.str();
}

std::string client::generate_salt(int length) {
    static const std::string symbols = {
        "0123456789!@#$%^&*"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(
        0, static_cast<int>(symbols.size())
    );
    std::stringstream random_symbols;
    for (int i = 0; i < length; i++) {
        random_symbols << symbols[distrib(gen)];
    }
    return random_symbols.str();
}
