#include "QtDemo_basicDrawing.h"

QtDemo_basicDrawing::QtDemo_basicDrawing(QWidget *parent)
    : QWidget(parent)
{

	m_pRenderArea = new QtDemo_renderArea;												///< 我发现官方很喜欢在后面指定对象,可能是这样灵活一点 

	/**————————————— 选择展示形状的空间 —————————————*/
	m_pShapeComboBox = new QComboBox;
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("多边形"), QtDemo_renderArea::em_Polygon);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("矩阵"), QtDemo_renderArea::em_Rect);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("圆角矩形"), QtDemo_renderArea::em_RoundedRect);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("椭圆形"), QtDemo_renderArea::em_Ellipse);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("扇形"), QtDemo_renderArea::em_Pie);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("小半圆"), QtDemo_renderArea::em_Chord);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("微积分"), QtDemo_renderArea::em_Path);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("线条"), QtDemo_renderArea::em_Line);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("折线"), QtDemo_renderArea::em_Polyline);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("弧线"), QtDemo_renderArea::em_Arc);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("点集"), QtDemo_renderArea::em_Points);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("文本"), QtDemo_renderArea::em_Text);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("图片"), QtDemo_renderArea::em_Pixmap);

	m_pShapeLable = new QLabel(tr("&Shape"));											///< 设置与Label对应的”伙伴”控件 
	m_pShapeLable->setBuddy(m_pShapeComboBox);

	/**————————————— 调节笔的宽度 —————————————*/

	m_pPenWidthSpinBox = new QSpinBox;
	m_pPenWidthSpinBox->setRange(0, 20);
	m_pPenWidthSpinBox->setSpecialValueText(QString::fromLocal8Bit(" 0 化妆笔"));		///< 翻译出来是化妆笔? 而且0和1没差别诶 
	
	m_pPenWidthLable = new QLabel(QString::fromLocal8Bit("画笔&宽度"));
	m_pPenWidthLable->setBuddy(m_pPenWidthSpinBox);

	/**————————————— 画笔风格 —————————————*/
	m_pPenStyleComboBox = new QComboBox;
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("实线"), static_cast<int>(Qt::SolidLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("破折号"), static_cast<int>(Qt::DashLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("虚线"), static_cast<int>(Qt::DotLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("点划线"), static_cast<int>(Qt::DashDotLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("点点划线"), static_cast<int>(Qt::DashDotDotLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("无"), static_cast<int>(Qt::NoPen));

	m_pPenStyleLable = new QLabel(QString::fromLocal8Bit("画笔&风格"));
	m_pPenStyleLable->setBuddy(m_pPenStyleComboBox);

	/**————————————— 线段末端 —————————————*/
	m_pPenCapComboBox = new QComboBox;
	m_pPenCapComboBox->addItem(QString::fromLocal8Bit("延长方形线端", Qt::FlatCap));
	m_pPenCapComboBox->addItem(QString::fromLocal8Bit("方形线端", Qt::SquareCap));
	m_pPenCapComboBox->addItem(QString::fromLocal8Bit("圆形线端", Qt::RoundCap));

	m_pPenCapLabel = new QLabel(QString::fromLocal8Bit("画笔&线段末端"));
	m_pPenCapLabel->setBuddy(m_pPenCapComboBox);

	/**————————————— 线段连接 —————————————*/
	m_pPenJoinComboBox = new QComboBox;
	m_pPenJoinComboBox->addItem(QString::fromLocal8Bit("方形连接"), Qt::MiterJoin);
	m_pPenJoinComboBox->addItem(QString::fromLocal8Bit("尖形连接"), Qt::BevelJoin);
	m_pPenJoinComboBox->addItem(QString::fromLocal8Bit("圆形连接"), Qt::RoundJoin);

	m_pPenJoinLable = new QLabel;
	m_pPenJoinLable->setBuddy(m_pPenJoinComboBox);

	m_pBrushStyleComboBox = new QComboBox;
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("线性渐变"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("辐射渐变"), static_cast<int>(Qt::RadialGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("圆锥渐变"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("纹理"), static_cast<int>(Qt::TexturePattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("固态"), static_cast<int>(Qt::SolidPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("水平"), static_cast<int>(Qt::HorPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("垂直"), static_cast<int>(Qt::VerPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("网格"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("反斜线"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("斜线"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("斜网格"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("稠密1"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("稠密2"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("稠密3"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("稠密4"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("稠密5"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("稠密6"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("稠密7"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("无"), static_cast<int>(Qt::LinearGradientPattern));






}

QtDemo_basicDrawing::~QtDemo_basicDrawing()
{


}
