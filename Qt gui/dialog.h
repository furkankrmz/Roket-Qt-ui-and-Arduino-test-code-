#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QtWidgets>
#include<QByteArray>
#define PAKET_UZUNLUGU 78

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void paket_okuma(unsigned char *alınan_paket);
    void readData();
    void processData(const QByteArray &data);
    //void readSensorValue();

private:

    typedef union{
        float sayi;
        unsigned char array[4];
    }FLOAT32_UINT8_DONUSTURUCU;

    Ui::Dialog *ui;
    QSerialPort *serialPort;
    QString arduino_port_name;
    bool arduino_is_available;

    static const quint16 arduino_uno_vendorID = 6790;
    static const quint16 arduino_uno_productID = 29987;


};
#endif // DIALOG_H
