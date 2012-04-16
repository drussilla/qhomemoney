#include "xmlparser.h"
#include <QString>
#include <QDomNode>

#ifndef CATEGORYLISTPARSER_H
#define CATEGORYLISTPARSER_H

class CategoryListParser : public XmlParser
{
public:
    CategoryListParser(QString inputSource);

private:

    virtual QDomNode getThirdLevenNode(QString nodeName) throw(const char*, QString);
};

#endif // CATEGORYLISTPARSER_H
