#include "serialsettingdialog.h"
#include "ui_serialsettingdialog.h"

SerialSettingDialog::SerialSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialSettingDialog)
{
    ui->setupUi(this);

    Init();

    SerialInterface s;

    s.SerialPortInfo();
}

SerialSettingDialog::~SerialSettingDialog()
{
    delete ui;
}

void SerialSettingDialog::Init()
{
    InitLabel();
}

void SerialSettingDialog::InitLabel()
{
    ui->settingLabel->setText(SERIAL_SETTING_LABEL);
    ui->baudrateLabel->setText(SERIAL_BAUDRATE_LABEL);
    ui->dataBitsLabel->setText(SERIAL_DATABITS_LABEL);
    ui->stopBitsLabel->setText(SERIAL_STOPBITS_LABEL);
    ui->parityBitsLabel->setText(SERIAL_PARITYBITS_LABEL);
}

void SerialSettingDialog::ComboBoxInit()
{

}
