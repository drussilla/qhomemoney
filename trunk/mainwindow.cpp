#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include "connectionmanager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    config = new ConfigManager();
    accountActions = new QList<CustomAction*>();

    connect(ui->pushButtonOk, SIGNAL(clicked()), this, SLOT(SaveSettings()));
    connect(ui->pushButtonCancel, SIGNAL(clicked()), this , SLOT(CancelSettings()));

    connect(ui->lineEditPassword, SIGNAL(returnPressed()), ui->pushButtonOk, SLOT(click()));

    ui->lineEditLogin->setText(config->getLogin());
    ui->errorLabel->hide();

    createDefaultSysTray();

    manager = new ConnectionManager(config->getLogin(), config->getPassword());

    RefreshTray();

}

void MainWindow::RefreshTray()
{
    if (manager->CheckConnection())
    {
        accounts = manager->GetAccountList(true);
        categories = manager->GetCategoryList(true);
        displayAccounts();
    }
    else
    {
        this->show();
        ui->errorLabel->setText(manager->GetLastError());
        ui->errorLabel->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete manager;
    delete accounts;
    //delete groups;
    delete config;
    delete accountActions;
}

void MainWindow::displayAccounts()
{
    deleteAccountsFromTray();

    QList<Account*>::iterator i = accounts->begin();
    int position = 0;
    while (i != accounts->end())
    {
        Account *acc = (*i);

        if(acc->isDisplay())
        {
            QString currencyStr;

            QList<Currency*>* currencyList = acc->getCurrencyList();
            QList<Currency*>::iterator j = currencyList->begin();
            while (j != currencyList->end())
            {
                Currency *currency = (*j);
                if(currency->isDisplay())
                {
                    currencyStr = currencyStr + QString::number(currency->getBalance()) + " " + currency->getShortName();
                }
                j++;
            }
            QString content = acc->getName() + ": " + currencyStr;
            CustomAction* action = new CustomAction(content, this, acc);
            accountActions->append(action);
            connect(action, SIGNAL(triggered(bool)), this, SLOT(AddTransaction()));
            trayIconMenu->insertAction(trayIconMenu->actions().at(position), action);
            position++;
        }

        i++;
    }

    /*
    QWidgetAction *testAction = new QWidgetAction(this);
    QHBoxLayout *layout = new QHBoxLayout();
    QPushButton *central = new QPushButton();

    QLabel *name = new QLabel("Test");
    QLabel *amount = new QLabel("100");
    layout->addWidget(name, 0, Qt::AlignLeft);
    layout->addWidget(amount, 0, Qt::AlignRight);

    central->setLayout(layout);

    testAction->setDefaultWidget(central);

    trayIconMenu->addAction(testAction);
    */
}

void MainWindow::createDefaultSysTray()
{
    trayIconMenu = new QMenu(this);

    QAction* exitAction = new QAction(tr("Quit"), this);
    connect(exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));

    QAction* settingsAction = new QAction(tr("Settings..."), this);
    connect(settingsAction, SIGNAL(triggered()),this, SLOT(show()));

    trayIconMenu->addSeparator();
    trayIconMenu->addAction(settingsAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(exitAction);

    trayIcon = new QSystemTrayIcon(this);
    QIcon icon(":/favicon.ico");
    trayIcon->setIcon(icon);
    trayIcon->setContextMenu(trayIconMenu);

    trayIcon->show();
}

void MainWindow::SaveSettings()
{
    QString newLogin = ui->lineEditLogin->text();
    QString newPass = ui->lineEditPassword->text();

    manager->ChangeCredentials(newLogin, newPass);

    if(manager->CheckConnection())
    {
        config->setLogin(newLogin);
        config->setPassword(newPass);
        ui->errorLabel->hide();
        this->hide();
    }
    else
    {
        ui->errorLabel->setText(manager->GetLastError());
        ui->errorLabel->show();
    }
}

void MainWindow::CancelSettings()
{
    ui->lineEditLogin->setText(config->getLogin());
    ui->lineEditPassword->setText("");
    this->hide();
}

void MainWindow::AddTransaction()
{
    for (int i = 0; i < trayIconMenu->actions().count(); i++)
    {
        if (trayIconMenu->actions().at(i)->isChecked())
        {
            Account* acc = ((CustomAction*)trayIconMenu->actions().at(i))->GetAccount();
            trayIconMenu->actions().at(i)->setChecked(false);
            TransactionDialog *dialog = new TransactionDialog(
                        acc,
                        accounts,
                        categories,
                        manager);
            connect(dialog, SIGNAL(refreshTray()), this, SLOT(RefreshTray()));

            dialog->show();
        }
    }
}

void MainWindow::deleteAccountsFromTray()
{
    QList<CustomAction*>::iterator i = accountActions->begin();

    while (i != accountActions->end())
    {
        CustomAction* ca = (*i);
        trayIconMenu->removeAction(ca);
        i++;
    }

    accountActions->clear();
}
