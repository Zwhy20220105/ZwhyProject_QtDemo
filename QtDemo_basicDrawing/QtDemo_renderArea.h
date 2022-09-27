#pragma once

/**¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª ¹Ù·½µÄ ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª*/
#include <QWidget>
#include <QPixmap>


/**¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª ×Ô¼ºµÄ ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª*/


class QtDemo_renderArea : public QWidget
{
	Q_OBJECT

/**¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª ¹«¿ªµÄº¯Êý ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª*/
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

/**¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª ±£»¤µÄº¯Êý,Ò»°ã×÷ÎªÖØÐ´Ðéº¯ÊýµÄ¼Ì³ÐÈ¨ÏÞ ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª*/
protected:

/**¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª Ë½ÓÐµÄº¯Êý,Ö»ÓÐÀàÄÚº¯Êý²Å¿ÉÒÔµ÷ÓÃ ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª*/
private:

/**¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª ¹«¿ªµÄ²Ûº¯Êý,±ãÓÚÍâ²¿µ÷ÓÃ ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª*/
public slots:

/**¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª ³ÉÔ±±äÁ¿µÄÈ¨ÏÞÄ¬ÈÏÊÇË½ÓÐµÄ ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª*/
private:
	Shape m_shape;

	bool m_bAntialiased;
	bool m_bTransformed;

	QPixmap pixmap;

/**¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª ÐÅºÅ ¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª*/
signals:

};
