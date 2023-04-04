#include "First_window.h"
#include "ui_First_window.h"

first_window::first_window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::first_window)
{
    ui->setupUi(this);
}

first_window::~first_window()
{
    delete ui;
}


void first_window::on_pushButton_clicked()
{
    hide();
    second_window = new authorization_window(this);
    second_window->showFullScreen();
}

