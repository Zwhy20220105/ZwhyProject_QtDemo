#pragma once

/**�������������������������� �ٷ��� ��������������������������*/
#include <QWidget>
#include <QPixmap>


/**�������������������������� �Լ��� ��������������������������*/


class QtDemo_renderArea : public QWidget
{
	Q_OBJECT

/**�������������������������� �����ĺ��� ��������������������������*/
public:
	QtDemo_renderArea(QWidget *parent = nullptr);
	~QtDemo_renderArea();

	enum Shape
	{
		em_Line,
		em_Points,
		em_Polyline,
		em_Polygon,
		em_Rect,
		em_RoundedRect,
		em_Ellipse,
		em_Arc,
		em_Chord,
		em_Pie,
		em_Path,
		em_Text,
		em_Pixmap
	};

/**�������������������������� �����ĺ���,һ����Ϊ��д�麯���ļ̳�Ȩ�� ��������������������������*/
protected:

/**�������������������������� ˽�еĺ���,ֻ�����ں����ſ��Ե��� ��������������������������*/
private:

/**�������������������������� �����Ĳۺ���,�����ⲿ���� ��������������������������*/
public slots:

/**�������������������������� ��Ա������Ȩ��Ĭ����˽�е� ��������������������������*/
private:
	Shape m_shape;

	bool m_bAntialiased;
	bool m_bTransformed;

	QPixmap pixmap;

/**�������������������������� �ź� ��������������������������*/
signals:

};
