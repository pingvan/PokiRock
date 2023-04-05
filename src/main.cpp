//#include "server/Server.h"
//#include "client/Client.h"
#include <pqxx/pqxx>
#include <openssl/sha.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <random>

std::string sha_hash(const std::string &phrase) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)phrase.c_str(), phrase.length(), hash);
    std::stringstream ss;
    for (unsigned char const i : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(i);
    }
    return ss.str();
}

std::string generate_salt(int length) {
    static const std::string av = {"0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, static_cast<int>(av.size()));
    std::stringstream ss;
    for (int i = 0; i < length; i++) {
        ss << av[distrib(gen)];
    }
    return ss.str();
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

    /*pqxx::connection con{con_str};
    server::Server s1;
    client::Client p1;
    client::Client p2;
    client::Client p3;
    p2.login();
    p1.login();
    p3.login();
    s1.add(p1);
    s1.add(p2);
    s1.add(p3);
//    p1.connect(S1);
//    p2.connect(S1);
//    p3.connect(S1);
    s1.start_game();*/
    const std::string test = "Hello World!";

    std::string salt_pas = generate_salt(static_cast<int>(test.size()));
    std::string to_has = test + salt_pas;
    std::string hashed = sha_hash(to_has);
    std::cout << hashed;
}