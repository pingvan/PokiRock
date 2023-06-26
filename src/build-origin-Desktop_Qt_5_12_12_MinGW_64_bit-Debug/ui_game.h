/********************************************************************************
** Form generated from reading UI file 'game.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAME_H
#define UI_GAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *player4_card_1;
    QLabel *player4_card_2;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_10;
    QSpacerItem *verticalSpacer_17;
    QPushButton *player4_icon;
    QHBoxLayout *horizontalLayout_9;
    QLabel *player4_name;
    QLabel *player4_balance;
    QSpacerItem *verticalSpacer_16;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *player2;
    QVBoxLayout *verticalLayout_8;
    QLabel *player2_card_1;
    QLabel *player2_card_2;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_13;
    QPushButton *player2_icon;
    QHBoxLayout *player2_info;
    QLabel *player2_name;
    QLabel *player2_balance;
    QSpacerItem *verticalSpacer_12;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *diller;
    QLabel *diller_card_1;
    QLabel *diller_card_2;
    QLabel *diller_card_3;
    QLabel *diller_card_4;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *player3;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_14;
    QPushButton *player3_icon;
    QHBoxLayout *player3_info;
    QLabel *player3_name;
    QLabel *player3_balance;
    QSpacerItem *verticalSpacer_15;
    QVBoxLayout *verticalLayout_3;
    QLabel *player3_card_1;
    QLabel *player3_card_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_12;
    QSlider *verticalSlider;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_6;
    QPushButton *raise;
    QHBoxLayout *horizontalLayout_8;
    QLabel *value;
    QPushButton *setValue;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QLabel *player1_card_1;
    QLabel *player1_card_2;
    QVBoxLayout *verticalLayout_11;
    QSpacerItem *verticalSpacer_19;
    QPushButton *player1_icon;
    QHBoxLayout *horizontalLayout_10;
    QLabel *player1_name;
    QLabel *player1_balance;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *horizontalSpacer_14;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_9;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_11;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_10;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_7;
    QSpacerItem *verticalSpacer_8;
    QPushButton *choose_sticker;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->resize(1341, 957);
        game->setStyleSheet(QString::fromUtf8("QWidget[objectName=\"game\"]{ background-image: url(\":/other/images/other/sukno.png\") no-repeat right bottom; } "));
        verticalLayout = new QVBoxLayout(game);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_10 = new QSpacerItem(160, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        player4_card_1 = new QLabel(game);
        player4_card_1->setObjectName(QString::fromUtf8("player4_card_1"));
        player4_card_1->setMinimumSize(QSize(150, 200));

        horizontalLayout_6->addWidget(player4_card_1);

        player4_card_2 = new QLabel(game);
        player4_card_2->setObjectName(QString::fromUtf8("player4_card_2"));
        player4_card_2->setMinimumSize(QSize(150, 200));

        horizontalLayout_6->addWidget(player4_card_2);

        horizontalSpacer_13 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_13);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalSpacer_17 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_17);

        player4_icon = new QPushButton(game);
        player4_icon->setObjectName(QString::fromUtf8("player4_icon"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(player4_icon->sizePolicy().hasHeightForWidth());
        player4_icon->setSizePolicy(sizePolicy);
        player4_icon->setMinimumSize(QSize(120, 120));
        player4_icon->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(\":/other/images/other/sukno.png\");\n"
"border-bottom: 0px;\n"
"\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  border-bottom: 0px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  border-left: 0px;\n"
"   border-right: 0px;\n"
"   border-bottom: 0px;\n"
"}\n"
""));

        verticalLayout_10->addWidget(player4_icon);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        player4_name = new QLabel(game);
        player4_name->setObjectName(QString::fromUtf8("player4_name"));
        player4_name->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 15px;"));

        horizontalLayout_9->addWidget(player4_name);

        player4_balance = new QLabel(game);
        player4_balance->setObjectName(QString::fromUtf8("player4_balance"));
        player4_balance->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 15px;"));

        horizontalLayout_9->addWidget(player4_balance);


        verticalLayout_10->addLayout(horizontalLayout_9);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_16);


        horizontalLayout_6->addLayout(verticalLayout_10);


        horizontalLayout_5->addLayout(horizontalLayout_6);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        player2 = new QHBoxLayout();
        player2->setObjectName(QString::fromUtf8("player2"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        player2_card_1 = new QLabel(game);
        player2_card_1->setObjectName(QString::fromUtf8("player2_card_1"));
        player2_card_1->setMinimumSize(QSize(200, 150));

        verticalLayout_8->addWidget(player2_card_1);

        player2_card_2 = new QLabel(game);
        player2_card_2->setObjectName(QString::fromUtf8("player2_card_2"));
        sizePolicy.setHeightForWidth(player2_card_2->sizePolicy().hasHeightForWidth());
        player2_card_2->setSizePolicy(sizePolicy);
        player2_card_2->setMinimumSize(QSize(200, 150));

        verticalLayout_8->addWidget(player2_card_2);


        player2->addLayout(verticalLayout_8);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_13);

        player2_icon = new QPushButton(game);
        player2_icon->setObjectName(QString::fromUtf8("player2_icon"));
        sizePolicy.setHeightForWidth(player2_icon->sizePolicy().hasHeightForWidth());
        player2_icon->setSizePolicy(sizePolicy);
        player2_icon->setMinimumSize(QSize(120, 120));
        player2_icon->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(\":/other/images/other/sukno.png\");\n"
"border-bottom: 0px;\n"
"\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  border-bottom: 0px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  border-left: 0px;\n"
"   border-right: 0px;\n"
"   border-bottom: 0px;\n"
"}\n"
""));

        verticalLayout_2->addWidget(player2_icon);

        player2_info = new QHBoxLayout();
        player2_info->setObjectName(QString::fromUtf8("player2_info"));
        player2_name = new QLabel(game);
        player2_name->setObjectName(QString::fromUtf8("player2_name"));
        player2_name->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 15px;"));
        player2_name->setFrameShape(QFrame::NoFrame);

        player2_info->addWidget(player2_name);

        player2_balance = new QLabel(game);
        player2_balance->setObjectName(QString::fromUtf8("player2_balance"));
        player2_balance->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 15px;"));
        player2_balance->setFrameShape(QFrame::NoFrame);

        player2_info->addWidget(player2_balance);


        verticalLayout_2->addLayout(player2_info);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_12);


        player2->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(player2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        diller = new QHBoxLayout();
        diller->setObjectName(QString::fromUtf8("diller"));
        diller_card_1 = new QLabel(game);
        diller_card_1->setObjectName(QString::fromUtf8("diller_card_1"));
        diller_card_1->setMinimumSize(QSize(150, 200));

        diller->addWidget(diller_card_1);

        diller_card_2 = new QLabel(game);
        diller_card_2->setObjectName(QString::fromUtf8("diller_card_2"));
        diller_card_2->setMinimumSize(QSize(150, 200));

        diller->addWidget(diller_card_2);

        diller_card_3 = new QLabel(game);
        diller_card_3->setObjectName(QString::fromUtf8("diller_card_3"));
        diller_card_3->setMinimumSize(QSize(150, 200));

        diller->addWidget(diller_card_3);

        diller_card_4 = new QLabel(game);
        diller_card_4->setObjectName(QString::fromUtf8("diller_card_4"));
        diller_card_4->setMinimumSize(QSize(150, 200));

        diller->addWidget(diller_card_4);


        horizontalLayout_3->addLayout(diller);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        player3 = new QHBoxLayout();
        player3->setObjectName(QString::fromUtf8("player3"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_14 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_14);

        player3_icon = new QPushButton(game);
        player3_icon->setObjectName(QString::fromUtf8("player3_icon"));
        sizePolicy.setHeightForWidth(player3_icon->sizePolicy().hasHeightForWidth());
        player3_icon->setSizePolicy(sizePolicy);
        player3_icon->setMinimumSize(QSize(120, 120));
        player3_icon->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(\":/other/images/other/sukno.png\");\n"
"border-bottom: 0px;\n"
"\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  border-bottom: 0px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  border-left: 0px;\n"
"   border-right: 0px;\n"
"   border-bottom: 0px;\n"
"}\n"
""));

        verticalLayout_9->addWidget(player3_icon);

        player3_info = new QHBoxLayout();
        player3_info->setObjectName(QString::fromUtf8("player3_info"));
        player3_name = new QLabel(game);
        player3_name->setObjectName(QString::fromUtf8("player3_name"));
        player3_name->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 15px;"));

        player3_info->addWidget(player3_name);

        player3_balance = new QLabel(game);
        player3_balance->setObjectName(QString::fromUtf8("player3_balance"));
        player3_balance->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 15px;"));

        player3_info->addWidget(player3_balance);


        verticalLayout_9->addLayout(player3_info);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_15);


        player3->addLayout(verticalLayout_9);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        player3_card_1 = new QLabel(game);
        player3_card_1->setObjectName(QString::fromUtf8("player3_card_1"));
        player3_card_1->setMinimumSize(QSize(200, 150));

        verticalLayout_3->addWidget(player3_card_1);

        player3_card_2 = new QLabel(game);
        player3_card_2->setObjectName(QString::fromUtf8("player3_card_2"));
        player3_card_2->setMinimumSize(QSize(200, 150));

        verticalLayout_3->addWidget(player3_card_2);


        player3->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(player3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_12);

        verticalSlider = new QSlider(game);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setMinimumSize(QSize(40, 100));
        verticalSlider->setCursor(QCursor(Qt::ClosedHandCursor));
        verticalSlider->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"     border: 1px solid #999999;\n"
"     height: 8px; /* \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\260 \321\200\320\260\321\201\321\210\320\270\321\200\321\217\320\265\321\202\321\201\321\217 \320\264\320\276 \321\200\320\260\320\267\320\274\320\265\321\200\320\276\320\262 \320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260. \320\267\320\260\320\264\320\260\320\262 \320\262\321\213\321\201\320\276\321\202\321\203 \320\276\320\275\320\260 \320\277\321\200\320\270\320\275\320\270\320\274\320\260\320\265\321\202 \321\204\320\270\320\272\321\201\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \321\200\320\260\320\267\320\274\320\265\321\200 */\n"
"     background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"     margin: 2px 0;\n"
" }\n"
"\n"
" QSlider::handle:horizontal {\n"
"     background: qlineargradie"
                        "nt(x1:0, y1:0, x2:1, y2:1, stop:0 #b4b4b4, stop:1 #8f8f8f);\n"
