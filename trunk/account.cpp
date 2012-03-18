#include "account.h"

Account::Account()
{
    this->currencyList = new QList<Currency*>();
}

Account::Account(unsigned int id, QString name, bool isDefault,
                 bool isIncludeInBalance, bool isIncludeInBudget, bool groupId)
{
    setId(id);
    setName(name);
    setIsDefault(isDefault);
    setIsIncludeInBalance(isIncludeInBalance);
    setIsIncludeInBudget(isIncludeInBudget);
    setGroupId(groupId);
    this->currencyList = new QList<Currency*>();
}

Account::~Account()
{
    delete this->currencyList;
}




// #########################
// Setter and Getter section
// #########################
void Account::setName(QString name)
{
    this->name = name;
}

void Account::setId(unsigned int id)
{
    this->id = id;
}

void Account::setIsDefault(bool _default)
{
    this->_default = _default;
}

void Account::setIsIncludeInBalance(bool includeInBalance)
{
    this->includeInBalance = includeInBalance;
}

void Account::setIsIncludeInBudget(bool includeInBudget)
{
    this->includeInBudget = includeInBudget;
}

void Account::setGroupId(unsigned int groupId)
{
    this->groupId = groupId;
}

void Account::setIsDisplay(bool display)
{
    this->display = display;
}

unsigned int Account::getId()
{
    return this->id;
}

QString Account::getName()
{
    return this->name;
}

bool Account::isIncludeInBalance()
{
    return this->includeInBalance;
}

bool Account::isDefault()
{
    return this->_default;
}

bool Account::isIncludeInBudget()
{
    return this->includeInBudget;
}

unsigned int Account::getGroupId()
{
    return this->groupId;
}

bool Account::isDisplay()
{
    return this->display;
}

QList<Currency *> * Account::getCurrencyList()
{
    return this->currencyList;
}

void Account::parseInitDom(const QDomElement &element)
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
        else if(node.toElement().tagName() == "default")
        {
            this->setIsDefault(node.firstChild().toText().data().toInt());
        }
        else if(node.toElement().tagName() == "display")
        {
            this->setIsDisplay(node.firstChild().toText().data().toInt());
        }
        else if(node.toElement().tagName() == "includeInBalance")
        {
            this->setIsIncludeInBalance(node.firstChild().toText().data().toInt());
        }
        else if(node.toElement().tagName() == "includeInBudget")
        {
            this->setIsIncludeInBudget(node.firstChild().toText().data().toInt());
        }
        else if(node.toElement().tagName() == "groupId")
        {
            this->setGroupId(node.firstChild().toText().data().toUInt());
        }
        node = node.nextSibling();
    }
}

QString Account::getCollectionName()
{
    return "accountcollection";
}

void Account::parseBalanceNode(QDomNode firstAccount) throw(const QString)
{
    do
    {
        QDomNode subNode = firstAccount.firstChild();
        if (subNode.toElement().tagName() == "id")
        {
            unsigned int _id = subNode.firstChild().toText().data().toUInt();
            if(_id == this->getId())
            {

                QDomNode firstCurrency = subNode.nextSibling();
                while(firstCurrency.toElement().tagName() != "currency")
                {
                    firstCurrency = firstCurrency.nextSibling();
                }

                while(!firstCurrency.isNull())
                {
                    Currency *item = new Currency();
                    item->parseInitDom(firstCurrency.toElement());
                    currencyList->append(item);
                    firstCurrency = firstCurrency.nextSibling();
                }

                break;
            }
        }
        else
        {
            throw "Wrong reply XML format";
        }

        firstAccount = firstAccount.nextSibling();
    }
    while(!firstAccount.isNull());
}


