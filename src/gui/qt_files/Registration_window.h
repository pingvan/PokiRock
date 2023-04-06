#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include <QDialog>

class authorization_window;

namespace Ui {
class registration_window;
}

class registration_window : public QDialog
{
    Q_OBJECT

public:
    explicit registration_window(QWidget *parent = nullptr);
    ~registration_window();
    authorization_window* second_window;

private slots:
    void on_pushButton_clicked();

private:
    Ui::registration_window *ui;
    bool add_new_user();

};

#endif // REGISTRATION_WINDOW_H
