#include "client.h"
#include "../server/server.h"

namespace client {

    void client::login() {
            std::cout << "Enter your name:\n";
            receive_name(*this);
    }
    void client::callback_name(const std::string &name) {
        nickname = name;
    }
    void receive_name(client& pl){
        std::string name;
        std::cin>>name;
        pl.callback_name(name);
    }

    void client::connect(server::server &Server) const {
        Server.add(*this);
    }

    std::string client::name() const{
        return nickname;
    }

    std::string client::move(int balance) const {
        std::cout << "Player " << nickname << " make your turn\n";
        std::cout << "Your balance is: " << balance << "\n";
        std::string move;
        std::cin >> move;
        return move;
    }

    std::string client::optional_move() const {
        std::cout << "Player " << nickname << " you may want to look over your cards\n";
        std::string move;
        std::cin >> move;
        return move;
    }
}