"     border: 1px solid #5c5c5c;\n"
"     width: 18px;\n"
"     margin: -2px 0; /* \321\200\321\203\320\272\320\276\321\217\321\202\320\272\320\260 \321\200\320\260\321\201\320\277\320\276\320\273\320\260\320\263\320\260\320\265\321\202\321\201\321\217 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216 \320\262 \320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\265 \321\201\320\276\320\264\320\265\321\200\320\266\320\270\320\274\320\276\320\263\320\276 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\270. \320\240\320\260\321\201\321\210\320\270\321\200\321\217\320\265\321\202\321\201\321\217 \320\275\320\260\321\200\321\203\320\266\321\203 \320\276\321\202 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\270 */\n"
"     border-radius: 3px;\n"
" }\n"
"\n"
"/*\320\225\321\201\320\273\320\270 \320\262\321\213 \321\205\320\276\321\202"
                        "\320\270\321\202\320\265 \320\270\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\206\320\262\320\265\321\202 \321\207\320\260\321\201\321\202\320\265\320\271 \320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260 \320\264\320\276 \320\270 \320\277\320\276\321\201\320\273\320\265 \321\200\321\203\320\272\320\276\321\217\321\202\320\272\320\270, \320\274\320\276\320\266\320\265\321\202\320\265 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\321\214 \321\201\321\203\320\261\321\215\320\273\320\265\320\274\320\265\320\275\321\202\321\213 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 add-page \320\270 sub-page. \320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200, \320\264\320\273\321\217 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\263\320\276 \320\277\320\276\320\273\320\267\321\203\320\275\320\272\320\260:*/\n"
