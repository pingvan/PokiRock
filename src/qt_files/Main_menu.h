#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "game.h"
#include "user.h"
#include <QDialog>
#include <QPixmap>
#include <string>
#include <QIcon>
#include <QString>
#include <QMessageBox>


namespace Ui {
class main_menu;
}

class main_menu : public QDialog
{
    Q_OBJECT

public:
    main_menu(QWidget *parent = nullptr, User person = User());
    User user;
    ~main_menu();

private slots:
    void on_exit_clicked();

    void on_play_clicked();

private:
    Ui::main_menu *ui;
    game* game_window;

};

#endif // MAIN_MENU_H
