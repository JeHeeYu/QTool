#include "serialmainwindow.h"
#include "ui_serialmainwindow.h"

SerialMainWindow::SerialMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialMainWindow)
{
    ui->setupUi(this);
}

SerialMainWindow::~SerialMainWindow()
{
    delete ui;
}
