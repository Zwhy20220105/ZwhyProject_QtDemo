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
	/**	这地方不知为什么要指定父对象,后面不是指定了吗,但是重复指定不报错,也行	*/
	,m_statusLabel(new QLabel(QString::fromLocal8Bit("请输入你想要下载文件的URL"),this))
	,m_urlLineEdit(new QLineEdit(cDefaultUrl))
	,m_downloadBtn(new QPushButton(QString::fromLocal8Bit("下载")))
	,m_launchCheckBox(new QCheckBox(QString::fromLocal8Bit("打开文件")))
	,m_defaultFileLineEdit(new QLineEdit(cDefaultFileName))
	,m_downDirLineEdit(new QLineEdit)
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

	/**————————————— 布局设置 —————————————*/
	/**	主体为表单布局	*/
	QFormLayout* formLayout = new QFormLayout();

	/**	这样的话 QlineEdit里面会多一个小叉叉,可以删除输入框的内容	*/
	m_urlLineEdit->setClearButtonEnabled(true);
	/**	检测如果url输入框内没有字符串,就会使下载按钮变暗	*/
	connect(m_urlLineEdit, &QLineEdit::textChanged, this, &QtDemo_http::on_btn_enable_download);

	/**	好多地方是先把这个控件功能啥的做好,然后加入布局之中,这就有点具象不了,慢慢来吧	*/
	formLayout->addRow(tr("URL:"), m_urlLineEdit);

	/**	函数命名还好,变量命名就有点冗长	*/
	QString strDownloadDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
	
	if (strDownloadDir.isEmpty()||!QFileInfo(strDownloadDir).isDir())
	{
		strDownloadDir = QDir::currentPath();
	}

	m_downDirLineEdit->setText(QDir::toNativeSeparators(strDownloadDir));

	formLayout->addRow(QString::fromLocal8Bit("下载目录"), m_downDirLineEdit);
	formLayout->addRow(QString::fromLocal8Bit("默认文件"), m_defaultFileLineEdit);
	m_launchCheckBox->setChecked(true);
	formLayout->addRow(m_launchCheckBox);

	/**	不能指定两个父亲,指定了也没用,只有第一个能行	*/
	/** 加入水平布局	*/
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	/**	m_statusLabel直接加入的窗口,然后用了这句他应该就自动加入了垂直布局,可以用水平测试一下*/
	mainLayout->addLayout(formLayout);

	/**	感觉有没有差不多	*/
	mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));

	m_statusLabel->setWordWrap(true);\

	/**	我还纳闷为什么他在下面	*/
	//mainLayout->addWidget(m_statusLabel);

	/**	重复指定不报错	*/
	//m_statusLabel->setParent(this);
	m_downloadBtn->setDefault(true);

	connect(m_downloadBtn, &QPushButton::clicked, this, &QtDemo_http::on_btn_download_file);



	qDebug() << QSslSocket::sslLibraryBuildVersionString();//"OpenSSL 1.1.1g  21 Apr 2020"
	qDebug() << QSslSocket::supportsSsl();



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
	/**	其实不是很懂为什么要用这么多的 trimmed()	*/
	const QString strUrlSpec = m_urlLineEdit->text().trimmed();
	 
	/**	从界面获得URL的QString数据 */
	if (strUrlSpec.isEmpty())
	{
		return;
	}

	/**	转换	*/
	const QUrl newUrl = QUrl::fromUserInput(strUrlSpec);

	/**	为了Debug是要做出这种日志输出,但是多线程的时候...*/
	if (!newUrl.isValid())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("无效的URL:%1:%2").arg(strUrlSpec, newUrl.errorString()));
	}

	/**	URL里面携带了文件名	*/
	QString strFileName = newUrl.fileName();

	/**	文件名空的在就把默认的载入	*/
	if (strFileName.isEmpty())
	{
		strFileName = m_defaultFileLineEdit->text().trimmed();
	}
	/**	万一默认的再是空的,就把默认预设常量设置为文件名	*/
	if (strFileName.isEmpty())
	{
		strFileName = cDefaultFileName;
	}
	/**	这一步名字也可以看出来不是clear 这里理解为清洁比较好	*/
	QString  strDownDir = QDir::cleanPath(m_downDirLineEdit->text().trimmed());

	bool bUseDir = !strDownDir.isEmpty() && QFileInfo(strDownDir).isDir();

	if (bUseDir)
	{
		/**	这里就是没有使用的接口,与append相反 这里知道URL是什么的,基本上都懂	*/
		strFileName.prepend(strDownDir + "/");
	}

	if (QFile::exists(strFileName))
	{
		/*if (QMessageBox::question(this,QString::fromLocal8Bit("覆盖以存储文件")
			,QString::fromLocal8Bit("%1 这个文件已经存在" "是否覆盖").arg(strFileName)
			,)
		{
		}*/
	}



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
