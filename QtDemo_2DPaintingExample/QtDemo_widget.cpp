#include "QtDemo_widget.h"

QtDemo_widget::QtDemo_widget(QtDemo_helper* pHelper,QWidget *parent)
	: QWidget(parent),m_pHelper(pHelper)
{
	m_nElapsed = 0;
	setFixedSize(200, 200);

}

QtDemo_widget::~QtDemo_widget()
{

}

void QtDemo_widget::paintEvent(QPaintEvent * event)
{
	/**	这里为什么不用头文件呢,是因为Helper类中已经加了,但是这样感觉很乱哦	*/
	QPainter painter;
	/**	这里是painter的基本用法	*/
	painter.begin(this);
	/**	这里说是反走样,计算机图形学的概念,看样子计算机图形学的学习还不错	*/
	painter.setRenderHint(QPainter::Antialiasing);				///<	告诉绘图引擎应该在可能的情况下进行边的反锯齿绘制
	//qDebug() << m_pHelper->a;
	//m_pHelper->inttest();
	//qDebug() << m_pHelper->a;
	m_pHelper->paint(&painter,event,m_nElapsed);

	painter.end();

}

void QtDemo_widget::printHelperA()
{
	qDebug()<<"printA."<<m_pHelper->a;
}
