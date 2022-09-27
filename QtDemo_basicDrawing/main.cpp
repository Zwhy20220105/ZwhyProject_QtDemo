#include "QtDemo_basicDrawing.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	/**	这玩意不会用,宏编译	*/
	Q_INIT_RESOURCE(QtDemo_basicDrawing);

    QApplication a(argc, argv);
    QtDemo_basicDrawing w;
    w.show();
    return a.exec();
}
