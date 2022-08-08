/********************************************************************************
** Form generated from reading UI file 'QtDemo_addressBook.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDEMO_ADDRESSBOOK_H
#define UI_QTDEMO_ADDRESSBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtDemo_addressBookClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtDemo_addressBookClass)
    {
        if (QtDemo_addressBookClass->objectName().isEmpty())
            QtDemo_addressBookClass->setObjectName(QString::fromUtf8("QtDemo_addressBookClass"));
        QtDemo_addressBookClass->resize(600, 400);
        menuBar = new QMenuBar(QtDemo_addressBookClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtDemo_addressBookClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtDemo_addressBookClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtDemo_addressBookClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtDemo_addressBookClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtDemo_addressBookClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtDemo_addressBookClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtDemo_addressBookClass->setStatusBar(statusBar);

        retranslateUi(QtDemo_addressBookClass);

        QMetaObject::connectSlotsByName(QtDemo_addressBookClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtDemo_addressBookClass)
    {
        QtDemo_addressBookClass->setWindowTitle(QCoreApplication::translate("QtDemo_addressBookClass", "QtDemo_addressBook", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtDemo_addressBookClass: public Ui_QtDemo_addressBookClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDEMO_ADDRESSBOOK_H
