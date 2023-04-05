#include "server/Server.h"
#include "client/Client.h"
#include "../rename_later.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {

    server::Server s1;
    client::Client p1;
    client::Client p2;
    client::Client p3;
    p1.login();

}