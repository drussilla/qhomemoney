#include "transactiondialog.h"
#include "ui_transactiondialog.h"

TransactionDialog::TransactionDialog(Account* acc,QList<Account*>* accs, QList<Category*>* cats, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDialog)
{
    ui->setupUi(this);
    account = acc;
    accounts = accs;
    categories = cats;

    connect(ui->pushButtonCancel, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->pushButtonAdd, SIGNAL(clicked()), this, SLOT(AddTransaction()));
    connect(ui->pushButtonAddClose, SIGNAL(clicked()), this, SLOT(AddTransactionAndClose()));

    buttonGroup = new QButtonGroup();
    buttonGroup->addButton(ui->pushButtonOutcome);
    buttonGroup->addButton(ui->pushButtonExchange);
    buttonGroup->addButton(ui->pushButtonIncome);

    connect(ui->pushButtonOutcome, SIGNAL(toggled(bool)), this, SLOT(outcomeChecked(bool)));
    connect(ui->pushButtonIncome, SIGNAL(toggled(bool)), this, SLOT(incomeChecked(bool)));
    connect(ui->pushButtonExchange, SIGNAL(toggled(bool)), this, SLOT(exchangeChecked(bool)));

    connect(ui->comboBoxAccountFrom, SIGNAL(currentIndexChanged(int)), this, SLOT(fromChanged(int)));
    connect(ui->comboBoxAccountTo, SIGNAL(currentIndexChanged(int)), this, SLOT(toChanged(int)));

    fillAccounts();
    setInitState();

}

TransactionDialog::~TransactionDialog()
{
    delete ui;
    delete buttonGroup;
}

void TransactionDialog::AddTransaction()
{

}

void TransactionDialog::AccountChanged()
{

}

void TransactionDialog::AddTransactionAndClose()
{
    AddTransaction();
    this->close();
}

void TransactionDialog::setInitState()
{
    ui->dateEdit->setDate(QDate::currentDate());

    // resize hack
    ui->pushButtonOutcome->toggle();
    ui->pushButtonIncome->toggle();
    ui->pushButtonOutcome->toggle();
}

void TransactionDialog::fillAccounts()
{
    QList<Account*>::iterator i = accounts->begin();

    int currentIndex = 0;
    int j = 0;
    while (i != accounts->end())
    {
        Account *acc = (*i);

        if(acc->isDisplay())
        {
            ui->comboBoxAccountFrom->addItem(acc->getName(), acc->getId());
            ui->comboBoxAccountTo->addItem(acc->getName(), acc->getId());

            if (acc == account)
            {
                currentIndex = j;
            }
        }

        j++;
        i++;
    }

    ui->comboBoxAccountFrom->setCurrentIndex(currentIndex);
}

void TransactionDialog::setAllInvisible()
{
    ui->groupBoxFrom->setVisible(false);
    ui->groupBoxTo->setVisible(false);
    ui->groupBoxCategory->setVisible(false);
    ui->groupBoxDescription->setVisible(false);
}

void TransactionDialog::changeCurrency(QComboBox *control, int index)
{
    Account* acc = accounts->at(index);

    QList<Currency*>* currency = acc->getCurrencyList();

    control->clear();

    QList<Currency*>::iterator i = currency->begin();

    while(i != currency->end())
    {
        Currency *cur = (*i);
        if (cur->isDisplay())
        {
            control->addItem(cur->getShortName());
        }

        i++;
    }
}

void TransactionDialog::changeCategory(int factor)
{
    QList<Category*>::iterator i = categories->begin();

    ui->comboBoxCategory->clear();

    while (i != categories->end())
    {
        Category *cat = (*i);
        if (cat->getFactor() == factor)
        {
            ui->comboBoxCategory->addItem(cat->getName(), cat->getId());
        }

        i++;
    }
}

void TransactionDialog::outcomeChecked(bool state)
{
    if (!state)
    {
        return;
    }

    setAllInvisible();

    ui->groupBoxFrom->setVisible(true);
    ui->groupBoxCategory->setVisible(true);
    ui->groupBoxDescription->setVisible(true);

    this->resize(this->width(), this->height() - ui->groupBoxTo->height());

    changeCategory(-1);
}

void TransactionDialog::incomeChecked(bool state)
{
    if (!state)
    {
        return;
    }

    setAllInvisible();

    ui->groupBoxTo->setVisible(true);
    ui->groupBoxCategory->setVisible(true);
    ui->groupBoxDescription->setVisible(true);

    this->resize(this->width(), this->height() - ui->groupBoxFrom->height());

    changeCategory(1);
}

void TransactionDialog::exchangeChecked(bool state)
{
    if (!state)
    {
        return;
    }

    setAllInvisible();

    ui->groupBoxFrom->setVisible(true);
    ui->groupBoxTo->setVisible(true);
    ui->groupBoxDescription->setVisible(true);

    this->resize(this->width(), this->height() - ui->groupBoxCategory->height());
}

void TransactionDialog::fromChanged(int index)
{
    changeCurrency(ui->comboBoxCurencyFrom, index);
}

void TransactionDialog::toChanged(int index)
{
    changeCurrency(ui->comboBoxCurencyTo, index);
}

