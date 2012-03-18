#ifndef TRANSACTIONDIALOG_H
#define TRANSACTIONDIALOG_H

#include <QDialog>
#include "account.h"
#include <QDateTime>

namespace Ui {
class TransactionDialog;
}

class TransactionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TransactionDialog(Account* acc, QList<Account*>* accs, QWidget *parent = 0);
    ~TransactionDialog();

public slots:
    void AddTransaction();
    void AccountChanged();
    
private:
    Ui::TransactionDialog *ui;
    Account *account;
    QList<Account*>* accounts;

    void setInitState();
    void fillAccounts();
};

#endif // TRANSACTIONDIALOG_H
