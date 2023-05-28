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

void game::show_sticker(int sticker_number) {
    std::string num = "";
    if (sticker_number < 10)
        num += "0";
    num += std::to_string(sticker_number);
    const std::string path_to_sticker = ":/stickers/images/stickers/chpic.su_-_duraktndrch_0" + num + ".png";
    if (sticker_number == 7) {
        ui->player2_icon->setIcon(QIcon(path_to_sticker.c_str()));
    } else {
        ui->player1_icon->setIcon(QIcon(path_to_sticker.c_str()));
    }
}


game::game(QWidget *parent, WindowManager *manager_m)
    : QDialog(parent), ui(new Ui::game), manager(manager_m) {
    ui->setupUi(this);

    initDillerCards();
    initPlayer1Cards();
    initPlayer2Cards();
    initPlayer3Cards();
    initPlayer4Cards();

    ui->choose_sticker->setIcon(QIcon(":/stickers/images/stickers/chpic.su_-_duraktndrch_006.png"));
    ui->choose_sticker->setIconSize(QSize(40, 40));

    ui->player1_icon->setIcon(QIcon(":/boys/images/boys/dmitriy.png"));
    ui->player1_icon->setIconSize(QSize(120, 120));

    ui->player2_icon->setIcon(QIcon(":/boys/images/boys/egor.png"));
    ui->player2_icon->setIconSize(QSize(120, 120));

    ui->player3_icon->setIcon(QIcon(":/boys/images/boys/alexei.png"));
    ui->player3_icon->setIconSize(QSize(120, 120));

    ui->player4_icon->setIcon(QIcon(":/boys/images/boys/ilia.png"));
    ui->player4_icon->setIconSize(QSize(120, 120));

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
    QFont font = ui->value->font();
    font.setPixelSize(20);
    ui->value->setText(QString(std::to_string(value).c_str()));
    ui->value->setFont(font);
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

void game::on_player1_icon_clicked()
{
    ui->player1_icon->setIcon(QIcon(":/boys/images/boys/dmitriy.png"));
}

void game::on_player2_icon_clicked()
{
    ui->player2_icon->setIcon(QIcon(":/boys/images/boys/egor.png"));
}

//void game::on_player3_icon_clicked()
//{
//    ui->player3_icon->setIcon(QIcon(":/other/images/other/user_icon.png"));
//}

//void game::on_player4_icon_clicked()
//{
//    ui->player4_icon->setIcon(QIcon(":/other/images/other/user_icon.png"));
//}


