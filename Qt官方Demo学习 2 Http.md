# Qt官方Demo学习 2 Http

## 1,explicit关键字

Effective C++中也写:

> 被声明为`explicit`的构造函数通常比其 non-explicit 兄弟更受欢迎, 因为它们禁止编译器执行非预期 (往往也不被期望) 的类型转换. 除非我有一个好理由允许构造函数被用于隐式类型转换, 否则我会把它声明为`explicit`. 我鼓励你遵循相同的政策.

这里也就是说,如果你想要构造函数不被隐式调用就再声明构造函数的时候,加上==explicit== 关键字

## 2.一种设计模式 (if中)

令人熟知的设计模式,就是那23之一,但是我觉得令人眼前一亮的算法或者方法也能叫设计模式

```
if (authenticationDalog.exec()==QDialog::Accepted)
	{
		authenticator->setUser(ui.userLineEdit->text());
		authenticator->setPassword(ui.passwordLineEdit->text());
	}
```

​	if语句的( )的里面,作为执行语句的做法,大家都看过很多次了,其实这是也是

​	但是这里是变体:authenticationDalog.exec()这句是执行语句,authenticationDalog.exec()==QDialog::Accepted这一整句是会返回true和false的

​	如果是用户点确定的时候,就可以退出/进入这个if语句

​	但是这个确定,不是自带啊,很迷茫了



