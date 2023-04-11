#include "game.h"
#include "ui_game.h"

game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);
    QPixmap image("D:/PokiRock/src/qt_files/images/cards/Diamonds/10.png");
    int width = ui->player1_card_1->width();
    int height = ui->player1_card_1->height();
    ui->player1_card_1->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap image2("D:/PokiRock/src/qt_files/images/cards/Spades/10.png");
    int width_2 = ui->player1_card_2->width();
    int height_2 = ui->player1_card_2->height();
    ui->player1_card_2->setPixmap(image2.scaled(width_2, height_2, Qt::KeepAspectRatio));




    QPixmap image3("D:/PokiRock/src/qt_files/images/cards/Spades/J.png");
    int width_3 = ui->diller_card_1->width();
    int height_3 = ui->diller_card_1->height();
    ui->diller_card_1->setPixmap(image3.scaled(width_3, height_3, Qt::KeepAspectRatio));

    QPixmap image4("D:/PokiRock/src/qt_files/images/cards/Spades/Q.png");
    int width_4 = ui->diller_card_2->width();
    int height_4 = ui->diller_card_2->height();
    ui->diller_card_2->setPixmap(image4.scaled(width_4, height_4, Qt::KeepAspectRatio));

    QPixmap image5("D:/PokiRock/src/qt_files/images/cards/Spades/K.png");
    int width_5 = ui->diller_card_3->width();
    int height_5 = ui->diller_card_3->height();
    ui->diller_card_3->setPixmap(image5.scaled(width_5, height_5, Qt::KeepAspectRatio));

    QPixmap image6("D:/PokiRock/src/qt_files/images/cards/Spades/A.png");
    int width_6 = ui->diller_card_4->width();
    int height_6 = ui->diller_card_4->height();
    ui->diller_card_4->setPixmap(image6.scaled(width_6, height_6, Qt::KeepAspectRatio));




    QPixmap image7("D:/PokiRock/src/qt_files/images/cards/Cover/main_cover_T.png");
    int width_7 = ui->player2_card_1->width();
    int height_7 = ui->player2_card_1->height();
    ui->player2_card_1->setPixmap(image7.scaled(width_7, height_7, Qt::KeepAspectRatio));

    ui->player2_card_2->setPixmap(image7.scaled(width_7, height_7, Qt::KeepAspectRatio));


    ui->player3_card_1->setPixmap(image7.scaled(width_7, height_7, Qt::KeepAspectRatio));

    ui->player3_card_2->setPixmap(image7.scaled(width_7, height_7, Qt::KeepAspectRatio));


    QPixmap image8("D:/PokiRock/src/qt_files/images/cards/Cover/main_cover.png");
    int width_8 = ui->player2_card_1->width();
    int height_8 = ui->player2_card_1->height();
    ui->player4_card_1->setPixmap(image8.scaled(width_8, height_8, Qt::KeepAspectRatio));
    ui->player4_card_2->setPixmap(image8.scaled(width_8, height_8, Qt::KeepAspectRatio));

}

game::~game()
{
    delete ui;
}
