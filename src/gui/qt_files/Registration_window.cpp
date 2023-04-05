#include "Registration_window.h"
#include "ui_Registration_window.h"

registration_window::registration_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::registration_window)
{
    ui->setupUi(this);
}

registration_window::~registration_window()
{
    delete ui;
}
