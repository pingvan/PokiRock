#ifndef POKIROCK_WINDOW_MANAGER_H
#define POKIROCK_WINDOW_MANAGER_H

#include "First_window.h"
#include "Authorization_window.h"
#include "Registration_window.h"
#include "Main_menu.h"
#include "game.h"
#include "user.h"
#include <memory>

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
    WindowManager() : startWindow(nullptr, this), authorizationWindow(&startWindow, this), registrationWindow(&authorizationWindow, this), mainMenu(&authorizationWindow, this), gameWindow(&mainMenu, this){};

    void start() {
        startWindow.showFullScreen();
    }

    void show_authorization_window() {
        authorizationWindow.show();
    }

    void show_registration_window() {
        authorizationWindow.hide();
//        registrationWindow = new registration_window(&authorizationWindow, this);
        registrationWindow.show();
    }

    void show_main_menu() {
//        mainMenu = new main_menu(&authorizationWindow, this);
        startWindow.close();
        authorizationWindow.close();
        mainMenu.showFullScreen();
    }

    void show_game_window() {
        mainMenu.close();
//        gameWindow = new game(mainMenu, this);
        gameWindow.showFullScreen();
    }
//    ~WindowManager() {
//        delete registrationWindow;
//        gameWindow.~game();
//        delete gameWindow;
//    }
    void game_exit() {
//        this->~WindowManager();
        exit(0);
    }
};
#endif  // POKIROCK_WINDOW_MANAGER_H
