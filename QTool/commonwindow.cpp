#include "commonwindow.h"


QAction* CommonWindow::AddToolBar(QToolBar *toolBar, QAction *action, QString actionText, QString iconPath)
{
    QPixmap pixmap(iconPath);

    action = toolBar->addAction(QIcon(pixmap), actionText);
    toolBar->addSeparator();
    toolBar->setIconSize(QSize(TOOL_BAR_ICON_SIZE_X, TOOL_BAR_ICON_SIZE_Y));
    toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    return action;
}

QString CommonWindow::OpenFileDialog(QWidget *widget, QString filePath)
{
    QString path;

    if(filePath == "") {
        path = QFileDialog::getOpenFileName(widget, "Search Folder", QDir::homePath(),"Files (*.*)");
    }
    else {
        path = QFileDialog::getOpenFileName(widget, "Search Folder", filePath,"Files (*.*)");
    }

    return path;
}
