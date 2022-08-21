#include "QtDemo_addDialog.h"

QtDemo_addDialog::QtDemo_addDialog(QWidget *parent)
	: QDialog(parent),
	/**	��߲�û��ָ��������,�������ڲ�����ָ����.����������ָ�����׵��׹ؼ����ؼ�	*/
	/**	������߸�����Ҳ������,��������ָ��,������ָ����	*/
	m_nameText(new QLineEdit),
	m_addressText(new QTextEdit)
{
	auto nameLable = new QLabel(QString("����"));
	auto addressLable = new QLabel(QString("��ַ"));

	auto okBtn = new QPushButton(QString("���"));
	auto cancelBtn = new QPushButton(QString("ȡ��"));
	/**	���񲼾�	*/
	auto gridLayout = new QGridLayout;
	/**	��֪������Ǹ����1,2	*/
	/**	��Ҫ��������˲�û�з�Ӧ	*/
	gridLayout->setColumnStretch(1,2);
	gridLayout->addWidget(nameLable, 0, 0);
	gridLayout->addWidget(m_nameText, 0, 1);

	/**	���ò��ֶ����ʽ,��������ʱ��	*/
	gridLayout->addWidget(addressLable, 1, 0, Qt::AlignLeft | Qt::AlignTop);
	gridLayout->addWidget(m_addressText, 1, 1, Qt::AlignLeft);
	
	/**	ˮƽ����	*/
	auto btnLayout = new QHBoxLayout;
	btnLayout->addWidget(okBtn);
	btnLayout->addWidget(cancelBtn);
	gridLayout->addLayout(btnLayout, 2, 1, Qt::AlignRight);
	/**	��ֱ����	*/
	auto mainLayout = new QVBoxLayout;
	mainLayout->addLayout(gridLayout);
	this->setLayout(mainLayout);

	connect(okBtn, &QPushButton::clicked, this, &QtDemo_addDialog::accept);
	connect(cancelBtn, &QPushButton::clicked, this, &QtDemo_addDialog::reject);

	this->setWindowTitle(QString("�����ϵ��"));
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
