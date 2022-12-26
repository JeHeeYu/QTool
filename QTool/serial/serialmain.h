#ifndef SERIALMAIN_H
#define SERIALMAIN_H

#include <QObject>

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>
#include <QVector>

#include "common.h"
#include "singleton.h"

#define SERIALMAIN()         SerialMain::Instance()

class SerialMain : public QObject, public Singleton<SerialMain>
{
    Q_OBJECT
public:
    explicit SerialMain(QObject *parent = nullptr);
    ~SerialMain();
};

#endif // SERIALMAIN_H




