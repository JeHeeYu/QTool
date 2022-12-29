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
