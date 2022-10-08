#include "QtDemo_basicDrawing.h"

QtDemo_basicDrawing::QtDemo_basicDrawing(QWidget *parent)
    : QWidget(parent)
{

	m_pRenderArea = new QtDemo_renderArea;												///< �ҷ��ֹٷ���ϲ���ں���ָ������,�������������һ�� 

	/**�������������������������� ѡ��չʾ��״�Ŀռ� ��������������������������*/
	m_pShapeComboBox = new QComboBox;
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("�����"), QtDemo_renderArea::em_Polygon);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("����"), QtDemo_renderArea::em_Rect);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("Բ�Ǿ���"), QtDemo_renderArea::em_RoundedRect);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("��Բ��"), QtDemo_renderArea::em_Ellipse);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("����"), QtDemo_renderArea::em_Pie);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("С��Բ"), QtDemo_renderArea::em_Chord);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("΢����"), QtDemo_renderArea::em_Path);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("����"), QtDemo_renderArea::em_Line);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("����"), QtDemo_renderArea::em_Polyline);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("����"), QtDemo_renderArea::em_Arc);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("�㼯"), QtDemo_renderArea::em_Points);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("�ı�"), QtDemo_renderArea::em_Text);
	m_pShapeComboBox->addItem(QString::fromLocal8Bit("ͼƬ"), QtDemo_renderArea::em_Pixmap);

	m_pShapeLable = new QLabel(tr("&Shape"));											///< ������Label��Ӧ�ġ���顱�ؼ� 
	m_pShapeLable->setBuddy(m_pShapeComboBox);

	/**�������������������������� ���ڱʵĿ�� ��������������������������*/

	m_pPenWidthSpinBox = new QSpinBox;
	m_pPenWidthSpinBox->setRange(0, 20);
	m_pPenWidthSpinBox->setSpecialValueText(QString::fromLocal8Bit(" 0 ��ױ��"));		///< ��������ǻ�ױ��? ����0��1û����� 
	
	m_pPenWidthLable = new QLabel(QString::fromLocal8Bit("����&���"));
	m_pPenWidthLable->setBuddy(m_pPenWidthSpinBox);

	/**�������������������������� ���ʷ�� ��������������������������*/
	m_pPenStyleComboBox = new QComboBox;
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("ʵ��"), static_cast<int>(Qt::SolidLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("���ۺ�"), static_cast<int>(Qt::DashLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("����"), static_cast<int>(Qt::DotLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("�㻮��"), static_cast<int>(Qt::DashDotLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("��㻮��"), static_cast<int>(Qt::DashDotDotLine));
	m_pPenStyleComboBox->addItem(QString::fromLocal8Bit("��"), static_cast<int>(Qt::NoPen));

	m_pPenStyleLable = new QLabel(QString::fromLocal8Bit("����&���"));
	m_pPenStyleLable->setBuddy(m_pPenStyleComboBox);

	/**�������������������������� �߶�ĩ�� ��������������������������*/
	m_pPenCapComboBox = new QComboBox;
	m_pPenCapComboBox->addItem(QString::fromLocal8Bit("�ӳ������߶�", Qt::FlatCap));
	m_pPenCapComboBox->addItem(QString::fromLocal8Bit("�����߶�", Qt::SquareCap));
	m_pPenCapComboBox->addItem(QString::fromLocal8Bit("Բ���߶�", Qt::RoundCap));

	m_pPenCapLabel = new QLabel(QString::fromLocal8Bit("����&�߶�ĩ��"));
	m_pPenCapLabel->setBuddy(m_pPenCapComboBox);

	/**�������������������������� �߶����� ��������������������������*/
	m_pPenJoinComboBox = new QComboBox;
	m_pPenJoinComboBox->addItem(QString::fromLocal8Bit("��������"), Qt::MiterJoin);
	m_pPenJoinComboBox->addItem(QString::fromLocal8Bit("��������"), Qt::BevelJoin);
	m_pPenJoinComboBox->addItem(QString::fromLocal8Bit("Բ������"), Qt::RoundJoin);

	m_pPenJoinLable = new QLabel;
	m_pPenJoinLable->setBuddy(m_pPenJoinComboBox);

	m_pBrushStyleComboBox = new QComboBox;
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("���Խ���"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("���佥��"), static_cast<int>(Qt::RadialGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("Բ׶����"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����"), static_cast<int>(Qt::TexturePattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("��̬"), static_cast<int>(Qt::SolidPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("ˮƽ"), static_cast<int>(Qt::HorPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("��ֱ"), static_cast<int>(Qt::VerPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("��б��"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("б��"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("б����"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����1"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����2"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����3"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����4"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����5"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����6"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("����7"), static_cast<int>(Qt::LinearGradientPattern));
	m_pBrushStyleComboBox->addItem(QString::fromLocal8Bit("��"), static_cast<int>(Qt::LinearGradientPattern));






}

QtDemo_basicDrawing::~QtDemo_basicDrawing()
{


}
