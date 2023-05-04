#include "Main_menu.h"
#include "ui_Main_menu.h"

main_menu::main_menu(QWidget *parent, User person) :
    QDialog(parent), user(person),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);
    QPixmap image("D:/PokiRock/src/qt_files/images/garbage/better/pngegg (40)");
    int width = ui->image->width();
    int height = ui->image->height();
    ui->image->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap user_icon(":/other/images/other/user_icon.png");
    int width_2 = ui->user_icon->width();
    int height_2 = ui->user_icon->height();
    ui->user_icon->setPixmap(user_icon.scaled(width_2, height_2, Qt::KeepAspectRatio));

    QPixmap cards("D:/PokiRock/src/qt_files/images/garbage/better/pngegg (15)");
    int width_3 = ui->right->width();
    int height_3 = ui->right->height();
    ui->right->setPixmap(cards.scaled(width_3, height_3, Qt::KeepAspectRatio));

    ui->name->setText(user.name.c_str());
    ui->balane->setText(std::to_string(user.balance).c_str());
}

main_menu::~main_menu()
{
    delete ui;
}

void main_menu::on_exit_clicked()
{
    close();
}

void main_menu::on_play_clicked()
{
    QMessageBox::information(this, "Подключение...", "Игра найдена!");
    hide();
    game_window = new game(this, user);
    game_window->showFullScreen();
}

