#ifndef SERIALMAINWINDOW_H
#define SERIALMAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>

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
#define BAUD_RATE_9600          "9600"
#define BAUD_RATE_1200          "1200"
#define BAUD_RATE_2400          "2400"
#define BAUD_RATE_4800          "4800"
#define BAUD_RATE_19200         "19200"
#define BAUD_RATE_38400         "38400"
#define BAUD_RATE_57600         "57600"
#define BAUD_RATE_115200        "115200"

// Data Bits Check Box Data
#define DATA_BITS_5         "5"
#define DATA_BITS_6         "6"
#define DATA_BITS_7         "7"
#define DATA_BITS_8         "8"
#define DATA_BITS_NONE      "-1"

// Stop Bits Check Box Data
#define STOP_BITS_1         "1"
#define STOP_BITS_2         "2"
#define STOP_BITS_3         "3"
#define STOP_BITS_NONE      "-1"

// Parity Bits Check Box Data
#define PARITY_BITS_1       "1"
#define PARITY_BITS_2       "2"
#define PARITY_BITS_3       "3"
#define PARITY_BITS_NONE    "-1"

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
    void LabelInit();
    void ComboBoxInit();
    void CheckBoxInit();
    void ButtonInit();
    void RadioButtonInit();
    void TextEditInit();

private:
    Ui::SerialMainWindow *ui;

signals:
};

#endif // SERIALMAINWINDOW_H
