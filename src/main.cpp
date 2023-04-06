#include "server/Server.h"
#include "client/Client.h"
#include "../rename_later.h"

void clear_db() {
    try {
        pqxx::connection con{"postgres://postgres:stillloveher@localhost:5432/clients"};
        pqxx::work txn{con};
        txn.exec("DELETE FROM id_to_password");
        txn.exec("DELETE FROM clients");
        txn.commit();
        con.close();
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}


int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

    std::cout << "FINALLY\n";
//    server::Server s1;
    client::Client p1;
    client::Client p2;
    client::Client p3;
//    p1.login();
//    p2.login();
    data::DataBase_connector connect;
    std::cout << (connect.sha_hash("") == "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855");
//    p1.registeration();
//    p2.registeration();
//    clear_db();

}