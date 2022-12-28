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


public:
    explicit SerialMain(QObject *parent = nullptr);
    ~SerialMain();

public slots:

public:

private:
    void ReadSerialPort();
    void SetSerialPortInfo(QVariant info);
    const QVariantList GetSerialPortInfo();

private slots:

private:
    QVariantList serialPortInfo;


};

#endif // SERIALMAIN_H
