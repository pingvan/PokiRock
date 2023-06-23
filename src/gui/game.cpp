#include "window_manager.h"
#include "game.h"
#include "ui_game.h"

#include <QIcon>
#include <string>
#include <iostream>
#include <thread>

const char* game::path(const Card& card, bool T) {
    if (card.m == 0) {
        std::string ans = ":/cover/images/cards/Cover/main_cover" + (std::string)(T ? "_T" : "") + ".png";
        return ans.c_str();
    }
    std::string suit;
    std::string upperSuit;
    if (card.m == 'd') {
        suit = "diamonds";
    } else if (card.m == 'h') {
        suit = "hearts";
    } else if (card.m == 'c') {
        suit = "clubs";
    } else if (card.m == 's') {
        suit = "spades";
    }
    upperSuit = suit;
    upperSuit[0] = toupper(upperSuit[0]);
    std::string ans = ":/" + suit + "/images/cards/" + upperSuit + "/" + card.value + (T ? "_T" : "") + ".png";
    return ans.c_str();
}

void game::show_sticker(int sticker_number) {
    std::thread t([&](){
        std::string num = "";
        if (sticker_number < 10)
            num += "0";
        num += std::to_string(sticker_number);
        const std::string path_to_sticker = ":/stickers/images/stickers/chpic.su_-_duraktndrch_0" + num + ".png";
        ui->player1_icon->setIcon(QIcon(path_to_sticker.c_str()));

        std::this_thread::sleep_for(std::chrono::nanoseconds(2000000000));
        ui->player1_icon->setIcon(QIcon(":/boys/images/boys/dmitriy.png"));
    });
    t.detach();
}

void game::setContext(const GameContext& new_game_context) {
    game_context = new_game_context;
}

void game::update_graphic() {
    setImage(ui->diller_card_1, path(game_context.diller.cards[0], 0));
    setImage(ui->diller_card_2, path(game_context.diller.cards[1], 0));
    setImage(ui->diller_card_3, path(game_context.diller.cards[2], 0));
    setImage(ui->diller_card_4, path(game_context.diller.cards[3], 0));

    setImage(ui->player1_card_1, path(game_context.all_players[0].cards[0], 0));
    setImage(ui->player1_card_2, path(game_context.all_players[0].cards[1], 0));

    setImage(ui->player2_card_1, path(game_context.all_players[1].cards[0], 1));
    setImage(ui->player2_card_2, path(game_context.all_players[1].cards[1], 1));

    setImage(ui->player3_card_1, path(game_context.all_players[2].cards[0], 1));
    setImage(ui->player3_card_2, path(game_context.all_players[2].cards[1], 1));

    setImage(ui->player4_card_1, path(game_context.all_players[3].cards[0], 0));
    setImage(ui->player4_card_2, path(game_context.all_players[3].cards[1], 0));
}


game::game(WindowManager *manager_m, QWidget *parent)
    : QDialog(parent), ui(new Ui::game), manager(manager_m) {
    ui->setupUi(this);

    std::vector<Player> all_players_m = {Player(Card('J', 'd'), Card('2', 'd')), Player(), Player(), Player()};
    Diller diller_m;
    GameContext new_game_context{all_players_m, diller_m};
    setContext(new_game_context);

    update_graphic();

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

    ui->verticalSlider->setRange(1, static_cast<int>(manager->user->get_balance()));
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
    std::vector<Player> all_players_m = {Player(Card('J', 'd'), Card('2', 'd')), Player(), Player(), Player()};

    Diller diller_m = Diller{{Card('A', 'c'), Card(), Card(), Card()}};
    GameContext new_game_context{all_players_m, diller_m};
    setContext(new_game_context);
    update_graphic();
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
