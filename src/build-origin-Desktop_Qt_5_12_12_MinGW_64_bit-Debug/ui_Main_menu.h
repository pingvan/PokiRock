/********************************************************************************
** Form generated from reading UI file 'Main_menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_MENU_H
#define UI_MAIN_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_main_menu
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QFrame *line_4;
    QSpacerItem *horizontalSpacer_4;
    QLabel *user_icon;
    QSpacerItem *horizontalSpacer_7;
    QVBoxLayout *verticalLayout_5;
    QLabel *name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLabel *balance;
    QFrame *line_2;
    QFrame *line;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *horizontalSpacer_5;
    QLabel *image;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_8;
    QPushButton *play;
    QSpacerItem *verticalSpacer;
    QPushButton *profile;
    QSpacerItem *verticalSpacer_2;
    QPushButton *settings;
    QSpacerItem *verticalSpacer_3;
    QPushButton *exit;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *main_menu)
    {
        if (main_menu->objectName().isEmpty())
            main_menu->setObjectName(QString::fromUtf8("main_menu"));
        main_menu->resize(1876, 1114);
        main_menu->setStyleSheet(QString::fromUtf8("QWidget[objectName=\"main_menu\"]{\n"
"	border-image: url(\"C:/Users/iliaa/Downloads/p1\") 0 0 0 0;\n"
"	background-repeat: no-repeat;\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(main_menu);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_6);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        line_3 = new QFrame(main_menu);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        line_4 = new QFrame(main_menu);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_4);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        user_icon = new QLabel(main_menu);
        user_icon->setObjectName(QString::fromUtf8("user_icon"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(user_icon->sizePolicy().hasHeightForWidth());
        user_icon->setSizePolicy(sizePolicy);
        user_icon->setMinimumSize(QSize(150, 150));
        user_icon->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(user_icon);

        horizontalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        name = new QLabel(main_menu);
        name->setObjectName(QString::fromUtf8("name"));
        sizePolicy.setHeightForWidth(name->sizePolicy().hasHeightForWidth());
        name->setSizePolicy(sizePolicy);
        name->setMinimumSize(QSize(250, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Rockwell Extra Bold"));
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        name->setFont(font);
        name->setLayoutDirection(Qt::LeftToRight);
        name->setFrameShape(QFrame::NoFrame);
        name->setFrameShadow(QFrame::Plain);
        name->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_5->addWidget(name);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(main_menu);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Rockwell Extra Bold"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_3->setFont(font1);

        horizontalLayout_4->addWidget(label_3);

        balance = new QLabel(main_menu);
        balance->setObjectName(QString::fromUtf8("balance"));
        sizePolicy1.setHeightForWidth(balance->sizePolicy().hasHeightForWidth());
        balance->setSizePolicy(sizePolicy1);
        balance->setMinimumSize(QSize(0, 0));
        QFont font2;
        font2.setPointSize(12);
        balance->setFont(font2);
        balance->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(balance);


        verticalLayout_5->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_5);

        line_2 = new QFrame(main_menu);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);


        verticalLayout_4->addLayout(horizontalLayout_3);

        line = new QFrame(main_menu);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_7);


        horizontalLayout_2->addLayout(verticalLayout_4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        image = new QLabel(main_menu);
        image->setObjectName(QString::fromUtf8("image"));
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setMinimumSize(QSize(600, 500));
        image->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(image);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalSpacer_6 = new QSpacerItem(370, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(600, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_8);

        play = new QPushButton(main_menu);
        play->setObjectName(QString::fromUtf8("play"));
        sizePolicy.setHeightForWidth(play->sizePolicy().hasHeightForWidth());
        play->setSizePolicy(sizePolicy);
        play->setMinimumSize(QSize(500, 50));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Rockwell Extra Bold"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        play->setFont(font3);
        play->setCursor(QCursor(Qt::PointingHandCursor));
        play->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"\n"
"  background-color:rgba(250,130,31, 1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(250, 170, 80, 1);\n"
"  border-left: 2px solid rgba(210, 125, 80, 1);\n"
"   border-right: 2px solid rgba(210, 125, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 125, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));

        verticalLayout->addWidget(play);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        profile = new QPushButton(main_menu);
        profile->setObjectName(QString::fromUtf8("profile"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(profile->sizePolicy().hasHeightForWidth());
        profile->setSizePolicy(sizePolicy2);
        profile->setMinimumSize(QSize(500, 50));
        profile->setFont(font3);
        profile->setCursor(QCursor(Qt::PointingHandCursor));
        profile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"\n"
"  background-color:rgba(250,130,31, 1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(250, 170, 80, 1);\n"
"  border-left: 2px solid rgba(210, 125, 80, 1);\n"
"   border-right: 2px solid rgba(210, 125, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 125, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));

        verticalLayout->addWidget(profile);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        settings = new QPushButton(main_menu);
        settings->setObjectName(QString::fromUtf8("settings"));
        sizePolicy2.setHeightForWidth(settings->sizePolicy().hasHeightForWidth());
        settings->setSizePolicy(sizePolicy2);
        settings->setMinimumSize(QSize(500, 50));
        settings->setFont(font3);
        settings->setCursor(QCursor(Qt::PointingHandCursor));
        settings->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"\n"
"  background-color:rgba(250,130,31, 1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(250, 170, 80, 1);\n"
"  border-left: 2px solid rgba(210, 125, 80, 1);\n"
"   border-right: 2px solid rgba(210, 125, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 125, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));

        verticalLayout->addWidget(settings);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        exit = new QPushButton(main_menu);
        exit->setObjectName(QString::fromUtf8("exit"));
        sizePolicy2.setHeightForWidth(exit->sizePolicy().hasHeightForWidth());
        exit->setSizePolicy(sizePolicy2);
        exit->setMinimumSize(QSize(496, 49));
        exit->setFont(font3);
        exit->setCursor(QCursor(Qt::PointingHandCursor));
        exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"\n"
"  background-color:rgba(250,130,31, 1);\n"
"  border-bottom: 4px solid rgba(200, 91, 72, 1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(250, 170, 80, 1);\n"
"  border-left: 2px solid rgba(210, 125, 80, 1);\n"
"   border-right: 2px solid rgba(210, 125, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 125, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(200, 101, 80, 1);\n"
"  border-left: 1px solid rgba(180, 90, 80, 1);\n"
"  border-right: -1px solid rgba(180, 90, 80, 1);\n"
"  border-top: 5px solid rgba(180, 90, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));

        verticalLayout->addWidget(exit);

        verticalSpacer_9 = new QSpacerItem(20, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_9);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(600, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(main_menu);

        QMetaObject::connectSlotsByName(main_menu);
    } // setupUi

    void retranslateUi(QDialog *main_menu)
    {
        main_menu->setWindowTitle(QApplication::translate("main_menu", "PokiRock", nullptr));
        user_icon->setText(QString());
        name->setText(QApplication::translate("main_menu", "<html><head/><body><p align=\"right\">Admin</p></body></html>", nullptr));
        label_3->setText(QApplication::translate("main_menu", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\320\221\320\260\320\273\320\260\320\275\321\201:</span></p></body></html>", nullptr));
        balance->setText(QApplication::translate("main_menu", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">0</span></p></body></html>", nullptr));
        image->setText(QString());
        play->setText(QApplication::translate("main_menu", "\320\230\320\263\321\200\320\260\321\202\321\214", nullptr));
        profile->setText(QApplication::translate("main_menu", "\320\237\321\200\320\276\321\204\320\270\320\273\321\214", nullptr));
        settings->setText(QApplication::translate("main_menu", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        exit->setText(QApplication::translate("main_menu", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_menu: public Ui_main_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_MENU_H
