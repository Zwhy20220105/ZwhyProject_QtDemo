#include "QtDemo_renderArea.h"

QtDemo_renderArea::QtDemo_renderArea(QWidget *parent)
	: QWidget(parent)
{
	/**	就是这样给枚举赋值的吗,Xs	*/

	/**	这里就是设置默认打开程序所显示的图像	*/
	m_shape = em_Polygon;

	/**	反抗锯齿	*/
	m_bAntialiased = false;

	/**	不知道是围着哪里反转	*/
	m_bTransformed = false;


	/**	装载图片,在某个枚举值被选中之后画出来	*/
	pixmap.load(":/images/qt-logo.png");


	setBackgroundRole(QPalette::Base);
	setAutoFillBackground(true);

}

QtDemo_renderArea::~QtDemo_renderArea()
{

}
