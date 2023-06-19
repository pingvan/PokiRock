#include "stickers_collection.h"
#include "ui_stickers_collection.h"
#include "window_manager.h"
#include "game.h"

StickersCollection::StickersCollection(WindowManager* manager_m, QWidget *parent) :
    QDialog(parent), ui(new Ui::StickersCollection),
     manager(manager_m)
{
    ui->setupUi(this);
    setWindowTitle("Коллекция стикеров");

    initSticker(ui->pushButton_1, 1);
    initSticker(ui->pushButton_2, 2);
    initSticker(ui->pushButton_3, 3);
    initSticker(ui->pushButton_4, 4);
    initSticker(ui->pushButton_5, 5);
    initSticker(ui->pushButton_6, 6);
    initSticker(ui->pushButton_7, 7);
    initSticker(ui->pushButton_8, 8);
    initSticker(ui->pushButton_9, 9);
    initSticker(ui->pushButton_10, 10);
    initSticker(ui->pushButton_11, 11);
    initSticker(ui->pushButton_12, 12);
    initSticker(ui->pushButton_13, 13);
    initSticker(ui->pushButton_14, 14);
    initSticker(ui->pushButton_15, 15);
    initSticker(ui->pushButton_16, 16);
    initSticker(ui->pushButton_17, 17);
    initSticker(ui->pushButton_18, 18);
    initSticker(ui->pushButton_19, 19);
    initSticker(ui->pushButton_20, 20);
    initSticker(ui->pushButton_21, 21);
    initSticker(ui->pushButton_22, 22);
    initSticker(ui->pushButton_23, 23);
    initSticker(ui->pushButton_24, 24);
    initSticker(ui->pushButton_25, 25);
}

StickersCollection::~StickersCollection()
{
    delete ui;
}


void StickersCollection::on_pushButton_1_clicked()
{
   manager->gameWindow_var->show_sticker(1);
   this->hide();
}

void StickersCollection::on_pushButton_2_clicked()
{
    manager->gameWindow_var->show_sticker(2);
    this->hide();
}


void StickersCollection::on_pushButton_3_clicked()
{
    manager->gameWindow_var->show_sticker(3);
    this->hide();
}


void StickersCollection::on_pushButton_4_clicked()
{
    manager->gameWindow_var->show_sticker(4);
    this->hide();
}


void StickersCollection::on_pushButton_5_clicked()
{
    manager->gameWindow_var->show_sticker(5);
    this->hide();
}


void StickersCollection::on_pushButton_6_clicked()
{
    manager->gameWindow_var->show_sticker(6);
    this->hide();
}

void StickersCollection::on_pushButton_7_clicked()
{
    manager->gameWindow_var->show_sticker(7);
    this->hide();
}


void StickersCollection::on_pushButton_8_clicked()
{
    manager->gameWindow_var->show_sticker(8);
    this->hide();
}


void StickersCollection::on_pushButton_9_clicked()
{
    manager->gameWindow_var->show_sticker(9);
    this->hide();
}

void StickersCollection::on_pushButton_10_clicked()
{
    manager->gameWindow_var->show_sticker(10);
    this->hide();
}

void StickersCollection::on_pushButton_11_clicked()
{
    manager->gameWindow_var->show_sticker(11);
    this->hide();
}

void StickersCollection::on_pushButton_12_clicked()
{
    manager->gameWindow_var->show_sticker(12);
    this->hide();
}

void StickersCollection::on_pushButton_13_clicked()
{
    manager->gameWindow_var->show_sticker(13);
    this->hide();
}
void StickersCollection::on_pushButton_14_clicked()
{
    manager->gameWindow_var->show_sticker(14);
    this->hide();
}

void StickersCollection::on_pushButton_15_clicked()
{
    manager->gameWindow_var->show_sticker(15);
    this->hide();
}

void StickersCollection::on_pushButton_16_clicked()
{
    manager->gameWindow_var->show_sticker(16);
    this->hide();
}

void StickersCollection::on_pushButton_17_clicked()
{
    manager->gameWindow_var->show_sticker(17);
    this->hide();
}

void StickersCollection::on_pushButton_18_clicked()
{
    manager->gameWindow_var->show_sticker(18);
    this->hide();
}

void StickersCollection::on_pushButton_19_clicked()
{
    manager->gameWindow_var->show_sticker(19);
    this->hide();
}

void StickersCollection::on_pushButton_20_clicked()
{
    manager->gameWindow_var->show_sticker(20);
    this->hide();
}

void StickersCollection::on_pushButton_21_clicked()
{
    manager->gameWindow_var->show_sticker(21);
    this->hide();
}

void StickersCollection::on_pushButton_22_clicked()
{
    manager->gameWindow_var->show_sticker(22);
    this->hide();
}

void StickersCollection::on_pushButton_23_clicked()
{
    manager->gameWindow_var->show_sticker(23);
    this->hide();
}

void StickersCollection::on_pushButton_24_clicked()
{
    manager->gameWindow_var->show_sticker(24);
    this->hide();
}

void StickersCollection::on_pushButton_25_clicked()
{
    manager->gameWindow_var->show_sticker(25);
    this->hide();
}

void StickersCollection::initSticker(QPushButton* button, int num) {
    std::string number = "";
    if (num < 10)
        number += "0";
    number += std::to_string(num);
    const std::string path_to_sticker = ":/stickers/images/stickers/chpic.su_-_duraktndrch_0" + number + ".png";
    button->setIcon(QIcon(path_to_sticker.c_str()));
    button->setIconSize(QSize(80, 80));
}



