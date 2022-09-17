#include "QtDemo_2DPaintingExample.h"

QtDemo_2DPaintingExample::QtDemo_2DPaintingExample()
{
	setWindowTitle(QString::fromLocal8Bit("普通情况和openGL下2D绘图对比"));

	/**	仇家的诞生	*/
	QtDemo_widget* pWidght = new QtDemo_widget(&helper, this);
	/**	这里定义的时候怎么不直接定义 pHelper	*/
	QtDemo_widgetGL* pWidghtGL = new QtDemo_widgetGL(&helper, this);

	/**	属于是title	*/
	QLabel* pNativeLable = new QLabel(QString::fromLocal8Bit("原生"));
	pNativeLable->setAlignment(Qt::AlignHCenter);

	QLabel* pOpenGLLable = new QLabel("OpenGL");
	pOpenGLLable->setAlignment(Qt::AlignHCenter);

	QGridLayout* pGridLayout = new QGridLayout;
	pGridLayout->addWidget(pWidght, 0, 0);
	pGridLayout->addWidget(pOpenGLLable, 0, 1);
	pGridLayout->addWidget(pNativeLable, 1, 0);
	pGridLayout->addWidget(pOpenGLLable, 1, 1);

	this->setLayout(pGridLayout);


}

