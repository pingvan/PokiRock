#include "Server.h"

namespace server {

Server::Server(int port_number)
    : m_acceptor(
          m_server_context,
          boost::asio::ip::tcp::endpoint(
              boost::asio::ip::tcp::v4(),
              static_cast<unsigned short>(port_number)
          )
      ) {
}

std::pair<std::string, std::string> Server::get_salt_and_hash(std::string &client_nickname) {
    try {
        auto hash_salt = data::DataBase_connector::log_in_client(client_nickname);
        //not return -- send
        return hash_salt;
    } catch(pqxx::unexpected_rows &e) {
        std::cerr << e.what() << '\n';
        return {"", ""};
    }
}

void Server::add(const client::Client &client) {
    players.push(client);
}

void Server::start_game() {
    std::vector<client::Client> lobby;
    for (int i = 0; i < 5; i++) {
        if (!players.empty()) {
            auto player = (players.front());
            players.pop();
            lobby.emplace_back(player);
        }
    }
    games.emplace_back(lobby);
    auto &our_game = games.back();
    our_game.preflop();
}

void Server::waiting_client_connection() {
    m_acceptor.async_accept(
        [this](std::error_code &e, boost::asio::ip::tcp::socket socket) {
            if (!e) {

            } else {
                std::cerr << e.message();
            }
            waiting_client_connection();
        }
    );
}

}  // namespace server
