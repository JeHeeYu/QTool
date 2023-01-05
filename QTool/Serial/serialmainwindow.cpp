#include "serialmainwindow.h"
#include "ui_serialmainwindow.h"

SerialMainWindow::SerialMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialMainWindow)
{
    ui->setupUi(this);

    Init();

    ui->textEdit->setPlaceholderText("Jehee");
}

SerialMainWindow::~SerialMainWindow()
{
    delete ui;
}

void SerialMainWindow::Init()
{
    LabelInit();
    ComboBoxInit();
    CheckBoxInit();
    ButtonInit();
    RadioButtonInit();
}

void SerialMainWindow::LabelInit()
{
    // Port Info Area Label
    ui->portAreaLabel->setText(PORT_AREA_LABEL);
    ui->portNumberLabel->setText(PORT_NUMBER_LABEL);
    ui->baudRateLabel->setText(BAUDRATE_LABEL);
    ui->dataBitsLabel->setText(DATA_BITS_LABEL);
    ui->stopBitsLabel->setText(STOP_BITS_LABEL);
    ui->parityBitsLabel->setText(PARITIY_BITS_LABEL);

    // Area Main Text
    ui->sendDataAreaLabel->setText(SEND_DATA_AREA_LABEL);
    ui->receivedSentAreaLabel->setText(RECEIVED_SENT_AREA_LABEL);
    ui->packetAreaLabel->setText(PACKET_AREA_LABEL);
    ui->connectionSetLabel->setText(CONNECTION_SET_AREA_LABEL);
}

void SerialMainWindow::ComboBoxInit()
{
    // Baud Rate Combo Box Data
    ui->baudRateComboBox->addItem(BAUD_RATE_9600);
    ui->baudRateComboBox->addItem(BAUD_RATE_1200);
    ui->baudRateComboBox->addItem(BAUD_RATE_2400);
    ui->baudRateComboBox->addItem(BAUD_RATE_4800);
    ui->baudRateComboBox->addItem(BAUD_RATE_19200);
    ui->baudRateComboBox->addItem(BAUD_RATE_38400);
    ui->baudRateComboBox->addItem(BAUD_RATE_57600);
    ui->baudRateComboBox->addItem(BAUD_RATE_115200);

    // Data Bits Combo Box Data
    ui->dataBitsComboBox->addItem(DATA_BITS_5);
    ui->dataBitsComboBox->addItem(DATA_BITS_6);
    ui->dataBitsComboBox->addItem(DATA_BITS_7);
    ui->dataBitsComboBox->addItem(DATA_BITS_8);
    ui->dataBitsComboBox->addItem(DATA_BITS_NONE);

    // Stop Bits Combo Box Data
    ui->stopBitsComboBox->addItem(STOP_BITS_1);
    ui->stopBitsComboBox->addItem(STOP_BITS_2);
    ui->stopBitsComboBox->addItem(STOP_BITS_3);
    ui->stopBitsComboBox->addItem(STOP_BITS_NONE);

    // Parity Bits Combo Box Data
    ui->parityBitsComboBox->addItem(PARITY_BITS_1);
    ui->parityBitsComboBox->addItem(PARITY_BITS_2);
    ui->parityBitsComboBox->addItem(PARITY_BITS_3);
    ui->parityBitsComboBox->addItem(PARITY_BITS_NONE);
}

void SerialMainWindow::CheckBoxInit()
{
    // Check Box Text
    ui->dtrCheckBox->setText(DTR_CHECK_BOX_TEXT);
    ui->dsrCheckBox->setText(DSR_CHECK_BOX_TEXT);
    ui->rtsCheckBox->setText(RTS_CHECK_BOX_TEXT);
    ui->ctsCheckBox->setText(CTS_CHECK_BOX_TEXT);

    // Send Data Check Box Text
    ui->firstSendDataCheckBoxASCII->setText(SEND_DATA_ASCII_TEXT);
    ui->firstSendDataCheckBoxHEX->setText(SEND_DATA_HEX_TEXT);
    ui->secondSendDataCheckBoxASCII->setText(SEND_DATA_ASCII_TEXT);
    ui->secondSendDataCheckBoxHEX->setText(SEND_DATA_HEX_TEXT);
    ui->thirdSendDataCheckBoxASCII->setText(SEND_DATA_ASCII_TEXT);
    ui->thirdSendDataCheckBoxHEX->setText(SEND_DATA_HEX_TEXT);
}

void SerialMainWindow::ButtonInit()
{
    // Button Text
    ui->serialConnectButton->setText(SERIAL_CONNECT_BUTTON_TEXT);
    ui->serialDisconnectButton->setText(SERIAL_DISCONNECT_BUTTON_TEXT);
    ui->saveDataButton->setText(SAVE_DATA_BUTTON_TEXT);
    ui->searchDataButton->setText(SEARCH_DATA_BUTTON_TEXT);

    // Send Data Button Text
    ui->firstSendDataSendButton->setText(SEND_DATA_SEND_BUTTON_TEXT);
    ui->firstSendDataClearButton->setText(SEND_DATA_CLEAR_BUTTON_TEXT);
    ui->secondSendDataSendButton->setText(SEND_DATA_SEND_BUTTON_TEXT);
    ui->secondSendDataClearButton->setText(SEND_DATA_CLEAR_BUTTON_TEXT);
    ui->thirdSendDataSendButton->setText(SEND_DATA_SEND_BUTTON_TEXT);
    ui->thirdSendDataClearButton->setText(SEND_DATA_CLEAR_BUTTON_TEXT);
}

void SerialMainWindow::RadioButtonInit()
{
    // Radio Button Text
    ui->noneRadioButton->setText(NONE_RADIO_BUTTON_TEXT);
    ui->crRadioButton->setText(CR_RADIO_BUTTON_TEXT);
    ui->lfRadioButton->setText(LF_RADIO_BUTTON_TEXT);
    ui->crLFRadioButton->setText(CR_LF_RADIO_BUTTON_TEXT);
}

void SerialMainWindow::TextEditInit()
{

}
