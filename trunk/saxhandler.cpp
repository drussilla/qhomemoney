#include "saxhandler.h"

SaxHandler::SaxHandler(QObject *parent) :
    QXmlDefaultHandler(parent)
{
}
bool SaxHandler::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &attribs)
{
    if (qName == "entry") {
        if (currentItem) {
          currentItem = new QListViewItem(currentItem);
        } else {
          currentItem = new QListViewItem(listView);
        }
        currentItem->setOpen(true);
        currentItem->setText(0, attribs.value("term"));
      } else if (qName == "page") {
        currentText = "";
      }
      return true;
}

bool SaxHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{

}

bool SaxHandler::fatalError(const QXmlParseException &exception)
{

}

bool SaxHandler::characters(const QString &str)
{

}

