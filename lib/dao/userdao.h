#ifndef USERDAO_H
#define USERDAO_H
#include "bean/userbean.h"
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT UserDAO
{

public:
    UserDAO();
    static int createUser(UserBean *user);
    static int updateUser(UserBean *user);
    static int deleteUser(UserBean *user);
    static int modiPassword(int userid,QString newPw);
    static UserBean *getUser(QString username);
    static UserBean *getUserById(int id);
    static QList<UserBean *> getAllUser();
    static QList<UserBean *> getUserByAction(QString action);
};

#endif // USERDAO_H
