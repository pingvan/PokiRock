#include "DataBase_connector.h"
#include <future>
#include <pqxx/connection>

namespace data {

    void DataBase_connector::insert_new_client(const std::string &client_login, const std::string &salt, const std::string &hash) {
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
            txn.commit();
            con.close();
        } catch (std::exception &e) {
            std::cerr << e.what() << '\n';
        }
    }

    std::pair<std::string, std::string> DataBase_connector::log_in_client(const std::string &client_login) {
            pqxx::connection con{conn_msg()};
            pqxx::work txn{con};
            auto client_id = txn.query_value<uint32_t>("SELECT client_id "
                                                       "FROM clients "
                                                       "WHERE client_login =" + txn.quote(client_login));
            pqxx::result const row = txn.exec("SELECT password_hashe, password_salt "
                                                     "FROM id_to_password "
                                                     "WHERE client_id = " + txn.quote(client_id));
            std::string hase_tab;
            std::string salt_tab;
            for (auto r: row) {
                hase_tab = r[0].as<std::string>();
                salt_tab = r[1].as<std::string>();
            }
            txn.commit();
            con.close();
            return std::make_pair(hase_tab, salt_tab);
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

