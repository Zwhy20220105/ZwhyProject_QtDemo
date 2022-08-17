#include "QtDemo_addressTab.h"

QtDemo_addressTab::QtDemo_addressTab(QWidget *parent)
	: QWidget(parent)

{
	auto descriptionLabel = new QLabel(QString("��ǰû����ϵ�������ͨ��¼��.""\n�뵥�����"));
	auto addBtn = new QPushButton(QString("���"),this);

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
