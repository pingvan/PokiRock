#include "First_window.h"
#include "ui_First_window.h"
#include "Authorization_window.h"

first_window::first_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::first_window)
{
    ui->setupUi(this);
    QPixmap image(":/labels/images/labels/main_label.png");
    int width = ui->label->width();
    int height = ui->label->height();
    ui->label->setPixmap(image.scaled(width, height, Qt::KeepAspectRatio));
}

first_window::~first_window()
{
    delete ui;
}


void first_window::on_pushButton_clicked()
{
    second_window = new authorization_window(this);
    second_window->start_window = this;
    second_window->show();
}

