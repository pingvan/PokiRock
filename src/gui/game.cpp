#include "window_manager.h"
#include "game.h"
#include "ui_game.h"

#include <QIcon>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <thread>

const char* game::path(const Card& card, bool T) {
    if (card.get_suit() == Suit::SUIT_SIZE) {
        std::string ans = ":/cover/images/cards/Cover/main_cover" + (std::string)(T ? "_T" : "") + ".png";
        return ans.c_str();
    }
    std::string suit;
    std::string upperSuit;
    if (card.get_suit() == Suit::DIAMONDS) {
        suit = "diamonds";
    } else if (card.get_suit() == Suit::HEARTS) {
        suit = "hearts";
    } else if (card.get_suit() == Suit::CLUBS) {
        suit = "clubs";
    } else if (card.get_suit() == Suit::SPADES) {
        suit = "spades";
    }
    upperSuit = suit;
    upperSuit[0] = toupper(upperSuit[0]);
    std::string value = card.value_to_string();
    if (value == "Jack") {
        value = "J";
    } else if (value == "Queen") {
        value = "Q";
    } else if (value == "King") {
        value = "K";
    } else if (value == "Ace") {
        value = "A";
    }
    std::string ans = ":/" + suit + "/images/cards/" + upperSuit + "/" + value + (T ? "_T" : "") + ".png";
    return ans.c_str();
}

void game::setContext(const GameContext& new_game_context) {
    game_context = new_game_context;
}

void game::update_graphic() {
    setImage(ui->diller_card_1, path(game_context.diller.cards[0], 0));
    setImage(ui->diller_card_2, path(game_context.diller.cards[1], 0));
    setImage(ui->diller_card_3, path(game_context.diller.cards[2], 0));
    setImage(ui->diller_card_4, path(game_context.diller.cards[3], 0));
    setImage(ui->diller_card_5, path(game_context.diller.cards[4], 0));

    setImage(ui->player1_card_1, path(game_context.all_players[0].player_cards.first, 0));
    setImage(ui->player1_card_2, path(game_context.all_players[0].player_cards.second, 0));

    setImage(ui->player2_card_1, path(game_context.all_players[1].player_cards.first, 1));
    setImage(ui->player2_card_2, path(game_context.all_players[1].player_cards.second, 1));

    setImage(ui->player3_card_1, path(game_context.all_players[2].player_cards.first, 1));
    setImage(ui->player3_card_2, path(game_context.all_players[2].player_cards.second, 1));

    setImage(ui->player4_card_1, path(game_context.all_players[3].player_cards.first, 0));
    setImage(ui->player4_card_2, path(game_context.all_players[3].player_cards.second, 0));

    ui->player1_balance->setText((std::to_string(game_context.player1_balance) + "k").c_str());
    ui->player1_turn->setText(game_context.player1_turn.c_str());

    ui->player2_balance->setText((std::to_string(game_context.player2_balance) + "k").c_str());
    ui->player2_turn->setText(game_context.player2_turn.c_str());

    ui->player3_balance->setText((std::to_string(game_context.player3_balance) + "k").c_str());
    ui->player3_turn->setText(game_context.player3_turn.c_str());

    ui->player4_balance->setText((std::to_string(game_context.player4_balance) + "k").c_str());
    ui->player4_turn->setText(game_context.player4_turn.c_str());
}


game::game(WindowManager *manager_m, QWidget *parent)
    : QDialog(parent), ui(new Ui::game), manager(manager_m) {
    ui->setupUi(this);
    update_graphic();
    ui->choose_sticker->setIcon(QIcon(":/stickers/images/stickers/chpic.su_-_duraktndrch_006.png"));
    ui->choose_sticker->setIconSize(QSize(40, 40));

    ui->unfair_play->setIcon(QIcon(":/other/images/other/lupa.png"));
    ui->unfair_play->setIconSize(QSize(40, 40));

    ui->player1_icon->setIcon(QIcon(":/boys/images/boys/dmitriy.png"));
    ui->player1_icon->setIconSize(QSize(120, 120));

    ui->player2_icon->setIcon(QIcon(":/boys/images/boys/egor.png"));
    ui->player2_icon->setIconSize(QSize(120, 120));

    ui->player3_icon->setIcon(QIcon(":/boys/images/boys/alexei.png"));
    ui->player3_icon->setIconSize(QSize(120, 120));

    ui->player4_icon->setIcon(QIcon(":/boys/images/boys/ilia.png"));
    ui->player4_icon->setIconSize(QSize(120, 120));

    std:: string s = ui->player1_balance->text().toStdString();
    s.pop_back();
    ui->verticalSlider->setRange(1, std::stoi(s));
    ui->setValue->hide();
    ui->verticalSlider->hide();
    ui->value->hide();
    setImage(ui->chips, ":/other/images/other/chips.png");

    ui->player1_name->setText(manager->user->get_name().c_str());
    ui->player1_balance->setText((std::to_string(manager->user->get_balance()) + "k").c_str());
    ui->player2_name->setText(game_context[1].player_name);
    ui->player3_name->setText(game_context[2].player_name);
    ui->player4_name->setText(game_context[3].player_name);
}

