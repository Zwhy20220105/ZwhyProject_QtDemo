#pragma once
/**	�ٷ����	*/
#include <QtWidgets/QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>


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

	/**	������ͻ���ù��캯��,������	*/
	QtDemo_helper m_helper;

};
