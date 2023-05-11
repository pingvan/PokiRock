#ifndef FIRST_WINDOW_H
#define FIRST_WINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class first_window; }
QT_END_NAMESPACE

struct WindowManager;

class first_window: public QMainWindow
{
    Q_OBJECT

public:
    first_window(QWidget *parent = nullptr, WindowManager* manager = nullptr);
    ~first_window();
private slots:
    void on_start_clicked() const;

private:
    Ui::first_window*ui;
    WindowManager* manager;
};
#endif // FIRST_WINDOW_H
