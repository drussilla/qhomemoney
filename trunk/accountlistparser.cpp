#include "accountlistparser.h"

AccountListParser::AccountListParser(QString inputSource)
    : XmlParser(inputSource)
{
}


QDomNode AccountListParser::getThirdLevenNode(QString nodeName) throw(const char*, QString)
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

    if(errorNode.firstChild().toText().data() != "0")
    {
        QString errorMessage = errorNode.firstChild().toText().data();
        throw errorMessage;
    }
    QDomNode accounts = errorNode.nextSibling();
    if(accounts.toElement().tagName() != "accounts")
    {
        throw "Wrong reply XML format";
    }

    QDomNode returnNode = accounts.firstChild();
    while(!returnNode.isNull())
    {
        if(returnNode.toElement().tagName() == nodeName)
        {
            return returnNode;
        }
        returnNode = returnNode.nextSibling();
    }

    throw "Wrong reply XML format";
}
