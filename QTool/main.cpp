#include "mainwindow.h"
#include <QApplication>

#include "common.h"
#include "sqlviewer/sqlviewerwindow.h"
#include "serial/serialwindow.h".h"
#include "sqlviewer/sqlviewermain.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //SQLViewerWindow s;
    SerialWindow s;
    SQLViewerMain m;

    //w.resize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
    //w.show();

//    s2.resize(WINDOW_SIZE_X, WINDOW_SIZE_Y);
//    s2.show();

    s.resize(WINDOW_SIZE_X, WINDOW_SIZE_Y);

    s.show();

    return a.exec();
}
