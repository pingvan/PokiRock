#ifndef SERVER_H
#define SERVER_H

#include <queue>
#include <vector>
#include "../client/client.h"
#include "Game.h"

namespace server {

struct Server {
private:
    enum class message_type {LOGIN, REGISTRATION};

    boost::asio::io_context m_server_context;
    std::thread m_context_thread;
    boost::asio::ip::tcp::acceptor m_acceptor;

    std::queue<client::Client> players;
    std::vector<server::Game> games;
public:
    Server(int port_number);
    ~Server() {
        stop_server();
    }

    std::pair<std::string, std::string> get_salt_and_hash(std::string &client_nickname);

    void start_server();
    void stop_server();
    void waiting_client_connection();

    void add(const client::Client &client);
    void start_game();
};

}  // namespace Server
#endif  // SERVER_H
