#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
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
    first_window* startWindow = nullptr;
    authorization_window* authorizationWindow = nullptr;
    main_menu* mainMenu = nullptr;
    registration_window* registrationWindow = nullptr;
    game* gameWindow = nullptr;
public:
    User* user; // NOLINT(cppcoreguidelines-non-private-member-variables-in-classes,misc-non-private-member-variables-in-classes)

    void setClient(const std::string& name) const {
        user->setData(name, 1000);
    }

    WindowManager() : startWindow(new first_window(nullptr, this)), user(new User()) {};

    void start() {
        startWindow->showFullScreen();
    }
    WindowManager(const WindowManager& other) = delete;
    WindowManager(WindowManager&& other) = delete;
    WindowManager operator=(const WindowManager&) = delete;
    WindowManager operator=(WindowManager&&) = delete;

    void show_authorization_window() {
        authorizationWindow = new authorization_window(nullptr, this);
        authorizationWindow->show();
    }

    void show_registration_window() {
        registrationWindow = new registration_window(nullptr, this);
        authorizationWindow->close();
        registrationWindow->show();
    }

    void show_main_menu() {
        mainMenu = new main_menu(nullptr, this);
        startWindow->close();
        authorizationWindow->close();
        mainMenu->showFullScreen();
    }

    void show_game_window() {
        gameWindow = new game(nullptr, this);
        mainMenu->close();
        gameWindow->showFullScreen();
    }

    ~WindowManager() {
        delete user;
        delete startWindow;
        delete authorizationWindow;
        delete registrationWindow;
        delete mainMenu;
        delete gameWindow;
    };

    static void game_exit() {
        exit(0);
    }
};
#endif  // POKIROCK_WINDOW_MANAGER_H

#pragma clang diagnostic pop