"\n"
" QSlider::groove:vertical {\n"
"     b"
                        "ackground: red;\n"
"	 width: 12px;\n"
"     position: absolute; /* \320\260\320\261\321\201\320\276\320\273\321\216\321\202\320\275\320\260\321\217 \320\277\320\276\320\267\320\270\321\206\320\270\321\217 \320\262 4px \321\201\320\273\320\265\320\262\320\260 \320\270 \321\201\320\277\321\200\320\260\320\262\320\260 \320\276\321\202 \320\262\320\270\320\264\320\266\320\265\321\202\320\260. \321\203\321\201\321\202\320\260\320\275\320\276\320\262\320\272\320\260 \320\277\320\276\320\273\320\265\320\271 \320\262\320\270\320\264\320\266\320\265\321\202\320\260 \321\202\320\260\320\272\320\266\320\265 \320\261\321\203\320\264\320\265\321\202 \321\200\320\260\320\261\320\276\321\202\320\260\321\202\321\214... */\n"
"     left: 8px; right: 8px;\n"
" }\n"
"\n"
" QSlider::handle:vertical {\n"
"     height: 10px;\n"
"	width: 20px;\n"
"\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  background-color:rgba(230,110,80,1);\n"
"  border-bottom: 4p"
                        "x solid rgba(200, 91, 72, 1);\n"
