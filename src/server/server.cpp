#include "server.h"

namespace server {
    std::string server::receive_input() {
        std::string name;
        std::cin >> name;
        return name;
    }

    bool server::login() {
        std::string user_name = receive_input();
        if (data_base.find(user_name) != data_base.end()) {
            std::cout << "SUCCESSFUL LOGIN IN"; //here will be widget to swap to another window - gui - main_page
            return true;
        } else {
            std::cout << "UNCORRECT LOGIN OR USER NOT EXIST"; //back to login page and offer to registration

            return false;
        }
    }

    void server::registration() {
        std::string user_name = receive_input();
        if (data_base.find(user_name) == data_base.end()) {
            data_base.insert({user_name, client::client(user_name)});
            std::cout << "SUCCESSFUL REGISTRATION";   //gui - main_page
        } else {
            std::cout << "NAME ALREADY EXIST, PLEASE, CHOOSE ANOTHER NAME";
        }
    }
}