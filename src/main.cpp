#include "server/Server.h"
#include "client/Client.h"

int main(){
    server::Server S1;
    client::Client p1;
    client::Client p2;
    client::Client p3;
    p2.login();
    p1.login();
    p3.login();
    p1.connect(S1);
    p2.connect(S1);
    p3.connect(S1);
    S1.start_game();
}