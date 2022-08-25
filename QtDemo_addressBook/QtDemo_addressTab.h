#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QAbstractTableModel>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>


/**	这个地方居然不能用<>,虽然从理论上来说确实不能用	*/
#include "QtDemo_addDialog.h"

class QtDemo_addressTab  : public QWidget
{
	Q_OBJECT

public:
	QtDemo_addressTab(QWidget *parent);
	~QtDemo_addressTab();


public:
	/**	测试函数	*/
	void testLayout(QVBoxLayout* mainLayout);

public slots:
	void on_btn_add_entry();

private:
	

signals:
	void sendDetails(const QString& strName, const QString& strAddress);
};
