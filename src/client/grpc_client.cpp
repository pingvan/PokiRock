#include "grpc_client.hpp"
#include <openssl/sha.h>
#include <iomanip>
#include <iostream>
#include <random>
#include <sstream>
#include <utility>


client::client(const std::shared_ptr<grpc::Channel>& new_channel)
    : lobby_stub_(game::PokerGame::NewStub(new_channel)) {
}

//client::~client() = default;

void client::login(const std::string &client_name, const std::string &password) {

}

void client::registration(const std::string &client_name, const std::string &password) {

}

std::string client::sha_hash(const std::string &phrase) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(phrase.data()), phrase.length(),hash);
    std::stringstream ss;
    for (const unsigned char i : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(i);
    }
    return ss.str();
}

std::string client::generate_salt(int length) { //TODO::salt can't be with null size
    static const std::string symbols = {
        "0123456789!@#$%^&*"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib( //TODO::min password size
        5, static_cast<int>(symbols.size()) //min salt size
    );
    std::stringstream random_symbols;
    for (int i = 0; i < length; i++) {
        random_symbols << symbols[distrib(gen)];
    }
    return random_symbols.str();
}
