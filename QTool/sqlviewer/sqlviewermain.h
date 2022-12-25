#ifndef SQLVIEWERMAIN_H
#define SQLVIEWERMAIN_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

#include "sqlviewerwindow.h"

#define SQLVIEWERMAIN()         SQLViewerMain::Instance()

class SQLViewerMain : public QObject, public Singleton<SQLViewerMain>
{
    Q_OBJECT

public:
    explicit SQLViewerMain(QObject *parent = nullptr);
    int GetQueryRowSize(QSqlQuery query);

private:

private slots:
    void SelectDatabase(QString dbPath);


private:
    QSqlDatabase db;
    int databaseRowCount;

};

#endif // SQLVIEWERMAIN_H
