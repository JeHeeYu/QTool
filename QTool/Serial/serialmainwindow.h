#ifndef SERIALMAINWINDOW_H
#define SERIALMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class SerialMainWindow;
}

class SerialMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SerialMainWindow(QWidget *parent = nullptr);
    ~SerialMainWindow();

private:
    Ui::SerialMainWindow *ui;
};

#endif // SERIALMAINWINDOW_H
