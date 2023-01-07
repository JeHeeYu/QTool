#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QVariant>
#include <QDebug>

#include "serialmainwindow.h"
#include "Common/singleton.h"

#define SERIALINTERFACE()       SerialInterface::Instance()

enum
{
    // Baud Rate Index 0 ~ 7
    BAUD_RATE_9600,
    BAUD_RATE_1200,
    BAUD_RATE_2400,
    BAUD_RATE_4800,
    BAUD_RATE_19200,
    BAUD_RATE_38400,
    BAUD_RATE_57600,
    BAUD_RATE_115200
};

enum
{
    // Data Bit Index 0 ~ 4
    DATA_BITS_8,
    DATA_BITS_5,
    DATA_BITS_6,
    DATA_BITS_7,
    DATA_BITS_UNKNOWN,
};

enum
{
    // Stop Bit Index 0 ~ 3
    STOP_BITS_1,
    STOP_BITS_2,
    STOP_BITS_3,
    STOP_BITS_UNKNOWN
};

enum
{
    // Parity Bit Index 0 ~ 5
    PARITY_BITS_NO,
    PARITY_BITS_ODD,
    PARITY_BITS_EVEN,
    PARITY_BITS_SPACE,
    PARITY_BITS_MRAK,
    PARITY_BITS_UNKNOWN
};


class SerialInterface : public QObject, public Singleton<SerialInterface>
{
    Q_OBJECT

public:
    explicit SerialInterface();
    ~SerialInterface();
    QVariantList GetSerialPortInfo();

public slots:
public:

private:
    void ConnectInit();
    void ReadSerialPortInfo();
    void SetSerialPortInfo(QVariant port);
    void SetPortNumber(QSerialPort *serial, const QString port);
    void SetBaudRate(QSerialPort *serial, int index);
    void SetDataBits(QSerialPort *serial, int index);
    void SetStopBits(QSerialPort *serial, int index);
    void SetParityBits(QSerialPort *serial, int index);

private slots:
    void ConnectSerialSlot(QVariantList data);
    void CloseSerialSlot();
    void ReadDataSlot();

private:
    QVariantList portInfo;
    QSerialPort *serialPort;
    bool connectionStatus = false;

signals:
    void ShowReadDataSignal(QString);
    void ConnectionResultSignal(bool);
};

#endif // SERIALINTERFACE_H
