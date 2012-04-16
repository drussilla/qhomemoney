#ifndef TRANSACTIONDIALOG_H
#define TRANSACTIONDIALOG_H

#include <QDialog>
#include "account.h"
#include "category.h"
#include <QDateTime>
#include <QButtonGroup>
#include <QComboBox>
#include "connectionmanager.h"
#include "mainwindow.h"

namespace Ui {
class TransactionDialog;
}

class TransactionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TransactionDialog(
            Account* acc,
            QList<Account*>* accs,
            QList<Category*>* cats,
            ConnectionManager *manager,
            QWidget *parent = 0);
    ~TransactionDialog();

signals:
    void refreshTray();

public slots:
    void AddTransaction();
    void AddTransactionAndClose();
    
private:
    Ui::TransactionDialog *ui;
    Account *account;
    QList<Account*>* accounts;
    QButtonGroup* buttonGroup;
    QList<Category*>* categories;
    ConnectionManager *manager;

    void setInitState();
    void fillAccounts();
    void setAllInvisible();
    void changeCurrency(QComboBox *control, int index);
    void changeCategory(int factor);
    void addOutcome();
    void addIncome();
    void addExchange();

    bool addTransaction();

    QString WRONGCOLOR;

private slots:
    void outcomeChecked(bool);
    void incomeChecked(bool);
    void exchangeChecked(bool);
    void fromChanged(int);
    void toChanged(int);
};

#endif // TRANSACTIONDIALOG_H
