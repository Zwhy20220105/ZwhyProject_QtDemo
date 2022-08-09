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
	/**	感觉这种初始化的跳跃性大,但是也是不错的选择,嗯,以后就这样了*/
	QFile file(fileName);
	/**	很喜欢这种既可以当作debug用的工具(log),又可以进行语句执行的if判断	*/
	/**	等待造轮子(log)	*/
	if (!file.open(QIODevice::ReadOnly))
	{
		/**	虽然暂时不知道这里怎么触发文件打不开,但是这种只要调用静态函数就可以触发,不用对象接受相应内容,虽然好像是废话	*/
		QMessageBox::information(this, tr("unable to open file"), file.errorString());
		return;
	}

	


}
