#pragma once

#include <QtWidgets/QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QFile>
#include <QString>
#include <QAuthenticator>
#include <QMessageBox>
#include <QFormLayout>
#include <QLayout>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>


class QtDemo_http : public QDialog
{
    Q_OBJECT

public:
	explicit QtDemo_http(QWidget *parent = nullptr);
    ~QtDemo_http();


public slots:

	void on_http_authentication_required(QNetworkReply* networkReply,QAuthenticator* authenticator);

	void on_btn_enable_download();

	void on_btn_download_file();

#ifndef QT_NO_SSL
	void on_http_ssl_errors(QNetworkReply*networkReply,const QList<QSslError>& errors);
#endif

private:

	QLabel* m_statusLabel;
	QLineEdit* m_urlLineEdit;
	QPushButton* m_downloadBtn;
	QCheckBox* m_launchCheckBox;
	QLineEdit* m_defaultFileLineEdit;
	QLineEdit* m_downloadDirLineEdit;

	QUrl m_url;
	QNetworkAccessManager m_networkManager;
	QNetworkReply* m_networkReply;
	QFile* m_file;

	/**	Aborted ∑≠“Î ÷’÷π	*/
	bool m_httpRequestAborted;

};
