#include "QtDemo_http.h"
#include "ui_authenticationDalog.h"

#if QT_CONFIG(ssl)
const char cDefaultUrl[] = "https://www.qt.io/";
#else
const char cDefaultUrl[] = "http://www.qt.io/";
#endif
const char cDefaultFileName[] = "index.html";

QtDemo_http::QtDemo_http(QWidget *parent)
	: QDialog(parent)
	,m_statusLabel(new QLabel(QString::fromLocal8Bit("����������Ҫ�����ļ���URL"),this))
	,m_urlLineEdit(new QLineEdit(cDefaultUrl))
	,m_downloadBtn(new QPushButton(QString::fromLocal8Bit("����")))
	,m_launchCheckBox(new QCheckBox(QString::fromLocal8Bit("���ļ�")))
	,m_defaultFileLineEdit(new QLineEdit(cDefaultFileName))
	,m_downloadDirLineEdit(new QLineEdit)
	,m_networkReply(nullptr)
	,m_file(nullptr)
	,m_httpRequestAborted(false)
{

	this->setFixedSize(800, 600);
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	setWindowTitle(tr("Http"));
	connect(&m_networkManager, &QNetworkAccessManager::authenticationRequired, this, &QtDemo_http::on_http_authentication_required);

}

QtDemo_http::~QtDemo_http()
{}


void QtDemo_http::on_http_authentication_required(QNetworkReply* networkReply, QAuthenticator* authenticator)
{
	/**�������������������������� ��һ�κܹؼ� ��������������������������*/
	QDialog authenticationDalog;
	Ui::Dialog ui;
	ui.setupUi(&authenticationDalog);
	authenticationDalog.adjustSize();
	ui.siteDescription->setText(tr("%1 at %2").arg(authenticator->realm(), m_url.host()));
	/**�������������������������� �ٷ���Ī�����˻��� ��������������������������*/ 

	// Did the URL have information? Fill the UI
	/**	��ַ����Ϣ�� ����û�����	*/
	// This is only relevant if the URL-supplied credentials were wrong
	/**	��ֻ��url�ṩ��ƾ�ݴ��������²�����	*/

	ui.userLineEdit->setText(m_url.userName());
	ui.passwordLineEdit->setText(m_url.password());

	/**
		my1��һ���Ի��򣬵�����exec����ʱ���������ȴ��û���Ӧ���û����ܵ��ȷ��
	����ôexec����QDialog::Acceptedֵ��������ȡ���򷵻�QDialog::Rejected,
	��仰��ͨ������ֵ��ȷ���û�����Ӧ���	
	*/
	if (authenticationDalog.exec()==QDialog::Accepted)
	{
		authenticator->setUser(ui.userLineEdit->text());
		authenticator->setPassword(ui.passwordLineEdit->text());
	}

}
