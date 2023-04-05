#include "DataBase_connector.h"

namespace data {

    std::string DataBase_connector::sha_hash(const std::string &phrase) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256((unsigned char *) phrase.c_str(), phrase.length(), hash);
        std::stringstream ss;
        for (unsigned char const i: hash) {
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

    void DataBase_connector::insert_new_client(const std::string &client_login) {
        try {
            pqxx::connection con{connection_message};
            pqxx::work txn{con};
            bool complete = false;
            std::string pass;
            std::string repeated_pass;
            while (!complete) {
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
            txn.exec_params("INSERT INTO clients (client_login, client_games, client_wins, client_balance)"
                            "VALUES ($1, $2, $3, $4)", client_login, 0, 0, 1000);
            auto client_id = txn.query_value<uint32_t>("SELECT client_id "
                                                       "FROM clients "
                                                       "WHERE client_login =" + txn.quote(client_login));
            txn.exec_params("INSERT INTO id_to_password (client_id, client_password_hashe, password_salt)"
                            "VALUES ($1, $2, $3)", client_id, hashed, salt);
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
        }
    }

    bool DataBase_connector::log_in_client(const std::string &client_login, const std::string &pass_entered) {
        try {
            pqxx::connection con{connection_message};
            pqxx::work txn{con};
            auto client_id = txn.query_value<uint32_t>("SELECT client_id "
                                                       "FROM clients "
                                                       "WHERE client_login =" + txn.quote(client_login));
            pqxx::result const row = txn.exec_params("SELECT client_password_hashe, password_salt "
                                                     "FROM id_to_password "
                                                     "WHERE client_id = $1",
                                                     client_id);
            std::string hase_tab;
            std::string salt_tab;
            for (auto r: row) {
                hase_tab = r[0].as<std::string>();
                salt_tab = r[1].as<std::string>();
            }
            std::cout << "Enter password:\n";
//        std::string pass_eneterd;
//        std::cin >> pass_eneterd;
            std::string const hashed_for_cin = sha_hash(salt_tab + pass_entered);
            txn.commit();
            con.close();
            if (hase_tab == hashed_for_cin) {
                std::cout << "You successfully logged in!\n";
                return true;
            } else {
                std::cout << "Uncorrect login or password! Try again:\n";
                return false;
            }
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
            return false;
        }
    }

    void DataBase_connector::insert_games(const std::string &client_login) {
        try {
            pqxx::connection con{connection_message};
            pqxx::work txn{con};
            txn.exec("UPDATE clients "
                     "SET client_games = client_games+1 "
                     "WHERE client_login = " + txn.quote(client_login));
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
        }
    }

    void DataBase_connector::insert_win(const std::string &client_login) {
        try {
            pqxx::connection con{connection_message};
            pqxx::work txn{con};
            txn.exec("UPDATE clients "
                     "SET client_wins = client_wins+1 "
                     "WHERE client_login = " + txn.quote(client_login));
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
        }
    }

    void DataBase_connector::update_balance(const std::string &client_login, const int &balance_delta) {
        try {
            pqxx::connection con{connection_message};
            pqxx::work txn{con};
            txn.exec_params("UPDATE clients "
                     "SET client_balance = client_balance + $1"
                     "WHERE client_login = $2", balance_delta, client_login);
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cout << e.what() << '\n';
        }
    }
}

