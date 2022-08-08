/********************************************************************************
** Form generated from reading UI file 'QtDemo_addressWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDEMO_ADDRESSWIDGET_H
#define UI_QTDEMO_ADDRESSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTabWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDemo_addressWidget
{
public:

    void setupUi(QTabWidget *QtDemo_addressWidget)
    {
        if (QtDemo_addressWidget->objectName().isEmpty())
            QtDemo_addressWidget->setObjectName(QString::fromUtf8("QtDemo_addressWidget"));
        QtDemo_addressWidget->resize(400, 300);

        retranslateUi(QtDemo_addressWidget);

        QMetaObject::connectSlotsByName(QtDemo_addressWidget);
    } // setupUi

    void retranslateUi(QTabWidget *QtDemo_addressWidget)
    {
        QtDemo_addressWidget->setWindowTitle(QCoreApplication::translate("QtDemo_addressWidget", "QtDemo_addressWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtDemo_addressWidget: public Ui_QtDemo_addressWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDEMO_ADDRESSWIDGET_H
