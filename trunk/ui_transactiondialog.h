/********************************************************************************
** Form generated from reading UI file 'transactiondialog.ui'
**
** Created: Mon 16. Apr 00:52:52 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONDIALOG_H
#define UI_TRANSACTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TransactionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonOutcome;
    QPushButton *pushButtonExchange;
    QPushButton *pushButtonIncome;
    QDateEdit *dateEdit;
    QGroupBox *groupBoxFrom;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBoxAccountFrom;
    QComboBox *comboBoxCurencyFrom;
    QLineEdit *lineEditTotalFrom;
    QGroupBox *groupBoxTo;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBoxAccountTo;
    QComboBox *comboBoxCurencyTo;
    QLineEdit *lineEditTotalTo;
    QGroupBox *groupBoxCategory;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *comboBoxCategory;
    QGroupBox *groupBoxDescription;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *lineEditDescription;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonAddClose;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonCancel;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *TransactionDialog)
    {
        if (TransactionDialog->objectName().isEmpty())
            TransactionDialog->setObjectName(QString::fromUtf8("TransactionDialog"));
        TransactionDialog->resize(458, 316);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TransactionDialog->sizePolicy().hasHeightForWidth());
        TransactionDialog->setSizePolicy(sizePolicy);
        TransactionDialog->setMaximumSize(QSize(16777215, 316));
        verticalLayout = new QVBoxLayout(TransactionDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButtonOutcome = new QPushButton(TransactionDialog);
        pushButtonOutcome->setObjectName(QString::fromUtf8("pushButtonOutcome"));
        pushButtonOutcome->setIconSize(QSize(32, 32));
        pushButtonOutcome->setCheckable(true);
        pushButtonOutcome->setChecked(false);

        horizontalLayout->addWidget(pushButtonOutcome);

        pushButtonExchange = new QPushButton(TransactionDialog);
        pushButtonExchange->setObjectName(QString::fromUtf8("pushButtonExchange"));
        pushButtonExchange->setCheckable(true);

        horizontalLayout->addWidget(pushButtonExchange);

        pushButtonIncome = new QPushButton(TransactionDialog);
        pushButtonIncome->setObjectName(QString::fromUtf8("pushButtonIncome"));
        pushButtonIncome->setCheckable(true);

        horizontalLayout->addWidget(pushButtonIncome);

        dateEdit = new QDateEdit(TransactionDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);
        dateEdit->setCurrentSectionIndex(0);

        horizontalLayout->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout);

        groupBoxFrom = new QGroupBox(TransactionDialog);
        groupBoxFrom->setObjectName(QString::fromUtf8("groupBoxFrom"));
        sizePolicy.setHeightForWidth(groupBoxFrom->sizePolicy().hasHeightForWidth());
        groupBoxFrom->setSizePolicy(sizePolicy);
        horizontalLayout_5 = new QHBoxLayout(groupBoxFrom);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        comboBoxAccountFrom = new QComboBox(groupBoxFrom);
        comboBoxAccountFrom->setObjectName(QString::fromUtf8("comboBoxAccountFrom"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxAccountFrom->sizePolicy().hasHeightForWidth());
        comboBoxAccountFrom->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(comboBoxAccountFrom);

        comboBoxCurencyFrom = new QComboBox(groupBoxFrom);
        comboBoxCurencyFrom->setObjectName(QString::fromUtf8("comboBoxCurencyFrom"));
        comboBoxCurencyFrom->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_5->addWidget(comboBoxCurencyFrom);

        lineEditTotalFrom = new QLineEdit(groupBoxFrom);
        lineEditTotalFrom->setObjectName(QString::fromUtf8("lineEditTotalFrom"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditTotalFrom->sizePolicy().hasHeightForWidth());
        lineEditTotalFrom->setSizePolicy(sizePolicy2);
        lineEditTotalFrom->setMaximumSize(QSize(100, 16777215));
        lineEditTotalFrom->setBaseSize(QSize(0, 0));

        horizontalLayout_5->addWidget(lineEditTotalFrom);


        verticalLayout->addWidget(groupBoxFrom);

        groupBoxTo = new QGroupBox(TransactionDialog);
        groupBoxTo->setObjectName(QString::fromUtf8("groupBoxTo"));
        horizontalLayout_2 = new QHBoxLayout(groupBoxTo);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        comboBoxAccountTo = new QComboBox(groupBoxTo);
        comboBoxAccountTo->setObjectName(QString::fromUtf8("comboBoxAccountTo"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBoxAccountTo->sizePolicy().hasHeightForWidth());
        comboBoxAccountTo->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(comboBoxAccountTo);

        comboBoxCurencyTo = new QComboBox(groupBoxTo);
        comboBoxCurencyTo->setObjectName(QString::fromUtf8("comboBoxCurencyTo"));
        comboBoxCurencyTo->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(comboBoxCurencyTo);

        lineEditTotalTo = new QLineEdit(groupBoxTo);
        lineEditTotalTo->setObjectName(QString::fromUtf8("lineEditTotalTo"));
        lineEditTotalTo->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_2->addWidget(lineEditTotalTo);


        verticalLayout->addWidget(groupBoxTo);

        groupBoxCategory = new QGroupBox(TransactionDialog);
        groupBoxCategory->setObjectName(QString::fromUtf8("groupBoxCategory"));
        horizontalLayout_4 = new QHBoxLayout(groupBoxCategory);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        comboBoxCategory = new QComboBox(groupBoxCategory);
        comboBoxCategory->setObjectName(QString::fromUtf8("comboBoxCategory"));

        horizontalLayout_4->addWidget(comboBoxCategory);


        verticalLayout->addWidget(groupBoxCategory);

        groupBoxDescription = new QGroupBox(TransactionDialog);
        groupBoxDescription->setObjectName(QString::fromUtf8("groupBoxDescription"));
        horizontalLayout_6 = new QHBoxLayout(groupBoxDescription);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        lineEditDescription = new QLineEdit(groupBoxDescription);
        lineEditDescription->setObjectName(QString::fromUtf8("lineEditDescription"));

        horizontalLayout_6->addWidget(lineEditDescription);


        verticalLayout->addWidget(groupBoxDescription);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButtonAddClose = new QPushButton(TransactionDialog);
        pushButtonAddClose->setObjectName(QString::fromUtf8("pushButtonAddClose"));

        horizontalLayout_3->addWidget(pushButtonAddClose);

        pushButtonAdd = new QPushButton(TransactionDialog);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        horizontalLayout_3->addWidget(pushButtonAdd);

        pushButtonCancel = new QPushButton(TransactionDialog);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(pushButtonCancel->sizePolicy().hasHeightForWidth());
        pushButtonCancel->setSizePolicy(sizePolicy4);

        horizontalLayout_3->addWidget(pushButtonCancel);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(TransactionDialog);

        QMetaObject::connectSlotsByName(TransactionDialog);
    } // setupUi

    void retranslateUi(QDialog *TransactionDialog)
    {
        TransactionDialog->setWindowTitle(QApplication::translate("TransactionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        pushButtonOutcome->setText(QApplication::translate("TransactionDialog", "\320\240\320\260\321\201\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        pushButtonExchange->setText(QApplication::translate("TransactionDialog", "\320\237\320\265\321\200\320\265\320\262\320\276\320\264", 0, QApplication::UnicodeUTF8));
        pushButtonIncome->setText(QApplication::translate("TransactionDialog", "\320\224\320\276\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        groupBoxFrom->setTitle(QApplication::translate("TransactionDialog", "\320\241\320\276 \321\201\321\207\320\265\321\202\320\260: ", 0, QApplication::UnicodeUTF8));
        groupBoxTo->setTitle(QApplication::translate("TransactionDialog", "\320\235\320\260 \321\201\321\207\320\265\321\202:", 0, QApplication::UnicodeUTF8));
        groupBoxCategory->setTitle(QApplication::translate("TransactionDialog", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217:", 0, QApplication::UnicodeUTF8));
        groupBoxDescription->setTitle(QApplication::translate("TransactionDialog", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265:", 0, QApplication::UnicodeUTF8));
        pushButtonAddClose->setText(QApplication::translate("TransactionDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270 \320\227\320\260\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonAdd->setText(QApplication::translate("TransactionDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonCancel->setText(QApplication::translate("TransactionDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TransactionDialog: public Ui_TransactionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONDIALOG_H
