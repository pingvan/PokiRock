#ifndef CLIENT_H
#define CLIENT_H

#include "../sources.h"
#include "../server/DataBase_connector.h"

namespace server {
    struct Server;
}

namespace client {
    struct Client {
    private:
        std::string nickname;
        int balance;
    public:
        friend struct ClientHash;
        void login_ONLY_TESTING();

        void registration_ONLY_TESTING();

        bool operator<(const Client &client) const {
            return nickname < client.nickname;
        }

        void callback_name(const std::string &name);
        [[nodiscard]] int get_balance() const;
        std::string receive_name(Client &pl);

        [[nodiscard]] std::string name() const;

        [[nodiscard]] std::string move(int balance) const;

        [[nodiscard]] std::string optional_move() const;

        bool operator==(const Client& other) const {
            return balance == other.balance && nickname == other.nickname;
        }

//        std::size_t operator()(const Client& obj) const {
//            std::size_t const h1 = std::hash<std::string>()(obj.nickname);
//            std::size_t const h2 = std::hash<int>()(obj.balance);
//            return h1 ^ (h2 << 1);
//        }
    };

}  // namespace Client

#endif  // CLIENT_H
