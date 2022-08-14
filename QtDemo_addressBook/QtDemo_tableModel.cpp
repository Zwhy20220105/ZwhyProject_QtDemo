#include "QtDemo_tableModel.h"

QtDemo_tableModel::QtDemo_tableModel(QWidget *parent)
	/**	这里本来是有个 parent 不知道为什么传进去不行 */
	: QAbstractTableModel()
{
	

}

QtDemo_tableModel::~QtDemo_tableModel()
{
}

const QVector<Contact>& QtDemo_tableModel::getContacts() const
{
	return m_contacts;
}

bool QtDemo_tableModel::insertRows(int position, int rows, const QModelIndex& index)
{
	/**	其实不是很懂为什么不用这个参数,还要传进来	*/
	Q_UNUSED(index);
	/**	这里QModelIndex(),难道掉用了什么东西?	*/
	beginInsertRows(QModelIndex(), position, position + rows - 1);
	
	for (int row = 0;row < rows ; ++row)
	{
		m_contacts.insert(position, { QString(),QString() });
	}
	/**	官方你这for循环都化简成一行,真的大逆不道	*/
	endInsertRows();
	return	true;
}

