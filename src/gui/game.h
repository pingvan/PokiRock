#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QLabel>
#include <string>
#include "../server/Card.hpp"
#include "../server/player.hpp"

struct Diller : player {
    std::vector<Card> cards = {Card(), Card(), Card(), Card(), Card()};
};

struct GameContext {
    std::vector<player> all_players;
    Diller diller;
    uint32_t player1_balance;
    uint32_t player2_balance;
    uint32_t player3_balance;
    uint32_t player4_balance;
    std::string player1_turn;
    std::string player2_turn;
    std::string player3_turn;
    std::string player4_turn;
};

class StickersCollection;
namespace Ui {
class game;
}

class WindowManager;
class GameState;

class game : public QDialog {
    Q_OBJECT

public:
    game(WindowManager *manager_m, QWidget *parent = nullptr);
    ~game();

private slots:
    void on_verticalSlider_valueChanged(int value);
    void on_value_textEdited(const QString &arg1);

    void on_choose_sticker_clicked();

    void on_player1_icon_clicked();

    void on_fold_clicked();

    void on_check_clicked();

    void on_raise_clicked();

    void on_setValue_clicked();

private:
    friend StickersCollection;
    friend GameState;
    Ui::game* ui;
    WindowManager *manager;
    GameContext game_context;
    static const char *path(const Card& card, bool T);
    static const char *path_to_cover_T();
    static const char *path_to_cover();
    static void setCoverCard(QLabel *place);
    static void setCoverCard_T(QLabel *place);
    void initDillerCards();
    void initPlayer1Cards();
    void initPlayer2Cards();
    void initPlayer3Cards();
    void initPlayer4Cards();
    void show_sticker(int sticker_number);
    void setContext(const GameContext& new_game_context);
    void update_graphic();
    void win();
    bool isStickerShown = false;
    friend StickersCollection;
    void update_turn_info();
    int cur_bet = 0;
    int bank = 0;
    void rebalance(QLabel* label, int val);

    void fold(int player_number);
    void raise(int value);
    void egor_check();
    void ilia_check();

    void ilia_raise(int bet);

};

#endif  // GAME_H
