/********************************************************************************
** Form generated from reading UI file 'QtDemo_tableModel.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDEMO_TABLEMODEL_H
#define UI_QTDEMO_TABLEMODEL_H

#include <QtCore/QAbstractTableModel>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>

QT_BEGIN_NAMESPACE

class Ui_QtDemo_tableModelClass
{
public:

    void setupUi(QAbstractTableModel *QtDemo_tableModelClass)
    {
        if (QtDemo_tableModelClass->objectName().isEmpty())
            QtDemo_tableModelClass->setObjectName(QString::fromUtf8("QtDemo_tableModelClass"));
        QtDemo_tableModelClass->resize(600, 400);

        retranslateUi(QtDemo_tableModelClass);

        QMetaObject::connectSlotsByName(QtDemo_tableModelClass);
    } // setupUi

    void retranslateUi(QAbstractTableModel *QtDemo_tableModelClass)
    {
        QtDemo_tableModelClass->setWindowTitle(QCoreApplication::translate("QtDemo_tableModelClass", "QtDemo_tableModel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtDemo_tableModelClass: public Ui_QtDemo_tableModelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDEMO_TABLEMODEL_H
