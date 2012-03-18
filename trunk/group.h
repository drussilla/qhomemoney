#ifndef GROUP_H
#define GROUP_H

#include <QString>
#include "parseditem.h"

class Group : ParsedItem
{
private:
    unsigned int id;
    QString name;


public:
    Group();
    Group(unsigned int id, QString name);

    void setId(unsigned int id);
    void setName(QString name);

    unsigned int getId();
    QString getName();

    virtual void parseInitDom(const QDomElement &element);
    static QString getCollectionName();

};

#endif // GROUP_H
