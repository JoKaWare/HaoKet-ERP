#ifndef WINDOWDAO_H
#define WINDOWDAO_H
#include <QList>
#include "system/bean/ProcessBean.h"
#include "system/bean/WindowBean.h"
#include "system/bean/RoleAccessBean.h"
#include "system/bean/RoleBean.h"
#include "system/bean/UserRolesBean.h"
#include "system/bean/SubSysBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
class WindowDAO
{
public:
    WindowDAO();
    static int createWindow(WindowBean *bean);
    static int updateWindow(WindowBean *bean);
    static WindowBean *getWindow(int win_id);
    static QList<WindowBean *> queryWindow();
    static QList<WindowBean *> queryWindowByNoRole(QString roleId);

};

#endif // WINDOWDAO_H
