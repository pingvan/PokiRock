#include "main_menu.h"
#include "ui_Main_menu.h"
#include "window_manager.h"

main_menu::main_menu(WindowManager *manager_m, QWidget *parent)
    : QDialog(parent), ui(new Ui::main_menu), manager(manager_m) {
    ui->setupUi(this);

    setImage(ui->image, ":/other/images/garbage/better/pngegg (13).png");
    setImage(ui->user_icon, ":/other/images/other/user_icon.png");
    setImage(ui->user_icon, ":/boys/images/boys/dmitriy.png");
}

main_menu::~main_menu() {
    delete ui;
}

void main_menu::set_user_info() {
    ui->name->setText(manager->this_client->client_name.c_str());
    ui->balance->setText((std::to_string(manager->this_client->client_balance) + "k").c_str());
}

void main_menu::on_exit_clicked() {
    manager->game_exit();
}


void main_menu::on_play_clicked() {
    QMessageBox::information(this, "Подключение...", "Игра найдена!");
    manager->this_client->make_lobby_requests(client::SEARCH_GAME, ("Game of " + this_client->client_name), 4, 0, 0);
    manager->show_game_window();
    this->close();
}
