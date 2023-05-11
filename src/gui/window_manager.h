#ifndef POKIROCK_WINDOW_MANAGER_H
#define POKIROCK_WINDOW_MANAGER_H

#include <memory>
#include "authorization_window.h"
#include "first_window.h"
#include "game.h"
#include "main_menu.h"
#include "registration_window.h"
#include "user.hpp"

class WindowManager {
    first_window startWindow;
    authorization_window authorizationWindow;
    main_menu mainMenu;
    registration_window registrationWindow;
    game gameWindow;
public:
    User user;
    void setClient(const std::string& name) {
        user = User(name);
    }
    WindowManager() : startWindow(nullptr, this), authorizationWindow(nullptr, this), registrationWindow(nullptr, this), mainMenu(nullptr, this), gameWindow(nullptr, this){};

    void start() {
        startWindow.showFullScreen();
    }

    void show_authorization_window() {
        authorizationWindow.show();
    }

    void show_registration_window() {
        authorizationWindow.hide();
        registrationWindow.show();
    }

    void show_main_menu() {
        startWindow.close();
        authorizationWindow.close();
        mainMenu.showFullScreen();
    }

    void show_game_window() {
        mainMenu.close();
        gameWindow.showFullScreen();
    }
    void game_exit() {
//        this->~WindowManager();
        exit(0);
    }
};
#endif  // POKIROCK_WINDOW_MANAGER_H
