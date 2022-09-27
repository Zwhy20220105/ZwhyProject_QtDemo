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

	/**	这一句就是漩涡旋转的奥秘	*/
	pPainter->rotate(nElapsed*0.03);

	/**	这个nElapsed就是两个窗口传进来的成员变量	*/
	/**	qreal 是QT中的qdouble	*/
	qreal r = nElapsed / 1000.0;
	//double r = nElapsed / 1000.0;

	/**	说实话这循环有点不讲究	*/
	int n = 30;

	/**	这里到最后是旋转了180+2n派	*/
	for ( int i = 0 ; i < n; ++i )
	//int i = 20;
	{
		/**————————————— 这里的算法有点意思 —————————————*/
		
		/**	这是触发旋转参数吧	*/
		pPainter->rotate(30);
		/**	我估计是 越转越大	*/
		/**	这里 当在一次循环时候 r是定值(是零),但是后面有旋转的时候,就定时器触发一次自增,改变角速度	*/
		qreal factor = (i + r) / n;
		/**	第一次循环第一个点 半径就是零,然后后面每一个点,半径都会长大	*/
		qreal radius = 0 + 120.0*factor;
		/**	所以说变量名取得好,可以起到注释的作用,这里就是每个小圆的半径,	*/
		qreal circleRadius = 1 + factor * 20;

		/**	所以这个是可以画出椭圆的	*/
		/**	这个看起来很奇怪,是因为每次都进行了旋转,坐标轴会的变得	*/
		/**	注意这里Y轴正方形是向下的,所以这里是负的	*/

		/**————————————— 这一句用的QRect就会出现画面抖动的情况 —————————————*/
		pPainter->drawEllipse(QRectF(radius, -circleRadius, circleRadius * 2, circleRadius * 2));
		/**————————————— 改了这里之后,就好了,因为点位不准,所以动画不平滑 —————————————*/
		
		//pPainter->drawLine(QPointF(0, 0), QPointF(100, 100));		
	}

	/**	可以看出,这条线穿过了斜半径的,这边Y坐标轴建立的方向是向下的 	*/
	//pPainter->drawLine(QPointF(0, 0), QPointF(20, 20));	
	//pPainter->drawEllipse(QRect(-20, -20,  40, 40));
	//pPainter->drawRect(QRect(0, -100, -100, -100));

	/**————————————— 至此到这里为止,类阿基米德螺线圆组已经画完了,可以说,没我想的那么难,但很神奇,这就是算法—————————————*/
	/**	所以这里恢复的是  转换坐标轴之后的	*/
	pPainter->restore();

	pPainter->setPen(m_textPen);
	/**	感觉这个是字体,不知道是字体还是大小,字属性都可以操作	*/
	pPainter->setFont(m_textFont);
	/**	AlignCenter确实是居中,但是没看到过效果呢	*/
	/**	使用 QStringLiteral 宏可以在编译期把代码里的常量字符串 str 直接构造为 QString 对象，于是运行时就不再需要额外的构造开销了。	*/
	
	/**	所以你要记住,画矩形就是指定左上角的坐标,然后加上指定长宽	*/
	pPainter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, QStringLiteral("Qt"));

}

QtDemo_helper::~QtDemo_helper()
{
	qDebug() << "qhelper destroy";
}

