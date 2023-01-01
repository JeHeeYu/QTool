#ifndef SERIALMAIN_H
#define SERIALMAIN_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

class SerialMain : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QVariantList serialPortInfo READ GetSerialPortInfo WRITE SetSerialPortInfo)
    Q_PROPERTY(QString readData READ GetReadData WRITE SetReadData NOTIFY ChangedReadData)
    Q_PROPERTY(bool connectionStatus READ GetConnectionStatus WRITE SetConnectionStatus NOTIFY ChangedConnectionStatus)


public:
    explicit SerialMain(QObject *parent = nullptr);
    ~SerialMain();

    Q_INVOKABLE void jeheetest(int i);
    Q_INVOKABLE void connectionSerial(QVariantList info);

public slots:

public:
    QString GetReadData();
    bool GetConnectionStatus();

private:
    void ConnectInit();
    void ReadSerialPort();
    void SetSerialPortInfo(QVariant info);
    const QVariantList GetSerialPortInfo();

    void SetPortNumber(QSerialPort *serial, const QString port);
    void SetBaudRate(QSerialPort *serial, qint32 baudRate);
    void SetDataBits(QSerialPort *serial, int dataBits);
    void SetStopBits(QSerialPort *serial, int stopBits);
    void SetParityBits(QSerialPort *serial, int parity);
    void SetFlowControlBits(QSerialPort *serial, int flowControl);

    void SetReadData(QString data);
    void SetConnectionStatus(bool status);


private slots:
    void ReadData();

private:
    QVariantList serialPortInfo;
    QSerialPort *serialPort = nullptr;
    bool connectionStatus = false;
    QString readData = "";

    int zz = 0;

signals:
    void ChangedConnectionStatus();
    void ChangedReadData();
};

#endif // SERIALMAIN_H
