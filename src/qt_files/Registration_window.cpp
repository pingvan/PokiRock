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

void registration_window::on_pushButton_clicked()
{
    QString user_login = ui->name->text();
    QString user_password = ui->password->text();
    QString user_password2 = ui->password2->text();
    if (user_password != user_password2) {
        QMessageBox::warning(this, "", "Пароли не совпадают");
    } else {
//        data::DataBase_connector::insert_new_client(user_login.toStdString(), user_password.toStdString());
        second_window->show();
        close();
    }
}

