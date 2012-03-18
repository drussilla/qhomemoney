#ifndef BALANCELISTPARSER_H
#define BALANCELISTPARSER_H

#include "xmlparser.h"
#include "account.h"

class BalanceListParser : XmlParser
{
public:
    BalanceListParser(QString inputString);

    void parse(QList<Account*>* accountList) throw(const char*, QString);

};

#endif // BALANCELISTPARSER_H