game::~game() {
    delete ui;
}

void game::on_verticalSlider_valueChanged(int value) {
    QFont font = ui->value->font();
    font.setPixelSize(20);
    ui->value->setText((std::to_string(value)).c_str());
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

    int val = ui->value->text().toInt();
    std::string balance = ui->player1_balance->text().toStdString();
    balance.pop_back();

    int new_balance = std::stoi(balance) - val;

    std::string text = "Ставка: " + std::to_string(val) + "k";
    this_client->make_game_request(TURN::RAISE, val);
    ui->player1_turn->setText(QString::fromStdString(text));
    ui->player1_balance->setText(QString((std::to_string(new_balance) + "k").c_str()));
    cur_bet = val;
    bank += cur_bet;
    ui->bank->setText((std::to_string(bank) + "k").c_str());
    ui->verticalSlider->setRange(cur_bet, new_balance);
}

void game::on_choose_sticker_clicked()
{
   manager->show_stickers();
}

void game::fold(int i) {
    game_context.all_players[i].player_cards = {Card(Suit::SUIT_SIZE, Value::VALUE_SIZE), Card(Suit::SUIT_SIZE, Value::VALUE_SIZE)};
    i++;
    if (i == 1) {
        ui->player1_turn->setText("ПАС");
    } else if (i == 2) {
        ui->player2_turn->setText("ПАС");
    } else if (i == 3) {
        ui->player3_turn->setText("ПАС");
    } else if (i == 4) {
        ui->player4_turn->setText("ПАС");
    }
}

void game::on_player1_icon_clicked()
{
    ui->player1_icon->setIcon(QIcon(":/boys/images/boys/dmitriy.png"));
}

void game::on_fold_clicked()
{
    this_client->make_game_request(TURN::FOLD);
    fold(0);
    update_graphic();
}

void game::rebalance(QLabel* label, int val) {
    QString s = label->text();
    std::string cur_balance = s.toStdString();
    cur_balance.pop_back();
    QString new_balance = QString((std::to_string(std::stoi(cur_balance) - val) + "k").c_str());
    label->setText(new_balance);
}

void game::update_turn_info() {
    ui->player1_turn->setText("");
    ui->player2_turn->setText("");
    ui->player3_turn->setText("");
    ui->player4_turn->setText("");
}

void game::on_check_clicked()
{
    this_client->make_game_request(TURN::CHECK);
    std::string text = "ЧЕК: " + std::to_string(cur_bet) + "k";
    ui->player1_turn->setText(text.c_str());
    rebalance(ui->player1_balance, cur_bet);
    bank += cur_bet;
    ui->bank->setText((std::to_string(bank) + "k").c_str());
}

//QMessageBox::information(this, "Вы победили!", ("Выигрыш: " + std::to_string(bank)).c_str());

void game::on_value_textEdited(const QString &val)
{
    try {
        ui->verticalSlider->setValue(std::stoi(val.toStdString()));
    } catch (...) {
        return;
    }
}

void game::show_sticker(int sticker_number) {
    std::thread ([&](){
        std::string num = "";
        if (sticker_number < 10)
            num += "0";
        num += std::to_string(sticker_number);
        const std::string path_to_sticker = ":/stickers/images/stickers/chpic.su_-_duraktndrch_0" + num + ".png";
        ui->player1_icon->setIcon(QIcon(path_to_sticker.c_str()));
        std::this_thread::sleep_for(std::chrono::nanoseconds(2000000000));
        ui->player1_icon->setIcon(QIcon(":/boys/images/boys/dmitriy.png"));
    }).detach();
}


// Card(10, Herts), Card(K, Hearts);

/* Preflop
check(); (0)
egor.check(); (0)
ilia.raise(100);
alexei.fold();
check(); (100)
egor.check(); (100)
diller.open_3_cards(); Card(K, Diamonds), Card(10, Spades), Card(2, Hearts);
*/

/* Flop
check(); (0)
egor.check(); (0)
ilia.check(); (0)
diller.open_1_card(); Card(9, Hearts);
*/

/* Turn
 raise(300);
 egor.fold();
 ilia.check(); (300)
 diller.open_1_card(); Card(7, Hearts);
*/

/* River
     check(); (0)
     ilia.check(); (0)
     ilia.show_cards(); Card(Q Spades), Card(J hearts)
     me.win(900); (+500)
     end();     // flash > straight
*/


