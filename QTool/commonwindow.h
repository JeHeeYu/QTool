#ifndef COMMONWINDOW_H
#define COMMONWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QString>
#include <QPixmap>
#include <QFileDialog>

#include "common.h"

class CommonWindow
{

protected:
    QAction* AddToolBar(QToolBar *bar, QAction *action, QString actionText, QString iconPath = "");
    QString OpenFileDialog(QWidget *widget, QString filePath);

protected:

};

#endif // COMMONWINDOW_H
