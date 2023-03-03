#ifndef SERVER_H
#define SERVER_H

#include "../client/client.h"
#include <string>
#include <iostream>
//#include <unordered_map> //I hope it will be DB in next versions
#include <map>

namespace server {
    struct server{
        static std::string receive_input();

        void registration();

        bool login();
    private:
        std::map<std::string, client::client> data_base; //here will be client elements instead of int
    };

    struct room {

    private:
        int needed_players;
        int cnt_of_current_players;
        std::vector<client::client> current_players;
    };

    struct game {
        //here will be menu with game rooms (and maybe game variants)
        std::vector<room> game_rooms;
    };



}

#endif //SERVER_H
