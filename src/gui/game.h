#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <QLabel>
#include <string>

namespace Ui {
class game;
}

class WindowManager;

class game : public QDialog {
    Q_OBJECT

public:
    game(QWidget *parent = nullptr, WindowManager *manager = nullptr);
    ~game();

private slots:
    void on_verticalSlider_valueChanged(int value);

    void on_raise_clicked();

    void on_setValue_clicked();

private:
    Ui::game *ui;
    WindowManager *manager;
    static const char *path(char c, const std::string &card);
    static const char *path_to_cover_T();
    static const char *path_to_cover();
    static void setCoverCard(QLabel *place);
    static void setCoverCard_T(QLabel *place);
    void initDillerCards();
    void initPlayer1Cards();
    void initPlayer2Cards();
    void initPlayer3Cards();
    void initPlayer4Cards();
};

#endif  // GAME_H