#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <utility>
#include <vector>
#include "../server/server.h"

namespace client {
struct client;
void receive_name(client &pl);

struct client {
private:
    std::string nickname;

public:
    void login();

    bool operator<(const client &client) const {
        return nickname < client.nickname;
    }

    void callback_name(const std::string &name);
    [[nodiscard]] std::string name() const;
//    void connect(server::server &Server) const;
    [[nodiscard]] std::string move(int balance) const;
    [[nodiscard]] std::string optional_move() const;
};

}  // namespace client

#endif  // CLIENT_H
