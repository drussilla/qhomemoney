#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <QString>
#include <QSettings>
#include <simplecrypt.h>

class ConfigManager
{
public:
    ConfigManager();
    ~ConfigManager();

    QString getLogin();
    QString getPassword();

    void setLogin(QString login);
    void setPassword(QString pass);

private:
    QSettings *setting;
    SimpleCrypt *crypt;

};

#endif // CONFIGMANAGER_H
