#include "xmlparser.h"

XmlParser::XmlParser(QString inputSource)
{
    doc = new QDomDocument();
    doc->setContent(inputSource, false);
}

XmlParser::~XmlParser()
{
    delete doc;
}
