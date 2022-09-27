#pragma once

/**！！！！！！！！！！！！！ 郊圭議 ！！！！！！！！！！！！！*/
#include <QWidget>
#include <QPixmap>


/**！！！！！！！！！！！！！ 徭失議 ！！！！！！！！！！！！！*/


class QtDemo_renderArea : public QWidget
{
	Q_OBJECT

/**！！！！！！！！！！！！！ 巷蝕議痕方 ！！！！！！！！！！！！！*/
public:
	QtDemo_renderArea(QWidget *parent = nullptr);
	~QtDemo_renderArea();

	enum Shape
	{
		em_Line,
		em_Points,
		em_Polyline,
		em_Polygon,
		em_Rect,
		em_RoundedRect,
		em_Ellipse,
		em_Arc,
		em_Chord,
		em_Pie,
		em_Path,
		em_Text,
		em_Pixmap
	};

/**！！！！！！！！！！！！！ 隠擦議痕方,匯違恬葎嶷亟倡痕方議写覚幡�� ！！！！！！！！！！！！！*/
protected:

/**！！！！！！！！！！！！！ 暴嗤議痕方,峪嗤窃坪痕方嘉辛參距喘 ！！！！！！！！！！！！！*/
private:

/**！！！！！！！！！！！！！ 巷蝕議菓痕方,宴噐翌何距喘 ！！！！！！！！！！！！！*/
public slots:

/**！！！！！！！！！！！！！ 撹埀延楚議幡�淞�範頁暴嗤議 ！！！！！！！！！！！！！*/
private:
	Shape m_shape;

	bool m_bAntialiased;
	bool m_bTransformed;

	QPixmap pixmap;

/**！！！！！！！！！！！！！ 佚催 ！！！！！！！！！！！！！*/
signals:

};
