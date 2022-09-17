#include "QtDemo_widgetGL.h"

QtDemo_widgetGL::QtDemo_widgetGL(QtDemo_helper* pHelper,QWidget *parent)
	: m_pHelper(pHelper)
	, QOpenGLWidget(parent)
{
	m_nEapsed = 0;
	setFixedSize(200, 200);
	setAutoFillBackground(false);
}

QtDemo_widgetGL::~QtDemo_widgetGL()
{

}
