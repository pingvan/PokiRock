#ifndef POKIROCK_WINDOW_MANAGER_H
#define POKIROCK_WINDOW_MANAGER_H
#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"

#include "first_window.h"
#include "authorization_window.h"
#include "game.h"
#include "main_menu.h"
#include "registration_window.h"
#include "user.hpp"
#include "stickers_collection.h"

inline void setImage(QLabel* image, const std::string& path_to_image) {
    QPixmap img(path_to_image.c_str());
    int width = image->width();
    int height = image->height();
    image->setPixmap(img.scaled(width, height, Qt::KeepAspectRatio));
}

class WindowManager {
    first_window* startWindow = nullptr;
    authorization_window* authorizationWindow = nullptr;
    main_menu* mainMenu = nullptr;
    registration_window* registrationWindow = nullptr;
    game* gameWindow = nullptr;
    StickersCollection* stickers = nullptr;
    friend StickersCollection;
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
        if (!authorizationWindow)
            authorizationWindow = new authorization_window(nullptr, this);
        authorizationWindow->show();
    }

    void show_registration_window() {
        if (!registrationWindow)
            registrationWindow = new registration_window(nullptr, this);
        authorizationWindow->close();
        registrationWindow->show();
    }

    void show_main_menu() {
        if (!mainMenu)
            mainMenu = new main_menu(nullptr, this);
        startWindow->close();
        authorizationWindow->close();
        mainMenu->showFullScreen();
    }

    void show_game_window() {
        if (!gameWindow)
            gameWindow = new game(nullptr, this);
        mainMenu->close();
        gameWindow->showFullScreen();
    }

    void show_stickers() {
        if (!stickers)
            stickers = new StickersCollection(nullptr, this);
        stickers->hide();
        stickers->show();
    }

    ~WindowManager() {
        delete user;
        delete startWindow;
        delete authorizationWindow;
        delete registrationWindow;
        delete mainMenu;
        delete gameWindow;
        delete stickers;
    };

    static void game_exit() {
        exit(0);
    }
};
#endif  // POKIROCK_WINDOW_MANAGER_H

#pragma clang diagnostic pop
