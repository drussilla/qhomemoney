#ifndef SAXHANDLER_H
#define SAXHANDLER_H

#include <QXmlDefaultHandler>

class SaxHandler : public QXmlDefaultHandler
{
    Q_OBJECT
public:
    explicit SaxHandler(QObject *parent = 0);
    bool startElement(const QString &namespaceURI,
                        const QString &localName,
                        const QString &qName,
                        const QXmlAttributes &attribs);
    bool endElement(const QString &namespaceURI,
                      const QString &localName,
                      const QString &qName);
    bool characters(const QString &str);
    bool fatalError(const QXmlParseException &exception);

private:
    QString currentText;

signals:

public slots:

};

#endif // SAXHANDLER_H
