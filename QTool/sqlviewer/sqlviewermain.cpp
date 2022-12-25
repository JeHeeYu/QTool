#include "sqlviewermain.h"

SQLViewerMain::SQLViewerMain(QObject *parent) : QObject(parent)
{
}

void SQLViewerMain::SelectDatabase(QString dbPath)
{
    qDebug() << "jehee test : " << dbPath;

    db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("/home/jhy/workstation/QTool/sample/chinook.db");

    if(!db.open()) {
        qDebug() << "Db Open Fail!";
    }

    if(db.isValid()) {
        qDebug() << "Database is Valid!";
    }
    else {
        qDebug() << "Database is Not Valid!";
    }

    QSqlQuery query(db);

    query.exec("SELECT * FROM sqlite_master WHERE type='table';");

    qDebug() << GetQueryRowSize(query);

    query.clear();
    db.close();
}

int SQLViewerMain::GetQueryRowSize(QSqlQuery query)
{
    if(!query.isValid()) {
        qDebug() << "Query is Valid";
    }

    databaseRowCount = 0;

    while(query.next()) {

        databaseRowCount++;
    }

    return databaseRowCount;
}
