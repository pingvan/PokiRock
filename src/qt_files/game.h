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
};

#endif // GAME_H
