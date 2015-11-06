#ifndef ROLEACCESSDAO_H
#define ROLEACCESSDAO_H
#include <QList>
#include "system/bean/ProcessBean.h"
#include "system/bean/RoleAccessBean.h"
#include "system/bean/RoleBean.h"
#include "system/bean/UserRolesBean.h"

#include "common/dbmanager.h"
#include "db/queryrunner.h"
class RoleAccessDAO
{
public:
    RoleAccessDAO();
    static int createRoleAccess(RoleAccessBean *bean);
    static int updateRoleAccess(RoleAccessBean *bean);
    static int delRoleAccess(RoleAccessBean *bean);
    static QList<RoleAccessBean *> queryRoleAccess();
    static QList<RoleAccessBean *> queryRoleAccessByRole(QString roleId);
    static QList<ProcessBean *> queryRoleProcessAccessByRole(QString roleId);
    static QList<ProcessBean *> queryRoleProcessAccessByUserId(QString userId);
    static RoleAccessBean * getRoleAccessById(QString id);
};

#endif // ROLEACCESSDAO_H
