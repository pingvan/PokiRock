#include "server/Server.h"
#include "client/Client.h"
#include "../rename_later.h"

void clear_db() {
    try {
        pqxx::connection con{"postgres://postgres:stillloveher@localhost:5432/clients"};
        pqxx::work txn{con};
        txn.exec("DELETE FROM clients");
        txn.exec("DELETE FROM id_to_password");
        txn.commit();
        con.close();
    } catch (std::exception &e) {
        std::cout << e.what() << '\n';
    }
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

    server::Server s1;
    client::Client p1;
    client::Client p2;
    client::Client p3;
    p1.registeration();
    p2.registeration();
//    clear_db();

}