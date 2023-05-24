#ifndef AUTHORIZATION_WINDOW_HPP
#define AUTHORIZATION_WINDOW_HPP

#include <QDialog>

class first_window;

namespace Ui {
class authorization_window;
}

class WindowManager;

class authorization_window : public QDialog {
    Q_OBJECT

public:
    authorization_window(
        QWidget *parent = nullptr,
        WindowManager *manager = nullptr
    );
    ~authorization_window();
private slots:
    void on_authorizate_clicked();
    void on_registrate_clicked();

private:
    Ui::authorization_window *ui;
    WindowManager *manager;
    void show_authorization_warning();
};

#endif  // AUTHORIZATION_WINDOW_HPP
