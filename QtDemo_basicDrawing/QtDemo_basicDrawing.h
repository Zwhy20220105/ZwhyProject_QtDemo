#pragma once

/**！！！！！！！！！！！！！ 郊圭議 ！！！！！！！！！！！！！*/
#include <QtWidgets/QWidget>
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>

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

	QComboBox* m_pShapeComboBox;
	QLabel* m_pShapeLable;

	QSpinBox* m_pPenWidthSpinBox;
	QLabel* m_pPenWidthLable;

	QComboBox* m_pPenStyleComboBox;
	QLabel* m_pPenStyleLable;

	QComboBox* m_pPenCapComboBox;
	QLabel* m_pPenCapLabel;

	QComboBox* m_pPenJoinComboBox;
	QLabel* m_pPenJoinLable;

	QComboBox* m_pBrushStyleComboBox;
	QLabel* m_pBrushStyleLable;
};
