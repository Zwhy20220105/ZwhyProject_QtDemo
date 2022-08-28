#include "QtDemo_addDialog.h"

QtDemo_addDialog::QtDemo_addDialog(QWidget *parent)
	: QDialog(parent),
	/**	��߲�û��ָ��������,�������ڲ�����ָ����.����������ָ�����׵��׹ؼ����ؼ�	*/
	/**	������߸�����Ҳ������,��������ָ��,������ָ����	*/
	m_nameText(new QLineEdit),
	m_addressText(new QTextEdit)
{
	/**�������������������������� �½����񲼾ֿؼ� ��������������������������*/

	auto nameLable = new QLabel(QString("����"));
	auto addressLable = new QLabel(QString("��ַ"));
	
	auto gridLayout = new QGridLayout;
	gridLayout->setColumnStretch(1,2); 
	/**�������������������������� ���ؼ��������񲼾�(����ѧϰ) ��������������������������*/

	gridLayout->addWidget(nameLable, 0, 0);
	gridLayout->addWidget(m_nameText, 0, 1);
	gridLayout->addWidget(addressLable, 1, 0, Qt::AlignLeft | Qt::AlignTop);
	gridLayout->addWidget(m_addressText, 1, 1, Qt::AlignLeft);
	
	/**�������������������������� �������������񲼾�(��ѧϰ) ��������������������������*/
	
	auto btnLayout = new QHBoxLayout;
	
	auto okBtn = new QPushButton(QString("���"));
	auto cancelBtn = new QPushButton(QString("ȡ��"));
	
	btnLayout->addWidget(okBtn);
	btnLayout->addWidget(cancelBtn);
	
	gridLayout->addLayout(btnLayout, 2, 1, Qt::AlignRight);
	
	/**	�½���ֱ������Ϊ������,��Ȼ����Ҳ����,���ǳ����³���Կ�����ǿ	*/
	auto mainLayout = new QVBoxLayout;
	mainLayout->addLayout(gridLayout);
	this->setLayout(mainLayout);

	/**�������������������������� ���ӿؼ����ܲۺ��� ��������������������������*/

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
