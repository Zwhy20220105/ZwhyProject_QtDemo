#pragma once

/**�������������������������� �ٷ��� ��������������������������*/
#include <QtWidgets/QWidget>



/**�������������������������� �Զ���� ��������������������������*/
#include "QtDemo_renderArea.h"

class QtDemo_basicDrawing : public QWidget
{
    Q_OBJECT

public:
    QtDemo_basicDrawing(QWidget *parent = nullptr);
    ~QtDemo_basicDrawing();

private:
	
	QtDemo_renderArea* m_pRenderArea;
};
