#include "sqlviewerwindow.h"
#include "ui_sqlviewerwindow.h"

SQLViewerWindow::SQLViewerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SQLViewerWindow)
{
    ui->setupUi(this);

    tableHeader = new QTreeWidgetItem();
    tableParent = new QTreeWidgetItem();

    Init();
}

SQLViewerWindow::~SQLViewerWindow()
{
    delete ui;

    delete tableHeader;
    delete tableParent;
}

void SQLViewerWindow::Init()
{
    ToolBarInit();
    ConnectInit();
    TreeWidgetInit();
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

void SQLViewerWindow::TreeWidgetInit()
{

//    // Header Text Aligment
    ui->structureTree->header()->setDefaultAlignment(Qt::AlignCenter);

    AddTreeWidgetHeader(ui->structureTree, tableHeader, SQL_NAME_INDEX, SQL_NAME_TEXT, false);
    AddTreeWidgetHeader(ui->structureTree, tableHeader, SQL_TYPE_INDEX, SQL_TYPE_TEXT, false);
    AddTreeWidgetHeader(ui->structureTree, tableHeader, SQL_SCHEMA_INDEX, SQL_SCHENA_TEXT, true);

    QTreeWidgetItem* row1 = new QTreeWidgetItem(ui->structureTree);
    row1->setText(0, "Tables");

    QTreeWidgetItem* subItem1 = new QTreeWidgetItem;
    subItem1->setText(0, "? - 1");
    subItem1->setText(1, "? - 2");
    subItem1->setText(2, "? - 3");
    row1->addChild(subItem1);

    QTreeWidgetItem* subItem2 = new QTreeWidgetItem;
    subItem2->setText(0, "? - 1");
    subItem2->setText(1, "? - 2");
    row1->addChild(subItem2);
}

void SQLViewerWindow::ConnectInit()
{
    // ToolBar Icon Click Event
    connect(newAction, SIGNAL(triggered()), this, SLOT(OpenDB()));
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);

    connect(this, SIGNAL(SignalSelectDatabase(QString)), SQLVIEWERMAIN(), SLOT(SelectDatabase(QString)));
}

void SQLViewerWindow::OpenDB()
{
    openFilePath = OpenFileDialog(this, openFilePath);

    qDebug() << "Jehee OpenDB" << openFilePath;
    emit SignalSelectDatabase(openFilePath);
}
