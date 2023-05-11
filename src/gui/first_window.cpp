#include "first_window.h"
#include "ui_First_window.h"
#include "window_manager.h"

first_window::first_window(QWidget *parent, WindowManager* manager_m)
    : QMainWindow(parent), manager(manager_m)
    , ui(new Ui::first_window)
{
    ui->setupUi(this);
    QPixmap image(":/labels/images/labels/not_bad.png");
    int width = ui->label->width();
    int height = ui->label->height();
    ui->label->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));
}

first_window::~first_window()
{
    delete ui;
}


void first_window::on_start_clicked() const
{
    manager->show_authorization_window();
}

