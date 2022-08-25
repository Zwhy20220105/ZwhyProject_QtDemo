#include "QtDemo_addressTab.h"

/**	������캯����ҳ�湹��֮��ͻ����,��ô����������ʧ��	*/
QtDemo_addressTab::QtDemo_addressTab(QWidget *parent)
	: QWidget(parent)

{
	/**	����ط�����������һ����ֱ���ּ������������еĿؼ�,��ʵ�Ҷ�ʹ������Զ��岼�ֻ����Ǻ�����	*/

	auto descriptionLabel = new QLabel(QString("��ǰû����ϵ�������ͨ��¼��.""\n�뵥�����"));
	auto addBtn = new QPushButton(QString("���"),this);

	connect(addBtn, &QPushButton::clicked, this, &QtDemo_addressTab::on_btn_add_entry);

	auto mainLayout = new QVBoxLayout;

	mainLayout->addWidget(descriptionLabel,0,Qt::AlignCenter);
	mainLayout->addWidget(addBtn, 0, Qt::AlignCenter);

	/**	������ͬһ��������,�������������	*/
	//testLayout(mainLayout);

	this->setLayout(mainLayout);
}

QtDemo_addressTab::~QtDemo_addressTab()
{

}

void QtDemo_addressTab::testLayout(QVBoxLayout* mainLayout)
{
	auto testLayout = new QHBoxLayout;
	auto addBtn1 = new QPushButton(QString("���"), this);
	auto addBtn2 = new QPushButton(QString("���"), this);
	testLayout->addWidget(addBtn1, 1);
	testLayout->addWidget(addBtn2, 2);
	mainLayout->addLayout(testLayout);
}

void QtDemo_addressTab::on_btn_add_entry()
{
	QtDemo_addDialog addDialog;
	if (addDialog.exec())
	{
		emit sendDetails(addDialog.getConetactName(), addDialog.getConetactAddress());
	}
}
