#ifndef SYSTEMSETDAO_H
#define SYSTEMSETDAO_H
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "bean/SystemSetBean.h"
#include "lib_global.h"
class LIBSHARED_EXPORT SystemSetDAO
{
public:
    SystemSetDAO();
    static int createSystemSet(SystemSetBean *bean);
    static int updateSystemSet(SystemSetBean *bean);
    static int delSystemSet(SystemSetBean *bean);
    static SystemSetBean * getBean(QString id);
    static QList<SystemSetBean *> queryBean();
};

#endif // SYSTEMSETDAO_H
