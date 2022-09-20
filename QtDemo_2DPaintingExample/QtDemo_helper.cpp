#include "QtDemo_helper.h"

QtDemo_helper::QtDemo_helper()
{
	/**————————————— 这段代码是用来上色的 —————————————*/
	/**	QPointF 的F是单精度的意思	*/
	/**	这里是设置起点和终点	*/
	QLinearGradient gridient(QPointF(50, -20), QPointF(80, 20));
	
	/**	这里是设置渐变	*/
	/**	这里的0/1理解为100%比较好	*/
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

void QtDemo_helper::paint(QPainter* pPainter, QPaintEvent* event, int nElapsed)
{
	QRect rect(0, 20,50,60);

	pPainter->fillRect(event->rect(), m_backgroudBrush);
	
	/**	留下一点点调试的痕迹	*/

	//m_backgroudBrush.setColor(QColor(64, 32, 64));
	//qDebug() << &m_backgroudBrush;
	//pPainter->fillRect(event->rect(), m_backgroudBrush);
	//pPainter->fillRect(event->rect(), QColor(64, 32, 64));
	
	/**	这里是从新定义坐标原点 应该是指widget的中心吧,可以加个控件测试一下	*/
	
	pPainter->translate(100, 100);

	/**	想起来这就是普通的类,并不是QWidget	*/
	//QPushButton* testBtn =new QPushButton(QString("测试"),this);

	/**	这里就是保存了当前的"状态", such as :坐标轴 主要是现在我只会这个	*/
	pPainter->save();

	/**	配置一下画笔	*/

	/**	这里你可以发现drawEllipse画出来的圆,中间是用刷子刷的,边框是用画笔画的	*/
	pPainter->setBrush(m_circleBrush);
	pPainter->setPen(m_circlePen);

	/**	这里就是漩涡旋转的奥秘	*/
	pPainter->rotate(nElapsed*0.03);

	qreal r = nElapsed / 1000.0;



	/**	说实话这循环有点不讲究	*/
	int n = 30;
	for (int i =0 ; i<n;++i)
	//int i = 20;
	{
		/**————————————— 这里的算法有点意思 —————————————*/
		/**	这是触发旋转参数吧	*/

		pPainter->rotate(30);
		qreal factor = (i + r) / n;
		qreal radius = 0 + 120.0*factor;
		qreal circleRadius = 1 + factor * 20;
		//pPainter->drawEllipse(QRect(radius, -circleRadius, circleRadius * 2, circleRadius * 2));
	}

	pPainter->drawLine(QPointF(0, 0), QPointF(100, 100));
	//pPainter->drawRect(QRect(0, -100, -100, -100));




	
}

QtDemo_helper::~QtDemo_helper()
{
	qDebug() << "qhelper destroy";
}

