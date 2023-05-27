//#include "../client/Client.h"
//#include "../server/Server.h"
#include <iostream>
#include <pqxx/pqxx>

int main([[maybe_unused]]  int argc, [[maybe_unused]] char* argv[]) {
    [[maybe_unused]] const std::string con_str = "postgres://postgres:stillloveher@localhost:5432/clients";
    pqxx::connection con{"postgres://postgres:stillloveher@localhost:5432/clients"};
    pqxx::work txn{con};
     std::cout << con.username();
    txn.exec("INSERT INTO clients (client_id, client_login, client_games, client_wins, client_balance)"
             "VALUES ('2', 'Player', '0', '0', '1000000')"
             );
//    txn.commit();
    return 0;
}