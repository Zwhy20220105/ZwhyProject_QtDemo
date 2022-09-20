#pragma once

#include <QWidget>

#include <QPainter>
#include <QPaintEvent>
#include <QLinearGradient>

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QColor>


#include <QDebug>
#include <QPushButton>
#include <QString>

class QtDemo_helper 
{

public:
	QtDemo_helper();

	void paint(QPainter* pPainter, QPaintEvent* event,int nElapsed);

	~QtDemo_helper();


private:

	QBrush m_backgroudBrush;

	QBrush m_circleBrush;

	QFont m_textFont;

	QPen m_circlePen;

	QPen m_textPen;

	
};
