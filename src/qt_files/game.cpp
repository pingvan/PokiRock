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

void game::setDillerCards(){
    QPixmap diller_card_1(path_to_cover());
    int width = ui->diller_card_1->width();
    int height = ui->diller_card_1->height();
    ui->diller_card_1->setPixmap(diller_card_1.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap diller_card_2(path_to_cover());
    ui->diller_card_2->setPixmap(diller_card_2.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap diller_card_3(path_to_cover());
    ui->diller_card_3->setPixmap(diller_card_3.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap diller_card_4(path_to_cover());
    ui->diller_card_4->setPixmap(diller_card_4.scaled(width, height, Qt::KeepAspectRatio));
}

void game::setPlayer1Cards(){
    QPixmap player1_card_1(path('s', "7"));
    int width = ui->player1_card_1->width();
    int height = ui->player1_card_1->height();
    ui->player1_card_1->setPixmap(player1_card_1.scaled(width, height, Qt::KeepAspectRatio));

    QPixmap player1_card_2(path('d', "A"));
    ui->player1_card_2->setPixmap(player1_card_2.scaled(width, height, Qt::KeepAspectRatio));
}

void game::setPlayer2Cards(){
    QPixmap cover_T(path_to_cover_T());
    int width = ui->player2_card_1->width();
    int height = ui->player2_card_1->height();
    ui->player2_card_1->setPixmap(cover_T.scaled(width, height, Qt::KeepAspectRatio));

    ui->player2_card_2->setPixmap(cover_T.scaled(width, height, Qt::KeepAspectRatio));
}

void game::setPlayer3Cards(){
    QPixmap cover_T(path_to_cover_T());
    int width = ui->player2_card_1->width();
    int height = ui->player2_card_1->height();
    ui->player3_card_1->setPixmap(cover_T.scaled(width, height, Qt::KeepAspectRatio));
    ui->player3_card_2->setPixmap(cover_T.scaled(width, height, Qt::KeepAspectRatio));
}

void game::setPlayer4Cards(){
    QPixmap cover(path_to_cover());
    int width = ui->player4_card_1->width();
    int height = ui->player4_card_2->height();
    ui->player4_card_1->setPixmap(cover.scaled(width, height, Qt::KeepAspectRatio));
    ui->player4_card_2->setPixmap(cover.scaled(width, height, Qt::KeepAspectRatio));
}
game::game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::game)
{
    ui->setupUi(this);

    setDillerCards();
    setPlayer1Cards();
    setPlayer2Cards();
    setPlayer3Cards();
    setPlayer4Cards();

}


game::~game()
{
    delete ui;
}
