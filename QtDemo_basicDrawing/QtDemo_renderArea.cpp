#include "QtDemo_renderArea.h"

QtDemo_renderArea::QtDemo_renderArea(QWidget *parent)
	: QWidget(parent)
{
	/**	����������ö�ٸ�ֵ����,Xs	*/

	/**	�����������Ĭ�ϴ򿪳�������ʾ��ͼ��	*/
	m_shape = em_Polygon;

	/**	�������	*/
	m_bAntialiased = false;

	/**	��֪����Χ�����ﷴת	*/
	m_bTransformed = false;


	/**	װ��ͼƬ,��ĳ��ö��ֵ��ѡ��֮�󻭳���	*/
	pixmap.load(":/images/qt-logo.png");


	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);

}

QtDemo_renderArea::~QtDemo_renderArea()
{

}
