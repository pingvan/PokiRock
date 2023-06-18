#include "Authorization_window.h"
#include "First_window.h"
#include "ui_Authorization_window.h"
#include "../server/DataBase_connector.h"
#include <QMessageBox>

authorization_window::authorization_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorization_window)
{
    ui->setupUi(this);
}

authorization_window::~authorization_window()
{
    delete ui;
}

void authorization_window::on_authorizate_clicked()
{
    QString user_login = ui->Login->text();
    QString user_password = ui->Password->text();

    if (){
        QMessageBox::information(this, "Добро пожаловать в PokiRock!", "Вы успешно авторизовались");
        start_window->close();
        close();
        main_window = new main_menu(this);
        main_window->showFullScreen();
    } else {
        QMessageBox::warning(this, "Некорректное имя пользователя или пароль", "Вероятна очепятка");
    }
}

void authorization_window::on_registrate_clicked()
{
    hide();
    registration = new registration_window(this);
    registration->second_window = this;
    registration->show();
}

