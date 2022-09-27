#include "QtDemo_basicDrawing.h"

QtDemo_basicDrawing::QtDemo_basicDrawing(QWidget *parent)
    : QWidget(parent)
{
	/**	我发现官方很喜欢在后面指定对象,可能是这样灵活一点	*/
	m_pRenderArea = new QtDemo_renderArea;


}

QtDemo_basicDrawing::~QtDemo_basicDrawing()
{


}
