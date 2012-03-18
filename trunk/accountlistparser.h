#include <QString>
#include <QList>
#include "account.h"
#include "group.h"
#include "xmlparser.h"

#ifndef ACCOUNTLISTPARSER_H
#define ACCOUNTLISTPARSER_H

class AccountListParser : XmlParser
{
public:
    AccountListParser(QString inputSource);

    template <typename T> QList<T*>* parse() throw (const char*, QString)
    {
        try
        {
            QDomNode collectionNode = getThirdLevenNode(T::getCollectionName());
            QDomNode node = collectionNode.firstChild();
            QList<T*>* itemList = new QList<T*>();
            while(!node.isNull())
            {
                T *item = new T();
                item->parseInitDom(node.toElement());
                itemList->append(item);
                node = node.nextSibling();
            }

            return itemList;
        }
        catch(const char* message)
        {
            throw message;
        }
        catch(QString message)
        {
            throw message;
        }
    }

private:

    QDomNode getThirdLevenNode(QString nodeName) throw(const char*, QString);
};

#endif // ACCOUNTLISTPARSER_H
