#include "transactiondialog.h"
#include "ui_transactiondialog.h"

TransactionDialog::TransactionDialog(
        Account* acc,
        QList<Account*>* accs,
        QList<Category*>* cats,
        ConnectionManager* manager,
        QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TransactionDialog)
{
    ui->setupUi(this);

    WRONGCOLOR = "#FF3D64";

    account = acc;
    accounts = accs;
    categories = cats;
    this->manager = manager;

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
    if (addTransaction())
    {
        emit refreshTray();
    }
}

void TransactionDialog::AddTransactionAndClose()
{
    if (addTransaction())
    {
        emit refreshTray();
        this->close();
    }
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
            control->addItem(cur->getShortName(), cur->getId());
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

void TransactionDialog::addOutcome()
{
    int accountId = ui->comboBoxAccountFrom->itemData(ui->comboBoxAccountFrom->currentIndex()).toInt();
    int curencyId = ui->comboBoxCurencyFrom->itemData(ui->comboBoxCurencyFrom->currentIndex()).toInt();
    int categoryId = ui->comboBoxCategory->itemData(ui->comboBoxCategory->currentIndex()).toInt();

    float total = ui->lineEditTotalFrom->text().toFloat();

    QString date = ui->dateEdit->date().toString("MM.dd.yyyy");
    QString description = ui->lineEditDescription->text();

    manager->AddOutcomeOrIncome(
                -1,
                accountId,
                total,
                curencyId,
                categoryId,
                date,
                description);
}

void TransactionDialog::addIncome()
{
    int accountId = ui->comboBoxAccountTo->itemData(ui->comboBoxAccountTo->currentIndex()).toInt();
    int curencyId = ui->comboBoxCurencyTo->itemData(ui->comboBoxCurencyTo->currentIndex()).toInt();
    int categoryId = ui->comboBoxCategory->itemData(ui->comboBoxCategory->currentIndex()).toInt();

    float total = ui->lineEditTotalTo->text().toFloat();

    QString date = ui->dateEdit->date().toString("MM.dd.yyyy");
    QString description = ui->lineEditDescription->text();

    manager->AddOutcomeOrIncome(
                1,
                accountId,
                total,
                curencyId,
                categoryId,
                date,
                description);
}

void TransactionDialog::addExchange()
{
    int accountIdFrom = ui->comboBoxAccountFrom->itemData(ui->comboBoxAccountFrom->currentIndex()).toInt();
    int curencyIdFrom = ui->comboBoxCurencyFrom->itemData(ui->comboBoxCurencyFrom->currentIndex()).toInt();
    int accountIdTo = ui->comboBoxAccountTo->itemData(ui->comboBoxAccountTo->currentIndex()).toInt();
    int curencyITo = ui->comboBoxCurencyTo->itemData(ui->comboBoxCurencyTo->currentIndex()).toInt();

    float totalFrom = ui->lineEditTotalFrom->text().toFloat();

    float totalTo;
    if (ui->lineEditTotalTo->text().isEmpty())
    {
        totalTo = totalFrom;
    }
    else
    {
        totalTo = ui->lineEditTotalTo->text().toFloat();
    }


    QString date = ui->dateEdit->date().toString("MM.dd.yyyy");
    QString description = ui->lineEditDescription->text();

    manager->AddExchange(
                accountIdFrom,
                totalFrom,
                curencyIdFrom,
                accountIdTo,
                totalTo,
                curencyITo,
                date,
                description);
}

bool TransactionDialog::addTransaction()
{
    if (ui->pushButtonOutcome->isChecked())
    {
        if (ui->lineEditTotalFrom->text().isEmpty())
        {
            ui->lineEditTotalFrom->setStyleSheet("background:" + WRONGCOLOR);
            return false;
        }
        else
        {
            ui->lineEditTotalFrom->setStyleSheet("background: white;");
            addOutcome();
            ui->lineEditTotalFrom->setText("");
            ui->lineEditDescription->setText("");
            return true;
        }
    }

    if (ui->pushButtonIncome->isChecked())
    {
        if (ui->lineEditTotalTo->text().isEmpty())
        {
            ui->lineEditTotalTo->setStyleSheet("background:" + WRONGCOLOR);
            return false;
        }
        else
        {
            ui->lineEditTotalTo->setStyleSheet("background: white;");
            addIncome();
            ui->lineEditTotalTo->setText("");
            ui->lineEditDescription->setText("");
            return true;
        }
    }

    if (ui->pushButtonExchange->isChecked())
    {
        if (ui->lineEditTotalFrom->text().isEmpty())
        {
            ui->lineEditTotalFrom->setStyleSheet("background:" + WRONGCOLOR);
            return false;
        }
        else
        {
            addExchange();
            ui->lineEditTotalFrom->setStyleSheet("background: white;");
            ui->lineEditTotalTo->setStyleSheet("background: white;");
            ui->lineEditTotalTo->setText("");
            ui->lineEditTotalFrom->setText("");
            ui->lineEditDescription->setText("");
            return true;
        }
    }

    return false;
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

