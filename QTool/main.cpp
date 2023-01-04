#include "mainwindow.h"

#include <QApplication>

#include <Serial/serialmainwindow.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //w.show();

    SerialMainWindow s;

    s.show();
    s.resize(1280, 820);

    return a.exec();
}
