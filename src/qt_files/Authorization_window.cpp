#include "Authorization_window.h"
#include "First_window.h"
#include "ui_Authorization_window.h"
//#include "../server/DataBase_connector.h"
#include <QMessageBox>

authorization_window::authorization_window(QWidget *parent) :
    QDialog(parent), ui(new Ui::authorization_window)
{
    ui->setupUi(this);
    registration = new registration_window(this);
    registration->second_window = this;
    ui->Password->setEchoMode(QLineEdit::Password);
}

authorization_window::~authorization_window()
{
    delete ui;
}

bool findUser(const std::string& login, const std::string& password)
{
    //check user
    return true;
}

void authorization_window::on_authorizate_clicked()
{
    QString user_login = ui->Login->text();
    QString user_password = ui->Password->text();
    bool isUserCorrect = findUser(user_login.toStdString(), user_password.toStdString());
    if (isUserCorrect) {
        QMessageBox::information(this, "Добро пожаловать в PokiRock!", "Вы успешно авторизовались");
        main_window = new main_menu(this, User(user_login.toStdString()));
        start_window->close();
        this->close();
        main_window->showFullScreen();
    } else {
        QMessageBox::warning(this, "Ошибка", "Некорректное имя пользователя или пароль");
    }
}

void authorization_window::on_registrate_clicked()
{
    hide();
    registration->show();
}

