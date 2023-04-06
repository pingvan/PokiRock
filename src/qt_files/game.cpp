#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    QPixmap image(":/cards/images/cards/Hearts/A.png");
    int width = ui->label->width();
    int height = ui->label->height();
    ui->label->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap image2(":/cards/images/cards/Hearts/A.png");
    int width_2 = ui->label_2->width();
    int height_2 = ui->label_2->height();
    ui->label_2->setPixmap(image2.scaled(width_2, height_2, Qt::KeepAspectRatio));

    QPixmap image3(":/cards/images/cards/Spades/Q.png");
    int width_3 = ui->label_3->width();
    int height_3 = ui->label_3->height();
    ui->label_3->setPixmap(image3.scaled(width_3, height_3, Qt::KeepAspectRatio));
}

game::~game()
{
    delete ui;
}
