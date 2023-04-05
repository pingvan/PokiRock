#include "Client.h"

namespace client {

    void Client::login() {
        std::cout << "Enter your name:\n";
        std::string log = receive_name(*this);
        data::DataBase_connector connect;
        std::string n;
        std::cin >> n;
        if (!connect.log_in_client(log, n)) {
            login();
        }
    }

    void Client::registeration() {
        std::cout << "Enter your name:\n";
        std::string login = receive_name(*this);
        data::DataBase_connector connect;
        connect.insert_new_client(login);
    }

    void Client::callback_name(const std::string &name) {
        nickname = name;
    }

    std::string Client::receive_name(Client &pl) {
        std::string name;
        std::cin >> name;
        pl.callback_name(name);
        return name;
    }

    std::string Client::name() const {
        return nickname;
    }

    std::string Client::move(int balance) const {
        std::cout << "Player " << nickname << " make your turn\n";
        std::cout << "Your balance is: " << balance << "\n";
        std::string move;
        std::cin >> move;
        return move;
    }

    std::string Client::optional_move() const {
        std::cout << "Player " << nickname << " you may want to look over your cards\n";
        std::string move;
        std::cin >> move;
        return move;
    }
}