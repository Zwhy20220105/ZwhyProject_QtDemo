#include "QtDemo_helper.h"

QtDemo_helper::QtDemo_helper()
{
	/**�������������������������� ��δ�����������ɫ�� ��������������������������*/
	/**	QPointF ��F�ǵ����ȵ���˼	*/
	/**	���������������յ�	*/
	QLinearGradient gridient(QPointF(50, -20), QPointF(80, 20));
	
	/**	���������ý���	*/
	/**	�����0/1���Ϊ100%�ȽϺ�	*/
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

void QtDemo_helper::paint(QPainter* pPainter, QPaintEvent* event, int nElapsed)
{
	pPainter->fillRect(event->rect(), m_backgroudBrush);
	
	/**	����һ�����Եĺۼ�	*/
			
	//m_backgroudBrush.setColor(QColor(64, 32, 64));
	//qDebug() << &m_backgroudBrush;
	//pPainter->fillRect(event->rect(), m_backgroudBrush);
	//pPainter->fillRect(event->rect(), QColor(64, 32, 64));
	
	/**	�����Ǵ��¶�������ԭ�� Ӧ����ָwidget�����İ�,���ԼӸ��ؼ�����һ��	*/
	
	pPainter->translate(100, 100);

	/**	�������������ͨ����,������QWidget	*/
	//QPushButton* testBtn =new QPushButton(QString("����"),this);

	/**	������Ǳ����˵�ǰ��"״̬", such as :������ ��Ҫ��������ֻ�����	*/
	pPainter->save();

	/**	����һ�»���	*/

	/**	��������Է���drawEllipse��������Բ,�м�����ˢ��ˢ��,�߿����û��ʻ���	*/
	pPainter->setBrush(m_circleBrush);
	pPainter->setPen(m_circlePen);

	/**	��һ�����������ת�İ���	*/
	pPainter->rotate(nElapsed*0.03);

	/**	���nElapsed�����������ڴ������ĳ�Ա����	*/
	/**	qreal ��QT�е�qdouble	*/
	qreal r = nElapsed / 1000.0;
	//double r = nElapsed / 1000.0;

	/**	˵ʵ����ѭ���е㲻����	*/
	int n = 30;

	/**	���ﵽ�������ת��180+2n��	*/
	for ( int i = 0 ; i < n; ++i )
	//int i = 20;
	{
		/**�������������������������� ������㷨�е���˼ ��������������������������*/
		
		/**	���Ǵ�����ת������	*/
		pPainter->rotate(30);
		/**	�ҹ����� ԽתԽ��	*/
		/**	���� ����һ��ѭ��ʱ�� r�Ƕ�ֵ(����),���Ǻ�������ת��ʱ��,�Ͷ�ʱ������һ������,�ı���ٶ�	*/
		qreal factor = (i + r) / n;
		/**	��һ��ѭ����һ���� �뾶������,Ȼ�����ÿһ����,�뾶���᳤��	*/
		qreal radius = 0 + 120.0*factor;
		/**	����˵������ȡ�ú�,������ע�͵�����,�������ÿ��СԲ�İ뾶,	*/
		qreal circleRadius = 1 + factor * 20;

		/**	��������ǿ��Ի�����Բ��	*/
		/**	��������������,����Ϊÿ�ζ���������ת,�������ı��	*/
		/**	ע������Y�������������µ�,���������Ǹ���	*/

		/**�������������������������� ��һ���õ�QRect�ͻ���ֻ��涶������� ��������������������������*/
		pPainter->drawEllipse(QRectF(radius, -circleRadius, circleRadius * 2, circleRadius * 2));
		/**�������������������������� ��������֮��,�ͺ���,��Ϊ��λ��׼,���Զ�����ƽ�� ��������������������������*/
		
		//pPainter->drawLine(QPointF(0, 0), QPointF(100, 100));		
	}

	/**	���Կ���,�����ߴ�����б�뾶��,���Y�����Ὠ���ķ��������µ� 	*/
	//pPainter->drawLine(QPointF(0, 0), QPointF(20, 20));	
	//pPainter->drawEllipse(QRect(-20, -20,  40, 40));
	//pPainter->drawRect(QRect(0, -100, -100, -100));

	/**�������������������������� ���˵�����Ϊֹ,�ఢ���׵�����Բ���Ѿ�������,����˵,û�������ô��,��������,������㷨��������������������������*/
	/**	��������ָ�����  ת��������֮���	*/
	pPainter->restore();

	pPainter->setPen(m_textPen);
	/**	�о����������,��֪�������廹�Ǵ�С,�����Զ����Բ���	*/
	pPainter->setFont(m_textFont);
	/**	AlignCenterȷʵ�Ǿ���,����û������Ч����	*/
	/**	ʹ�� QStringLiteral ������ڱ����ڰѴ�����ĳ����ַ��� str ֱ�ӹ���Ϊ QString ������������ʱ�Ͳ�����Ҫ����Ĺ��쿪���ˡ�	*/
	
	/**	������Ҫ��ס,�����ξ���ָ�����Ͻǵ�����,Ȼ�����ָ������	*/
	pPainter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, QStringLiteral("Qt"));

}

QtDemo_helper::~QtDemo_helper()
{
	qDebug() << "qhelper destroy";
}

