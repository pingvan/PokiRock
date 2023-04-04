#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <utility>
#include <vector>
#include <iostream>

namespace server {
    struct Server;
}

namespace client {
struct Client {
private:
    std::string nickname{};

public:
    void login();

    bool operator<(const Client &client) const {
        return nickname < client.nickname;
    }

    void callback_name(const std::string &name);
    void receive_name(Client &pl);
    [[nodiscard]] std::string name() const;
//    void connect(server::Server &server) const;
    [[nodiscard]] std::string move(int balance) const;
    [[nodiscard]] std::string optional_move() const;
};

}  // namespace Client

#endif  // CLIENT_H
