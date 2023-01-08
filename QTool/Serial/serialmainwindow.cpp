#include "serialmainwindow.h"
#include "ui_serialmainwindow.h"

SerialMainWindow::SerialMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialMainWindow)
{
    showDataListModel = new QStringListModel(this);

    ui->setupUi(this);

    Init();


}

SerialMainWindow::~SerialMainWindow()
{
    delete ui;
    delete showDataListModel;
}

void SerialMainWindow::Init()
{
    ConnectInit();
    LabelInit();
    ComboBoxInit();
    CheckBoxInit();
    ButtonInit();
    RadioButtonInit();
    TextEditInit();
}

void SerialMainWindow::ConnectInit()
{
    // ui -> SerialMainWindow Connect Event
    connect(ui->serialConnectButton, SIGNAL(clicked()), this, SLOT(ConnectButtonClickEvent()));
    connect(ui->serialDisconnectButton, SIGNAL(clicked()), this, SLOT(DisconnectButtonClickEvent()));
    connect(ui->dataListViewClearButton, SIGNAL(clicked()), this, SLOT(DataListViewClearButtonClickEvent()));
    connect(ui->firstSendDataSendButton, SIGNAL(clicked()), this, SLOT(FirstSendDataButtonClickEvent()));
    connect(ui->secondSendDataSendButton, SIGNAL(clicked()), this, SLOT(SecondSendDataButtonClickEvent()));
    connect(ui->thirdSendDataSendButton, SIGNAL(clicked()), this, SLOT(ThirdSendDataButtonClickEvent()));
    connect(ui->firstSendDataClearButton, SIGNAL(clicked()), this, SLOT(FirstSendDataClearButtonClickEvent()));
    connect(ui->secondSendDataClearButton, SIGNAL(clicked()), this, SLOT(SecondSendDataClearButtonClickEvent()));
    connect(ui->thirdSendDataClearButton, SIGNAL(clicked()), this, SLOT(ThirdSendDataClearButtonClickEvent()));

    // SerialMainWindow -> SerialInterface Connect Event
    connect(this, SIGNAL(ConnectButtonClickSignal(QVariantList)), SERIALINTERFACE(), SLOT(ConnectSerialSlot(QVariantList)));
    connect(this, SIGNAL(DisconnectButtonClickSignal()), SERIALINTERFACE(), SLOT(CloseSerialSlot()));
    connect(this, SIGNAL(SendDataButtonClickSignal(QByteArray)), SERIALINTERFACE(), SLOT(SendDataSlot(QByteArray)));

    // SerialInterface -> SerialMainWindow Connect Event
    connect(SERIALINTERFACE(), SIGNAL(ShowReadDataSignal(QString)), this, SLOT(ShowReadDataSlot(QString)));
    connect(SERIALINTERFACE(), SIGNAL(ConnectionResultSignal(bool)), this, SLOT(ConnectionResultSlot(bool)));
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
    QVariantList portInfo = SERIALINTERFACE()->GetSerialPortInfo();

    for(int i = 0; i < portInfo.size(); i++) {
        ui->portNumberComboBox->addItem(portInfo[i].toString());
    }

    // Baud Rate Combo Box Data
    ui->baudRateComboBox->addItem(BAUD_RATE_COMBO_BOX_9600);
    ui->baudRateComboBox->addItem(BAUD_RATE_COMBO_BOX_1200);
    ui->baudRateComboBox->addItem(BAUD_RATE_COMBO_BOX_2400);
    ui->baudRateComboBox->addItem(BAUD_RATE_COMBO_BOX_4800);
    ui->baudRateComboBox->addItem(BAUD_RATE_COMBO_BOX_19200);
    ui->baudRateComboBox->addItem(BAUD_RATE_COMBO_BOX_38400);
    ui->baudRateComboBox->addItem(BAUD_RATE_COMBO_BOX_57600);
    ui->baudRateComboBox->addItem(BAUD_RATE_COMBO_BOX_115200);

    // Data Bits Combo Box Data
    ui->dataBitsComboBox->addItem(DATA_BITS_COMBO_BOX_8);
    ui->dataBitsComboBox->addItem(DATA_BITS_COMBO_BOX_5);
    ui->dataBitsComboBox->addItem(DATA_BITS_COMBO_BOX_6);
    ui->dataBitsComboBox->addItem(DATA_BITS_COMBO_BOX_7);
    ui->dataBitsComboBox->addItem(DATA_BITS_COMBO_BOX_NONE);

    // Stop Bits Combo Box Data
    ui->stopBitsComboBox->addItem(STOP_BITS_COMBO_BOX_1);
    ui->stopBitsComboBox->addItem(STOP_BITS_COMBO_BOX_2);
    ui->stopBitsComboBox->addItem(STOP_BITS_COMBO_BOX_3);
    ui->stopBitsComboBox->addItem(STOP_BITS_COMBO_BOX_NONE);

    // Parity Bits Combo Box Data
    ui->parityBitsComboBox->addItem(PARITY_BITS_COMBO_BOX_NO);
    ui->parityBitsComboBox->addItem(PARITY_BITS_COMBO_BOX_ODD);
    ui->parityBitsComboBox->addItem(PARITY_BITS_COMBO_BOX_EVEN);
    ui->parityBitsComboBox->addItem(PARITY_BITS_COMBO_BOX_SPACE);
    ui->parityBitsComboBox->addItem(PARITY_BITS_COMBO_BOX_MARK);
    ui->parityBitsComboBox->addItem(PARITY_BITS_COMBO_BOX_NONE);
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

    // List View Data Clear Button Text
    ui->dataListViewClearButton->setText(SEND_DATA_CLEAR_BUTTON_TEXT);

    ui->serialDisconnectButton->setEnabled(false);
}

