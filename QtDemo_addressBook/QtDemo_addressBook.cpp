#include "QtDemo_addressBook.h"

QtDemo_addressBook::QtDemo_addressBook(QWidget *parent)
    : QMainWindow(), m_addressWidget(new QtDemo_addressWidget)
{
	//this->setFixedSize(800, 600);
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
