#include "registration_window.h"
#include <QMessageBox>
#include <string>
#include "ui_Registration_window.h"
//#include "../server/DataBase_connector.h"
#include "window_manager.h"

registration_window::registration_window(QWidget *parent, WindowManager* manager_m) :
    QDialog(parent), manager(manager_m),
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
    return name.empty() && password.empty();
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
            manager->setClient(user_login.toStdString());
            manager->show_main_menu();
        } else {
            QMessageBox::warning(this, "Ошибка", "Некорректное имя пользователя или пароль");
        }
    }
}

