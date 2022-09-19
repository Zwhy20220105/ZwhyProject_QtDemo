#include "QtDemo_helper.h"

QtDemo_helper::QtDemo_helper()
{
	/**�������������������������� ��δ�����������ɫ�� ��������������������������*/
	/**	QPointF ��F�ǵ����ȵ���˼	*/
	QLinearGradient gridient(QPointF(50, -20), QPointF(80, 20));

	gridient.setColorAt(0.0, Qt::white);
	/**	�о�������ԭɫRGB,������ô�õ�16����	*/
	gridient.setColorAt(1.0, QColor(0xa6,0xce,0x39));

	m_backgroudBrush = QBrush(QColor(64, 32, 64));
	//qDebug() << m_backgroudBrush;
	m_circleBrush = QBrush(gridient);

	m_backgroudBrush.setColor(QColor(64, 32, 64));

	m_circlePen = QPen(Qt::black);
	m_circlePen.setWidth(1);

	m_textPen = QPen(Qt::white);
	m_textFont.setPixelSize(50);

	qDebug() << "qhelper create";
	/**	��δ�������ĵط�����,������϶�Ҫ��д���,Ȼ����д�������ڵ�Paintevent��,��������д��û��Ч����	*/
	/**	��ʵҲ��һ������,��Ϊ,ֻҪ������������,�����������Ľṹ���Ѿ����Ƶ�,��ʵ������Demo,����֪��������д����	*/

}

void QtDemo_helper::paint(QPainter* pPainter, QPaintEvent* event, int elapsed)
{
	QRect rect(0, 20,50,60);
	//m_backgroudBrush.setColor(QColor(64, 32, 64));
	//pPainter->fillRect(event->rect(), QBrush(QColor(64, 32, 64)));
	//qDebug() << &m_backgroudBrush;

	//pPainter->fillRect(event->rect(), m_backgroudBrush);

	//pPainter->fillRect(event->rect(), QColor(64, 32, 64));

	//pPainter->translate(100, 100);
	

	
}

QtDemo_helper::~QtDemo_helper()
{
	qDebug() << "qhelper destroy";
}

void QtDemo_helper::inttest()
{
	a = 100;
}