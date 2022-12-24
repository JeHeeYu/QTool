#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

#include <QObject>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

#include "common.h"
#include "singleton.h"

class SerialInterface : public QObject, public Singleton<SerialInterface>
{
    Q_OBJECT
public:
    explicit SerialInterface(QObject *parent = nullptr);
    ~SerialInterface();

    void SerialPortInfo();
};

#endif // SERIALINTERFACE_H
