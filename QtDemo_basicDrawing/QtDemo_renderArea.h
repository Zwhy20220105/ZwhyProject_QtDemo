#pragma once

/**————————————— 官方的 —————————————*/
#include <QWidget>
#include <QPixmap>


/**————————————— 自己的 —————————————*/


class QtDemo_renderArea : public QWidget
{
	Q_OBJECT

/**————————————— 公开的函数 —————————————*/
public:
	QtDemo_renderArea(QWidget *parent = nullptr);
	~QtDemo_renderArea();

	enum Shape
	{
		em_Line,	    ///< 线条
		em_Points,	    ///< 点集 
		em_Polyline,    ///< 折线
		em_Polygon,	    ///< 多边形 
		em_Rect,        ///< 矩阵
		em_RoundedRect, ///< 圆角矩形 
		em_Ellipse,		///< 椭圆
		em_Arc,			///< 弧线 
		em_Chord,		///< 小半圆
		em_Pie,			///< 扇形
		em_Path,		///< 微积分
		em_Text,		///< 文本
		em_Pixmap		///< 图片

	};

/**————————————— 保护的函数,一般作为重写虚函数的继承权限 —————————————*/
protected:

/**————————————— 私有的函数,只有类内函数才可以调用 —————————————*/
private:

/**————————————— 公开的槽函数,便于外部调用 —————————————*/
public slots:

/**————————————— 成员变量的权限默认是私有的 —————————————*/
private:
	Shape m_shape;
	 
	bool m_bAntialiased;
	bool m_bTransformed;

	QPixmap pixmap;

/**————————————— 信号 —————————————*/
signals:

};
