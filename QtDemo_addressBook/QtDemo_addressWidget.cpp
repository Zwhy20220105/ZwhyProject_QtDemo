#include "QtDemo_addressWidget.h"
#include "ui_QtDemo_addressWidget.h"

QtDemo_addressWidget::QtDemo_addressWidget(QWidget *parent)
	: QTabWidget(parent)
{
}

QtDemo_addressWidget::~QtDemo_addressWidget()
{
}



void QtDemo_addressWidget::readFromFile(const QString& fileName)
{
	/**	�о����ֳ�ʼ������Ծ�Դ�,����Ҳ�ǲ����ѡ��,��,�Ժ��������*/
	QFile file(fileName);
	/**	��ϲ�����ּȿ��Ե���debug�õĹ���(log),�ֿ��Խ������ִ�е�if�ж�	*/
	/**	�ȴ�������(log)	*/
	if (!file.open(QIODevice::ReadOnly))
	{
		/**	��Ȼ��ʱ��֪��������ô�����ļ��򲻿�,��������ֻҪ���þ�̬�����Ϳ��Դ���,���ö��������Ӧ����,��Ȼ�����Ƿϻ�	*/
		QMessageBox::information(this, tr("unable to open file"), file.errorString());
		return;
	}

	/**	 װͨ��¼��Ա������	*/
	QVector<Contact> tContact;
	/**	һֱ��֪������ in file��ô����	*/
	QDataStream in(&file);
	/**	����ط�ʵ��Ӧ���ǵ���tableModel�����ȫ�ֲ�����>>,Ȼ���ٵ���QDataStream�����>>������������,��Ҫ��ctrl+�������ȥ,����������Խ�ȥ	*/
	/**	�����������ֱ�Ӵ�һ��txt�ļ�,��ֱ�ӱ���,��֪��Ϊʲô������bug	*/
	in >> tContact;
	
	if (tContact.isEmpty())
	{
		QMessageBox::information(this, QString("�ļ���û����ϵ����Ϣ"), QString("�����Դ򿪵��ļ��������κ���ϵ��!"));
	}
	else
	{
		/**	qAsConst ������ת����	*/
		for (const auto &tContact : qAsConst(tContact))
		{
			/**	һ����ϵ�˵���һ��	*/
			addEntry(tContact.strName, tContact.strAddress);
		}
	}
}


void QtDemo_addressWidget::addEntry(const QString & strName, const QString & strAddress)
{
	/**	���������û���������ϵ��	*/
	if (!m_tableModel->getContacts().contains({strName,strAddress}))
	{
		/**	����������Լ����ع���,������Qt��׼�������	*/
		m_tableModel->insertRows(0, 1, QModelIndex());
		QModelIndex index = m_tableModel->index(0, 0, QModelIndex());
		m_tableModel->setData(index, strName, Qt::EditRole);
		index = m_tableModel->index(0, 1, QModelIndex());
		m_tableModel->setData(index, strAddress, Qt::EditRole);
		removeTab(indexOf(m_addressTab));
	}
	else
	{
		/**	����ط��� \"%1"\������˼*/
		QMessageBox::information(this, QString("�ظ�����ϵ��"),QString("��ϵ��\"%1\"�Ѵ���").arg(strName));
	}
}

void QtDemo_addressWidget::writeToFile(const QString & strFileName)
{
	QFile file(strFileName);

	if (!file.open(QIODevice::WriteOnly))
	{
		QMessageBox::information(this, QString("δ�ܴ��ļ�"), file.errorString());
		return;
	}
	QDataStream out(&file);
	out << m_tableModel->getContacts();

}
