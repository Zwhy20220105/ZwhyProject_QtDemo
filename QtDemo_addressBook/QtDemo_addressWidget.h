#pragma once
#pragma execution_character_set("utf-8")

#include <QTabWidget>
#include <QFile>
#include <QMessageBox>
#include <QVector>

namespace Ui { class QtDemo_addressWidget; };

class QtDemo_addressWidget : public QTabWidget
{
	Q_OBJECT

public:
	QtDemo_addressWidget(QWidget *parent = Q_NULLPTR);
	~QtDemo_addressWidget();

	void readFromFile(const QString& fileName);

private:
	Ui::QtDemo_addressWidget *ui;
};
