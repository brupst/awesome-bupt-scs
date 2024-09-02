#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
int food_kinds_num;
int combo_kinds_num;
int order_num;
int queue_low_num;
int queue_high_num;
int data_read_state;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "McDonald_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
