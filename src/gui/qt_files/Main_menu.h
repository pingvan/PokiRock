#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "game.h"
#include <QDialog>

namespace Ui {
class main_menu;
}

class main_menu : public QDialog
{
    Q_OBJECT

public:
    explicit main_menu(QWidget *parent = nullptr);
    ~main_menu();

private slots:
    void on_exit_clicked();

    void on_play_clicked();

private:
    Ui::main_menu *ui;
    game* game_window;
};

#endif // MAIN_MENU_H
