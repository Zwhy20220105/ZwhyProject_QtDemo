#include "QtDemo_helper.h"

QtDemo_helper::QtDemo_helper()
{
	/**————————————— 这段代码是用来上色的 —————————————*/
	/**	QPointF 的F是单精度的意思	*/
	QLinearGradient gridient(QPointF(50, -20), QPointF(80, 20));

	gridient.setColorAt(0.0, Qt::white);
	/**	感觉这是三原色RGB,但是怎么用的16进制	*/
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
	/**	这段代码神奇的地方就是,按道理肯定要先写这个,然后再写两个窗口的Paintevent的,但是这样写就没有效果的	*/
	/**	其实也有一定道理,因为,只要是你引入这类,按道理这个类的结构是已经完善的,所实话看完Demo,都不知道从哪里写起了	*/

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