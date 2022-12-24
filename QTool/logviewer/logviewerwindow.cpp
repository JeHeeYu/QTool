#include "logviewerwindow.h"
#include "ui_logviewerwindow.h"

LogViewerWindow::LogViewerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LogViewerWindow)
{
    ui->setupUi(this);

    newAction = new QAction(tr("&New"), this);
    newAction->setShortcut(tr("Ctrl+N"));


    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);

    toolBar = addToolBar("main Toolbar");
    toolBar->addAction("New");
}

LogViewerWindow::~LogViewerWindow()
{
    delete ui;
}
