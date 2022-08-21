#pragma once
#pragma execution_character_set("utf-8")

#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QLayout>

class QtDemo_addDialog  : public QDialog
{
	Q_OBJECT

public:
	QtDemo_addDialog(QWidget *parent = nullptr);
	~QtDemo_addDialog();

	QString getConetactName() const;
	QString getConetactAddress() const;

	void editContact(const QString& strName, const QString& strAddress);

private:
	QLineEdit* m_nameText;
	QTextEdit* m_addressText;
};
