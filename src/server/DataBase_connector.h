#pragma once

#include <pqxx/pqxx>
#include <pqxx/connection>

#include <string>
#include <iostream>

#include "../proto/game.pb.h"

namespace data {

    struct DataBase_connector {

        static std::string sha_hash(const std::string &phrase);

        static std::string generate_salt(int length);

        static bool check_login_correctness(const std::string &client_login);

        static void get_client_info(const std::string &client_login, game::player_info *player_info);
        static void insert_new_client(const std::string &client_login, const std::string &salt, const std::string &hash, game::player_info *player_info);
        static std::pair<std::string, std::string> log_in_client(const std::string &client_login);

        static unsigned int get_client_id(const std::string &client_login);

        static std::string get_salt(const std::string &client_login);
        static std::string get_hash(const std::string &client_login);

        static void get_salt(const std::string &client_login, game::login_response_first *login_response_first, game::status_message *status_message);
//        static void get_hash(game::LoginResponseFirst *LoginResponseFirst, game::StatusMessage *StatusMessage);

        static void insert_games(const std::string &client_login);
        static void insert_win(const std::string &client_login);
        static void update_balance(const std::string &client_login, const int &balance_delta);
    private:
        //const std::string connection_message = "postgres://postgres:stillloveher@localhost:5432/clients";
        //mutable std::mutex m_data_mutex; ??????????????????
        static std::string& conn_msg() {
            static std::string mm = "postgres://postgres:stillloveher@localhost:5432/clients";
            return mm;
        }
    };
}