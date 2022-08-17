#include "QtDemo_addressTab.h"

QtDemo_addressTab::QtDemo_addressTab(QWidget *parent)
	: QWidget(parent)

{
	auto descriptionLabel = new QLabel(QString("当前没有联系人在你的通信录中.""\n请单击添加"));
	auto addBtn = new QPushButton(QString("添加"),this);

	connect(addBtn, &QPushButton::clicked, this, &QtDemo_addressTab::on_btn_add_entry);

	auto mainLayout = new QVBoxLayout;

	mainLayout->addWidget(descriptionLabel,0,Qt::AlignCenter);
	mainLayout->addWidget(addBtn, 0, Qt::AlignCenter);

	this->setLayout(mainLayout);
}

QtDemo_addressTab::~QtDemo_addressTab()
{

}

void QtDemo_addressTab::on_btn_add_entry()
{
	QtDemo_addDialog addDialog;
	if (addDialog.exec())
	{
		emit sendDetails(addDialog.getConetactName(), addDialog.getConetactAddress());
	}
}
