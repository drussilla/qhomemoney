#include "category.h"

Category::Category()
{
}

Category::Category(QString name, unsigned int id, int factor)
{
    this->name = name;
    this->id = id;
    this->factor = factor;
}

// #########################
// Setter and Getter section
// #########################

QString Category::getName()
{
    return this->name;
}

unsigned int Category::getId()
{
    return this->id;
}

int Category::getFactor()
{
    return this->factor;
}

void Category::setName(QString newName)
{
    this->name = newName;
}

void Category::setId(unsigned int newId)
{
    this->id = newId;
}

void Category::setFactor(int newFactor)
{
    this->factor = newFactor;
}

void Category::parseInitDom(const QDomElement &element)
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
        else if(node.toElement().tagName() == "factor")
        {
            this->setFactor(node.firstChild().toText().data().toInt());
        }
        node = node.nextSibling();
    }
}

QString Category::getCollectionName()
{
    return "categories";
}


