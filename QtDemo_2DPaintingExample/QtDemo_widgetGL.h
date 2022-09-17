#pragma once

#include <QWidget>
#include <QOpenGLWidget>

/**————————————— 	自定义的类	 —————————————*/
/**	这里很神奇的是,为什么QtDemo里面是 Class helper	*/
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
