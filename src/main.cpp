#include <pqxx/pqxx>
#include <iostream>
//#include "client/client.h"
//#include "server/Server.h"

/*void clear_db() {
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
}*/

int main(/*[[maybe_unused]] int argc, [[maybe_unused]] char *argv[]*/) {
    /*server::Server s1;
    client::Client p1;
    client::Client p2;
    client::Client p3;
    p1.login_console();
    p2.login_console();
    p3.login_console();
    s1.add(p1);
    s1.add(p2);
    s1.add(p3);
    s1.start_game();*/

    std::string login;
    std::cin >> login;

    try {
        pqxx::connection con{
            "postgres://postgres:stillloveher@localhost:5432/clients"};
        pqxx::work txn{con};

        auto res = txn.exec_params("SELECT client_id "
                        "FROM clients "
                        "WHERE client_login = $1 ", login);

        std::cout << res.size() << '\n';
        txn.commit();
        con.close();
    } catch (pqxx::plpgsql_no_data_found &ee) {
        std::cerr << ee.what() << '\n';
        std::cerr << "NO DATA WITH THIS PARAMS" << '\n';
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}