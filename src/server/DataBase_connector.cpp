#include "DataBase_connector.h"


std::string DataBase_connector::sha_hash(const std::string &phrase) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)phrase.c_str(), phrase.length(), hash);
    std::stringstream ss;
    for (unsigned char const i : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(i);
    }
    return ss.str();
}

std::string DataBase_connector::generate_salt(int length) {
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

void DataBase_connector::insert_new_client(const std::string &name) {
    bool id_generated = false;
    uint32_t client_id = 0;
    while (!id_generated) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, 28122019);
         client_id = distrib(gen);
        if (client_ids.find(client_id) == client_ids.end()) {
            client_ids.emplace(client_id);
            id_generated = true;
        }
    }
    try {
        pqxx::connection con{connection_message};
        pqxx::work txn{con};
        bool complete = false;
        std::string pass;
        std::string repeated_pass;
        while(!complete) {
            std::cout << "Choose password:\n";
            std::cin >> pass;
            std::cout << "Repeate your password:\n";
            std::cin >> repeated_pass;
            if (pass == repeated_pass) {
                complete = true;
            } else {
                std::cout << "Passwords doesn't match! Try again:\n";
            }
        }
        std::string salt = generate_salt(static_cast<int>(pass.size()));
        std::string hashed = sha_hash(salt + pass);
        txn.exec("INSERT INTO id_to_password (client_id, client_password_hashe, password_salt)"
                 "VALUES" + txn.quote(client_id) + ',' + txn.quote(hashed) + ',' + txn.quote(salt));
        txn.exec("INSERT INTO clients (client_id, client_login, client_games, client_wins, client_balance)"
                 "VALUES" + txn.quote(client_id) + ',' + txn.quote(name) + ',' + txn.quote(0) + ',' + txn.quote(0) + ',' + txn.quote(1000));
        txn.commit();
        con.close();
    } catch(std::exception &e) {
        std::cout << e.what() << '\n';
    }
}