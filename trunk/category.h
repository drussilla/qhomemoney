#include <QString>
#include "parseditem.h"

#ifndef CATEGORY_H
#define CATEGORY_H

class Category : ParsedItem
{
public:
    Category();
    Category(QString name, unsigned int id, int factor);

    QString getName();
    unsigned int getId();
    int getFactor();

    void setName(QString newName);
    void setId(unsigned int newId);
    void setFactor(int newFactor);

    void parseInitDom(const QDomElement &element);
    static QString getCollectionName();
private:
    QString name;
    unsigned int id;
    int factor;
};

#endif // CATEGORY_H
