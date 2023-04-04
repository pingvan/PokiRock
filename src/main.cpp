#include "server/Server.h"
#include "client/Client.h"
#include <pqxx/pqxx>

int main(){
    const std::string con_str = "postgres://postgres:stillloveher@localhost:5432/clients";
    pqxx::connection con{con_str};
    server::Server s1;
    client::Client p1;
    client::Client p2;
    client::Client p3;
    p2.login();
    p1.login();
    p3.login();
    s1.add(p1);
    s1.add(p2);
    s1.add(p3);
//    p1.connect(S1);
//    p2.connect(S1);
//    p3.connect(S1);
    s1.start_game();
}