# Qt 官方Demo学习: 1 addressBook

## 一,根据构建工程的顺序来阅读官方代码

### 1,列表初始化是不是能使用重载的父类构造函数?

```
MainWindow::MainWindow()
    : QMainWindow(),
      addressWidget(new AddressWidget)
{
    setCentralWidget(addressWidget);
    createMenus();
    setWindowTitle(tr("Address Book"));
}
```

首先到主窗口MainWindow的构造函数,这里就有点点意思MainWindow::MainWindow()后面""":,这是列表初始化.但是有个QMainWindow( ),刚开始没有看到Q,其实这是**官方命名的一个小坑**,平时我们自己命名不会这样.然而这QMainWindow( )其实是可以忽略的,平时我们自己也不会去写这玩意,除非**你想调用父类的重载的构造函数**.后面的addressWidget(new AddressWidget)基本上就很清晰了,只是我们一般不会在这里实例化对象,而且这里没有指定父对象,让我很诧异

### 2,为什么没有指定父对象?

刚开始看到这一段代码的时候,有点不解

```
addressWidget(new AddressWidget)
```

这里并没有指定父对象,但是

```
AddressWidget::AddressWidget(QWidget *parent)
    : QTabWidget(parent),
      table(new TableModel(this)),
      newAddressTab(new NewAddressTab(this))
{
    connect(newAddressTab, &NewAddressTab::sendDetails,
        this, &AddressWidget::addEntry);

    addTab(newAddressTab, tr("Address Book"));

    setupTabs();
}
```

他的构造函数里面吧他的子对象指定为了自己,后来查阅源码才知道

```
setCentralWidget(addressWidget);
```

这一步另有玄机,你可以把他看成

```
this->setCentralWidget(addressWidget);
```

其实是这样的

```
*!
    Sets the given \a widget to be the main window's central widget.

    Note: QMainWindow takes ownership of the \a widget pointer and
    deletes it at the appropriate time.

    \sa centralWidget()
*/
void QMainWindow::setCentralWidget(QWidget *widget)
{
    Q_D(QMainWindow);
    if (d->layout->centralWidget() && d->layout->centralWidget() != widget) {
        d->layout->centralWidget()->hide();
        d->layout->centralWidget()->deleteLater();
    }
    d->layout->setCentralWidget(widget);
}
```

这是**Qt中的源码**,英文已经很明白了,就是**这一步指定了父对象**

### 3,tr()是什么?

tr()这在之前做进阶培训的时候已经见过很多次了,这次bing了一下.

 用**tr包住英文** (源码英文，然后提供英文到其他语言的翻译包,**最最推荐的用法**)

**题外话:** 看源码很容易ctrl+左键进入到很深入的地方,不要迷失了方向



### 4,QModelIndex()是什么

QModelIndex有三个要素：**行row 列column 父节点索引parent**
但是注意我们并不能定义一个QModelIndex
QModelIndex的构造函数QModelIndex()的功能是创建一个新的空的QModelIndex

QModelIdex()是一个空索引，它其实可以代表任意model中的顶层节点，例如TableModel中每个Item的父节点都是顶层节点，所以每个Item的索引中的parent都是QModelIndex;【1】

可以获得QModelIndex 的方法有两种：
1.通过Model中的成员函数index()取得，详见下【2】
2.通过和Model绑定的View的成员函数取得，详见下【3】

举例：
class TabelModel : pulic QAbstractTableModel
auto table = new TableModel();
auto tableView = new QTableView();

tableView.setModel(table);
QModelIndex index1 = tableView.currentIndex ();//【3】
//QModelIndex Model::index(int row, int column, QModelIndex parent)
QModelIndex index2 = tabel.index(0,0,QModelIndex());//【2】【1】



## 二,**根据官方的Help来学习**