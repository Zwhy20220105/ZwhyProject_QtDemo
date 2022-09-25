#include "QtDemo_widget.h"

QtDemo_widget::QtDemo_widget(QtDemo_helper* pHelper,QWidget *parent)
		/**	����ط�̫����,֮ǰд����m_pHelper(m_pHelper) �Ų��˺þ�	*/
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
	/**	����Ϊʲô����ͷ�ļ���,����ΪHelper�����Ѿ�����,���������о�����Ŷ	*/
	QPainter painter;
	/**	������painter�Ļ����÷�	*/
	painter.begin(this);

	/**	����˵�Ƿ�����,�����ͼ��ѧ�ĸ���,�����Ӽ����ͼ��ѧ��ѧϰ������	*/
	painter.setRenderHint(QPainter::Antialiasing);				///<	���߻�ͼ����Ӧ���ڿ��ܵ�����½��бߵķ���ݻ���
	//qDebug() << m_pHelper->a;
	//m_pHelper->inttest();	   
	//qDebug() << m_pHelper->a;
	m_pHelper->paint(&painter,event,m_nElapsed);	 
	painter.end();			   
}

void QtDemo_widget::beAnimate()
{
	m_nElapsed = (m_nElapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
	update();
}

