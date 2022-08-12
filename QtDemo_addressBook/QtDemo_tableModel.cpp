#include "QtDemo_tableModel.h"

QtDemo_tableModel::QtDemo_tableModel(QWidget *parent)
	/**	���ﱾ�����и� parent ��֪��Ϊʲô����ȥ���� */
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
	/**	��ʵ���Ǻܶ�Ϊʲô�����������,��Ҫ������	*/
	Q_UNUSED(index);
	/**	����QModelIndex(),�ѵ�������ʲô����?	*/
	beginInsertRows(QModelIndex(), position, position + rows - 1);
	
	for (int row = 0;row < rows ; ++row)
	{
		m_contacts.insert(position, { QString(),QString() });
		endInsertRows();
		return	true;
	}
}

