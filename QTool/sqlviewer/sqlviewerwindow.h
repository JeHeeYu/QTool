#ifndef SQLVIEWERWINDOW_H
#define SQLVIEWERWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QAction>
#include <QDebug>
#include <QPixmap>

#include "common.h"
#include "singleton.h"
#include "commonwindow.h"

namespace Ui {
class SQLViewerWindow;
}

#define SQLVIEWERWINDOW()         SQLViewerWindow::Instance()

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
};

#endif // SQLVIEWERWINDOW_H
