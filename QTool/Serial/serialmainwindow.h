#ifndef SERIALMAINWINDOW_H
#define SERIALMAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QStringListModel>
#include <QFileDialog>

#include "serialinterface.h"

// Label Text
#define PORT_AREA_LABEL                 "Port"
#define PORT_NUMBER_LABEL               "Port Number"
#define BAUDRATE_LABEL                  "Baud Rate"
#define DATA_BITS_LABEL                 "Data Bits"
#define STOP_BITS_LABEL                 "Stop Bits"
#define PARITIY_BITS_LABEL              "Parity Bits"
#define CONNECTION_SET_AREA_LABEL       "Connection Set"
#define SEND_DATA_AREA_LABEL            "Send Data"
#define RECEIVED_SENT_AREA_LABEL        "Received/Send Data"
#define PACKET_AREA_LABEL               "Packet"

// Baud Rate Check Box Data
#define BAUD_RATE_COMBO_BOX_9600          "9600"
#define BAUD_RATE_COMBO_BOX_1200          "1200"
#define BAUD_RATE_COMBO_BOX_2400          "2400"
#define BAUD_RATE_COMBO_BOX_4800          "4800"
#define BAUD_RATE_COMBO_BOX_19200         "19200"
#define BAUD_RATE_COMBO_BOX_38400         "38400"
#define BAUD_RATE_COMBO_BOX_57600         "57600"
#define BAUD_RATE_COMBO_BOX_115200        "115200"

// Data Bits Check Box Data
#define DATA_BITS_COMBO_BOX_5         "5"
#define DATA_BITS_COMBO_BOX_6         "6"
#define DATA_BITS_COMBO_BOX_7         "7"
#define DATA_BITS_COMBO_BOX_8         "8"
#define DATA_BITS_COMBO_BOX_NONE      "-1"

// Stop Bits Check Box Data
#define STOP_BITS_COMBO_BOX_1         "1"
#define STOP_BITS_COMBO_BOX_2         "2"
#define STOP_BITS_COMBO_BOX_3         "3"
#define STOP_BITS_COMBO_BOX_NONE      "-1"

// Parity Bits Check Box Data
#define PARITY_BITS_COMBO_BOX_NO       "No Parity"
#define PARITY_BITS_COMBO_BOX_ODD      "Odd Parity"
#define PARITY_BITS_COMBO_BOX_EVEN     "Even Parity"
#define PARITY_BITS_COMBO_BOX_SPACE    "Space Parity"
#define PARITY_BITS_COMBO_BOX_MARK     "Mark Parity"
#define PARITY_BITS_COMBO_BOX_NONE     "Unknown"

// CheckBox Text
#define DTR_CHECK_BOX_TEXT              "DTR"
#define DSR_CHECK_BOX_TEXT              "DSR"
#define RTS_CHECK_BOX_TEXT              "RTS"
#define CTS_CHECK_BOX_TEXT              "CTS"
#define SEND_DATA_ASCII_TEXT            "ASCII"
#define SEND_DATA_HEX_TEXT              "HEX"

// Button Text
#define SERIAL_CONNECT_BUTTON_TEXT         "Serial Connect"
#define SERIAL_DISCONNECT_BUTTON_TEXT      "Serial Disconnect"
#define SAVE_DATA_BUTTON_TEXT              "Save Data"
#define SEARCH_DATA_BUTTON_TEXT            "Search Data"
#define SEND_DATA_SEND_BUTTON_TEXT         "Send"
#define SEND_DATA_CLEAR_BUTTON_TEXT        "Clear"

#define NONE_RADIO_BUTTON_TEXT          "None"
#define CR_RADIO_BUTTON_TEXT            "CR"
#define LF_RADIO_BUTTON_TEXT            "LF"
#define CR_LF_RADIO_BUTTON_TEXT         "CR + LF"

// Place Holder Text
#define SEND_DATA_PLACE_HOLDER      "Enter data to send"

#define CONNECT_SUCCESS_MESSAGE     "Serial Connect Success!\n\n"
#define CONNECT_FAIL_MESSAGE        "Serial Connect Fail!\n\n"
#define DISCONNECT_MESSAGE          "Serial Close..."

namespace Ui {
class SerialMainWindow;
}

class SerialMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialMainWindow(QWidget *parent = nullptr);
    ~SerialMainWindow();

public slots:

public:

private:
    void Init();
    void ConnectInit();
    void LabelInit();
    void ComboBoxInit();
    void CheckBoxInit();
    void ButtonInit();
    void RadioButtonInit();
    void TextEditInit();

private slots:
    // UI Event
    void ConnectButtonClickEvent();
    void DisconnectButtonClickEvent();
    void DataListViewClearButtonClickEvent();
    void FirstSendDataButtonClickEvent();
    void SecondSendDataButtonClickEvent();
    void ThirdSendDataButtonClickEvent();
    void FirstSendDataClearButtonClickEvent();
    void SecondSendDataClearButtonClickEvent();
    void ThirdSendDataClearButtonClickEvent();

    // Data Event
    void ShowReadDataSlot(QString data);
    void ConnectionResultSlot(bool result);

private:
    Ui::SerialMainWindow *ui;
    QStringListModel *showDataListModel;
    QStringList showDataList;

signals:
    void ConnectButtonClickSignal(QVariantList);
    void DisconnectButtonClickSignal();
    void SendDataButtonClickSignal(QByteArray);
};

#endif // SERIALMAINWINDOW_H
