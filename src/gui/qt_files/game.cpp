#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    QPixmap image(":/cards/images/cards/Spades/10.png");
    int width = ui->label->width();
    int height = ui->label->height();

    ui->label->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));
}

game::~game()
{
    delete ui;
}
