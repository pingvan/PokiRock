#include "server/server.h"
#include "client/client.h"

int main(){
    srand(time(nullptr));
    client::client p1;
    client::client p2;
    p2.login();
    p1.login();
    server::server S1;
    p1.connect(S1);
    p2.connect(S1);
    S1.start_game();
}