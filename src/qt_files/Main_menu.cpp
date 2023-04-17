#include "Main_menu.h"
#include "ui_Main_menu.h"
#include <QPixmap>
#include <QMessageBox>

main_menu::main_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);
    QPixmap image(":/other/images/other/people.png");
    int width = ui->image->width() + 1000;
    int height = ui->image->height();
    ui->image->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));
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
    game_window = new game(this);
    game_window->showFullScreen();
}

