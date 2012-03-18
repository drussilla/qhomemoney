#ifndef CUSTOMACTION_H
#define CUSTOMACTION_H

#include <QAction>
#include <QEvent>
#include <QMouseEvent>
#include "account.h"

class CustomAction : public QAction
{
    Q_OBJECT
public:
    explicit CustomAction(QString& text, QObject *parent, Account* acc);

    Account* GetAccount();
    void SetAccount(Account *acc);

signals:
    
public slots:

private:
    Account* account;
    
};

#endif // CUSTOMACTION_H
