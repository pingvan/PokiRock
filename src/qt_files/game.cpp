#include "game.h"
#include "ui_game.h"

const char* game::path(const char c, const std::string& card) {
    std::string suit, usuit;
    if (c == 'd'){
        suit = "diamonds";
        usuit = "Diamonds";
    }else if (c == 'h'){
        suit = "hearts";
        usuit = "Hearts";
    }else if (c == 'c'){
        suit = "clubs";
        usuit = "Clubs";
    }else if (c == 's'){
        suit = "spades";
        usuit = "Spades";
    }
    const std::string& ans = ":/" + suit + "/images/cards/" + usuit + "/" + card+ ".png";
    return ans.c_str();
}

const char* game::path_to_cover() {
    return ":/cover/images/cards/Cover/main_cover.png";
}

const char* game::path_to_cover_T() {
    return ":/cover/images/cards/Cover/main_cover_T.png";
}

game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    QPixmap player1_card_1(path('c', "J"));
    int width = ui->player1_card_1->width();
    int height = ui->player1_card_1->height();
    ui->player1_card_1->setPixmap(player1_card_1.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap player1_card_2(path('d', "A"));
    ui->player1_card_2->setPixmap(player1_card_2.scaled(width, height, Qt::KeepAspectRatio));


    QPixmap diller_card_1(path_to_cover());
    int width_2 = ui->diller_card_1->width();
    int height_2 = ui->diller_card_1->height();
    ui->diller_card_1->setPixmap(diller_card_1.scaled(width_2, height_2, Qt::KeepAspectRatio));

    QPixmap diller_card_2(path_to_cover());
    ui->diller_card_2->setPixmap(diller_card_2.scaled(width_2, height_2, Qt::KeepAspectRatio));

    QPixmap diller_card_3(path_to_cover());
    ui->diller_card_3->setPixmap(diller_card_3.scaled(width_2, height_2, Qt::KeepAspectRatio));

    QPixmap diller_card_4(path_to_cover());
    ui->diller_card_4->setPixmap(diller_card_4.scaled(width_2, height_2, Qt::KeepAspectRatio));




    QPixmap cover_T(path_to_cover_T());
    int width_3 = ui->player2_card_1->width();
    int height_3 = ui->player2_card_1->height();
    ui->player2_card_1->setPixmap(cover_T.scaled(width_3, height_3, Qt::KeepAspectRatio));

    ui->player2_card_2->setPixmap(cover_T.scaled(width_3, height_3, Qt::KeepAspectRatio));


    ui->player3_card_1->setPixmap(cover_T.scaled(width_3, height_3, Qt::KeepAspectRatio));

    ui->player3_card_2->setPixmap(cover_T.scaled(width_3, height_3, Qt::KeepAspectRatio));


    QPixmap cover(path_to_cover());
    int width_4 = ui->player4_card_1->width();
    int height_4 = ui->player4_card_2->height();
    ui->player4_card_1->setPixmap(cover.scaled(width_4, height_4, Qt::KeepAspectRatio));
    ui->player4_card_2->setPixmap(cover.scaled(width_4, height_4, Qt::KeepAspectRatio));

}


game::~game()
{
    delete ui;
}
