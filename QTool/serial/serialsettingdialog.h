#ifndef SERIALSETTINGDIALOG_H
#define SERIALSETTINGDIALOG_H

#include <QDialog>

#include "common.h"
#include "serialinterface.h"

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
    void Init();
    void InitLabel();
    void ComboBoxInit();

private:
    Ui::SerialSettingDialog *ui;
};

#endif // SERIALSETTINGDIALOG_H
