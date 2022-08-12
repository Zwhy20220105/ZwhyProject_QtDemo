#include "QtDemo_addressBook.h"

QtDemo_addressBook::QtDemo_addressBook(QWidget *parent)
    : QMainWindow(), m_addressWidget(new QtDemo_addressWidget)
{
	this->setFixedSize(800, 600);
	this->setCentralWidget(m_addressWidget);
	createMenus();

}

void QtDemo_addressBook::createMenus()
{
	QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
	QAction* openAct = new QAction(tr("&Open..."), this);
	fileMenu->addAction(openAct);
	connect(openAct, &QAction::triggered, this, &QtDemo_addressBook::on_btn_open_file);
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
