#include "customaction.h"

CustomAction::CustomAction(QString &text, QObject *parent, Account* acc) : QAction(text, parent)
{
    account = acc;
    setCheckable(true);
}

Account *CustomAction::GetAccount()
{
    return account;
}

void CustomAction::SetAccount(Account *acc)
{
    account = acc;
}
