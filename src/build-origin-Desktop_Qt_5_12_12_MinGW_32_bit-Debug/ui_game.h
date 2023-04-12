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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_game
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *player4_card_1;
    QLabel *player4_card_2;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *player2_card_1;
    QLabel *player2_card_2;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *diller_card_1;
    QLabel *diller_card_2;
    QLabel *diller_card_3;
    QLabel *diller_card_4;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *player3_card_1;
    QLabel *player3_card_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *All_in;
    QSpacerItem *horizontalSpacer_13;
    QPushButton *Raise;
    QSpacerItem *horizontalSpacer_10;
    QPushButton *Call;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *player1_card_1;
    QLabel *player1_card_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *Fold;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *game)
    {
        if (game->objectName().isEmpty())
            game->setObjectName(QString::fromUtf8("game"));
        game->resize(1239, 853);
        verticalLayout = new QVBoxLayout(game);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_4);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        player4_card_1 = new QLabel(game);
        player4_card_1->setObjectName(QString::fromUtf8("player4_card_1"));
        player4_card_1->setMinimumSize(QSize(150, 200));

        horizontalLayout_5->addWidget(player4_card_1);

        player4_card_2 = new QLabel(game);
        player4_card_2->setObjectName(QString::fromUtf8("player4_card_2"));
        player4_card_2->setMinimumSize(QSize(150, 200));

        horizontalLayout_5->addWidget(player4_card_2);


        horizontalLayout_4->addLayout(horizontalLayout_5);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        player2_card_1 = new QLabel(game);
        player2_card_1->setObjectName(QString::fromUtf8("player2_card_1"));
        player2_card_1->setMinimumSize(QSize(200, 150));

        verticalLayout_2->addWidget(player2_card_1);

        player2_card_2 = new QLabel(game);
        player2_card_2->setObjectName(QString::fromUtf8("player2_card_2"));
        player2_card_2->setMinimumSize(QSize(200, 150));

        verticalLayout_2->addWidget(player2_card_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        diller_card_1 = new QLabel(game);
        diller_card_1->setObjectName(QString::fromUtf8("diller_card_1"));
        diller_card_1->setMinimumSize(QSize(150, 200));

        horizontalLayout_6->addWidget(diller_card_1);

        diller_card_2 = new QLabel(game);
        diller_card_2->setObjectName(QString::fromUtf8("diller_card_2"));
        diller_card_2->setMinimumSize(QSize(150, 200));

        horizontalLayout_6->addWidget(diller_card_2);

        diller_card_3 = new QLabel(game);
        diller_card_3->setObjectName(QString::fromUtf8("diller_card_3"));
        diller_card_3->setMinimumSize(QSize(150, 200));

        horizontalLayout_6->addWidget(diller_card_3);

        diller_card_4 = new QLabel(game);
        diller_card_4->setObjectName(QString::fromUtf8("diller_card_4"));
        diller_card_4->setMinimumSize(QSize(150, 200));

        horizontalLayout_6->addWidget(diller_card_4);


        horizontalLayout_3->addLayout(horizontalLayout_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

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


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        All_in = new QPushButton(game);
        All_in->setObjectName(QString::fromUtf8("All_in"));
        All_in->setMinimumSize(QSize(130, 65));

        horizontalLayout_2->addWidget(All_in);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        Raise = new QPushButton(game);
        Raise->setObjectName(QString::fromUtf8("Raise"));
        Raise->setMinimumSize(QSize(130, 65));

        horizontalLayout_2->addWidget(Raise);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_10);

        Call = new QPushButton(game);
        Call->setObjectName(QString::fromUtf8("Call"));
        Call->setMinimumSize(QSize(130, 65));

        horizontalLayout_2->addWidget(Call);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        player1_card_1 = new QLabel(game);
        player1_card_1->setObjectName(QString::fromUtf8("player1_card_1"));
        player1_card_1->setMinimumSize(QSize(150, 200));

        horizontalLayout->addWidget(player1_card_1);

        player1_card_2 = new QLabel(game);
        player1_card_2->setObjectName(QString::fromUtf8("player1_card_2"));
        player1_card_2->setMinimumSize(QSize(150, 200));

        horizontalLayout->addWidget(player1_card_2);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer_3 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalSpacer_11 = new QSpacerItem(170, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_11);

        Fold = new QPushButton(game);
        Fold->setObjectName(QString::fromUtf8("Fold"));
        Fold->setMinimumSize(QSize(130, 65));

        horizontalLayout_2->addWidget(Fold);

        horizontalSpacer_12 = new QSpacerItem(170, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        horizontalSpacer_4 = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);


        retranslateUi(game);

        QMetaObject::connectSlotsByName(game);
    } // setupUi

    void retranslateUi(QDialog *game)
    {
        game->setWindowTitle(QApplication::translate("game", "Dialog", nullptr));
        player4_card_1->setText(QString());
        player4_card_2->setText(QString());
        player2_card_1->setText(QString());
        player2_card_2->setText(QString());
        diller_card_1->setText(QString());
        diller_card_2->setText(QString());
        diller_card_3->setText(QString());
        diller_card_4->setText(QString());
        player3_card_1->setText(QString());
        player3_card_2->setText(QString());
        All_in->setText(QApplication::translate("game", "All in", nullptr));
        Raise->setText(QApplication::translate("game", "Raise", nullptr));
        Call->setText(QApplication::translate("game", "Call", nullptr));
        player1_card_1->setText(QString());
        player1_card_2->setText(QString());
        Fold->setText(QApplication::translate("game", "Fold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class game: public Ui_game {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAME_H
