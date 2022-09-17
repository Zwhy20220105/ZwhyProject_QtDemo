#pragma once

#include <QWidget>
#include <QOpenGLWidget>

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

private:
	QtDemo_helper* m_pHelper;
	int m_nEapsed;
};
