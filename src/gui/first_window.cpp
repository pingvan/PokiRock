#include "first_window.h"
#include "ui_First_window.h"
#include "window_manager.h"

first_window::first_window(WindowManager *manager_m, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::first_window), manager(manager_m) {
    ui->setupUi(this);
    setImage(ui->label, ":/labels/images/labels/main_label.png");
}

first_window::~first_window() {
    delete ui;
}

void first_window::on_start_clicked() const {
    manager->show_authorization_window();
}
