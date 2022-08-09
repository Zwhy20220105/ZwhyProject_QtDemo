#include "QtDemo_addressWidget.h"
#include "ui_QtDemo_addressWidget.h"

QtDemo_addressWidget::QtDemo_addressWidget(QWidget *parent)
	: QTabWidget(parent)
{
	ui = new Ui::QtDemo_addressWidget();
	ui->setupUi(this);
}

QtDemo_addressWidget::~QtDemo_addressWidget()
{
	delete ui;
}

void QtDemo_addressWidget::readFromFile(const QString& fileName)
{
	/**	�о����ֳ�ʼ������Ծ�Դ�,����Ҳ�ǲ����ѡ��,��,�Ժ��������*/
	QFile file(fileName);
	/**	��ϲ�����ּȿ��Ե���debug�õĹ���(log),�ֿ��Խ������ִ�е�if�ж�	*/
	/**	�ȴ�������(log)	*/
	if (!file.open(QIODevice::ReadOnly))
	{
		/**	��Ȼ��ʱ��֪��������ô�����ļ��򲻿�,��������ֻҪ���þ�̬�����Ϳ��Դ���,���ö��������Ӧ����,��Ȼ�����Ƿϻ�	*/
		QMessageBox::information(this, tr("unable to open file"), file.errorString());
		return;
	}

	


}
