#pragma once

#include <QAbstractTableModel>
#include <QAbstractAnimation>
#include <QString>


struct Contact;

/**	自己定义了一个tableModel	*/
class QtDemo_tableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	QtDemo_tableModel(QObject *parent = nullptr);
	~QtDemo_tableModel();


	/**	这个地方开始重写还想改名字,真是荒唐了	*/
	/**	其实是有一点预警的,override加了之后,智能提示说有问题,我还纳闷了	*/
	/**	这个地方还有一点,刚开始只有声明没有实现,就报错"无法解析的外部命令"这个老生常谈的话题*/
	
	QVariant data(const QModelIndex& index, int nRole) const override;
	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;


	bool insertRows(int position, int rows, const QModelIndex& index);



	const QVector<Contact>& getContacts() const;

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

inline QDataStream& operator<< (QDataStream& stream, const Contact& tContact)
{
	return stream << tContact.strName << tContact.strAddress;
}