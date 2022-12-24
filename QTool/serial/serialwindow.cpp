#include "serialwindow.h"
#include "ui_serialwindow.h"

SerialWindow::SerialWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialWindow)
{
    ui->setupUi(this);

    Init();
}

SerialWindow::~SerialWindow()
{
    delete ui;
}

void SerialWindow::Init()
{
    ToolBarInit();
    ConnectInit();
}

void SerialWindow::ConnectInit()
{
    // ToolBar Icon Click Event
    connect(newAction, &QAction::triggered, qApp, &QApplication::quit);
    connect(settingAction, SIGNAL(triggered()), this, SLOT(OpenSerialInfoSetting()));
    connect(exitAction, &QAction::triggered, qApp, &QApplication::quit);
}

void SerialWindow::ToolBarInit()
{

    toolBar = addToolBar("toolbar");

    newAction = AddToolBar(toolBar, newAction, "New", "../images/new_icon.png");
    settingAction = AddToolBar(toolBar, settingAction, "Setting", "../images/setting_icon.png");
    exitAction = AddToolBar(toolBar, exitAction, "Exit", "../images/exit_icon.png");

}

void SerialWindow::OpenSerialInfoSetting()
{
    qDebug() << "jehee";

    serialUi = new SerialSettingDialog(this);
    serialUi->show();
}
