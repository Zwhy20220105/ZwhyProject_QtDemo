#include "QtDemo_tableModel.h"

QtDemo_tableModel::QtDemo_tableModel(QObject *parent)
	/**	���ﱾ�����и� parent ��֪��Ϊʲô����ȥ���� */
	/**	����һ���������Ǳ�ҲҪͬ����һ��	*/
	: QAbstractTableModel(parent)
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
	}
	/**	�ٷ�����forѭ���������һ��,��Ĵ��治��	*/
	endInsertRows();
	return	true;
}

QVariant QtDemo_tableModel::data(const QModelIndex & index, int nRole) const
{
	return QVariant();
}

int QtDemo_tableModel::rowCount(const QModelIndex & parent) const
{
	return 0;
}

int QtDemo_tableModel::columnCount(const QModelIndex & parent) const
{
	return 0;
}

