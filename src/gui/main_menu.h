#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <QDialog>
#include <QIcon>
#include <QMessageBox>
#include <QPixmap>
#include <QString>
#include <string>

namespace Ui {
class main_menu;
}

class WindowManager;

class main_menu : public QDialog {
    Q_OBJECT

public:
    main_menu(WindowManager* manager_m, QWidget *parent = nullptr);
    ~main_menu();

private slots:
    void on_exit_clicked();

    void on_play_clicked();

private:
    Ui::main_menu *ui;
    WindowManager *manager;
};

#endif  // MAIN_MENU_H
