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
	/**	��ط���֪ΪʲôҪָ��������,���治��ָ������,�����ظ�ָ��������,Ҳ��	*/
	,m_statusLabel(new QLabel(QString::fromLocal8Bit("����������Ҫ�����ļ���URL"),this))
	,m_urlLineEdit(new QLineEdit(cDefaultUrl))
	,m_downloadBtn(new QPushButton(QString::fromLocal8Bit("����")))
	,m_launchCheckBox(new QCheckBox(QString::fromLocal8Bit("���ļ�")))
	,m_defaultFileLineEdit(new QLineEdit(cDefaultFileName))
	,m_downDirLineEdit(new QLineEdit)
	,m_networkReply(nullptr)
	,m_file(nullptr)
	,m_httpRequestAborted(false)
{
	//this->setFixedSize(800, 600);
	/**	����Dialog��?,���񻹻�	*/
	setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);

	setWindowTitle(tr("Http"));
	connect(&m_networkManager, &QNetworkAccessManager::authenticationRequired, this, &QtDemo_http::on_http_authentication_required);
	/**	if no defined*/
#ifndef QT_NO_SSL
	connect(&m_networkManager, &QNetworkAccessManager::sslErrors, this, &QtDemo_http::on_http_ssl_errors);
#endif

	/**�������������������������� �������� ��������������������������*/
	/**	����Ϊ������	*/
	QFormLayout* formLayout = new QFormLayout();

	/**	�����Ļ� QlineEdit������һ��С���,����ɾ������������	*/
	m_urlLineEdit->setClearButtonEnabled(true);
	/**	������url�������û���ַ���,�ͻ�ʹ���ذ�ť�䰵	*/
	connect(m_urlLineEdit, &QLineEdit::textChanged, this, &QtDemo_http::on_btn_enable_download);

	/**	�ö�ط����Ȱ�����ؼ�����ɶ������,Ȼ����벼��֮��,����е������,��������	*/
	formLayout->addRow(tr("URL:"), m_urlLineEdit);

	/**	������������,�����������е��߳�	*/
	QString strDownloadDir = QStandardPaths::writableLocation(QStandardPaths::TempLocation);
	
	if (strDownloadDir.isEmpty()||!QFileInfo(strDownloadDir).isDir())
	{
		strDownloadDir = QDir::currentPath();
	}

	m_downDirLineEdit->setText(QDir::toNativeSeparators(strDownloadDir));

	formLayout->addRow(QString::fromLocal8Bit("����Ŀ¼"), m_downDirLineEdit);
	formLayout->addRow(QString::fromLocal8Bit("Ĭ���ļ�"), m_defaultFileLineEdit);
	m_launchCheckBox->setChecked(true);
	formLayout->addRow(m_launchCheckBox);

	/**	����ָ����������,ָ����Ҳû��,ֻ�е�һ������	*/
	/** ����ˮƽ����	*/
	QVBoxLayout* mainLayout = new QVBoxLayout(this);

	/**	m_statusLabelֱ�Ӽ���Ĵ���,Ȼ�����������Ӧ�þ��Զ������˴�ֱ����,������ˮƽ����һ��*/
	mainLayout->addLayout(formLayout);

	/**	�о���û�в��	*/
	mainLayout->addItem(new QSpacerItem(0, 0, QSizePolicy::Ignored, QSizePolicy::MinimumExpanding));

	m_statusLabel->setWordWrap(true);\

	/**	�һ�����Ϊʲô��������	*/
	//mainLayout->addWidget(m_statusLabel);

	/**	�ظ�ָ��������	*/
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
	/**	��ʵ���Ǻܶ�ΪʲôҪ����ô��� trimmed()	*/
	const QString strUrlSpec = m_urlLineEdit->text().trimmed();
	 
	/**	�ӽ�����URL��QString���� */
	if (strUrlSpec.isEmpty())
	{
		return;
	}

	/**	ת��	*/
	const QUrl newUrl = QUrl::fromUserInput(strUrlSpec);

	/**	Ϊ��Debug��Ҫ����������־���,���Ƕ��̵߳�ʱ��...*/
	if (!newUrl.isValid())
	{
		QMessageBox::information(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��Ч��URL:%1:%2").arg(strUrlSpec, newUrl.errorString()));
	}

	/**	URL����Я�����ļ���	*/
	QString strFileName = newUrl.fileName();

	/**	�ļ����յ��ھͰ�Ĭ�ϵ�����	*/
	if (strFileName.isEmpty())
	{
		strFileName = m_defaultFileLineEdit->text().trimmed();
	}
	/**	��һĬ�ϵ����ǿյ�,�Ͱ�Ĭ��Ԥ�賣������Ϊ�ļ���	*/
	if (strFileName.isEmpty())
	{
		strFileName = cDefaultFileName;
	}
	/**	��һ������Ҳ���Կ���������clear �������Ϊ���ȽϺ�	*/
	QString  strDownDir = QDir::cleanPath(m_downDirLineEdit->text().trimmed());

	bool bUseDir = !strDownDir.isEmpty() && QFileInfo(strDownDir).isDir();

	if (bUseDir)
	{
		/**	�������û��ʹ�õĽӿ�,��append�෴ ����֪��URL��ʲô��,�����϶���	*/
		strFileName.prepend(strDownDir + "/");
	}

	if (QFile::exists(strFileName))
	{
		/*if (QMessageBox::question(this,QString::fromLocal8Bit("�����Դ洢�ļ�")
			,QString::fromLocal8Bit("%1 ����ļ��Ѿ�����" "�Ƿ񸲸�").arg(strFileName)
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
		,QString::fromLocal8Bit("SSL ����")
		,QString::fromLocal8Bit("һ������SSL������:\n%1").arg(strError)
		,QMessageBox::Ignore|QMessageBox::Abort))== QMessageBox::Ignore)
	{
		m_networkReply->ignoreSslErrors();
	}

}


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
