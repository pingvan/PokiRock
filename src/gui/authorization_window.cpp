#include "authorization_window.h"
#include <QMessageBox>
#include "ui_Authorization_window.h"
//#include "../server/DataBase_connector.h"
#include "window_manager.h"

authorization_window::authorization_window(
    QWidget *parent,
    WindowManager *manager_m
)
    : QDialog(parent), ui(new Ui::authorization_window), manager(manager_m) {
    ui->setupUi(this);
    ui->Password->setEchoMode(QLineEdit::Password);
}

authorization_window::~authorization_window() {
    delete ui;
}

bool findUser(const std::string &login, const std::string &password) {
    // check user
    return !login.empty() && !password.empty();
}

void authorization_window::on_authorizate_clicked() {
    QString user_login = ui->Login->text();
    QString user_password = ui->Password->text();
    bool isUserCorrect =
        findUser(user_login.toStdString(), user_password.toStdString());
    if (isUserCorrect) {
        QMessageBox::information(
            this, "Добро пожаловать в PokiRock!", "Вы успешно авторизовались"
        );
        //        manager->user.setName(user_login.toStdString());
        manager->setClient(user_login.toStdString());
        //        manager->user.name = "asdfasdf";
        manager->show_main_menu();
    } else {
        QMessageBox::warning(
            this, "Ошибка", "Некорректное имя пользователя или пароль"
        );
    }
}

void authorization_window::on_registrate_clicked() {
    manager->show_registration_window();
}