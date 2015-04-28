#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef Q_OS_LINUX
    QString slash = "/";
#endif
#ifdef Q_OS_WIN
    QString slash = "\\";
#endif

    QTranslator tran;
    tran.load(QApplication::applicationDirPath() + slash + "wheel_ru");
    a.installTranslator(&tran);

    MainWindow w;
    //w.show();
    //w.showFullScreen();
    w.showMaximized();

    return a.exec();
}
