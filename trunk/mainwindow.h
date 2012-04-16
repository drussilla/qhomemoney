#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QWidgetAction>
#include <QNetworkAccessManager>
#include <account.h>
#include <group.h>
#include <QNetworkRequest>
#include <QUrl>
#include <QNetworkReply>
#include <QDomDocument>
#include <accountlistparser.h>
#include <balancelistparser.h>
#include "configmanager.h"
#include "connectionmanager.h"
#include "customaction.h"
#include "transactiondialog.h"
#include "category.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:
    void SaveSettings();
    void CancelSettings();
    void AddTransaction();
    void RefreshTray();

private:
    Ui::MainWindow *ui;

    ConnectionManager *manager;

    QList<Account*>* accounts;
    QList<Group*>* groups;
    QList<Category*>* categories;

    QList<CustomAction*>* accountActions;

    QString getResult(QString reply);

    void deleteAccountsFromTray();
    void displayAccounts();
    void createDefaultSysTray();

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;

    ConfigManager *config;


};

#endif // MAINWINDOW_H
