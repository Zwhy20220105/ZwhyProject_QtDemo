#pragma once


#include <QPainter>
#include <QPaintEvent>

#include <QLinearGradient>
#include <QWidget>


#include <QBrush>
#include <QFont>
#include <QPen>
#include <QColor>
#include <QDebug>
class QtDemo_helper 
{

public:
	QtDemo_helper();

	void paint(QPainter* pPainter, QPaintEvent* event,int elapsed);

	void inttest();

	~QtDemo_helper();

	int a = 10;

private:

	QBrush m_backgroudBrush;

	QBrush m_circleBrush;

	QFont m_textFont;

	QPen m_circlePen;

	QPen m_textPen;

	
};
