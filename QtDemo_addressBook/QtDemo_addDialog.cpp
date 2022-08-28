#include "QtDemo_addDialog.h"

QtDemo_addDialog::QtDemo_addDialog(QWidget *parent)
	: QDialog(parent),
	/**	这边并没有指定父对象,可能是在布局中指定了.所以在哪里指定父亲到底关键不关键	*/
	/**	反正这边父对象也不是他,而且有了指针,很容易指定的	*/
	m_nameText(new QLineEdit),
	m_addressText(new QTextEdit)
{
	/**————————————— 新建网格布局控件 —————————————*/

	auto nameLable = new QLabel(QString("姓名"));
	auto addressLable = new QLabel(QString("地址"));
	
	auto gridLayout = new QGridLayout;
	gridLayout->setColumnStretch(1,2); 
	/**————————————— 将控件载入网格布局(可以学习) —————————————*/

	gridLayout->addWidget(nameLable, 0, 0);
	gridLayout->addWidget(m_nameText, 0, 1);
	gridLayout->addWidget(addressLable, 1, 0, Qt::AlignLeft | Qt::AlignTop);
	gridLayout->addWidget(m_addressText, 1, 1, Qt::AlignLeft);
	
	/**————————————— 将布局载入网格布局(可学习) —————————————*/
	
	auto btnLayout = new QHBoxLayout;
	
	auto okBtn = new QPushButton(QString("完成"));
	auto cancelBtn = new QPushButton(QString("取消"));
	
	btnLayout->addWidget(okBtn);
	btnLayout->addWidget(cancelBtn);
	
	gridLayout->addLayout(btnLayout, 2, 1, Qt::AlignRight);
	
	/**	新建垂直布局作为整体框架,虽然不加也可以,但是程序的鲁棒性可以增强	*/
	auto mainLayout = new QVBoxLayout;
	mainLayout->addLayout(gridLayout);
	this->setLayout(mainLayout);

	/**————————————— 链接控件功能槽函数 —————————————*/

	connect(okBtn, &QPushButton::clicked, this, &QtDemo_addDialog::accept);
	connect(cancelBtn, &QPushButton::clicked, this, &QtDemo_addDialog::reject);

	this->setWindowTitle(QString("添加联系人"));

}

QtDemo_addDialog::~QtDemo_addDialog()
{

}


QString QtDemo_addDialog::getConetactName() const
{
	return m_nameText->text();

}

QString QtDemo_addDialog::getConetactAddress() const
{
	return m_addressText->toPlainText();
}

void QtDemo_addDialog::editContact(const QString & strName, const QString & strAddress)
{
	m_nameText->setReadOnly(true);
	m_nameText->setText(strName);
	m_addressText->setPlainText(strAddress);
}
