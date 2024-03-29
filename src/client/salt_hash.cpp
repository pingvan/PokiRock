#include <openssl/sha.h>
#include <random>
#include <sstream>
#include <iomanip>

#include "salt_hash.hpp"

std::string salt_hash::sha_hash(const std::string &phrase) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char *>(phrase.data()), phrase.length(),hash);
    std::stringstream ss;
    for (const unsigned char i : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0')
           << static_cast<int>(i);
    }
    return ss.str();
}

std::string salt_hash::generate_salt(int length) { //TODO::salt can't be with null size
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