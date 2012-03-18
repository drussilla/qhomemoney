#include "group.h"

Group::Group()
{
}

Group::Group(unsigned int id, QString name)
{
    this->setName(name);
    this->setId(id);
}

// #########################
// Setter and Getter section
// #########################

void Group::setId(unsigned int id)
{
    this->id = id;
}

void Group::setName(QString name)
{
    this->name = name;
}

unsigned int Group::getId()
{
    return this->id;
}

QString Group::getName()
{
    return this->name;
}

void Group::parseInitDom(const QDomElement &element)
{
    QDomNode node = element.firstChild();
    while(!node.isNull())
    {
        if (node.toElement().tagName() == "id")
        {
            this->setId(node.firstChild().toText().data().toUInt());
        }
        else if(node.toElement().tagName() == "name")
        {
            this->setName(node.firstChild().toText().data());
        }
        node = node.nextSibling();
    }
}

QString Group::getCollectionName()
{
    return "groupcollection";
}
