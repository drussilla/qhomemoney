#include "transactiondialog.h"
#include "ui_transactiondialog.h"

TransactionDialog::TransactionDialog(Account* acc,QList<Account*>* accs, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDialog)
{
    ui->setupUi(this);
    account = acc;
    accounts = accs;

    connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(AddTransaction()));

    setInitState();
    fillAccounts();
}

TransactionDialog::~TransactionDialog()
{
    delete ui;
}

void TransactionDialog::AddTransaction()
{

}

void TransactionDialog::AccountChanged()
{

}

void TransactionDialog::setInitState()
{

}

void TransactionDialog::fillAccounts()
{
    QList<Account*>::iterator i = accounts->begin();

    while (i != accounts->end())
    {
        Account *acc = (*i);

        if(acc->isDisplay())
        {

        }

        i++;
    }
}
