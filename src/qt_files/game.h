#ifndef GAME_H
#define GAME_H

#include <QDialog>

namespace Ui {
class game;
}

class game : public QDialog
{
    Q_OBJECT

public:
    explicit game(QWidget *parent = nullptr);
    ~game();

private:
    Ui::game *ui;
    const char* path(const char c, const std::string& card);
    const char* path_to_cover_T();
    const char* path_to_cover();
    void setDillerCards();
    void setPlayer1Cards();
    void setPlayer2Cards();
    void setPlayer3Cards();
    void setPlayer4Cards();
};

#endif // GAME_H
