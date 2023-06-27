#include "registration_window.h"
#include <QMessageBox>
#include <string>
#include "ui_Registration_window.h"
//#include "../server/DataBase_connector.h"
#include "window_manager.h"

registration_window::registration_window(WindowManager *manager_m, QWidget *parent)
    : QDialog(parent), manager(manager_m), ui(new Ui::registration_window) {
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    ui->password2->setEchoMode(QLineEdit::Password);
}

registration_window::~registration_window() {
    delete ui;
}

void registration_window::show_warning_of_different_passwords() {
    QMessageBox::warning(this, "Ошибка", "Пароли не совпадают");
}

void registration_window::show_success() {
    QMessageBox::information(
        this, "Успех", "Вы успешно зарегистрировались!"
    );
}

void registration_window::on_registration_clicked() {
    QString user_login = ui->name->text();
    QString user_password = ui->password->text();
    QString user_password2 = ui->password2->text();
    if (user_password != user_password2) {
        show_warning_of_different_passwords();
    } else {
        manager->this_client->registration(user_login.toStdString(), user_password.toStdString());
        show_success();
        manager->show_main_menu();
        this->close();
    }
}
