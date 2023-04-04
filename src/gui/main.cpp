#include "../client/Client.h"
#include "../server/Server.h"
#include <pqxx/pqxx>
//TODO::include graphic lib

int main(int argc, char* argv[]) {
    const std::string con_str = "postgres://postgres:stillloveher@localhost:5432/clients";
    pqxx::connection con{con_str};
    pqxx::work txn{con};
    txn.exec("INSERT INTO clients (client_id, client_login, client_games, client_wins, client_balance)"
             "VALUES ('1', 'admin', '0', '0', '1000000')"
             );
    txn.commit();
    return 0;
}