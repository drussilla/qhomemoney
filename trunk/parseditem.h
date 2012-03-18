#include <QDomElement>

#ifndef PARSEDITEM_H
#define PARSEDITEM_H

class ParsedItem
{
public:
    ParsedItem();

    virtual void parseInitDom(const QDomElement &element) = 0;
};

#endif // PARSEDITEM_H
