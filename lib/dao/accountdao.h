#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H
#include <QList>
#include "bean/AccountBean.h"
#include "lib_global.h"
class LIBSHARED_EXPORT AccountDAO
{
public:
    AccountDAO();
    static int createAccount(AccountBean *abean);
    static QList<AccountBean *> queryAccount();
    static AccountBean *getAccountById(QString id);
};

#endif // ACCOUNTDAO_H
