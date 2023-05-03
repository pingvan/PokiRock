#ifndef FIRST_WINDOW_H
#define FIRST_WINDOW_H

#include <QMainWindow>
#include "Authorization_window.h"

QT_BEGIN_NAMESPACE
namespace Ui { class first_window; }
QT_END_NAMESPACE

class first_window : public QMainWindow
{
    Q_OBJECT

public:
    first_window(QWidget *parent = nullptr);
    ~first_window();

private slots:
    void on_start_clicked();

private:
    Ui::first_window *ui;
    authorization_window *second_window;
};
#endif // FIRST_WINDOW_H
