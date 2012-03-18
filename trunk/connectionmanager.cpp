#include "connectionmanager.h"

ConnectionManager::ConnectionManager(QString login, QString password, QObject *parent) : QObject(parent)
{
    ChangeCredentials(login, password);

    appKey = "demo";
    domain = "http://homemoney.ua";
    accountListCS = "[domain]/iPhone/api14.asmx/AccountList?UserName=[login]&AppKey=[appKey]&UserKey=[password]";
    balanceListCS = "[domain]/iPhone/api14.asmx/BalanceList?UserName=[login]&AppKey=[appKey]&UserKey=[password]";
    categoryListCS = "[domain]/iPhone/api14.asmx/CategoryList?UserName=[login]&AppKey=[appKey]&UserKey=[password]";
    transactionSaveCS = "[domain]/iPhone/api14.asmx/TransactionSave?UserName=[login]&AppKey=[appKey]&UserKey=[password]&AccountId=[accountId]&Factor=[factor]&isTrans=[isTrans]&Total=[total]&CurencyId=[curencyId]&CategoryId=[categotyId]&Date=[date]&Description=[description]&TransAccountId=[transAccountId]&TransTotal=[transTotal]&TransCurencyId=[transCurencyId]&isPlan=[isPlan]&GUID=[guid]";

    netManager = new QNetworkAccessManager(this);

}

ConnectionManager::~ConnectionManager()
{
    delete netManager;
}

bool ConnectionManager::CheckConnection()
{
    try
    {
        GetAccountList(true);
    }
    catch (const char* message)
    {
        lastError = message;
        return false;
    }
    catch (QString message)
    {
        lastError = message;
        return false;
    }

    return true;
}

void ConnectionManager::ChangeCredentials(QString newLogin, QString newPass)
{
    this->login = newLogin;
    this->password = newPass;

    accountList = NULL;
    groupList = NULL;
}

QList<Account*>* ConnectionManager::GetAccountList(bool refresh) throw (const char*, QString)
{
    if (accountList != NULL && refresh)
    {
       accountList = NULL;
       groupList = NULL;
    }
    else if(accountList != NULL && !refresh)
    {
        return accountList;
    }

    QNetworkRequest request(QUrl(getCS(ConnectionManager::AccountList)));
    QNetworkReply *accountListReply = netManager->get(request);

    QEventLoop eventLoop;
    connect(accountListReply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();

    QString reply = QString::fromUtf8(accountListReply->readAll());

    delete accountListReply;

    QString result = getResult(reply);

    try
    {
        AccountListParser accountListParser(result);

        accountList = accountListParser.parse<Account>();
        groupList = accountListParser.parse<Group>();

        QNetworkRequest request2(QUrl(getCS(ConnectionManager::BalanceList)));
        QNetworkReply *balanceListReply = netManager->get(request2);

        QEventLoop eventLoop2;
        connect(balanceListReply, SIGNAL(finished()), &eventLoop2, SLOT(quit()));
        eventLoop2.exec();

        QString reply2 = QString::fromUtf8(balanceListReply->readAll());

        delete balanceListReply;

        QString result2 = getResult(reply2);

        BalanceListParser balanceListParser(result2);

        balanceListParser.parse(accountList);

        return accountList;
    }
    catch (const char* message)
    {
        throw message;
    }
    catch (QString message)
    {
        throw message;
    }
}

QString ConnectionManager::GetLastError()
{
    return lastError;
}

QString ConnectionManager::getCS(CSTypes type)
{
    QString connString;

    switch (type)
    {

        case ConnectionManager::AccountList :
            connString = accountListCS;
            break;

        case ConnectionManager::BalanceList :
            connString = balanceListCS;
            break;
        case ConnectionManager::CategoryList :
            connString = categoryListCS;
            break;
        case ConnectionManager::TransactionSave :
            connString = transactionSaveCS;
            break;
    }

    connString.replace("[domain]", domain);
    connString.replace("[login]", login);
    connString.replace("[password]", password);
    connString.replace("[appKey]", appKey);

    return connString;
}

QString ConnectionManager::getResult(QString reply)
{
    QDomDocument doc;
    doc.setContent(reply, true);
    QDomNode node = doc.documentElement();
    QString result = node.firstChild().toText().data();
    // TODO: Add exception handling
    return result;

}

QString ConnectionManager::getTransactionSaveCS(
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
        QString guid)
{
    QString connString = getCS(ConnectionManager::TransactionSave);
    connString.replace("[accountId]", QString::number(accountId));
    connString.replace("[factor]", QString::number(factor));
    connString.replace("[isTrans]", QVariant(isTrans).toString());
    connString.replace("[total]", QString::number(total));
    connString.replace("[curencyId]", QString::number(curencyId));
    connString.replace("[categoryId]", QString::number(categoryId));
    connString.replace("[date]", date);
    connString.replace("[description]", description);
    connString.replace("[transAccountId]", QString::number(transAccountId));
    connString.replace("[transTotal]", QString::number(transTotal));
    connString.replace("[transCurencyId]", QString::number(transCurencyId));
    connString.replace("[isPlan]", QVariant(isPlan).toString());
    connString.replace("[guid]", guid);

    return connString;
}
