#include "Client.h"

namespace client {

    void Client::login_ONLY_TESTING() {
        std::cout << "Enter your name:\n";
        auto log = receive_name(*this);
        std::cout << "Enter password:\n";
        std::string n;
        std::cin >> n;
        if (!data::DataBase_connector::log_in_client(log, n)) {
            login_ONLY_TESTING();
        }
        callback_name(log);
    }

    void Client::registration_ONLY_TESTING() {
        std::cout << "Enter your name:\n";
        std::string const login = receive_name(*this);
//        data::DataBase_connector connect;
        std::string pass;
        std::string pass_repeated;
        bool completed = false;
        while (!completed) {
            std::cout << "Create password:\n";
            std::cin >> pass;
            std::cout << "Repeate your password:\n";
            std::cin >> pass_repeated;
            if (pass == pass_repeated) {
                completed = true;
            }
        }
        data::DataBase_connector::insert_new_client(login, pass);
        std::cout << "You successfully registered!\n";
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


    //above here only testing methods (for console)
    int Client::get_balance() const {
        return balance;
    }

    std::string Client::name() const {
        return nickname;
    }

    std::string Client::move(int balance_a) const {
        std::cout << "Player " << nickname << " make your turn\n";
        std::cout << "Your balance is: " << balance_a << "\n";
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