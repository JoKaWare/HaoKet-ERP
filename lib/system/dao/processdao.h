#ifndef PROCESSDAO_H
#define PROCESSDAO_H
#include <QList>
#include "system/bean/ProcessBean.h"
#include "system/bean/WindowBean.h"
#include "system/bean/RoleAccessBean.h"
#include "system/bean/RoleBean.h"
#include "system/bean/UserRolesBean.h"
#include "system/bean/SubSysBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
class ProcessDAO
{
public:
    ProcessDAO();
    static int createPorcess(ProcessBean *bean);
    static int updatePorcess(ProcessBean *bean);
    static ProcessBean *getProcess(int proc_id);
    static ProcessBean *getProcessByName(int winId, QString name);

    static int createWindow(WindowBean *bean);
    static int updateWindow(WindowBean *bean);
    static WindowBean *getWindow(int win_id);
    static QList<ProcessBean *> queryProcess();
    static QList<ProcessBean *> queryProcessByNoRole(QString roleId);
    static QList<WindowBean *> queryWindow();
    static QList<WindowBean *> queryWindowByNoRole(QString roleId);
    static QList<SubSysBean *> querySubSys();
};

#endif // PROCESSDAO_H
