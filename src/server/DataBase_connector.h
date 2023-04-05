#ifndef DATABASE_CONNECTOR_H
#define DATABASE_CONNECTOR_H

#include "../rename_later.h"
//#include "../client/Client.h"

struct DataBase_connector {
    std::string sha_hash(const std::string &phrase);
    static std::string generate_salt(int length);
    void insert_new_client(const std::string &name);


private:
    const std::string connection_message = "postgres://postgres:stillloveher@localhost:5432/clients";
    static std::unordered_set<uint32_t> client_ids;
};


#endif //DATABASE_CONNECTOR_H
