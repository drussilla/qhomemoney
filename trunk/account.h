#include <QString>
#include <QList>
#include <QDomElement>
#include "currency.h"
#include "parseditem.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account : ParsedItem
{
public:
    Account();
    Account(unsigned int id, QString name, bool isDefault, bool isIncludeInBalance,
            bool isIncludeInBudget, bool groupId);

    ~Account();

    unsigned int getId();
    QString getName();
    bool isDefault();
    bool isDisplay();
    bool isIncludeInBalance();
    bool isIncludeInBudget();
    unsigned int getGroupId();
    QList<Currency*>* getCurrencyList();

    void setId(unsigned int);
    void setName(QString);
    void setIsDefault(bool);
    void setIsDisplay(bool);
    void setIsIncludeInBalance(bool);
    void setIsIncludeInBudget(bool);
    void setGroupId(unsigned int);

    virtual void parseInitDom(const QDomElement &element);

    void parseBalanceNode(QDomNode firstAccount) throw(const QString);
    static QString getCollectionName();
private:
    unsigned int id;
    QString name;
    bool _default;
    bool display;
    bool includeInBalance;
    bool includeInBudget;
    unsigned int groupId;
    QList<Currency*> *currencyList;

};

#endif // ACCOUNT_H
