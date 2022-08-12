#pragma once

#include <QAbstractTableModel>
#include <QAbstractAnimation>
#include <QString>

struct Contact;

class QtDemo_tableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	QtDemo_tableModel(QWidget *parent = nullptr);
	~QtDemo_tableModel();

	const QVector<Contact>& getContacts() const;

	bool insertRows(int position, int rows, const QModelIndex& index);
private:

	QVector<Contact> m_contacts;
};

/**	ͨѶ¼��Ա������	*/
struct Contact
{
	QString strName;
	QString strAddress;
	/**	���� == ��	*/
	bool operator==(const Contact& other) const
	{
		return strName == other.strName && strAddress == other.strAddress;
	}
};

/**	����C++�У�stream��>>ֱ�Ӿ����Կո�Ϊ�ָ�����ȡ�ļ�����,����һֱ������βEOF	*/
inline QDataStream& operator>> (QDataStream& stream, Contact& tContact)
{
	return stream >> tContact.strName >> tContact.strAddress;
}
