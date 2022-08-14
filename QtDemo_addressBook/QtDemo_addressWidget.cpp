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
	/**	感觉这种初始化的跳跃性大,但是也是不错的选择,嗯,以后就这样了*/
	QFile file(fileName);
	/**	很喜欢这种既可以当作debug用的工具(log),又可以进行语句执行的if判断	*/
	/**	等待造轮子(log)	*/
	if (!file.open(QIODevice::ReadOnly))
	{
		/**	虽然暂时不知道这里怎么触发文件打不开,但是这种只要调用静态函数就可以触发,不用对象接受相应内容,虽然好像是废话	*/
		QMessageBox::information(this, tr("unable to open file"), file.errorString());
		return;
	}

	/**	 装通信录成员的数组	*/
	QVector<Contact> tContact;
	/**	一直不知到这种 in file怎么命名	*/
	QDataStream in(&file);
	/**	这个地方实际应该是调用tableModel里面的全局操作符>>,然后再调用QDataStream里面的>>这里很容易误解,主要是ctrl+左键进不去,速览定义可以进去	*/
	/**	但是这里如果直接打开一个txt文件,会直接报错,不知道为什么这里有bug	*/
	in >> tContact;
	
	if (tContact.isEmpty())
	{
		QMessageBox::information(this, QString("文件中没有联系人信息"), QString("您尝试打开的文件不包含任何联系人!"));
	}
	else
	{
		/**	qAsConst 是类型转换的	*/
		for (const auto &tContact : qAsConst(tContact))
		{
			/**	一个联系人调用一次	*/
			addEntry(tContact.strName, tContact.strAddress);
		}
	}
}


void QtDemo_addressWidget::addEntry(const QString & strName, const QString & strAddress)
{
	/**	如果容器中没有这个了联系人	*/
	if (!m_tableModel->getContacts().contains({strName,strAddress}))
	{
		/**	这个函数是自己重载过的,并不是Qt标准库里面的	*/
		m_tableModel->insertRows(0, 1, QModelIndex());
		QModelIndex index = m_tableModel->index(0, 0, QModelIndex());
		m_tableModel->setData(index, strName, Qt::EditRole);
		index = m_tableModel->index(0, 1, QModelIndex());
		m_tableModel->setData(index, strAddress, Qt::EditRole);
		removeTab(indexOf(m_addressTab));
	}
	else
	{
		/**	这个地方的 \"%1"\很有意思*/
		QMessageBox::information(this, QString("重复的联系人"),QString("联系人\"%1\"已存在").arg(strName));
	}
}

void QtDemo_addressWidget::writeToFile(const QString & strFileName)
{
	QFile file(strFileName);

	if (!file.open(QIODevice::WriteOnly))
	{
		QMessageBox::information(this, QString("未能打开文件"), file.errorString());
		return;
	}
	QDataStream out(&file);
	out << m_tableModel->getContacts();

}
