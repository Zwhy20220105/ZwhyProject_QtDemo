#pragma once

#include <QWidget>
#include <QOpenGLWidget>
#include <QTimer>


/**�������������������������� 	�Զ������	 ��������������������������*/
/**	������������,ΪʲôQtDemo������ Class helper	*/
#include "QtDemo_helper.h"

//class QtDemo_helper;

class QtDemo_widgetGL  : public QOpenGLWidget
{
	Q_OBJECT

public:
	QtDemo_widgetGL(QtDemo_helper* pHelper,QWidget *parent);
	~QtDemo_widgetGL();

	void paintEvent(QPaintEvent *event);


private:

	QtDemo_helper* m_pHelper;
	int m_nElapsed;


public slots:

	void beAnimate();
};
