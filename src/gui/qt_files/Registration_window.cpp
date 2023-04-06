#include "Registration_window.h"
#include "ui_Registration_window.h"
#include <QMessageBox>
#include <string>
#include "Authorization_window.h"

registration_window::registration_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration_window)
{
    ui->setupUi(this);
}

registration_window::~registration_window()
{
    delete ui;
}

//bool add_new_user(const std::string& login, const std::string& password){
//    return true;
//}

void registration_window::on_pushButton_clicked()
{
    QString user_login = ui->name->text();
    QString user_password = ui->password->text();
    QString user_password2 = ui->password2->text();

    if (user_password != user_password2) {
        QMessageBox::warning(this, "", "Пароли не совпадают");
    } else {
//        if (add_new_user(user_login.toStdString(), user_password.toStdString())){
//            ...
//        }
        second_window->show();
        close();
    }
}

