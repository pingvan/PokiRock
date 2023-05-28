#ifndef STICKERS_COLLECTION_H
#define STICKERS_COLLECTION_H

#include <QDialog>

namespace Ui {
class StickersCollection;
}

class WindowManager;

class StickersCollection : public QDialog
{
    Q_OBJECT

public:
    StickersCollection(QWidget *parent = nullptr, WindowManager* manager = nullptr);
    ~StickersCollection();

private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

private:
    Ui::StickersCollection *ui;
    WindowManager* manager;
    void initSticker(QPushButton* button, int number);
};

#endif // STICKERS_COLLECTION_H
