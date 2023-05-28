#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include <QDialog>

class authorization_window;

namespace Ui {
class registration_window;
}

class WindowManager;

class registration_window : public QDialog {
    Q_OBJECT

public:
    registration_window(
        QWidget *parent = nullptr,
        WindowManager *manager = nullptr
    );
    ~registration_window();
    WindowManager *manager;
private slots:
    void on_registration_clicked();

private:
    Ui::registration_window *ui;
    bool add_new_user();
    void show_registration_warning();
    void show_warning_of_different_passwords();
    void show_success();
};

#endif  // REGISTRATION_WINDOW_H
