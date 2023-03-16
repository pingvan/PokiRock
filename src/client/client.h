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
        bool operator<(const client & client) const{
            return nickname < client.nickname;
        }
        void callback_name(const std::string &name);
        std::string name() const;
        void connect(server::server &Server) const;
        std::string move(int balance) const;
        std::string optional_move() const;
    };

}

#endif //CLIENT_H
