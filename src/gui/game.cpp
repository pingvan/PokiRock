#include "game.h"
#include "ui_game.h"
#include "window_manager.h"
#include <QIcon>
#include <string>
#include <iostream>

const char* game::path(const char c, const std::string &card) {
    std::string suit;
    std::string upperSuit;
    if (c == 'd') {
        suit = "diamonds";
        upperSuit = "Diamonds";
    } else if (c == 'h') {
        suit = "hearts";
        upperSuit = "Hearts";
    } else if (c == 'c') {
        suit = "clubs";
        upperSuit = "Clubs";
    } else if (c == 's') {
        suit = "spades";
        upperSuit = "Spades";
    }
    std::string ans =
        ":/" + suit + "/images/cards/" + upperSuit + "/" + card + ".png";
    return ans.c_str();
}

const char* game::path_to_cover() {
    return ":/cover/images/cards/Cover/main_cover.png";
}

const char* game::path_to_cover_T(
) {
    return ":/cover/images/cards/Cover/main_cover_T.png";
}

void game::setCoverCard(QLabel* label) {
    setImage(label, path_to_cover());
}

void game::setCoverCard_T(QLabel* label) {
    setImage(label, path_to_cover_T());
}

void game::initDillerCards() {
    setCoverCard(ui->diller_card_1);
    setCoverCard(ui->diller_card_2);
    setCoverCard(ui->diller_card_3);
    setCoverCard(ui->diller_card_4);
}

void game::initPlayer1Cards() {
    setCoverCard(ui->player1_card_1);
    setCoverCard(ui->player1_card_2);
}

void game::initPlayer2Cards() {
    setCoverCard_T(ui->player2_card_1);
    setCoverCard_T(ui->player2_card_2);
}

void game::initPlayer3Cards() {
    setCoverCard_T(ui->player3_card_1);
    setCoverCard_T(ui->player3_card_2);
}

void game::initPlayer4Cards() {
    setCoverCard(ui->player4_card_1);
    setCoverCard(ui->player4_card_2);
}

game::game(QWidget *parent, WindowManager *manager_m)
    : QDialog(parent), ui(new Ui::game), manager(manager_m) {
    ui->setupUi(this);

    initDillerCards();
    initPlayer1Cards();
    initPlayer2Cards();
    initPlayer3Cards();
    initPlayer4Cards();

    ui->player1_sticker->setIconSize(QSize(200, 200));

    ui->choose_sticker->setIcon(QIcon(":/stickers/images/stickers/chpic.su_-_duraktndrch_006.png"));
    ui->choose_sticker->setIconSize(QSize(50, 50));



    ui->verticalSlider->setRange(
        1, static_cast<int>(manager->user->get_balance())
    );
    ui->setValue->hide();
    ui->verticalSlider->hide();
    ui->value->hide();
}

game::~game() {
    delete ui;
}

void game::on_verticalSlider_valueChanged(int value) {
    ui->value->setText(QString(std::to_string(value).c_str()));
}

void game::on_raise_clicked() {
    ui->value->show();
    ui->verticalSlider->show();
    ui->setValue->show();
}

void game::on_setValue_clicked() {
    ui->setValue->hide();
    ui->verticalSlider->hide();
    ui->value->hide();
}

void game::on_choose_sticker_clicked()
{
   manager->show_stickers();
}

void game::on_player1_sticker_clicked()
{
    ui->player1_sticker->setIcon(QIcon());
}

void game::show_sticker(int sticker_number) {
    std::string num = "";
    if (sticker_number < 10)
        num += "0";
    num += std::to_string(sticker_number);
    const std::string path_to_sticker = ":/stickers/images/stickers/chpic.su_-_duraktndrch_0" + num + ".png";
    ui->player1_sticker->setIcon(QIcon(path_to_sticker.c_str()));
}

