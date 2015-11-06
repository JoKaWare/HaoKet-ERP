#ifndef LOGDAO_H
#define LOGDAO_H
#include "system/bean/LogBean.h"
#include "db/queryrunner.h"
#include "common/dbmanager.h"

class LogDAO
{
public:
    LogDAO();
    static int createLog(LogBean *bean);
    static int updateLog(LogBean *bean);
    static int delLog(LogBean *bean);
    static int delLogBy(QDate date);

    static QList<LogBean *> queryLogBy(QDate date);
    static QList<LogBean *> queryLogBy(QDate start,QDate end);
};

#endif // LOGDAO_H
