#ifndef LOGVIEWERWINDOW_H
#define LOGVIEWERWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QAction>
#include <QToolBar>

namespace Ui {
class LogViewerWindow;
}

class LogViewerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LogViewerWindow(QWidget *parent = nullptr);
    ~LogViewerWindow();

private:
    Ui::LogViewerWindow *ui;

    QMenu *fileMenu;
    QAction *newAction;

    QToolBar *toolBar;
    QAction *addAction;
};

#endif // LOGVIEWERWINDOW_H
