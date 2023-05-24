#include "main_menu.h"
#include "ui_Main_menu.h"
#include "window_manager.h"

main_menu::main_menu(QWidget *parent, WindowManager *manager_m)
    : QDialog(parent), ui(new Ui::main_menu), manager(manager_m) {
    ui->setupUi(this);


    setImage(ui->image, ":/other/images/garbage/better/pngegg (13).png");
    setImage(ui->user_icon, ":/other/images/other/user_icon.png");


    ui->name->setText(manager->user->get_name().c_str());
    ui->balance->setText(std::to_string(manager->user->get_balance()).c_str());
}

main_menu::~main_menu() {
    delete ui;
}

void main_menu::on_exit_clicked() {
    manager->game_exit();
}

void main_menu::on_play_clicked() {
    QMessageBox::information(this, "Подключение...", "Игра найдена!");
    manager->show_game_window();
}
