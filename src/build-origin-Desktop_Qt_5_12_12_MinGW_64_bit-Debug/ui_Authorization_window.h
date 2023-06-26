/********************************************************************************
** Form generated from reading UI file 'Authorization_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_WINDOW_H
#define UI_AUTHORIZATION_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_authorization_window
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *label_3;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *Login;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *Password;
    QSpacerItem *verticalSpacer_3;
    QPushButton *authorizate;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QPushButton *registrate;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_5;

    void setupUi(QDialog *authorization_window)
    {
        if (authorization_window->objectName().isEmpty())
            authorization_window->setObjectName(QString::fromUtf8("authorization_window"));
        authorization_window->resize(1160, 588);
        authorization_window->setStyleSheet(QString::fromUtf8("QWidget[objectName=\"authorization_window\"]{ \n"
"	border-image: url(\"C:/Users/iliaa/Downloads/p1\") 0 0 0 0;\n"
"	background-repeat: no-repeat;\n"
"} "));
        verticalLayout_4 = new QVBoxLayout(authorization_window);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_3 = new QLabel(authorization_window);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: black;"));
        label_3->setWordWrap(true);

        verticalLayout_4->addWidget(label_3);

        verticalSpacer_2 = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        groupBox = new QGroupBox(authorization_window);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(60, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        Login = new QLineEdit(groupBox);
        Login->setObjectName(QString::fromUtf8("Login"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Login->sizePolicy().hasHeightForWidth());
        Login->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(Login);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(60, 0));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        Password = new QLineEdit(groupBox);
        Password->setObjectName(QString::fromUtf8("Password"));
        sizePolicy1.setHeightForWidth(Password->sizePolicy().hasHeightForWidth());
        Password->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(Password);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_3);

        authorizate = new QPushButton(groupBox);
        authorizate->setObjectName(QString::fromUtf8("authorizate"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(authorizate->sizePolicy().hasHeightForWidth());
        authorizate->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        authorizate->setFont(font2);
        authorizate->setCursor(QCursor(Qt::PointingHandCursor));
        authorizate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_3->addWidget(authorizate);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer_4);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        verticalLayout_3->addWidget(checkBox);

        verticalSpacer = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);

        registrate = new QPushButton(groupBox);
        registrate->setObjectName(QString::fromUtf8("registrate"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(registrate->sizePolicy().hasHeightForWidth());
        registrate->setSizePolicy(sizePolicy3);
        registrate->setFont(font2);
        registrate->setCursor(QCursor(Qt::PointingHandCursor));
        registrate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
"  background-color: rgba(200, 140, 80, 1);\n"
"  border-left: 1px solid rgba(180, 110, 80, 1);\n"
"  border-right: -1px solid rgba(180, 110, 80, 1);\n"
"  border-top: 5px solid rgba(180, 110, 80, 1);\n"
"  padding-top: 3px;  \n"
"  border-bottom: none;  \n"
"}"));

        verticalLayout_3->addWidget(registrate);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(200, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        verticalSpacer_5 = new QSpacerItem(20, 180, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_4->addItem(verticalSpacer_5);


        retranslateUi(authorization_window);

        QMetaObject::connectSlotsByName(authorization_window);
    } // setupUi

    void retranslateUi(QDialog *authorization_window)
    {
        authorization_window->setWindowTitle(QApplication::translate("authorization_window", "PokiRock", nullptr));
        label_3->setText(QApplication::translate("authorization_window", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; font-weight:600;\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217 \320\270 \320\277\320\260\321\200\320\276\320\273\321\214</span></p></body></html>", nullptr));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("authorization_window", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QApplication::translate("authorization_window", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        authorizate->setText(QApplication::translate("authorization_window", "\320\220\320\262\321\202\320\276\321\200\320\270\320\267\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        checkBox->setText(QApplication::translate("authorization_window", "\320\227\320\260\320\277\320\276\320\274\320\275\320\270\321\202\321\214 \320\274\320\265\320\275\321\217", nullptr));
        registrate->setText(QApplication::translate("authorization_window", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class authorization_window: public Ui_authorization_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_WINDOW_H
