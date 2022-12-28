#include "serialmain.h"

SerialMain::SerialMain(QObject *parent) : QObject {parent}
{
    ReadSerialPort();
}

SerialMain::~SerialMain()
{

}

void SerialMain::ReadSerialPort()
{
    const auto infos = QSerialPortInfo::availablePorts();

    qDebug() << "SerialPortInfo : " << QSerialPortInfo::availablePorts().count();

    for(const QSerialPortInfo &info : infos) {
        qDebug() << "port : " << info.portName();
        SetSerialPortInfo(info.portName());
    }
}

void SerialMain::SetSerialPortInfo(QVariant info)
{
    qDebug() << "Jehee Set : " << info;
    serialPortInfo << info;
}

const QVariantList SerialMain::GetSerialPortInfo()
{
    qDebug() << "Jehee get : " << serialPortInfo;
    return serialPortInfo;
}
