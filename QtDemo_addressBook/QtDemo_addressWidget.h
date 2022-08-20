#pragma once
#pragma execution_character_set("utf-8")

#include <QTabWidget>
#include <QFile>
#include <QMessageBox>
#include <QVector>
#include <QDataStream>
#include <QModelIndex>
#include <QregularExpression>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QAbstractItemView>
#include <QItemSelection>
#include <QHeaderView>
#include <QVariant>


#include "QtDemo_tableModel.h"
#include "QtDemo_addressTab.h"
#include "QtDemo_addDialog.h"

class QtDemo_addressWidget : public QTabWidget
{
	Q_OBJECT

public:
	QtDemo_addressWidget(QWidget *parent = Q_NULLPTR);
	~QtDemo_addressWidget();
	
	/**	读取通信录文件	*/
	void readFromFile(const QString& fileName);

	void addEntry(const QString& strName, const QString& strAddress);

	void writeToFile(const QString& strFileName);

	void setupTabs();

public slots:
	//void on_item_changed_emit(const QItemSelection& selectied);
	void on_dialog_add_entry();

	void on_dialog_edit_entry();

	void on_btn_remove_entry();


private:

	QtDemo_tableModel* m_tableModel;
	QtDemo_addressTab* m_addressTab;

signals:
	void signalSelectionChanged(const QItemSelection& selected);
};
