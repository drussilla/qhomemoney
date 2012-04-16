#ifndef BALANCELISTPARSER_H
#define BALANCELISTPARSER_H

#include "xmlparser.h"
#include "account.h"
#include <QDomNode>

class BalanceListParser : private XmlParser
{
public:
    BalanceListParser(QString inputString);

    void parse(QList<Account*>* accountList) throw(const char*, QString);

private:

    virtual QDomNode getThirdLevenNode(QString nodeName) throw(const char*, QString);

};

#endif // BALANCELISTPARSER_H
