#pragma once

#include <QWidget>
#include <QPainter>
#include "QtDemo_helper.h"
#include<QDebug>
#include <QTimer>

class QtDemo_widget : public QWidget
{
	Q_OBJECT

public:
	QtDemo_widget(QtDemo_helper* pHelper,QWidget *parent = nullptr);
	~QtDemo_widget();

protected:
	void paintEvent(QPaintEvent *event);

private:


public slots:

	void beAnimate();

private:
	QtDemo_helper* m_pHelper;
	int m_nElapsed;
};
