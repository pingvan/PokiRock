#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include "../server/server.h"
#include <utility>
#include <vector>
namespace client {
    struct client;
    void receive_name(client& pl);
    struct client {
    private:
        std::string nickname;
    public:
        void login();
        void callback_name(std::string name);
        void connect(server::server Server);
    };

}

#endif //CLIENT_H
