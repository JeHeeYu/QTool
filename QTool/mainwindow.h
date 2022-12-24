#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QToolBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void Run();
    void Init();

    void MenuBarInit();
    void MenuBarActionIInit();

    void ToolBarInit();


private:
    Ui::MainWindow *ui;

    QMenu *fileMenu;
    QAction *newAction;

    QToolBar *toolBar;
    QAction *addAction;
};

#endif // MAINWINDOW_H
