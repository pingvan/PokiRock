#include "Server.h"

int main() {
    server::Server new_server(291203);
    try {
        new_server.start_server();
    } catch(std::exception &e) {
        std::cerr << e.what() << '\n';
    }
}