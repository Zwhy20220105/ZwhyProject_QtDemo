#pragma once
/**	�ٷ����	*/
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QGridLayout>

/** �Զ�������	*/
#include "QtDemo_widget.h"
#include "QtDemo_helper.h"
#include "QtDemo_widgetGL.h"

class QtDemo_2DPaintingExample : public QWidget
{
    Q_OBJECT

public:

    QtDemo_2DPaintingExample();


private:
	QtDemo_helper helper;

};
