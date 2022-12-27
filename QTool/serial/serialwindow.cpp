#include "serialwindow.h"
#include "ui_serialwindow.h"

SerialWindow::SerialWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialWindow)
{
    ui->setupUi(this);

    Init();

    QPixmap pix("../images/red_indicator_2.png");
    ui->label->setPixmap(pix);

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

void SerialWindow::paintEvent(QPaintEvent *event)
{
    QPainter ellipsePainter(this);
    QPen pen;
    //pen.setWidth(8);
    pen.setBrush(Qt::red);
    ellipsePainter.setBrush(Qt::red);
    ellipsePainter.setPen(pen);

    ellipsePainter.drawEllipse(QRect(1200, 100, 20, 20));

    QPainter ellipsePainter2(this);
    QPen pen2;
    pen.setWidth(8);
    pen2.setBrush(Qt::green);
    ellipsePainter2.setBrush(Qt::green);
    ellipsePainter2.setPen(pen2);

    ellipsePainter2.drawEllipse(QRect(1300, 100, 20, 20));
}
