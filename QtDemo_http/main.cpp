#include "QtDemo_http.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtDemo_http w;

    w.show();
    return a.exec();
}