void SerialMainWindow::RadioButtonInit()
{
    // Radio Button Text
    ui->noneRadioButton->setText(NONE_RADIO_BUTTON_TEXT);
    ui->crRadioButton->setText(CR_RADIO_BUTTON_TEXT);
    ui->lfRadioButton->setText(LF_RADIO_BUTTON_TEXT);
    ui->crLFRadioButton->setText(CR_LF_RADIO_BUTTON_TEXT);

    ui->noneRadioButton->setChecked(true);
    ui->crRadioButton->setChecked(false);
    ui->lfRadioButton->setChecked(false);
    ui->crLFRadioButton->setChecked(false);

}

/**
* @brief Text Edit Widget
* @details Returns the currently connected serial status
* @param void
* @return void
* @see SerialMainWindow
*/
void SerialMainWindow::TextEditInit()
{
    // Place holder Text
    ui->firstSendDataTextEdit->setPlaceholderText(SEND_DATA_PLACE_HOLDER);
    ui->secondSendDataTextEdit->setPlaceholderText(SEND_DATA_PLACE_HOLDER);
    ui->thirdSendDataTextEdit->setPlaceholderText(SEND_DATA_PLACE_HOLDER);
}

void SerialMainWindow::ConnectButtonClickEvent()
{
    QVariantList portInfo;

    portInfo << ui->portNumberComboBox->currentText();
    portInfo << ui->baudRateComboBox->currentIndex();
    portInfo << ui->dataBitsComboBox->currentIndex();
    portInfo << ui->stopBitsComboBox->currentIndex();
    portInfo << ui->parityBitsComboBox->currentIndex();

    emit ConnectButtonClickSignal(portInfo);

    showDataList.clear();
}

void SerialMainWindow::DisconnectButtonClickEvent()
{
    emit DisconnectButtonClickSignal();

    showDataList << DISCONNECT_MESSAGE;
    showDataListModel->setStringList(showDataList);

    ui->dataListView->setModel(showDataListModel);
    showDataList.clear();
}

