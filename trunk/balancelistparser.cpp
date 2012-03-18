#include "balancelistparser.h"

BalanceListParser::BalanceListParser(QString inputString)
    : XmlParser(inputString)
{
}

void BalanceListParser::parse(QList<Account *> *accountList) throw(const char*, QString)
{
    QDomElement root = doc->documentElement();
    if (root.tagName() != "result")
    {
        throw "Wrong reply XML format";
    }

    QDomNode errorNode = root.firstChild();
    if(errorNode.toElement().tagName() != "error")
    {
        throw "Wrong reply XML format";
    }

    if(errorNode.firstChild().toText().data().toInt() != 0)
    {
        throw errorNode.firstChild().toText().data();
    }
    QDomNode accountsbalances = errorNode.nextSibling();
    if(accountsbalances.toElement().tagName() != "accountsbalances")
    {
        throw "Wrong reply XML format";
    }

    QDomNode defaultcurrency = accountsbalances.firstChild();
    if(defaultcurrency.toElement().tagName() != "defaultcurrency")
    {
        throw "Wrong reply XML format";
    }
    QDomNode firstAccount = defaultcurrency.nextSibling();

    QList<Account*>::iterator i = accountList->begin();
    while (i != accountList->end())
    {
        Account *acc = (*i);
        acc->parseBalanceNode(firstAccount.toElement());
        i++;
    }
}



