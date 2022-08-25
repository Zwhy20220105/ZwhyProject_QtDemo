#pragma once

#include <QAbstractTableModel>
#include <QAbstractAnimation>
#include <QString>


struct Contact;

/**	�Լ�������һ��tableModel	*/
class QtDemo_tableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	QtDemo_tableModel(QObject *parent = nullptr);
	~QtDemo_tableModel();


	/**	����ط���ʼ��д���������,���ǻ�����	*/
	/**	��ʵ����һ��Ԥ����,override����֮��,������ʾ˵������,�һ�������	*/
	/**	����ط�����һ��,�տ�ʼֻ������û��ʵ��,�ͱ���"�޷��������ⲿ����"���������̸�Ļ���*/
	
	QVariant data(const QModelIndex& index, int nRole) const override;
	int rowCount(const QModelIndex &parent) const override;
	int columnCount(const QModelIndex &parent) const override;


	bool insertRows(int position, int rows, const QModelIndex& index);



	const QVector<Contact>& getContacts() const;

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

inline QDataStream& operator<< (QDataStream& stream, const Contact& tContact)
{
	return stream << tContact.strName << tContact.strAddress;
}