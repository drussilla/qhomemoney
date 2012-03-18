#include <QString>
#include <parseditem.h>

#ifndef CURRENCY_H
#define CURRENCY_H

class Currency : ParsedItem
{
public:
    Currency();
    Currency(unsigned int id, QString shortname, float rate,
             float balance, bool display);

    unsigned int getId();
    QString getShortName();
    float getRate();
    float getBalance();
    bool isDisplay();

    void setId(unsigned int id);
    void setShortName(QString shortName);
    void setRate(float rate);
    void setBalance(float balance);
    void setIsDisplay(bool display);

    virtual void parseInitDom(const QDomElement &element);

private:
    unsigned int id;
    QString shortName;
    float rate;
    float balance;
    bool display;
};

#endif // CURRENCY_H
