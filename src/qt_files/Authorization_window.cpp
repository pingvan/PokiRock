#include "Authorization_window.h"
#include "ui_Authorization_window.h"
#include <QMessageBox>

authorization_window::authorization_window(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::authorization_window) {
    ui->setupUi(this);

}

authorization_window::~authorization_window() {
    delete ui;
}

void authorization_window::on_pushButton_clicked() {

    QString user_login = ui->Login->text();
    QString user_password = ui->Password->text();
    data::DataBase_connector connect;
    if (connect.log_in_client(user_login.toStdString(), user_password.toStdString())) {
        hide();
        QMessageBox::information(this, "Добро пожаловать, ...", "Вы успешно авторизовались!");
        main_window = new main_menu(this);
        main_window->showFullScreen();
//        authorization_window::~authorization_window();
    } else {
        ui->Login->clear();
        ui->Password->clear();
        QMessageBox::warning(this, "Некорректное имя пользователя или пароль", "Вероятна очепятка");
    }
}

