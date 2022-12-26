#include "serialsettingdialog.h"
#include "ui_serialsettingdialog.h"

SerialSettingDialog::SerialSettingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialSettingDialog)
{
    ui->setupUi(this);

    Init();
}

SerialSettingDialog::~SerialSettingDialog()
{
    delete ui;
}

void SerialSettingDialog::Init()
{
    LabelInit();
    ComboBoxInit();
}

void SerialSettingDialog::ConnectInit()
{

}

void SerialSettingDialog::LabelInit()
{
    ui->settingLabel->setText(SERIAL_SETTING_LABEL);
    ui->baudrateLabel->setText(SERIAL_BAUDRATE_LABEL);
    ui->dataBitsLabel->setText(SERIAL_DATABITS_LABEL);
    ui->stopBitsLabel->setText(SERIAL_STOPBITS_LABEL);
    ui->parityBitsLabel->setText(SERIAL_PARITYBITS_LABEL);
}

void SerialSettingDialog::ComboBoxInit()
{
    // Set PortNumber ComboBox Init
    GetSerialPort();

    // Set Baudrate ComboBox Init
    ui->baudrateComboBox->addItem(BAUDRATE_115200);
    ui->baudrateComboBox->addItem(BAUDRATE_1200);
    ui->baudrateComboBox->addItem(BAUDRATE_2400);
    ui->baudrateComboBox->addItem(BAUDRATE_4800);
    ui->baudrateComboBox->addItem(BAUDRATE_9600);
    ui->baudrateComboBox->addItem(BAUDRATE_19200);
    ui->baudrateComboBox->addItem(BAUDRATE_28800);
    ui->baudrateComboBox->addItem(BAUDRATE_38400);
    ui->baudrateComboBox->addItem(BAUDRATE_57600);

    // Set Data Bits ComboBox Init
    ui->dataBitsComboBox->addItem(DATA_BITS_8BITS);
    ui->dataBitsComboBox->addItem(DATA_BITS_9BITS);

    // Set Stop Bits ComboBox Init
    ui->stopBitsComboBox->addItem(STOP_BITS_0BITS);
    ui->stopBitsComboBox->addItem(STOP_BITS_0BITS);

    // Set Paritiy Bits ComboBox Init
    ui->parityBitsComboBox->addItem(PARITIY_BITS_NONE);
    ui->parityBitsComboBox->addItem(PARITIY_BITS_ODD);
    ui->parityBitsComboBox->addItem(PARITIY_BITS_EVEN);
}

void SerialSettingDialog::GetSerialPort()
{
    const auto infos = QSerialPortInfo::availablePorts();

    ui->portNumberComboBox->clear();

    for(const QSerialPortInfo &info : infos) {
        ui->portNumberComboBox->addItem(info.portName());
    }
}
