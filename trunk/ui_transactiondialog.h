/********************************************************************************
** Form generated from reading UI file 'transactiondialog.ui'
**
** Created: Sun Mar 18 01:43:48 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONDIALOG_H
#define UI_TRANSACTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TransactionDialog
{
public:
    QComboBox *comboBoxAccount;
    QLineEdit *lineEditTotal;
    QComboBox *comboBoxCategory;
    QLineEdit *lineEditDescription;
    QLineEdit *lineEditDate;
    QCheckBox *checkBoxIsPlan;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonCancel;
    QComboBox *comboBoxCurency;

    void setupUi(QDialog *TransactionDialog)
    {
        if (TransactionDialog->objectName().isEmpty())
            TransactionDialog->setObjectName(QString::fromUtf8("TransactionDialog"));
        TransactionDialog->resize(458, 393);
        comboBoxAccount = new QComboBox(TransactionDialog);
        comboBoxAccount->setObjectName(QString::fromUtf8("comboBoxAccount"));
        comboBoxAccount->setGeometry(QRect(20, 10, 231, 27));
        lineEditTotal = new QLineEdit(TransactionDialog);
        lineEditTotal->setObjectName(QString::fromUtf8("lineEditTotal"));
        lineEditTotal->setGeometry(QRect(330, 10, 113, 27));
        comboBoxCategory = new QComboBox(TransactionDialog);
        comboBoxCategory->setObjectName(QString::fromUtf8("comboBoxCategory"));
        comboBoxCategory->setGeometry(QRect(20, 50, 301, 27));
        lineEditDescription = new QLineEdit(TransactionDialog);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));
        lineEditDescription->setGeometry(QRect(20, 90, 301, 27));
        lineEditDate = new QLineEdit(TransactionDialog);
        lineEditDate->setObjectName(QString::fromUtf8("lineEditDate"));
        lineEditDate->setGeometry(QRect(330, 50, 113, 27));
        checkBoxIsPlan = new QCheckBox(TransactionDialog);
        checkBoxIsPlan->setObjectName(QString::fromUtf8("checkBoxIsPlan"));
        checkBoxIsPlan->setGeometry(QRect(330, 90, 97, 22));
        pushButtonAdd = new QPushButton(TransactionDialog);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(20, 140, 141, 27));
        pushButtonCancel = new QPushButton(TransactionDialog);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(190, 140, 131, 27));
        comboBoxCurency = new QComboBox(TransactionDialog);
        comboBoxCurency->setObjectName(QString::fromUtf8("comboBoxCurency"));
        comboBoxCurency->setGeometry(QRect(260, 10, 61, 27));

        retranslateUi(TransactionDialog);

        QMetaObject::connectSlotsByName(TransactionDialog);
    } // setupUi

    void retranslateUi(QDialog *TransactionDialog)
    {
        TransactionDialog->setWindowTitle(QApplication::translate("TransactionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        checkBoxIsPlan->setText(QApplication::translate("TransactionDialog", "CheckBox", 0, QApplication::UnicodeUTF8));
        pushButtonAdd->setText(QApplication::translate("TransactionDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("TransactionDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TransactionDialog: public Ui_TransactionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONDIALOG_H
