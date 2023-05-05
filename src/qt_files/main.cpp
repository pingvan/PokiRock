#include "First_window.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

void magic_with_translator(QApplication* a) {
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "origin_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a->installTranslator(&translator);
            break;
        }
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    magic_with_translator(&a);

    first_window w;
    w.showFullScreen();
    return a.exec();
}
