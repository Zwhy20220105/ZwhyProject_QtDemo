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

bool QtDemo_tableModel::removeRows(int position, int rows, const QModelIndex & index)
{
	Q_UNUSED(index);
	beginInsertRows(QModelIndex(), position, position + rows - 1);

	for (int row=0;row<rows;++row)
	{
		m_contacts.remove(position);
	}
	endInsertRows();

	return true;
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

bool QtDemo_tableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (index.isValid()&& role ==Qt::EditRole)
	{
		const int row = index.row();
		auto contact = m_contacts.value(row);
		
		switch (index.column())
		{
		case 0:
			contact.strName = value.toString();
			break;
		case 1:
			contact.strAddress = value.toString();
			break;
		default:
			break;
		}
		m_contacts.replace(row, contact);
		/**	�����Ȼ�Ǹ�����д�õĺ���	*/
		emit dataChanged(index, index,{ Qt::DisplayRole,Qt::EditRole });

		return true;
	}
	return false;
}

QVariant QtDemo_tableModel::data(const QModelIndex& index, int nRole) const
{
	if (!index.isValid())
	{
		return QVariant();
	}
	if (index.row() >= m_contacts.size()||index.row()<0)
	{
		return QVariant();
	}

	if (nRole == Qt::DisplayRole)
	{
		const auto& contact = m_contacts.at(index.row());

		switch (index.column())
		{
		case 0:
			return contact.strName;
		case 1:
			return contact.strAddress;
		default:
			break;
		}
	}

	return QVariant();
}

int QtDemo_tableModel::rowCount(const QModelIndex & parent) const
{
	return parent.isValid() ? 0 : m_contacts.size();
}

int QtDemo_tableModel::columnCount(const QModelIndex & parent) const
{
	return parent.isValid() ? 0 : 2;
}

QVariant QtDemo_tableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
	{
		return QVariant();
	}

	if (Qt::Horizontal == orientation)
	{
		switch (section)
		{
		case 0:
			return QString::fromLocal8Bit("����");
		case 1:
			return QString::fromLocal8Bit("��ַ");
		default:
			break;
		}
	}
	return QVariant();
}

Qt::ItemFlags QtDemo_tableModel::flags(const QModelIndex & index) const
{
	if (!index.isValid())
	{
		return Qt::ItemIsEnabled;
	}
	return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}

