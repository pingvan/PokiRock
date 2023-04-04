#include "server/server.h"
#include "client/client.h"

int main(){
    srand(time(nullptr));
    server::server S1;
    client::client p1;
    client::client p2;
    client::client p3;
    p2.login();
    p1.login();
    p3.login();
    p1.connect(S1);
    p2.connect(S1);
    p3.connect(S1);
    S1.start_game();
}