"\n"
"     background: rgba(255, 120, 31, 1);\n"
"     margin: 0 -20px; /* \321\200\320\260\321\201\321\210\320\270\321\200\321\217\320\265\321\202\321\201\321\217 \320\275\320\260\321\200\321\203\320\266\321\203 \320\276\321\202 \320\261\320\276\321\200\320\276\320\267\320\264\320\272\320\270 */\n"
" }\n"
"\n"
" QSlider::add-page:vertical {\n"
"     background: rgba(240, 140, 80, 1);\n"
" }\n"
"\n"
" QSlider::sub-page:vertical {\n"
"     background: rgba(180, 105, 80, 0.8);\n"
" }"));
        verticalSlider->setSingleStep(10);
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_7->addWidget(verticalSlider);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_11);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalSpacer_9 = new QSpacerItem(80, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        verticalLayout_4->addItem(horizontalSpacer_9);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_7 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_7);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        raise = new QPushButton(game);
        raise->setObjectName(QString::fromUtf8("raise"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(raise->sizePolicy().hasHeightForWidth());
        raise->setSizePolicy(sizePolicy1);
        raise->setMinimumSize(QSize(200, 65));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell Extra Bold"));
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        raise->setFont(font);
        raise->setCursor(QCursor(Qt::PointingHandCursor));
        raise->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"\n"
"  background-color:rgba(255,120,31, 1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(240, 140, 80, 1);\n"
"  border-left: 2px solid rgba(210, 105, 80, 1);\n"
"   border-right: 2px solid rgba(210, 105, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 105, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));

        verticalLayout_5->addWidget(raise);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        value = new QLabel(game);
        value->setObjectName(QString::fromUtf8("value"));
        sizePolicy.setHeightForWidth(value->sizePolicy().hasHeightForWidth());
        value->setSizePolicy(sizePolicy);
        value->setMinimumSize(QSize(90, 50));
        value->setStyleSheet(QString::fromUtf8("color: black;\n"
"margin-right: 3%;\n"
"margin-top: 5px;\n"
"padding: 5px 9px;\n"
"font-size: 1.2em;\n"
"background-color: rgba(200, 101, 80, 1);"));
        value->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(value);

        setValue = new QPushButton(game);
        setValue->setObjectName(QString::fromUtf8("setValue"));
        sizePolicy.setHeightForWidth(setValue->sizePolicy().hasHeightForWidth());
        setValue->setSizePolicy(sizePolicy);
        setValue->setMinimumSize(QSize(100, 50));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        setValue->setFont(font1);
        setValue->setCursor(QCursor(Qt::PointingHandCursor));
        setValue->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  background-color:rgba(230,110,80,1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(240, 140, 80, 1);\n"
"  border-left: 2px solid rgba(210, 105, 80, 1);\n"
"   border-right: 2px solid rgba(210, 105, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 105, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));

        horizontalLayout_8->addWidget(setValue);


        verticalLayout_5->addLayout(horizontalLayout_8);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);


        horizontalLayout_2->addLayout(verticalLayout_5);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        player1_card_1 = new QLabel(game);
        player1_card_1->setObjectName(QString::fromUtf8("player1_card_1"));
        player1_card_1->setMinimumSize(QSize(200, 300));

        horizontalLayout->addWidget(player1_card_1);

        player1_card_2 = new QLabel(game);
        player1_card_2->setObjectName(QString::fromUtf8("player1_card_2"));
        player1_card_2->setMinimumSize(QSize(200, 300));

        horizontalLayout->addWidget(player1_card_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalSpacer_19 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_19);

        player1_icon = new QPushButton(game);
        player1_icon->setObjectName(QString::fromUtf8("player1_icon"));
        sizePolicy.setHeightForWidth(player1_icon->sizePolicy().hasHeightForWidth());
        player1_icon->setSizePolicy(sizePolicy);
        player1_icon->setMinimumSize(QSize(125, 125));
        player1_icon->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-image: url(\":/other/images/other/sukno.png\");\n"
"border-bottom: 0px;\n"
"\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  border-bottom: 0px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  border-left: 0px;\n"
"   border-right: 0px;\n"
"   border-bottom: 0px;\n"
"}\n"
""));

        verticalLayout_11->addWidget(player1_icon);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        player1_name = new QLabel(game);
        player1_name->setObjectName(QString::fromUtf8("player1_name"));
        player1_name->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 15px;"));

        horizontalLayout_10->addWidget(player1_name);

        player1_balance = new QLabel(game);
        player1_balance->setObjectName(QString::fromUtf8("player1_balance"));
        player1_balance->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 15px;"));

        horizontalLayout_10->addWidget(player1_balance);


        verticalLayout_11->addLayout(horizontalLayout_10);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_11->addItem(verticalSpacer_18);


        horizontalLayout_2->addLayout(verticalLayout_11);

        horizontalSpacer_14 = new QSpacerItem(75, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_14);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_9);

        pushButton_3 = new QPushButton(game);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);
        pushButton_3->setMinimumSize(QSize(175, 70));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Rockwell Extra Bold"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_3->setFont(font2);
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  background-color:rgba(230,110,80,1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(240, 140, 80, 1);\n"
"  border-left: 2px solid rgba(210, 105, 80, 1);\n"
"   border-right: 2px solid rgba(210, 105, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 105, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));
        pushButton_3->setFlat(false);

        verticalLayout_6->addWidget(pushButton_3);

        verticalSpacer_11 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_11);

        pushButton_2 = new QPushButton(game);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);
        pushButton_2->setMinimumSize(QSize(175, 70));
        pushButton_2->setFont(font2);
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2->setMouseTracking(false);
        pushButton_2->setTabletTracking(false);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  background-color:rgba(230,110,80,1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(240, 140, 80, 1);\n"
"  border-left: 2px solid rgba(210, 105, 80, 1);\n"
"   border-right: 2px solid rgba(210, 105, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 105, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));

        verticalLayout_6->addWidget(pushButton_2);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_10);


        horizontalLayout_2->addLayout(verticalLayout_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalSpacer_4 = new QSpacerItem(93, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_8);

        choose_sticker = new QPushButton(game);
        choose_sticker->setObjectName(QString::fromUtf8("choose_sticker"));
        sizePolicy.setHeightForWidth(choose_sticker->sizePolicy().hasHeightForWidth());
        choose_sticker->setSizePolicy(sizePolicy);
        choose_sticker->setMinimumSize(QSize(40, 40));
        choose_sticker->setCursor(QCursor(Qt::PointingHandCursor));
        choose_sticker->setLayoutDirection(Qt::LeftToRight);
        choose_sticker->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  background-color:rgba(230,110,80,1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(240, 140, 80, 1);\n"
"  border-left: 2px solid rgba(210, 105, 80, 1);\n"
"   border-right: 2px solid rgba(210, 105, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 105, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));
        choose_sticker->setIconSize(QSize(20, 20));

        verticalLayout_7->addWidget(choose_sticker);


        horizontalLayout_2->addLayout(verticalLayout_7);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(game);

        pushButton_3->setDefault(false);


        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Dialog", nullptr));
        player4_card_1->setText(QString());
        player4_card_2->setText(QString());
        player4_icon->setText(QString());
        player4_name->setText(QApplication::translate("game", "Player4", nullptr));
        player4_balance->setText(QApplication::translate("game", "Balance", nullptr));
        player2_card_1->setText(QString());
        player2_card_2->setText(QString());
        player2_icon->setText(QString());
        player2_name->setText(QApplication::translate("game", "Player2", nullptr));
        player2_balance->setText(QApplication::translate("game", "Balance", nullptr));
        diller_card_1->setText(QString());
        diller_card_2->setText(QString());
        diller_card_3->setText(QString());
        diller_card_4->setText(QString());
        player3_icon->setText(QString());
        player3_name->setText(QApplication::translate("game", "Player3", nullptr));
        player3_balance->setText(QApplication::translate("game", "Balance", nullptr));
        player3_card_1->setText(QString());
        player3_card_2->setText(QString());
        raise->setText(QApplication::translate("game", "\320\237\320\276\320\262\321\213\321\201\320\270\321\202\321\214 \321\201\321\202\320\260\320\262\320\272\321\203", nullptr));
        value->setText(QApplication::translate("game", "<html><head/><body><p><span style=\" font-size:12pt;\">0</span></p></body></html>", nullptr));
        setValue->setText(QApplication::translate("game", "\320\223\320\276\321\202\320\276\320\262\320\276", nullptr));
        player1_card_1->setText(QString());
        player1_card_2->setText(QString());
        player1_icon->setText(QString());
        player1_name->setText(QApplication::translate("game", "Player1", nullptr));
        player1_balance->setText(QApplication::translate("game", "Balance", nullptr));
        pushButton_3->setText(QApplication::translate("game", "\320\247\320\265\320\272", nullptr));
        pushButton_2->setText(QApplication::translate("game", "\320\237\320\260\321\201", nullptr));
        choose_sticker->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
