#include "serialmain.h"

SerialMain::SerialMain(QObject *parent) : QObject {parent}
{
    ReadSerialPort();

    serialPort = new QSerialPort(this);

    qDebug() << "Jehee ZZ : " << GetSerialPortInfo();

    ConnectInit();
}

SerialMain::~SerialMain()
{
    delete serialPort;
}

void SerialMain::ConnectInit()
{
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(ReadData()));
}

void SerialMain::ReadSerialPort()
{
    const auto infos = QSerialPortInfo::availablePorts();

    qDebug() << "SerialPortInfo : " << QSerialPortInfo::availablePorts().count();

    for(const QSerialPortInfo &info : infos) {
        SetSerialPortInfo(info.portName());
    }
}

void SerialMain::SetSerialPortInfo(QVariant info)
{
    serialPortInfo << info;
}

const QVariantList SerialMain::GetSerialPortInfo()
{
    return serialPortInfo;
}

void SerialMain::jeheetest(int i)
{
    qDebug() << "Jehee test : " << i;
}

void SerialMain::ReadData()
{
    const QByteArray data = serialPort->readAll();

    qDebug() << "Jehee Data : " << data;
}

void SerialMain::ConnectionSerial(QVariantList info)
{
    qDebug() << "ConnectionSerial : " << info;

    SetPortNumber(serialPort, info[0].toString());
    SetBaudRate(serialPort, info[1].toInt());
    SetDataBits(serialPort, info[2].toInt());
    SetStopBits(serialPort, info[3].toInt());
    SetParityBits(serialPort, info[4].toInt());
    SetFlowControlBits(serialPort, info[5].toInt());

    if(!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Serial Open Fail" << info[0].toString();
    }
}

void SerialMain::SetPortNumber(QSerialPort *serial, const QString port)
{
    serial->setPortName(port);
}

void SerialMain::SetBaudRate(QSerialPort *serial, qint32 baudRate)
{
    serial->setBaudRate(QSerialPort::Baud115200);
}

void SerialMain::SetDataBits(QSerialPort *serial, int dataBits)
{
    if(dataBits == 0) {
        serial->setDataBits(QSerialPort::Data8);
    }
    else if(dataBits == 1) {
        serial->setDataBits(QSerialPort::Data5);
    }
    else if(dataBits == 2) {
        serial->setDataBits(QSerialPort::Data6);
    }
    else if(dataBits == 3) {
        serial->setDataBits(QSerialPort::Data7);
    }
    else {
        serial->setDataBits(QSerialPort::UnknownDataBits);
    }

}

void SerialMain::SetStopBits(QSerialPort *serial, int stopBits)
{
    if(stopBits == 0) {
        serial->setStopBits(QSerialPort::OneStop);
    }
    else if(stopBits == 1) {
        serial->setStopBits(QSerialPort::TwoStop);
    }
    else if(stopBits == 2) {
        serial->setStopBits(QSerialPort::OneAndHalfStop);
    }
    else {
        serial->setStopBits(QSerialPort::UnknownStopBits);
    }
}

void SerialMain::SetParityBits(QSerialPort *serial, int parity)
{
    if(parity == 0) {
        serial->setParity(QSerialPort::NoParity);
    }
    else if(parity == 1) {
        serial->setParity(QSerialPort::EvenParity);
    }
    else if(parity == 2) {
        serial->setParity(QSerialPort::OddParity);
    }
    else if(parity == 3) {
        serial->setParity(QSerialPort::SpaceParity);
    }
    else if(parity == 4) {
        serial->setParity(QSerialPort::MarkParity);
    }
    else {
        serial->setParity(QSerialPort::UnknownParity);
    }
}

void SerialMain::SetFlowControlBits(QSerialPort *serial, int flowControl)
{
    if(flowControl == 0) {
        serial->setFlowControl(QSerialPort::NoFlowControl);
    }
    else if(flowControl == 1) {
        serial->setFlowControl(QSerialPort::HardwareControl);
    }
    else if(flowControl == 2) {
        serial->setFlowControl(QSerialPort::SoftwareControl);
    }
    else {
        serial->setFlowControl(QSerialPort::UnknownFlowControl);
    }
}
