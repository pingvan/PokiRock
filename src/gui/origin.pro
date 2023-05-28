QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Authorization_window.cpp \
    Main_menu.cpp \
    Registration_window.cpp \
    game.cpp \
    main.cpp \
    First_window.cpp \
    stickers_collection.cpp

HEADERS += \
    Authorization_window.h \
    First_window.h \
    Main_menu.h \
    Registration_window.h \
    game.h \
    stickers_collection.h \
    user.hpp \
    window_manager.h

FORMS += \
    Authorization_window.ui \
    First_window.ui \
    Main_menu.ui \
    Registration_window.ui \
    game.ui \
    stickers_collection.ui

TRANSLATIONS += \
    origin_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    clubs.qrc \
    cover.qrc \
    diamonds.qrc \
    hearts.qrc \
    labels.qrc \
    other.qrc \
    spades.qrc \
    stickers.qrc

DISTFILES += \
    images/labels/Prob-transformed.png \
    images/labels/label_1.png \
    images/labels/last_label.png \
    images/labels/main_label.png \
    images/labels/not_bad.png \
    images/labels/not_bad_but_green.png \
    images/labels/template.png
