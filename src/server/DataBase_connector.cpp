#include "DataBase_connector.h"
#include <future>
#include <random>
#include <openssl/sha.h>
#include <pqxx/connection>

namespace data {

    void DataBase_connector::get_client_info(const std::string &client_login, game::player_info *player_info) {
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            pqxx::result const row = txn.exec("SELECT client_id, client_games, client_wins, client_balance "
                                            "FROM clients "
                                            "WHERE client_login =" + txn.quote(client_login));
            for (auto r : row) {
                player_info->set_client_id(r[0].as<int>());
                player_info->set_client_games(r[1].as<int>());
                player_info->set_client_wins(r[2].as<int>());
                player_info->set_client_balance(r[3].as<int>());
            }
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    void DataBase_connector::insert_new_client(const std::string &client_login, const std::string &salt, const std::string &hash, game::player_info *player_info) {
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            txn.exec_params("INSERT INTO clients (client_login, client_games, client_wins, client_balance)"
                            "VALUES ($1, $2, $3, $4)", client_login, 0, 0, 1000);
            auto client_id = txn.query_value<uint32_t>("SELECT client_id "
                                                       "FROM clients "
                                                       "WHERE client_login =" + txn.quote(client_login));
            txn.exec_params("INSERT INTO id_to_password (client_id, password_hashe, password_salt)"
                            "VALUES ($1, $2, $3)", client_id, hash, salt);
            player_info->set_client_id(client_id);
            player_info->set_client_balance(1000);
            player_info->set_client_wins(0);
            player_info->set_client_games(0);
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    unsigned int DataBase_connector::get_client_id(const std::string &client_login) {
        pqxx::connection con{conn_msg()};
        pqxx::work txn{con};
        auto client_id = txn.query_value<uint32_t>(
            "SELECT client_id "
            "FROM clients "
            "WHERE client_login =" +
            txn.quote(client_login)
        );
        txn.commit();
        con.close();
        return client_id;
    }


    std::string data::DataBase_connector::get_salt(const std::string &client_login) {
        std::string salt = "";
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            auto client_id = txn.query_value<uint32_t>(
                "SELECT client_id "
                "FROM clients "
                "WHERE client_login =" +
                txn.quote(client_login)
            );
            pqxx::result const row = txn.exec(
                "SELECT password_salt "
                "FROM id_to_password "
                "WHERE client_id = " +
                txn.quote(client_id)
            );
            for (auto r : row) {
                salt = r[0].as<std::string>();
            }
            txn.commit();
            con.close();
            return salt;
        } catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    void data::DataBase_connector::get_salt(const std::string &client_login, game::login_response_first *login_response_first, game::status_message *status_message) {
        pqxx::connection con{conn_msg()};
        pqxx::work txn{con};
        auto client_id = txn.query_value<uint32_t>(
            "SELECT client_id "
            "FROM clients "
            "WHERE client_login =" +
            txn.quote(client_login)
        );
        pqxx::result const row = txn.exec(
            "SELECT password_salt "
            "FROM id_to_password "
            "WHERE client_id = " +
            txn.quote(client_id)
        );
        if (row.empty()) {
            status_message->set_status(false);
            status_message->set_message("NO CLIENT WITH THIS NAME");
        }
        std::string salt;
        for (auto r : row) {
            salt = r[0].as<std::string>();
        }
        login_response_first->set_salt(salt);
    }


    std::string data::DataBase_connector::get_hash(const std::string &client_login) {
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            auto client_id = txn.query_value<uint32_t>(
                "SELECT client_id "
                "FROM clients "
                "WHERE client_login =" +
                txn.quote(client_login)
            );
            pqxx::result const row = txn.exec(
                "SELECT password_hashe "
                "FROM id_to_password "
                "WHERE client_id = " +
                txn.quote(client_id)
            );
            std::string hash;
            for (auto r : row) {
                hash = r[0].as<std::string>();
            }
            txn.commit();
            con.close();
            return hash;
        } catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    std::pair<std::string, std::string> DataBase_connector::log_in_client(const std::string &client_login) {
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            auto client_id = txn.query_value<uint32_t>(
                "SELECT client_id "
                "FROM clients "
                "WHERE client_login =" +
                txn.quote(client_login)
            );
            pqxx::result const row = txn.exec(
                "SELECT password_hashe, password_salt "
                "FROM id_to_password "
                "WHERE client_id = " +
                txn.quote(client_id)
            );
            std::string hase_tab;
            std::string salt_tab;
            for (auto r : row) {
                hase_tab = r[0].as<std::string>();
                salt_tab = r[1].as<std::string>();
            }
            txn.commit();
            con.close();
            return std::make_pair(hase_tab, salt_tab);
        } catch(std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    void DataBase_connector::insert_games(const std::string &client_login) {
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            txn.exec("UPDATE clients "
                     "SET client_games = client_games+1 "
                     "WHERE client_login = " + txn.quote(client_login));
            txn.commit();
            con.close();
        }
        catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    void DataBase_connector::insert_win(const std::string &client_login) {
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            txn.exec("UPDATE clients "
                     "SET client_wins = client_wins+1 "
                     "WHERE client_login = " + txn.quote(client_login));
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    void DataBase_connector::update_balance(const std::string &client_login, const int &balance_delta) {
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            txn.exec_params("UPDATE clients "
                     "SET client_balance = client_balance + $1 "
                     "WHERE client_login = $2 ", balance_delta, client_login);
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    bool DataBase_connector::check_login_correctness(const std::string &client_login) {
        bool already_registered = false;
        try {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};

            auto result = txn.exec_params("SELECT client_id "
                "FROM clients "
                "WHERE client_login = $1 ", client_login);

            if (!result.empty()) {already_registered = true;}

            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
        return already_registered;
    }
}

    std::string data::DataBase_connector::sha_hash(const std::string &phrase) {
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

    std::string data::DataBase_connector::generate_salt(int length) {
        static const std::string symbols = {
            "0123456789!@#$%^&*"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(
            5, static_cast<int>(symbols.size())
        );
        std::stringstream random_symbols;
        for (int i = 0; i < length; i++) {
            random_symbols << symbols[distrib(gen)];
        }
        return random_symbols.str();
    }

