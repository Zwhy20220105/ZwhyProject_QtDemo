#include "QtDemo_2DPaintingExample.h"
#include <QtWidgets/QApplication>
#include <QSurfaceFormat>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QSurfaceFormat fmt;
	fmt.setSamples(4);
	QSurfaceFormat::setDefaultFormat(fmt);

    QtDemo_2DPaintingExample w;
    w.show();
    return a.exec();
}
