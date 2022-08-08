#include "QtDemo_addressBook.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtDemo_addressBook w;
    w.show();
    return a.exec();
}
