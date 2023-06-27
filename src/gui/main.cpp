#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "window_manager.h"
#include <condition_variable>

using namespace std::literals::chrono_literals;

void magic_with_translator(QApplication *a) {
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

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    magic_with_translator(&a);
//    client this_client(grpc::CreateChannel(server_address, grpc::InsecureChannelCredentials()));
    WindowManager manager/*(this_client)*/;
    manager.start();

    a.exec();

    return 0;
}
