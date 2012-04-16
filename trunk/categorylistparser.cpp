#include "categorylistparser.h"

CategoryListParser::CategoryListParser(QString inputSource) : XmlParser(inputSource)
{
}

QDomNode CategoryListParser::getThirdLevenNode(QString nodeName)
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

    QDomNode returnNode = errorNode.nextSibling();
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


