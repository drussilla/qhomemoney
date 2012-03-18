#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QString>
#include <QDomDocument>

class XmlParser
{
public:
    XmlParser(QString inputSource);
    ~XmlParser();

protected:
    QDomDocument *doc;
};

#endif // XMLPARSER_H
