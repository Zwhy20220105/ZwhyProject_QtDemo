#include "QtDemo_basicDrawing.h"

QtDemo_basicDrawing::QtDemo_basicDrawing(QWidget *parent)
    : QWidget(parent)
{
	/**	�ҷ��ֹٷ���ϲ���ں���ָ������,�������������һ��	*/
	m_pRenderArea = new QtDemo_renderArea;


}

QtDemo_basicDrawing::~QtDemo_basicDrawing()
{


}
