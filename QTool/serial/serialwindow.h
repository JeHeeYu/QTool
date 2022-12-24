#ifndef SERIALWINDOW_H
#define SERIALWINDOW_H

#include <QMainWindow>

#include <QToolBar>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QDebug>

#include "singleton.h"
#include "common.h"
#include "commonwindow.h"
#include "serialsettingdialog.h"

namespace Ui {
class SerialWindow;
}

class SerialWindow : public QMainWindow, public CommonWindow
{
    Q_OBJECT

public:
    explicit SerialWindow(QWidget *parent = nullptr);
    ~SerialWindow();


private:
    void Init();
    void ToolBarInit();
    void ConnectInit();

private slots:
    void OpenSerialInfoSetting();


public:

private:
    Ui::SerialWindow *ui;

    SerialSettingDialog *serialUi;

    QToolBar *toolBar;
    QAction *newAction;
    QAction *settingAction;
    QAction *exitAction;
};

#endif // SERIALWINDOW_H
