#include "QtDemo_addressBook.h"

QtDemo_addressBook::QtDemo_addressBook(QWidget *parent)
    : QMainWindow(), m_addressWidget(new QtDemo_addressWidget)
{
	/**	这里Demo里面没有设置窗口尺寸	*/
	this->setFixedSize(600, 400);
	this->setCentralWidget(m_addressWidget);
	createMenus();

}

void QtDemo_addressBook::createMenus()
{
	QMenu* fileMenu = menuBar()->addMenu(QString("文件"));
	
	QAction* openAct = new QAction(tr("&打开"), this);
	fileMenu->addAction(openAct);
	connect(openAct, &QAction::triggered, this, &QtDemo_addressBook::on_btn_open_file);

	QAction* saveAct = new QAction(QString("&保存"));
	fileMenu->addAction(saveAct);
	connect(saveAct, &QAction::triggered, this, &QtDemo_addressBook::on_btn_save_file);
	
	/**	这里是加上了一颗分割点	*/
	fileMenu->addSeparator();

	QAction* exitAct = new QAction(QString("退出"), this);
	fileMenu->addAction(exitAct);
	connect(exitAct, &QAction::triggered, this, &QWidget::close);

	QMenu* toolMenu = menuBar()->addMenu(QString("工具"));

	QAction* addAct = new QAction(QString("增加联系人"),this);
	toolMenu->addAction(addAct);
	connect(addAct, &QAction::triggered, m_addressWidget, &QtDemo_addressWidget::on_dialog_add_entry);

	/**	这边这个按钮是全局变量,可能是别的地方要用到吧	*/
	editAct = new QAction(QString("编辑联系人"), this);
	editAct->setEnabled(false);
	toolMenu->addAction(editAct);
	connect(editAct, &QAction::triggered, m_addressWidget, &QtDemo_addressWidget::on_dialog_edit_entry);
	
	toolMenu->addSeparator();

	removeAct = new QAction(QString("移除联系人"), this);
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
