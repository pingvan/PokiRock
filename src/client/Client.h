#ifndef CLIENT_H
#define CLIENT_H

#include "../rename_later.h"
#include "../server/DataBase_connector.h"

namespace server {
    struct Server;
}

namespace client {
struct Client {
private:
    std::string nickname{};
public:
void login();
void registeration();

bool operator<(const Client &client) const {
    return nickname < client.nickname;
}

void callback_name(const std::string &name);
std::string receive_name(Client &pl);
[[nodiscard]] std::string name() const;
[[nodiscard]] std::string move(int balance) const;
[[nodiscard]] std::string optional_move() const;
};

}  // namespace Client

#endif  // CLIENT_H
