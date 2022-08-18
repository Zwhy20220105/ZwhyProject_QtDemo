#include "QtDemo_addressWidget.h"

QtDemo_addressWidget::QtDemo_addressWidget(QWidget *parent)
     /**	����ط��е�����,�����ﹹ�������,Ȼ������������Ҫ��ȥ��д�麯����,ֻ��û����,���ǲ�������	*/
	/**	���Ҫ��дһ����������,�������Ϊ�Ǵ��麯��,����Ҫ����,�������ڿ���ȥ����	*/
	: QTabWidget(parent),m_tableModel(new QtDemo_tableModel(this)),
	/**	��������������ʼ��	*/
	m_addressTab(new QtDemo_addressTab(this))
{
	/**	��ʵ����Ĺ��캯�����Ƚ��е�,˳��û���,��������������bug*/

	connect(m_addressTab, &QtDemo_addressTab::sendDetails, this, &QtDemo_addressWidget::addEntry);

	this->addTab(m_addressTab, QString("��ַ��"));

	setupTabs();

}

QtDemo_addressWidget::~QtDemo_addressWidget()
{
}

void QtDemo_addressWidget::setupTabs()
{
	const auto groups = { "ABC","DEF","GHI","JKL","MNO","PQR","STU","VW","XYZ" };

	for (const QString& str : groups)
	{
		/**	�����и�������ʽ,�����Ǹ����Ǵ�С������	*/
		const auto regExp = QRegularExpression(QString("^[%1].*").arg(str), QRegularExpression::CaseInsensitiveOption);
		
		/**	��һ����ã�ĺ�	*/
		auto proxyModel = new QSortFilterProxyModel(this);
		proxyModel->setSourceModel(m_tableModel);
		proxyModel->setFilterRegularExpression(regExp);
		proxyModel->setFilterKeyColumn(0);

		QTableView* tableView = new QTableView;
		/**	��һ��view��һ��ģ�ͺͺ�ˮһ��	,�����ǳ������*/
		tableView->setModel(proxyModel);
		/**	������һ�Ѷ���������,Qt�ӿ�Ҳ̫����	*/
		tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
		tableView->horizontalHeader()->setStretchLastSection(true);
		tableView->verticalHeader()->hide();
		tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tableView->setSelectionMode(QAbstractItemView::SingleSelection);
		tableView->setSortingEnabled(true);

		/**	����źźͲ۰󶨵ľ�Ȼ��һ����ȫ�ֱ���,���ҷǳ�����	*/
		/**	Ȼ�����Ĳۺ�����Ȼ��һ���ź�,�����Ҵ�����	*/
		connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &QtDemo_addressWidget::signalSelectionChanged);

		/**	�������ǲ�����ʹ��lambda���ʽ���ۺ�����,����ѧϰ��,���Ե�*/
		/**	�������ǲ������,()�Ǵ��ݲ���,����źźͲ۵Ļ�,�����źŷ������Ĳ���	*/
		connect(this, &QTabWidget::currentChanged, this, [this, tableView](int tabIndex) {
			/**	���addressWidgrt��Ҫ��	*/
			if(this->widget(tabIndex)==tableView)
			{
				emit signalSelectionChanged(tableView->selectionModel()->selection());
			}
		});
		addTab(tableView, str);
	}
}




void QtDemo_addressWidget::on_dialog_add_entry()
{
	QtDemo_addDialog addDialog;
	if (addDialog.exec())
	{
		addEntry(addDialog.getConetactName(), addDialog.getConetactAddress());
	}
}

void QtDemo_addressWidget::on_dialog_edit_entry()
{
	/**	����ط���ǿ��ת���Ҿ�û������,�����ڸ�ʲô,�����ٿ�	*/
	QTableView* editTableView = static_cast<QTableView*>(currentWidget());
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
	/**	���ǲ�֪��ʲôʱ��������tableModel�����ȫ��>>����	*/
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

		/**	�տ�ʼ��Ȼû����	*/
		/**	��Ϊ֮ǰ�и����캯��û��ȥ,����Ż�ʹ�ó�Ա����,Ҫ��Ȼ,��ʹ��δ��ʼ����ָ����	*/
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
	/**	������������ļ�����˵�Ͼ��������ļ����к��ļ�����������ֹ��һ��,��������������ҾͲ�֪����,	*/
	out << m_tableModel->getContacts();

}

