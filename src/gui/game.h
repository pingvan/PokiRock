#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QLabel>
#include <string>

struct Card {
    char value;
    char m;
    Card(std::size_t value_m, char m_m) : value(value_m), m(m_m){};
    Card() : Card(0, 0){};
};

struct Player {
    std::vector<Card> cards = {Card(), Card()};
    Player(const Card& first, const Card& second){ cards = {first, second}; };
    Player() : Player(Card(), Card()) {};
};

struct Diller {
    std::vector<Card> cards = {Card(), Card(), Card(), Card()};
};

struct GameContext {
    std::vector<Player> all_players;
    Diller diller;
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

    void on_raise_clicked();

    void on_setValue_clicked();

    void on_choose_sticker_clicked();

    void on_player1_icon_clicked();

    void on_player2_icon_clicked();

//    void on_player4_icon_clicked();

//    void on_player3_icon_clicked();

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
    bool isStickerShown = false;
    friend StickersCollection;
};

#endif  // GAME_H
