#ifndef CLIENT_H
#define CLIENT_H

#include "../server/DataBase_connector.h"
#include <string>
#include <boost/asio.hpp>

namespace client {
struct Client {
private:
    std::string nickname;
    int balance = 0;
    int client_id = 0;
    boost::asio::io_context m_context;
    boost::asio::ip::tcp::socket m_socket;
    std::thread m_context_thread;
public:
    Client();

    friend struct ClientHash;

    void login_console();
    void registration_console();

    bool operator<(const Client &client) const {
        return nickname < client.nickname;
    }

    void login_with_graphic(std::string &nickname_received, std::string &password);
    void registration_with_graphic(std::string &nickname_received, std::string &password);

    void callback_name(const std::string &name);

    void client_try_to_connect(); //TODO


    [[nodiscard]] int get_balance() const;
    std::string receive_name(Client &pl);

    [[nodiscard]] std::string name() const;

    [[nodiscard]] std::string move(int balance) const;

    [[nodiscard]] std::string optional_move() const;

    bool operator==(const Client &other) const {
        return balance == other.balance && nickname == other.nickname;
    }

//    ~Client() = default;
};

struct ClientHash {
    std::size_t operator()(const Client &obj) const {
        std::size_t const h1 = std::hash<std::string>()(obj.nickname);
        std::size_t const h2 = std::hash<int>()(obj.balance);
        return h1 ^ (h2 << 1);
    }
};

}  // namespace client

#endif  // CLIENT_H
