#include "sqlviewerwindow.h"
#include "ui_sqlviewerwindow.h"

SQLViewerWindow::SQLViewerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SQLViewerWindow)
{
    ui->setupUi(this);

    Init();
}

SQLViewerWindow::~SQLViewerWindow()
{
    delete ui;
}

void SQLViewerWindow::Init()
{
    ToolBarInit();
    ConnectInit();
}

void SQLViewerWindow::MenuInit()
{

}

void SQLViewerWindow::ToolBarInit()
{
    toolBar = addToolBar("toolbar");

    newAction = AddToolBar(toolBar, newAction, DATABASE_OPEN_TEXT, "../images/new_icon.png");
    exitAction = AddToolBar(toolBar, exitAction, EXIT_TEXT, "../images/exit_icon.png");
}

void SQLViewerWindow::ConnectInit()
{
    // ToolBar Icon Click Event
    connect(newAction, SIGNAL(triggered()), this, SLOT(OpenDB()));
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
}

void SQLViewerWindow::OpenDB()
{
    openFilePath = OpenFileDialog(this, openFilePath);
}
