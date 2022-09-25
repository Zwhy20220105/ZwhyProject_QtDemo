#include "QtDemo_widgetGL.h"

QtDemo_widgetGL::QtDemo_widgetGL(QtDemo_helper* pHelper,QWidget *parent)
	: m_pHelper(pHelper)
	, QOpenGLWidget(parent)
{
	m_nElapsed = 0;
	setFixedSize(200, 200);
	setAutoFillBackground(false);
}

QtDemo_widgetGL::~QtDemo_widgetGL()
{

}

void QtDemo_widgetGL::paintEvent(QPaintEvent *event)
{
	QPainter painter;
	painter.begin(this);
	painter.testRenderHint(QPainter::Antialiasing);
	m_pHelper->paint(&painter, event, m_nElapsed);
	painter.end();
}

void QtDemo_widgetGL::beAnimate()
{
	 /**	这个地方没加 QTimer的头文件报错,因为这个插件的原因	*/
	m_nElapsed = (m_nElapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
	update();
}
