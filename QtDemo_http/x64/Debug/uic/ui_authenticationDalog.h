/********************************************************************************
** Form generated from reading UI file 'authenticationDalog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICATIONDALOG_H
#define UI_AUTHENTICATIONDALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QLabel *showLabel;
    QLabel *siteLable;
    QLabel *userLabel;
    QLineEdit *userLineEdit;
    QLabel *passwordLable;
    QLineEdit *passwordLineEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;
    QLabel *siteDescription;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(477, 320);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        showLabel = new QLabel(Dialog);
        showLabel->setObjectName(QString::fromUtf8("showLabel"));

        gridLayout->addWidget(showLabel, 0, 0, 1, 3);

        siteLable = new QLabel(Dialog);
        siteLable->setObjectName(QString::fromUtf8("siteLable"));

        gridLayout->addWidget(siteLable, 1, 0, 1, 1);

        userLabel = new QLabel(Dialog);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));

        gridLayout->addWidget(userLabel, 2, 0, 1, 1);

        userLineEdit = new QLineEdit(Dialog);
        userLineEdit->setObjectName(QString::fromUtf8("userLineEdit"));

        gridLayout->addWidget(userLineEdit, 2, 1, 1, 2);

        passwordLable = new QLabel(Dialog);
        passwordLable->setObjectName(QString::fromUtf8("passwordLable"));

        gridLayout->addWidget(passwordLable, 3, 0, 1, 1);

        passwordLineEdit = new QLineEdit(Dialog);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        gridLayout->addWidget(passwordLineEdit, 3, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 154, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 2, 1, 1);

        siteDescription = new QLabel(Dialog);
        siteDescription->setObjectName(QString::fromUtf8("siteDescription"));

        gridLayout->addWidget(siteDescription, 1, 1, 1, 2);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        showLabel->setText(QCoreApplication::translate("Dialog", "         \344\275\240\351\234\200\350\246\201\346\217\220\344\276\233\345\257\206\347\240\201\345\222\214\350\264\246\345\217\267\346\211\215\350\203\275\350\277\233\345\205\245\346\255\244\347\253\231\347\202\271", nullptr));
        siteLable->setText(QCoreApplication::translate("Dialog", "site", nullptr));
        userLabel->setText(QCoreApplication::translate("Dialog", "\347\224\250\346\210\267\345\220\215:", nullptr));
        passwordLable->setText(QCoreApplication::translate("Dialog", "\345\257\206\347\240\201:", nullptr));
        siteDescription->setText(QCoreApplication::translate("Dialog", " %1 at %2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICATIONDALOG_H
