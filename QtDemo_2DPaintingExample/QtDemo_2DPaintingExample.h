#pragma once
/**	官方类库	*/
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QGridLayout>

/** 自定义的类库	*/
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
