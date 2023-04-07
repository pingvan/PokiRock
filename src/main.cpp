#include "../sources.h"
#include "client/Client.h"
#include "server/Server.h"

void clear_db() {
    try {
        pqxx::connection con{
            "postgres://postgres:stillloveher@localhost:5432/clients"};
        pqxx::work txn{con};
        txn.exec("DELETE FROM id_to_password");
        txn.exec("DELETE FROM clients");
        txn.commit();
        con.close();
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}

int main(/*[[maybe_unused]] int argc, [[maybe_unused]] char *argv[]*/) {
    server::Server s1;
    client::Client p1;
    client::Client p2;
    client::Client p3;
    p1.login_ONLY_TESTING();
    p2.login_ONLY_TESTING();
    p3.login_ONLY_TESTING();
    s1.add(p1);
    s1.add(p2);
    s1.add(p3);
    s1.start_game();
}