#include "serialinterface.h"

SerialInterface::SerialInterface()
{
    ReadSerialPortInfo();

    serialPort = new QSerialPort(this);

    ConnectInit();
}

SerialInterface::~SerialInterface()
{
    delete serialPort;
}

void SerialInterface::ConnectInit()
{
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(ReadDataSlot()));
}

void SerialInterface::ConnectSerialSlot(QVariantList data)
{
    qDebug() << "Serial Port Info : " << data;

    /*
     * VarintList Index Info
     * 0 : Serial Port
     * 1 : Baud Rate
     * 2 : Data Bit
     * 3 : Stop Bit
     * 4 : Parity Bit
    */

    SetPortNumber(serialPort, data[0].toString());
    SetBaudRate(serialPort, data[1].toInt());
    SetDataBits(serialPort, data[2].toInt());
    SetStopBits(serialPort, data[3].toInt());
    SetParityBits(serialPort, data[4].toInt());

    // Connection Serial Port
    if(!serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Serial Open Fail";
        connectionStatus = false;
    }
    else {
        qDebug() << "Serial Open Success";
        connectionStatus = true;
    }

    emit ConnectionResultSignal(connectionStatus);
}

void SerialInterface::CloseSerialSlot()
{
    serialPort->close();

    connectionStatus = false;
    emit ConnectionResultSignal(connectionStatus);
}

void SerialInterface::ReadSerialPortInfo()
{
    portInfo.clear();

    const auto infos = QSerialPortInfo::availablePorts();

    qDebug() << "SerialPortInfo : " << QSerialPortInfo::availablePorts().count();

    for(const QSerialPortInfo &info : infos) {
        SetSerialPortInfo(info.portName());
    }
}

void SerialInterface::SetSerialPortInfo(QVariant port)
{
    portInfo << port;
}

QVariantList SerialInterface::GetSerialPortInfo()
{
    return portInfo;
}

void SerialInterface::SetPortNumber(QSerialPort *serial, const QString port)
{
    serial->setPortName(port);
}

void SerialInterface::SetBaudRate(QSerialPort *serial, int index)
{
    if(index == BAUD_RATE_9600) {
        serial->setBaudRate(QSerialPort::Baud9600);
    }
    else if(index == BAUD_RATE_1200) {
        serial->setBaudRate(QSerialPort::Baud1200);
    }
    else if(index == BAUD_RATE_2400) {
        serial->setBaudRate(QSerialPort::Baud2400);
    }
    else if(index == BAUD_RATE_4800) {
        serial->setBaudRate(QSerialPort::Baud4800);
    }
    else if(index == BAUD_RATE_19200) {
        serial->setBaudRate(QSerialPort::Baud19200);
    }
    else if(index == BAUD_RATE_38400) {
        serial->setBaudRate(QSerialPort::Baud38400);
    }
    else if(index == BAUD_RATE_57600) {
        serial->setBaudRate(QSerialPort::Baud57600);
    }
    else {
        serial->setBaudRate(QSerialPort::Baud115200);
    }
}

void SerialInterface::SetDataBits(QSerialPort *serial, int index)
{
    if(index == DATA_BITS_8) {
        serial->setDataBits(QSerialPort::Data8);
    }
    else if(index == DATA_BITS_5) {
        serial->setDataBits(QSerialPort::Data5);
    }
    else if(index == DATA_BITS_6) {
        serial->setDataBits(QSerialPort::Data6);
    }
    else if(index == DATA_BITS_7) {
        serial->setDataBits(QSerialPort::Data7);
    }
    else {
        serial->setDataBits(QSerialPort::UnknownDataBits);
    }
}

void SerialInterface::SetStopBits(QSerialPort *serial, int index)
{
    if(index == STOP_BITS_1) {
        serial->setStopBits(QSerialPort::OneStop);
    }
    else if(index == STOP_BITS_2){
        serial->setStopBits(QSerialPort::TwoStop);
    }
    else if(index == STOP_BITS_3) {
        serial->setStopBits(QSerialPort::OneAndHalfStop);
    }
    else {
        serial->setStopBits(QSerialPort::UnknownStopBits);
    }
}

void SerialInterface::SetParityBits(QSerialPort *serial, int index)
{
    qDebug() << "SetParityBits";

    if(index == PARITY_BITS_NO) {
        serial->setParity(QSerialPort::NoParity);
    }
    else if(index == PARITY_BITS_ODD) {
        serial->setParity(QSerialPort::OddParity);
    }
    else if(index == PARITY_BITS_EVEN) {
        serial->setParity(QSerialPort::EvenParity);
    }
    else if(index == PARITY_BITS_SPACE) {
        serial->setParity(QSerialPort::SpaceParity);
    }
    else if(index == PARITY_BITS_MRAK) {
        serial->setParity(QSerialPort::MarkParity);
    }
    else {
        serial->setParity(QSerialPort::UnknownParity);
    }

    serial->setFlowControl(QSerialPort::NoFlowControl);
}

void SerialInterface::ReadDataSlot()
{
    const QByteArray data = serialPort->readAll();

    QString temp(data);

    emit ShowReadDataSignal(temp);
}
