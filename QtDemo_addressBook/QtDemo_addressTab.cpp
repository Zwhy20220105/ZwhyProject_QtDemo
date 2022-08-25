#include "QtDemo_addressTab.h"

/**	这个构造函数在页面构造之后就会出现,那么是在哪里消失呢	*/
QtDemo_addressTab::QtDemo_addressTab(QWidget *parent)
	: QWidget(parent)

{
	/**	这个地方就是生成了一个垂直布局加入了两个居中的控件,其实我对使用这个自定义布局还不是很熟练	*/

	auto descriptionLabel = new QLabel(QString("当前没有联系人在你的通信录中.""\n请单击添加"));
	auto addBtn = new QPushButton(QString("添加"),this);

	connect(addBtn, &QPushButton::clicked, this, &QtDemo_addressTab::on_btn_add_entry);

	auto mainLayout = new QVBoxLayout;

	mainLayout->addWidget(descriptionLabel,0,Qt::AlignCenter);
	mainLayout->addWidget(addBtn, 0, Qt::AlignCenter);

	/**	测试在同一个布局中,两个组件的伸缩	*/
	//testLayout(mainLayout);

	this->setLayout(mainLayout);
}

QtDemo_addressTab::~QtDemo_addressTab()
{

}

void QtDemo_addressTab::testLayout(QVBoxLayout* mainLayout)
{
	auto testLayout = new QHBoxLayout;
	auto addBtn1 = new QPushButton(QString("添加"), this);
	auto addBtn2 = new QPushButton(QString("添加"), this);
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
