#ifndef CONNECTIONMANAGER_H
#define CONNECTIONMANAGER_H

#include <QObject>
#include <QString>
#include <QList>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QDomDocument>
#include <QDomNode>
#include <QEventLoop>
#include "accountlistparser.h"
#include "balancelistparser.h"
#include "categorylistparser.h"
#include "account.h"
#include "group.h"
#include "category.h"


class ConnectionManager : public QObject
{
Q_OBJECT
public:
    explicit ConnectionManager(QString login, QString password, QObject *parent = 0);
    ~ConnectionManager();

    enum CSTypes
    {
        AccountList,
        BalanceList,
        CategoryList,
        TransactionSave
    };

    bool CheckConnection();
    void ChangeCredentials(QString newLogin, QString newPass);
    QList<Account*>* GetAccountList(bool refresh = false) throw(const char*, QString);
    QList<Category*>* GetCategoryList(bool refresh = false) throw(const char*, QString);
    QString GetLastError();

private:
    QString login;
    QString password;

    QString appKey;
    QString domain;
    QString accountListCS;
    QString balanceListCS;
    QString categoryListCS;
    QString transactionSaveCS;

    QString lastError;

    QNetworkAccessManager *netManager;

    QList<Account*>* accountList;
    QList<Category*>* categoryList;
    QList<Group*>* groupList;

    QString getCS(CSTypes type);
    QString getResult(QString reply);
    QString getTransactionSaveCS(
            int accountId,
            int factor,
            bool isTrans,
            float total,
            int curencyId,
            int categoryId,
            QString date,
            QString description,
            int transAccountId,
            float transTotal,
            int transCurencyId,
            bool isPlan,
            QString guid);


};

#endif // CONNECTIONMANAGER_H
