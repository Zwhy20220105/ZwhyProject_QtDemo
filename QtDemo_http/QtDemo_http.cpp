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
	,m_statusLabel(new QLabel(QString::fromLocal8Bit("请输入你想要下载文件的URL"),this))
	,m_urlLineEdit(new QLineEdit(cDefaultUrl))
	,m_downloadBtn(new QPushButton(QString::fromLocal8Bit("下载")))
	,m_launchCheckBox(new QCheckBox(QString::fromLocal8Bit("打开文件")))
	,m_defaultFileLineEdit(new QLineEdit(cDefaultFileName))
	,m_downloadDirLineEdit(new QLineEdit)
	,m_networkReply(nullptr)
	,m_file(nullptr)
	,m_httpRequestAborted(false)
{
	//this->setFixedSize(800, 600);
	/**	隐藏Dialog的?,好像还会	*/
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
	setWindowTitle(tr("Http"));
	connect(&m_networkManager, &QNetworkAccessManager::authenticationRequired, this, &QtDemo_http::on_http_authentication_required);
	/**	if no defined*/
#ifndef QT_NO_SSL
	connect(&m_networkManager, &QNetworkAccessManager::sslErrors, this, &QtDemo_http::on_http_ssl_errors);
#endif
	QFormLayout* formLayout = new QFormLayout;
	m_urlLineEdit->setClearButtonEnabled(true);
	connect(m_urlLineEdit, &QLineEdit::textChanged, this, &QtDemo_http::on_btn_enable_download);

	formLayout->addRow(tr("URL:"), m_urlLineEdit);

	QString strDownloadDirectory = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
	
	if (strDownloadDirectory.isEmpty()||!QFileInfo(strDownloadDirectory).isDir())
	{
		strDownloadDirectory = QDir::currentPath();
	}

	m_downloadDirLineEdit->setText(QDir::toNativeSeparators(strDownloadDirectory));

	formLayout->addRow(QString::fromLocal8Bit("下载目录"), m_downloadDirLineEdit);
	formLayout->addRow(QString::fromLocal8Bit("默认文件"), m_defaultFileLineEdit);
	m_launchCheckBox->setChecked(true);
	formLayout->addRow(m_launchCheckBox);

	QVBoxLayout* mainLayout = new QVBoxLayout(this);
	mainLayout->addLayout(formLayout);

	mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));

	m_statusLabel->setWordWrap(true);
	mainLayout->addWidget(m_statusLabel);

	m_downloadBtn->setDefault(true);
	connect(m_downloadBtn, &QPushButton::clicked, this, &QtDemo_http::on_btn_download_file);







}

QtDemo_http::~QtDemo_http()
{

}

void QtDemo_http::on_btn_enable_download()
{
	m_downloadBtn->setEnabled(!m_urlLineEdit->text().isEmpty());
}

void QtDemo_http::on_btn_download_file()
{
	const QString strStop;

}

void QtDemo_http::on_http_ssl_errors(QNetworkReply * networkReply, const QList<QSslError>& errors)
{
	QString strError;
	for (const QSslError& error:errors)
	{
		if (!strError.isEmpty())
		{
			strError += '\n';
		}
		strError += error.errorString();
	}
	if((QMessageBox::warning(this
		,QString::fromLocal8Bit("SSL 错误")
		,QString::fromLocal8Bit("一个或多个SSL错误发生:\n%1").arg(strError)
		,QMessageBox::Ignore|QMessageBox::Abort))== QMessageBox::Ignore)
	{
		m_networkReply->ignoreSslErrors();
	}

}


void QtDemo_http::on_http_authentication_required(QNetworkReply* networkReply, QAuthenticator* authenticator)
{
	/**————————————— 这一段很关键 —————————————*/
	QDialog authenticationDalog;
	Ui::Dialog ui;
	ui.setupUi(&authenticationDalog);
	authenticationDalog.adjustSize();
	ui.siteDescription->setText(tr("%1 at %2").arg(authenticator->realm(), m_url.host()));
	/**————————————— 官方戴莫教做人环节 —————————————*/ 

	// Did the URL have information? Fill the UI
	/**	网址有信息吗？ 填充用户界面	*/
	// This is only relevant if the URL-supplied credentials were wrong
	/**	这只在url提供的凭据错误的情况下才有用	*/

	ui.userLineEdit->setText(m_url.userName());
	ui.passwordLineEdit->setText(m_url.password());

	/**
		my1是一个对话框，当调用exec方法时，弹出，等待用户响应，用户可能点击确定
	，那么exec返回QDialog::Accepted值，如果点击取消则返回QDialog::Rejected,
	这句话是通过返回值来确定用户的响应结果	
	*/
	if (authenticationDalog.exec()==QDialog::Accepted)
	{
		authenticator->setUser(ui.userLineEdit->text());
		authenticator->setPassword(ui.passwordLineEdit->text());
	}

}
