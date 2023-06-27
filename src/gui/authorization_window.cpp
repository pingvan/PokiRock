#include "authorization_window.h"
#include <QMessageBox>
#include "ui_Authorization_window.h"
#include "../server/DataBase_connector.h"
#include "window_manager.h"

authorization_window::authorization_window(
        WindowManager *manager_m, QWidget *parent
)
    : QDialog(parent), ui(new Ui::authorization_window), manager(manager_m) {
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
}

authorization_window::~authorization_window() {
    delete ui;
}

void authorization_window::on_authorizate_clicked() {
    QString user_login = ui->Login->text();
    QString user_password = ui->Password->text();
    if (this_client.login(user_login, user_password);) {
        manager->setClient(user_login.toStdString());
        manager->show_main_menu();
        this->close();
    } else {
        show_authorization_warning();
    }
}

void authorization_window::show_authorization_warning() {
    QMessageBox::warning(
        this, "Ошибка", "Некорректное имя пользователя или пароль"
    );
}

void authorization_window::on_registrate_clicked() {
    manager->show_registration_window();
}
