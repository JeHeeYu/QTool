#ifndef COMMONWINDOW_H
#define COMMONWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QString>
#include <QPixmap>
#include <QFileDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>

#include "common.h"

class CommonWindow
{

protected:
    QAction* AddToolBar(QToolBar *bar, QAction *action, QString actionText, QString iconPath = "");
    QString OpenFileDialog(QWidget *widget, QString filePath);

    void AddTreeWidgetHeader(QTreeWidget *treeWidget, QTreeWidgetItem *treeItem, int index, QString text, bool end);

protected:

};

#endif // COMMONWINDOW_H
