#include "server/server.h"
#include "client/client.h"

int main(){
    client::client p1;
    p1.login();
    server::server S1;
    p1.connect(S1);

}