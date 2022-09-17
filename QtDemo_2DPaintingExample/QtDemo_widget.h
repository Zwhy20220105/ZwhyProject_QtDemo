#pragma once

#include <QWidget>
#include "QtDemo_helper.h"
class QtDemo_widget : public QWidget
{
	Q_OBJECT

public:
	QtDemo_widget(QtDemo_helper* pHelper,QWidget *parent = nullptr);
	~QtDemo_widget();

private:
	QtDemo_helper* m_pHelper;
	int m_nElapsed;
};
