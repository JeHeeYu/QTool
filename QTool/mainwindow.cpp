#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "serial/serialwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);


    newAction = new QAction(tr("&New"), this);
    newAction->setShortcut(tr("Ctrl+N"));


    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAction);

    toolBar = addToolBar("main Toolbar");
    toolBar->addAction("New");
}

MainWindow::~MainWindow()
{
    delete ui;
}

