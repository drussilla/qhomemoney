#include "currency.h"

Currency::Currency()
{}

Currency::Currency(unsigned int id, QString shortName, float rate,
                    float balance, bool display)
{
    this->setId(id);
    this->setShortName(shortName);
    this->setBalance(balance);
    this->setIsDisplay(display);
    this->setRate(rate);
}

unsigned int Currency::getId()
{
    return this->id;
}

QString Currency::getShortName()
{
    return this->shortName;
}

float Currency::getRate()
{
    return this->rate;
}

float Currency::getBalance()
{
    return this->balance;
}

bool Currency::isDisplay()
{
    return this->display;
}

void Currency::setId(unsigned int id)
{
    this->id = id;
}

void Currency::setShortName(QString shortName)
{
    this->shortName = shortName;
}

void Currency::setRate(float rate)
{
    this->rate = rate;
}

void Currency::setBalance(float balance)
{
    this->balance = balance;
}

void Currency::setIsDisplay(bool display)
{
    this->display = display;
}

void Currency::parseInitDom(const QDomElement &element)
{
    QDomNode node = element.firstChild();
    while(!node.isNull())
    {
        if (node.toElement().tagName() == "id")
        {
            this->setId(node.firstChild().toText().data().toUInt());
        }
        else if(node.toElement().tagName() == "shortname")
        {
            this->setShortName(node.firstChild().toText().data());
        }
        else if(node.toElement().tagName() == "rate")
        {
            this->setRate(node.firstChild().toText().data().toFloat());
        }
        else if(node.toElement().tagName() == "balance")
        {
            this->setBalance(node.firstChild().toText().data().toFloat());
        }
        else if(node.toElement().tagName() == "display")
        {
            this->setIsDisplay(node.firstChild().toText().data().toInt());
        }
        node = node.nextSibling();
    }
}


