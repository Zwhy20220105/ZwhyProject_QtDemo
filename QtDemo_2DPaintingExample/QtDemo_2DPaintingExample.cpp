#include "QtDemo_2DPaintingExample.h"

QtDemo_2DPaintingExample::QtDemo_2DPaintingExample()
{
	setWindowTitle(QString::fromLocal8Bit("普通widget和openGL下2D绘图对比"));

	/**	仇家的诞生	*/
	QtDemo_widget* pWidght = new QtDemo_widget(&m_helper, this);
	/**	这里定义的时候怎么不直接定义 pHelper	*/
	QtDemo_widgetGL* pWidghtGL = new QtDemo_widgetGL(&m_helper, this);
	/**	属于是title	*/
	QLabel* pNativeLable = new QLabel(QString::fromLocal8Bit("原生"));
	pNativeLable->setAlignment(Qt::AlignHCenter);

	QLabel* pOpenGLLable = new QLabel("OpenGL");
	pOpenGLLable->setAlignment(Qt::AlignHCenter);

	QGridLayout* pGridLayout = new QGridLayout;
	pGridLayout->addWidget(pWidght, 0, 0);
	pGridLayout->addWidget(pWidghtGL, 0, 1);

	/**	变量的命名确实很关键,人不可能不可能不犯错	*/
	pGridLayout->addWidget(pNativeLable, 1, 0);
	pGridLayout->addWidget(pOpenGLLable, 1, 1);

	this->setLayout(pGridLayout);

	QTimer* pTimer = new QTimer(this);
	connect(pTimer, &QTimer::timeout, pWidght, &QtDemo_widget::beAnimate);
	connect(pTimer, &QTimer::timeout, pWidghtGL, &QtDemo_widgetGL::beAnimate);
	pTimer->start(50);

}

