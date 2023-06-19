#ifndef PROFILE_WINDOW_H
#define PROFILE_WINDOW_H

#include <QDialog>

namespace Ui {
class ProfileWindow;
}

class ProfileWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileWindow(QWidget *parent = nullptr);
    ~ProfileWindow();

private:
    Ui::ProfileWindow *ui;
};

#endif // PROFILE_WINDOW_H
