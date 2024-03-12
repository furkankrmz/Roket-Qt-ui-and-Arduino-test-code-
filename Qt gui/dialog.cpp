#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
     ui->setupUi(this);
    //setup qserialport
    serialPort = new QSerialPort;
    arduino_is_available = false;
    arduino_port_name = "";

    //view ports on your system
    qDebug() << "Number of Ports: " << QSerialPortInfo::availablePorts().length();
    foreach (auto &serialPortInfo, QSerialPortInfo::availablePorts()){

        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            qDebug() << "VendorID: " <<serialPortInfo.vendorIdentifier();
            qDebug() << "ProductID: " << serialPortInfo.productIdentifier();
            ui->cmbPort->addItem(serialPortInfo.portName());
        }
        qDebug() << QString(ui->cmbPort->currentText());

    }
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendorID){
                if(serialPortInfo.productIdentifier() == arduino_uno_productID){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true;
                    qDebug() << "Port Available!";
                }
            }

        }
    }
    if(arduino_is_available)
    {
        serialPort->setPortName(ui->cmbPort->currentText());
        serialPort->open(QSerialPort::WriteOnly|QSerialPort::ReadOnly);
        serialPort->setBaudRate(QSerialPort::Baud9600);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);
        connect(serialPort, &QSerialPort::readyRead, this, &Dialog::readData);
    }
    else{
        QMessageBox::warning(this,"Port Error!","Couldn't find Port");
    }

}

Dialog::~Dialog()
{
    if(serialPort->isOpen()){
        qDebug() << "closing port";
        serialPort->close();
    }
    delete ui;
}
QByteArray charBuffer;
void Dialog::readData()
{
    //header: QByteArray charBuffer;
    if(serialPort->isReadable()){
        QByteArray data = serialPort->readAll();
        charBuffer.append(data);
        // QString receivedData = QString(data);
        qDebug() << "charbuffer size:" << charBuffer.size();
        QString paketSayaci;
        QFont font20("Arial", 16);
        paketSayaci = "Paket Sayacı: " + QString::number(charBuffer.size());
        ui->packIndex->setFont(font20);
        ui->packIndex->setText(paketSayaci);
        if(charBuffer.size() >= 78)
        {
            processData(charBuffer);
            qDebug() << " olduuuuuu laaaaa " << charBuffer;
            paket_okuma(reinterpret_cast<unsigned char*>(charBuffer.data()));
            charBuffer = "";

        }
    }
    else
        qDebug() << "Couldn't read from serial";

}

 void Dialog::processData(const QByteArray &data)
    {
        qDebug() << data.size();
        QString hexString;
        hexString = data.toHex(' ').toUpper();

        QFont font("Arial", 12);
        ui->packCont->setFont(font);
        ui->packCont->setText(hexString);
    }
void Dialog::paket_okuma(unsigned char *alınan_paket) {
    // Paket boyutunu kontrol et
    if (alınan_paket[0] != 0xFF || alınan_paket[1] != 0xFF || alınan_paket[2] != 0x54 || alınan_paket[3] != 0x52 ||
        alınan_paket[PAKET_UZUNLUGU - 2] != 0x0D || alınan_paket[PAKET_UZUNLUGU - 1] != 0x0A) {
        // Geçersiz paket, işlem yapma
        return;
    }

    // Check sum kontrolü yap
    //unsigned char hesaplanan_check_sum = check_sum_hesapla(alınan_paket);

    // Paket sabitlerine göre işlem yap
    unsigned char takim_id = alınan_paket[4];
    unsigned char sayac_degeri = alınan_paket[5];

    // İrtifa
    FLOAT32_UINT8_DONUSTURUCU irtifa_float32_uint8_donusturucu;
    irtifa_float32_uint8_donusturucu.array[0] = alınan_paket[6];
    irtifa_float32_uint8_donusturucu.array[1] = alınan_paket[7];
    irtifa_float32_uint8_donusturucu.array[2] = alınan_paket[8];
    irtifa_float32_uint8_donusturucu.array[3] = alınan_paket[9];
    float irtifa_degeri = irtifa_float32_uint8_donusturucu.sayi;
    ui->lcdNumber->display(irtifa_degeri);
    // Roket GPS İrtifası
    FLOAT32_UINT8_DONUSTURUCU roket_gps_irtifa_float32_uint8_donusturucu;
    roket_gps_irtifa_float32_uint8_donusturucu.array[0] = alınan_paket[10];
    roket_gps_irtifa_float32_uint8_donusturucu.array[1] = alınan_paket[11];
    roket_gps_irtifa_float32_uint8_donusturucu.array[2] = alınan_paket[12];
    roket_gps_irtifa_float32_uint8_donusturucu.array[3] = alınan_paket[13];
    float roket_gps_irtifa_degeri = roket_gps_irtifa_float32_uint8_donusturucu.sayi;

    // Roket Enlem
    FLOAT32_UINT8_DONUSTURUCU roket_enlem_float32_uint8_donusturucu;
    roket_enlem_float32_uint8_donusturucu.array[0] = alınan_paket[14];
    roket_enlem_float32_uint8_donusturucu.array[1] = alınan_paket[15];
    roket_enlem_float32_uint8_donusturucu.array[2] = alınan_paket[16];
    roket_enlem_float32_uint8_donusturucu.array[3] = alınan_paket[17];
    float roket_enlem_degeri = roket_enlem_float32_uint8_donusturucu.sayi;

    // Diğer verilerin okunması için aynı yöntemle devam edilir...

    // Durum bilgisi
    unsigned char durum_bilgisi = alınan_paket[74];

    // Okunan verilerle işlem yap
    // Örnek olarak verileri ekrana yazdırabiliriz
    printf("Takım ID: %d\n", takim_id);
    printf("Sayaç Değeri: %d\n", sayac_degeri);
    printf("İrtifa: %.2f\n", irtifa_degeri);
    printf("Roket GPS İrtifası: %.2f\n", roket_gps_irtifa_degeri);
    printf("Roket Enlem: %.6f\n", roket_enlem_degeri);
    // Diğer verileri yazdır...
    printf("Durum Bilgisi: %d\n", durum_bilgisi);
}

