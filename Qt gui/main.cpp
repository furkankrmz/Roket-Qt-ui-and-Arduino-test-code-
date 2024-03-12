#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.setFixedSize(800, 602);
    w.setWindowFlags(w.windowFlags() | Qt::WindowMinimizeButtonHint);//simge durumu icin ama calismiyor
    w.show();
    return a.exec();
}
