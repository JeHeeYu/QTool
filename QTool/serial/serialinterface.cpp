#include "serialinterface.h"


SerialInterface::SerialInterface(QObject *parent) : QObject(parent)
{

}

SerialInterface::~SerialInterface()
{

}

void SerialInterface::SerialPortInfo()
{
    const auto infos = QSerialPortInfo::availablePorts();

    qDebug() << "SerialPortInfo : " << QSerialPortInfo::availablePorts().count();

    for(const QSerialPortInfo &info : infos) {
        qDebug() << "port : " << info.portName();
    }
}
