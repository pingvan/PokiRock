#include "Main_menu.h"
#include "ui_Main_menu.h"
#include <QPixmap>
main_menu::main_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::main_menu)
{
    ui->setupUi(this);
    QPixmap image("/Users/user/PokiRock/src/qt_files/images_png/Poker-Transparent-Images-Clip-Art.png");
    int width = ui->image->width() + 1000;
    int height = ui->image->height();

    ui->image->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));
}

main_menu::~main_menu()
{
    delete ui;
}

void main_menu::on_pushButton_clicked()
{
    close();
}
