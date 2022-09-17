#include "QtDemo_2DPaintingExample.h"

QtDemo_2DPaintingExample::QtDemo_2DPaintingExample()
{
	setWindowTitle(QString::fromLocal8Bit("��ͨ�����openGL��2D��ͼ�Ա�"));

	/**	��ҵĵ���	*/
	QtDemo_widget* pWidght = new QtDemo_widget(&helper, this);
	/**	���ﶨ���ʱ����ô��ֱ�Ӷ��� pHelper	*/
	QtDemo_widgetGL* pWidghtGL = new QtDemo_widgetGL(&helper, this);

	/**	������title	*/
	QLabel* pNativeLable = new QLabel(QString::fromLocal8Bit("ԭ��"));
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

