#ifndef SQLVIEWERWINDOW_H
#define SQLVIEWERWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QDebug>
#include <QPixmap>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include "common.h"
#include "singleton.h"
#include "commonwindow.h"
#include "sqlviewermain.h"

namespace Ui {
class SQLViewerWindow;
}

#define SQLVIEWERWINDOW()         SQLViewerWindow::Instance()

class SQLViewerMain;

class SQLViewerWindow : public QMainWindow, public CommonWindow, public Singleton<SQLViewerWindow>
{
    Q_OBJECT

public:
    explicit SQLViewerWindow(QWidget *parent = nullptr);
    ~SQLViewerWindow();

public slots:
    void OpenDB();

private:
    void Init();
    void MenuInit();
    void ToolBarInit();
    void TreeWidgetInit();
    void ConnectInit();

signals:
    void SignalSelectDatabase(QString dbPath);

private:
    Ui::SQLViewerWindow *ui;    

    QToolBar *toolBar;
    QAction *newAction;
    QAction *settingAction;
    QAction *exitAction;

    QString openFilePath = "";

    QTreeWidgetItem *tableHeader;
    QTreeWidgetItem *tableParent;
};

#endif // SQLVIEWERWINDOW_H
