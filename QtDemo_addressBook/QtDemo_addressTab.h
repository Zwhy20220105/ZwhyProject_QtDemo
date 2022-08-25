#pragma once
#pragma execution_character_set("utf-8")
#include <QWidget>
#include <QAbstractTableModel>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>


/**	����ط���Ȼ������<>,��Ȼ����������˵ȷʵ������	*/
#include "QtDemo_addDialog.h"

class QtDemo_addressTab  : public QWidget
{
	Q_OBJECT

public:
	QtDemo_addressTab(QWidget *parent);
	~QtDemo_addressTab();


public:
	/**	���Ժ���	*/
	void testLayout(QVBoxLayout* mainLayout);

public slots:
	void on_btn_add_entry();

private:
	

signals:
	void sendDetails(const QString& strName, const QString& strAddress);
};
