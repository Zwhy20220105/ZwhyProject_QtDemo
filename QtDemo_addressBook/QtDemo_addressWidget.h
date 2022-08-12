#pragma once
#pragma execution_character_set("utf-8")

#include <QTabWidget>
#include <QFile>
#include <QMessageBox>
#include <QVector>
#include <QDataStream>
#include <QModelIndex>

#include "QtDemo_tableModel.h"
#include "QtDemo_addressTab.h"

class QtDemo_addressWidget : public QTabWidget
{
	Q_OBJECT

public:
	QtDemo_addressWidget(QWidget *parent = Q_NULLPTR);
	~QtDemo_addressWidget();
	
	/**	读取通信录文件	*/
	void readFromFile(const QString& fileName);

	void addEntry(const QString& strName, const QString& strAddress);
private:

	QtDemo_tableModel* m_tableModel;
	QtDemo_addressTab* m_addressTab;
};
