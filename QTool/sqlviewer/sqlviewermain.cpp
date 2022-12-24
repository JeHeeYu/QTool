#include "sqlviewermain.h"

SQLViewerMain::SQLViewerMain(QObject *parent) : QObject(parent)
{
    ConnectInit();

    qDebug() << "Jehee Constructor";
}

void SQLViewerMain::ConnectInit()
{
    // DB Open
    connect(SQLVIEWERWINDOW(), SIGNAL(SignalSelectDatabase(QString)), this, SLOT(SelectDatabase(QString)));
}

void SQLViewerMain::SelectDatabase(QString dbPath)
{
    qDebug() << "ehe test : " << dbPath;


}
