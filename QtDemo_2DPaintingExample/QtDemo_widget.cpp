#include "QtDemo_widget.h"

QtDemo_widget::QtDemo_widget(QtDemo_helper* pHelper,QWidget *parent)
	: QWidget(parent),m_pHelper(m_pHelper)
{
	m_nElapsed = 0;
	setFixedSize(200, 200);
}

QtDemo_widget::~QtDemo_widget()
{

}
