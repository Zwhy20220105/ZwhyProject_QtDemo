#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include <QMenuBar>

#include "QtDemo_addressWidget.h"

class QtDemo_addressBook : public QMainWindow
{
    Q_OBJECT

public:
    QtDemo_addressBook(QWidget *parent = Q_NULLPTR);

	void createMenus();

public slots:
	/**	触发window打开文件的句柄	*/
	void on_btn_open_file();

	void on_btn_save_file();

private:
 
	QtDemo_addressWidget* m_addressWidget;
};
