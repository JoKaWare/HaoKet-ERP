#ifndef LIMITSCOMMON_H
#define LIMITSCOMMON_H
#include <system/bean/ProcessBean.h>
#include <system/bean/UserRolesBean.h>
#include <system/dao/roleaccessdao.h>
#include <system/dao/userrolesdao.h>

class LIBSHARED_EXPORT LimitsCommon
{
public:
    LimitsCommon();
    static bool getUserRoleLimits(int userid, const char *);
    static bool getUserRoleLimits(int userid, QString pName,int pWindow);
    static bool getUserRoleLimits(int userid, int processId);
    static void authority(QToolBar *bar,int winId);

};

#endif // LIMITSCOMMON_H
