/********************************************************************************
** Form generated from reading UI file 'First_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_WINDOW_H
#define UI_FIRST_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_first_window
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *start;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *first_window)
    {
        if (first_window->objectName().isEmpty())
            first_window->setObjectName(QString::fromUtf8("first_window"));
        first_window->resize(1424, 1100);
        first_window->setStyleSheet(QString::fromUtf8("QWidget[objectName=\"first_window\"]{\n"
"	border-image: url(\"C:/Users/iliaa/Downloads/p1\") 0 0 0 0;\n"
"	background-repeat: no-repeat;\n"
"}\n"
""));
        centralwidget = new QWidget(first_window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(800, 800));
        label->setSizeIncrement(QSize(0, 0));
        label->setCursor(QCursor(Qt::ArrowCursor));
        label->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(700, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_3);

        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(start->sizePolicy().hasHeightForWidth());
        start->setSizePolicy(sizePolicy1);
        start->setMinimumSize(QSize(250, 39));
        start->setBaseSize(QSize(0, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(10);
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        start->setFont(font);
        start->setCursor(QCursor(Qt::PointingHandCursor));
        start->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: black;\n"
"  margin-right: 3%;\n"
"  margin-top: 5px;\n"
"  border-radius: 8px;\n"
"  padding: 5px 9px;\n"
"  font-size: 1.2em;\n"
"  background-color:rgba(255, 70, 31, 0.9);\n"
"  border-bottom: 4px solid rgba(190, 70, 80,1);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  background-color: rgba(255, 130, 40, 1);\n"
"  border-left: 2px solid rgba(210, 105, 80, 1);\n"
"   border-right: 2px solid rgba(210, 105, 80, 1);\n"
"   border-bottom: 6px solid rgba(210, 105, 80, 1);\n"
"}\n"
"QPushButton:pressed {\n"
"  background-color: rgba(190, 60, 35, 1);\n"
"  border-left: 1px solid rgba(156, 38, 34, 1);\n"
"  border-right: -1px solid rgba(156, 38, 34, 1);\n"
"  border-top: 5px solid rgba(156, 38, 34, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));
        start->setIconSize(QSize(400, 50));
        start->setAutoRepeatInterval(97);

        verticalLayout_2->addWidget(start);

        verticalSpacer_4 = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer_2 = new QSpacerItem(700, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        first_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(first_window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1424, 25));
        first_window->setMenuBar(menubar);
        toolBar = new QToolBar(first_window);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        first_window->addToolBar(Qt::LeftToolBarArea, toolBar);

        retranslateUi(first_window);

        QMetaObject::connectSlotsByName(first_window);
    } // setupUi

    void retranslateUi(QMainWindow *first_window)
    {
        first_window->setWindowTitle(QApplication::translate("first_window", "PokiRock", nullptr));
        label->setText(QString());
        start->setText(QApplication::translate("first_window", "\320\222\320\236\320\231\320\242\320\230", nullptr));
        toolBar->setWindowTitle(QApplication::translate("first_window", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class first_window: public Ui_first_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_WINDOW_H
