#ifndef SERIALSETTINGDIALOG_H
#define SERIALSETTINGDIALOG_H

#include <QDialog>

#include "common.h"
#include "serialmain.h"

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

namespace Ui {
class SerialSettingDialog;
}

class SerialSettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SerialSettingDialog(QWidget *parent = nullptr);
    ~SerialSettingDialog();

private:
    void ConnectInit();
    void Init();
    void LabelInit();
    void ComboBoxInit();
    void GetSerialPort();


private:
    Ui::SerialSettingDialog *ui;
};

#endif // SERIALSETTINGDIALOG_H
