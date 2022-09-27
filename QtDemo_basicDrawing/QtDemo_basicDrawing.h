#pragma once

/**！！！！！！！！！！！！！ 郊圭議 ！！！！！！！！！！！！！*/
#include <QtWidgets/QWidget>



/**！！！！！！！！！！！！！ 徭協吶議 ！！！！！！！！！！！！！*/
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
