#ifndef TRANSACTIONDIALOG_H
#define TRANSACTIONDIALOG_H

#include <QDialog>
#include "account.h"
#include "category.h"
#include <QDateTime>
#include <QButtonGroup>
#include <QComboBox>

namespace Ui {
class TransactionDialog;
}

class TransactionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TransactionDialog(Account* acc, QList<Account*>* accs, QList<Category*>* cats, QWidget *parent = 0);
    ~TransactionDialog();

public slots:
    void AddTransaction();
    void AccountChanged();
    void AddTransactionAndClose();
    
private:
    Ui::TransactionDialog *ui;
    Account *account;
    QList<Account*>* accounts;
    QButtonGroup* buttonGroup;
    QList<Category*>* categories;

    void setInitState();
    void fillAccounts();
    void setAllInvisible();
    void changeCurrency(QComboBox *control, int index);
    void changeCategory(int factor);

private slots:
    void outcomeChecked(bool);
    void incomeChecked(bool);
    void exchangeChecked(bool);
    void fromChanged(int);
    void toChanged(int);
};

#endif // TRANSACTIONDIALOG_H
