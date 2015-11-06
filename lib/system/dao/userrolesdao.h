#ifndef USERROLESDAO_H
#define USERROLESDAO_H
#include <QList>
#include "system/bean/ProcessBean.h"
#include "system/bean/RoleAccessBean.h"
#include "system/bean/RoleBean.h"
#include "system/bean/UserRolesBean.h"

#include "common/dbmanager.h"
#include "db/queryrunner.h"
class UserRolesDAO
{
public:
    UserRolesDAO();
    static int createUserRole(UserRolesBean *bean);
    static int updateUserRole(UserRolesBean *bean);
    static int delUserRole(UserRolesBean *bean);
    static QList<UserRolesBean *> queryUserRole();
    static UserRolesBean * getUserRoleById(QString id);
};

#endif // USERROLESDAO_H
