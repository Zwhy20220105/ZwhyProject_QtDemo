#include "QtDemo_addressBook.h"

QtDemo_addressBook::QtDemo_addressBook(QWidget *parent)
    : QMainWindow(), m_addressWidget(new QtDemo_addressWidget)
{
	/**	����Demo����û�����ô��ڳߴ�	*/
	this->setFixedSize(600, 400);
	this->setCentralWidget(m_addressWidget);
	createMenus();

}

void QtDemo_addressBook::createMenus()
{
	QMenu* fileMenu = menuBar()->addMenu(QString("�ļ�"));
	
	QAction* openAct = new QAction(tr("&��"), this);
	fileMenu->addAction(openAct);
	connect(openAct, &QAction::triggered, this, &QtDemo_addressBook::on_btn_open_file);

	QAction* saveAct = new QAction(QString("&����"));
	fileMenu->addAction(saveAct);
	connect(saveAct, &QAction::triggered, this, &QtDemo_addressBook::on_btn_save_file);
	
	/**	�����Ǽ�����һ�ŷָ��	*/
	fileMenu->addSeparator();

	QAction* exitAct = new QAction(QString("�˳�"), this);
	fileMenu->addAction(exitAct);
	connect(exitAct, &QAction::triggered, this, &QWidget::close);

	QMenu* toolMenu = menuBar()->addMenu(QString("����"));

	QAction* addAct = new QAction(QString("������ϵ��"),this);
	toolMenu->addAction(addAct);
	connect(addAct, &QAction::triggered, m_addressWidget, &QtDemo_addressWidget::on_dialog_add_entry);

	/**	��������ť��ȫ�ֱ���,�����Ǳ�ĵط�Ҫ�õ���	*/
	editAct = new QAction(QString("�༭��ϵ��"), this);
	editAct->setEnabled(false);
	toolMenu->addAction(editAct);
	connect(editAct, &QAction::triggered, m_addressWidget, &QtDemo_addressWidget::on_dialog_edit_entry);
	
	toolMenu->addSeparator();

	removeAct = new QAction(QString("�Ƴ���ϵ��"), this);
	removeAct->setEnabled(false);
	toolMenu->addAction(removeAct);	
	//connect(removeAct,&QAction::triggered,m_addressWidget,&QtDemo_addressWidget::)


}

void QtDemo_addressBook::on_btn_save_file()
{
	QString strFileName = QFileDialog::getSaveFileName();
	if (!strFileName.isEmpty())
	{
		m_addressWidget->writeToFile(strFileName);
	}
}

void QtDemo_addressBook::on_btn_open_file()
{
	/**	���ǵ�����һ����̬����	*/
	/**	���������ľ���Z:\Zwhy2022\Desktop����ȥ����,����Z:\Zwhy2022//Desktop�ǿ��Խ�ȥ��	*/
	QString fileName = QFileDialog::getOpenFileName(this,QString("��ѡ��Ҫ�򿪵��ļ�"), "Z://Zwhy2022//Desktop");
	/**	 If the user presses Cancel, it returns a null string.	*/
	if (!fileName.isEmpty())
	{
		/**	����������˳�����Ͻ���,���Ե�	*/
		m_addressWidget->readFromFile(fileName);
	}
}
