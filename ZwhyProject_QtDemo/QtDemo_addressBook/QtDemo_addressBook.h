#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtDemo_addressBook.h"
#include <QFileDialog>

#include "QtDemo_addressWidget.h"

class QtDemo_addressBook : public QMainWindow
{
    Q_OBJECT

public:
    QtDemo_addressBook(QWidget *parent = Q_NULLPTR);

	void createMenus();

public slots:
	void openFile();

private:
    Ui::QtDemo_addressBookClass ui;

	QtDemo_addressWidget* m_addressWidget;
};
