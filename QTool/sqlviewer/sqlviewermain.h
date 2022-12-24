#ifndef SQLVIEWERMAIN_H
#define SQLVIEWERMAIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

#include "sqlviewerwindow.h"

class SQLViewerMain
{
public:
    SQLViewerMain();

private slots:
    void SelectDatabase(QString);


private:
    QSqlDatabase db;
};

#endif // SQLVIEWERMAIN_H
