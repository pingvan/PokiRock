#ifndef DATABASE_CONNECTOR_H
#define DATABASE_CONNECTOR_H

#include "../rename_later.h"
//#include "../client/Client.h"

namespace data {

    struct DataBase_connector {
        std::string sha_hash(const std::string &phrase);

        static std::string generate_salt(int length);

        void insert_new_client(const std::string &client_login);

        bool log_in_client(const std::string &client_login, const std::string &pass_entered);
        void insert_games(const std::string &client_login);
        void insert_win(const std::string &client_login);
        void update_balance(const std::string &client_login);
    private:
        std::string connection_message = "postgres://postgres:stillloveher@localhost:5432/clients";
    };
}


#endif //DATABASE_CONNECTOR_H
