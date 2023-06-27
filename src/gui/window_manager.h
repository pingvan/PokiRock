#ifndef POKIROCK_WINDOW_MANAGER_H
#define POKIROCK_WINDOW_MANAGER_H

#include "first_window.h"
#include "authorization_window.h"
#include "game.h"
#include "main_menu.h"
#include "registration_window.h"
#include "user.hpp"
#include "stickers_collection.h"
#include "../client/grpc_client.hpp"

using FirstWindow = first_window;
using AuthorizationWindow = authorization_window;
using RegistrationWindow = registration_window;
using MainMenu = main_menu;
using Game = game;

inline void setImage(QLabel* image, const std::string& path_to_image) {
    QPixmap img(path_to_image.c_str());
    int width = image->width();
    int height = image->height();
    image->setPixmap(img.scaled(width, height, Qt::KeepAspectRatio));
}

class WindowManager {
    FirstWindow* firstWindow_var = nullptr;
    AuthorizationWindow* authorizationWindow_var = nullptr;
    MainMenu* mainMenu_var = nullptr;
    RegistrationWindow* registrationWindow_var = nullptr;
    Game* gameWindow_var = nullptr;
    StickersCollection* stickers_var = nullptr;
    friend StickersCollection;
    friend MainMenu;
    friend Game;
    client* this_client;
public:
    WindowManager() : firstWindow_var(new FirstWindow(this)) {};

    void start() {
        firstWindow_var->showFullScreen();
        if (!authorizationWindow_var) authorizationWindow_var = new AuthorizationWindow(this);
    }

    WindowManager(const WindowManager& other) = delete;
    WindowManager(WindowManager&& other) noexcept = default;
    WindowManager &operator=(const WindowManager&) = delete;
    WindowManager &operator=(WindowManager&&) noexcept = default;

    void show_authorization_window() {
        if (!mainMenu_var) mainMenu_var = new MainMenu(this);

        if (authorizationWindow_var->isVisible()){
            authorizationWindow_var->hide();
        } else {
            authorizationWindow_var->show();
        }
    }

    void show_registration_window() {
        if (!registrationWindow_var) registrationWindow_var = new RegistrationWindow(this);
        authorizationWindow_var->close();
        registrationWindow_var->show();
    }

    void show_main_menu() {
        if (!mainMenu_var)
            mainMenu_var = new MainMenu(this);
        mainMenu_var->set_user_info();
        firstWindow_var->close();
        authorizationWindow_var->close();
        mainMenu_var->showFullScreen();
    }

    void show_game_window() {
        if (!gameWindow_var)
            gameWindow_var = new Game(this);
        mainMenu_var->close();
        gameWindow_var->showFullScreen();
    }

    void show_stickers() {
        if (!stickers_var)
            stickers_var = new StickersCollection(this);
        if (stickers_var->isVisible()){
            stickers_var->hide();
        } else {
            stickers_var->show();
        }
    }

    ~WindowManager() {
        delete this_client;
        delete firstWindow_var;
        delete authorizationWindow_var;
        delete registrationWindow_var;
        delete mainMenu_var;
        delete gameWindow_var;
        delete stickers_var;
    };

    static void game_exit() {
        exit(0);
    }
};
#endif  // POKIROCK_WINDOW_MANAGER_H
