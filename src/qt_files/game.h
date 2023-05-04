#ifndef GAME_H
#define GAME_H

#include <QDialog>
#include <string>
#include "user.h"

namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    game(QWidget *parent = nullptr, User person = User());
    User user;
    ~game();

private slots:
    void on_verticalSlider_valueChanged(int value);

    void on_raise_clicked();

    void on_setValue_clicked();

private:
    Ui::game *ui;
    const char* path(const char c, const std::string& card);
    const char* path_to_cover_T();
    const char* path_to_cover();
    void initDillerCards();
    void initPlayer1Cards();
    void initPlayer2Cards();
    void initPlayer3Cards();
    void initPlayer4Cards();
};

#endif // GAME_H
