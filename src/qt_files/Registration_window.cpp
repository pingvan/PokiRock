#include "Registration_window.h"
#include "ui_Registration_window.h"
//#include "../server/DataBase_connector.h"
#include <QMessageBox>
#include <string>
#include "Authorization_window.h"

registration_window::registration_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration_window)
{
    ui->setupUi(this);
    ui->password->setEchoMode(QLineEdit::Password);
    ui->password2->setEchoMode(QLineEdit::Password);
}

registration_window::~registration_window()
{
    delete ui;
}

bool addUser(const std::string& name, const std::string& password) {
    //add user
    return true;
}

void registration_window::on_registration_clicked()
{
    QString user_login = ui->name->text();
    QString user_password = ui->password->text();
    QString user_password2 = ui->password2->text();
    if (user_password != user_password2) {
        QMessageBox::warning(this, "Ошибка", "Пароли не совпадают");
    } else {
        bool isUserCorrect = addUser(user_login.toStdString(), user_password.toStdString());
        if (isUserCorrect) {
            QMessageBox::information(this, "Успех", "Вы успешно зарегистрировались!");
            second_window->show();
            close();
        } else {
            QMessageBox::warning(this, "Ошибка", "Некорректное имя пользователя или пароль");
        }
    }
}

