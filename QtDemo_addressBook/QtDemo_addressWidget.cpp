#include "QtDemo_addressWidget.h"

QtDemo_addressWidget::QtDemo_addressWidget(QWidget *parent)
     /**	这个地方有点神奇,在这里构造就算了,然后他还里面是要先去重写虚函数的,只是没见过,但是不难理解吧	*/
	/**	这边要重写一下三个函数,起初我以为是纯虚函数,必须要重载,但是现在看上去不是	*/
	: QTabWidget(parent),
	m_tableModel(new QtDemo_tableModel(this)),
	/**	这个变量在这里初始化	*/
	m_addressTab(new QtDemo_addressTab(this))
{
	/**	其实这里的构造函数是先进行的,顺序没搞对,所以用起来可能bug*/

	connect(m_addressTab, &QtDemo_addressTab::sendDetails, this, &QtDemo_addressWidget::addEntry);

	this->addTab(m_addressTab, QString("地址簿"));

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
		/**	这里有个正则表达式,后面那个宏是大小不敏感	*/
		const auto regExp = QRegularExpression(QString("^[%1].*").arg(str), QRegularExpression::CaseInsensitiveOption);
		
		/**	这一段迷茫的很	*/
		auto proxyModel = new QSortFilterProxyModel(this);
		proxyModel->setSourceModel(m_tableModel);
		proxyModel->setFilterRegularExpression(regExp);
		proxyModel->setFilterKeyColumn(0);

		QTableView* tableView = new QTableView;
		/**	给一个view上一个模型和喝水一样	,看来是常规操作*/
		tableView->setModel(proxyModel);
		/**	这下面一堆都看不懂的,Qt接口也太多了	*/
		tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
		tableView->horizontalHeader()->setStretchLastSection(true);
		tableView->verticalHeader()->hide();
		tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
		tableView->setSelectionMode(QAbstractItemView::SingleSelection);
		tableView->setSortingEnabled(true);

		/**	这边信号和槽绑定的居然是一个非全局变量,让我非常不解	*/
		/**	然后他的槽函数居然是一个信号,这让我大受震憾	*/
		connect(tableView->selectionModel(), &QItemSelectionModel::selectionChanged, this, &QtDemo_addressWidget::signalSelectionChanged);

		/**	理论上是不允许使用lambda表达式做槽函数的,但是学习嘛,可以的*/
		/**	中括号是捕获变量,()是传递参数,如果信号和槽的话,就是信号发过来的参数	*/

		connect(this, &QTabWidget::currentChanged, this, [this, tableView](int tabIndex) {
			/**	这边addressWidgrt主要是	*/
			if(this->widget(tabIndex)==tableView)
			{
				emit signalSelectionChanged(tableView->selectionModel()->selection());
			}
		});
		addTab(tableView, str);
	}

}




void QtDemo_addressWidget::on_btn_add_entry()
{
	QtDemo_addDialog addDialog;
	if (addDialog.exec())
	{
		addEntry(addDialog.getConetactName(), addDialog.getConetactAddress());
	}
}

void QtDemo_addressWidget::on_btn_edit_entry()
{
	/**	这个地方的强制转换我就没看懂了,这是在干什么,明天再看	*/
	QTableView* editTableView = static_cast<QTableView*>(currentWidget());
	QSortFilterProxyModel* proxy = static_cast<QSortFilterProxyModel*>(editTableView->model());
	QItemSelectionModel* selectionModel = editTableView->selectionModel();

	const QModelIndexList listIndex = selectionModel->selectedRows();
	QString strName;
	QString strAddress;
	int nRow = 1;

	for (const QModelIndex& index : listIndex)
	{
		nRow = proxy->mapToSource(index).row();
		QModelIndex nameIndex = m_tableModel->index(nRow, 0, QModelIndex());
		QVariant varName = m_tableModel->data(nameIndex, Qt::DisplayRole);
		strName = varName.toString();

		QModelIndex addressIndex = m_tableModel->index(nRow, 1, QModelIndex());
		QVariant varAddr = m_tableModel->data(addressIndex, Qt::DisplayRole);
		strAddress = varAddr.toString();
	}

	QtDemo_addDialog addDialog;
	addDialog.setWindowTitle(QString("编辑一个联系人"));
	addDialog.editContact(strName, strAddress);

	if (addDialog.exec())
	{
		const QString strNewAddress = addDialog.getConetactAddress();
		if (strNewAddress!=strAddress)
		{
			const QModelIndex index = m_tableModel->index(nRow, 1, QModelIndex());
			m_tableModel->setData(index, strNewAddress, Qt::EditRole);
		}
	}
}

void QtDemo_addressWidget::on_btn_remove_entry()
{
	QTableView* removeTableView = static_cast<QTableView*>(currentWidget());
	QSortFilterProxyModel *proxy = static_cast<QSortFilterProxyModel*>(removeTableView->model());
	QItemSelectionModel* selectionModol = removeTableView->selectionModel();

	const QModelIndexList listIndex = selectionModol->selectedRows();
	for (QModelIndex index:listIndex)
	{
		int nRow = proxy->mapToSource(index).row();
		m_tableModel->removeRows(nRow, 1, QModelIndex());
	}

	if (m_tableModel->rowCount(QModelIndex())==0)
	{
		this->insertTab(0, m_addressTab, QString("地址簿"));
	}

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
	/**	还是不知道什么时候引用了tableModel里面的全局>>符号	*/
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

		/**	刚开始居然没发现	*/
		/**	因为之前有个构造函数没进去,这里才会使用成员变量,要不然,是使用未初始化的指针了	*/
		/**	这里如果有新的联系人加入,这里将会移除初始页面,也就是之前在构造函数中初始化的那个	*/
		/**	这样一通百通了,为什么是insexOf	*/
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
	/**	这里是如果是文件还好说毕竟可以以文件换行和文件结束符来终止这一切,但是如果是数组我就不知道了,	*/
	out << m_tableModel->getContacts();

}

