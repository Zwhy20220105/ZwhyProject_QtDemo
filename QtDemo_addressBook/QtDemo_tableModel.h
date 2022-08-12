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

/**	通讯录成员管理类	*/
struct Contact
{
	QString strName;
	QString strAddress;
	/**	重载 == 号	*/
	bool operator==(const Contact& other) const
	{
		return strName == other.strName && strAddress == other.strAddress;
	}
};

/**	而在C++中，stream的>>直接就是以空格为分隔符读取文件内容,他会一直读到结尾EOF	*/
inline QDataStream& operator>> (QDataStream& stream, Contact& tContact)
{
	return stream >> tContact.strName >> tContact.strAddress;
}
