#pragma once
/**	官方类库	*/
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>


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

	/**	在这里就会调用构造函数,这里是	*/
	QtDemo_helper m_helper;

};