void SerialMainWindow::ShowReadDataSlot(QString data)
{
    showDataList << data;
    showDataListModel->setStringList(showDataList);

    ui->dataListView->setModel(showDataListModel);
}

void SerialMainWindow::DataListViewClearButtonClickEvent()
{
    showDataList.clear();
    showDataListModel->setStringList({});
    ui->dataListView->setModel(showDataListModel);
}

void SerialMainWindow::ConnectionResultSlot(bool result)
{
    // Connection Success
    if(result == true) {
        showDataList << CONNECT_SUCCESS_MESSAGE;
        showDataListModel->setStringList(showDataList);

        ui->dataListView->setModel(showDataListModel);

        ui->serialConnectButton->setEnabled(false);
        ui->serialDisconnectButton->setEnabled(true);
    }
    // Connection Fail
    else {
        showDataList << CONNECT_FAIL_MESSAGE;
        showDataListModel->setStringList(showDataList);

        ui->dataListView->setModel(showDataListModel);

        ui->serialConnectButton->setEnabled(true);
        ui->serialDisconnectButton->setEnabled(false);
    }
}

void SerialMainWindow::FirstSendDataButtonClickEvent()
{
    QString str = ui->firstSendDataTextEdit->toPlainText();

    bool hexCheckBoxStatus = ui->firstSendDataCheckBoxHEX->isChecked();
    bool asciiCheckBoxStatus = ui->firstSendDataCheckBoxASCII->isChecked();

    QByteArray sendData;

    if((hexCheckBoxStatus == true) && (asciiCheckBoxStatus == false)) {
        sendData = QByteArray::fromHex(str.toLatin1());
    }
    else if((hexCheckBoxStatus == false) && (asciiCheckBoxStatus == true)) {
        sendData = str.toUtf8();
    }
    else {
        sendData = str.toLatin1();
    }

    emit SendDataButtonClickSignal(sendData);
}

void SerialMainWindow::SecondSendDataButtonClickEvent()
{
    QString str = ui->secondSendDataTextEdit->toPlainText();

    bool hexCheckBoxStatus = ui->secondSendDataCheckBoxHEX->isChecked();
    bool asciiCheckBoxStatus = ui->secondSendDataCheckBoxASCII->isChecked();

    QByteArray sendData;

    if((hexCheckBoxStatus == true) && (asciiCheckBoxStatus == false)) {
        sendData = QByteArray::fromHex(str.toLatin1());
    }
    else if((hexCheckBoxStatus == false) && (asciiCheckBoxStatus == true)) {
        sendData = str.toUtf8();
    }
    else {
        sendData = str.toLatin1();
    }

    emit SendDataButtonClickSignal(sendData);
}

void SerialMainWindow::ThirdSendDataButtonClickEvent()
{
    QString str = ui->thirdSendDataTextEdit->toPlainText();

    bool hexCheckBoxStatus = ui->thirdSendDataCheckBoxHEX->isChecked();
    bool asciiCheckBoxStatus = ui->thirdSendDataCheckBoxASCII->isChecked();

    QByteArray sendData;

    if((hexCheckBoxStatus == true) && (asciiCheckBoxStatus == false)) {
        sendData = QByteArray::fromHex(str.toLatin1());
    }
    else if((hexCheckBoxStatus == false) && (asciiCheckBoxStatus == true)) {
        sendData = str.toUtf8();
    }
    else {
        sendData = str.toLatin1();
    }

    emit SendDataButtonClickSignal(sendData);
}

void SerialMainWindow::FirstSendDataClearButtonClickEvent()
{
    ui->firstSendDataTextEdit->clear();
}

void SerialMainWindow::SecondSendDataClearButtonClickEvent()
{
    ui->secondSendDataTextEdit->clear();
}

void SerialMainWindow::ThirdSendDataClearButtonClickEvent()
{
    ui->thirdSendDataTextEdit->clear();
}
