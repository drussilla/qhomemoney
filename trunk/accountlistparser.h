#include <QString>
#include <QList>
#include "account.h"
#include "group.h"
#include "xmlparser.h"

#ifndef ACCOUNTLISTPARSER_H
#define ACCOUNTLISTPARSER_H

class AccountListParser : public XmlParser
{
public:
    AccountListParser(QString inputSource);

private:

    virtual QDomNode getThirdLevenNode(QString nodeName) throw(const char*, QString);
};

#endif // ACCOUNTLISTPARSER_H
