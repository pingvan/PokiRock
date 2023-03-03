#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <utility>
#include <vector>

namespace client {
    struct client {
        client(std::string user_name) : login(std::move(user_name)) {};
    private:
//        std::string nick_name;
        std::string login;
    };
}

#endif //CLIENT_H
