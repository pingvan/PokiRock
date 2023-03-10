#include "client.h"
#include "../server/server.h"

namespace client {
    void client::login() {
            std::cout << "Enter your name:";
            receive_name(*this);
    }
    void client::callback_name(std::string name) {
        nickname = name;
    }
    void receive_name(client& pl){
        std::string name;
        std::cin>>name;
        pl.callback_name(name);
    }

    void client::connect(server::server Server) {
        Server.add(*this);
    }
}