#include "configmanager.h"

ConfigManager::ConfigManager()
{
    setting = new QSettings("SPG", "qhomemoney");
    crypt = new SimpleCrypt(Q_UINT64_C(0x012a3a3a43a9f023));
}

ConfigManager::~ConfigManager()
{
    delete setting;
    delete crypt;
}

QString ConfigManager::getLogin()
{
    return setting->value("login", "").value<QString>();
}

QString ConfigManager::getPassword()
{
    QString encryptedPass = setting->value("time", "").value<QString>();
    if(encryptedPass == "")
    {
        return "";
    }

    QString plainPass = crypt->decryptToString(encryptedPass);
    return plainPass;
}

void ConfigManager::setLogin(QString login)
{
    setting->setValue("login", login);
}

void ConfigManager::setPassword(QString pass)
{
    QString encryptedPass = crypt->encryptToString(pass);
    setting->setValue("time", encryptedPass);
}
