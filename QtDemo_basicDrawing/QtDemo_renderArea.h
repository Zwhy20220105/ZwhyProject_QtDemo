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
		em_Line,	    ///< ����
		em_Points,	    ///< �㼯 
		em_Polyline,    ///< ����
		em_Polygon,	    ///< ����� 
		em_Rect,        ///< ����
		em_RoundedRect, ///< Բ�Ǿ��� 
		em_Ellipse,		///< ��Բ
		em_Arc,			///< ���� 
		em_Chord,		///< С��Բ
		em_Pie,			///< ����
		em_Path,		///< ΢����
		em_Text,		///< �ı�
		em_Pixmap		///< ͼƬ

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
