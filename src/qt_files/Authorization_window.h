#ifndef AUTHORIZATION_WINDOW_H
#define AUTHORIZATION_WINDOW_H

#include <QDialog>
#include "Main_menu.h"
#include "../client/Client.h"
#include "../server/Server.h"
#include "../server/DataBase_connector.h"

namespace Ui {
class authorization_window;
}

class authorization_window : public QDialog
{
    Q_OBJECT

public:
    explicit authorization_window(QWidget *parent = nullptr);
    ~authorization_window();

private slots:
    void on_pushButton_clicked();

private:
    Ui::authorization_window *ui;
    main_menu *main_window;
};

#endif // AUTHORIZATION_WINDOW_H
