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
	/**	这是调用了一个静态函数	*/
	/**	这里很神奇的就是Z:\Zwhy2022\Desktop进不去桌面,但是Z:\Zwhy2022//Desktop是可以进去的	*/
	QString fileName = QFileDialog::getOpenFileName(this,QString("请选择要打开的文件"), "Z://Zwhy2022//Desktop");
	/**	 If the user presses Cancel, it returns a null string.	*/
	if (!fileName.isEmpty())
	{
		/**	这里就体现了程序的严谨性,可以的	*/
		m_addressWidget->readFromFile(fileName);
	}



}
