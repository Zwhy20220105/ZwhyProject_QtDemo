#include "QtDemo_addressTab.h"

QtDemo_addressTab::QtDemo_addressTab(QWidget *parent)
	: QWidget(parent)
{
	auto descriptionLabel = new QLabel(QString("��ǰû����ϵ�������ͨ��¼��.""\n�뵥�����"));
	auto addBtn = new QPushButton(QString("���"),this);

	connect(addBtn, &QPushButton::clicked, this, &QtDemo_addressTab::on_btn_add_entry);
}

QtDemo_addressTab::~QtDemo_addressTab()
{

}

void QtDemo_addressTab::on_btn_add_entry()
{
	QtDemo_addDialog addDialog;
}
