#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QString>
#include <QDomDocument>

class XmlParser
{
public:
    XmlParser(QString inputSource);
    ~XmlParser();

    template <typename T> QList<T*>* parse() throw (const char*, QString)
    {
        try
        {
            QDomNode collectionNode = this->getThirdLevenNode(T::getCollectionName());
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

protected:
    QDomDocument *doc;

    virtual QDomNode getThirdLevenNode(QString nodeName) throw(const char*, QString) = 0;
};

#endif // XMLPARSER_H
