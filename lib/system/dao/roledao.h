#ifndef ROLEDAO_H
#define ROLEDAO_H
#include <QList>
#include "system/bean/ProcessBean.h"
#include "system/bean/RoleAccessBean.h"
#include "system/bean/RoleBean.h"
#include "system/bean/UserRolesBean.h"

#include "common/dbmanager.h"
#include "db/queryrunner.h"
class RoleDAO
{
public:
    RoleDAO();
    static int createRole(RoleBean *bean);
    static int updateRole(RoleBean *bean);
    static int delRole(RoleBean *bean);
    static QList<RoleBean *> queryRole();
    static RoleBean * getRoleById(QString id);
};

#endif // ROLEDAO_H
