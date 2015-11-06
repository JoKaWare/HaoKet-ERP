#ifndef REPORTDAO_H
#define REPORTDAO_H
#include <QList>
#include "bean/ReportFormatBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"
class LIBSHARED_EXPORT ReportDAO
{
public:
    ReportDAO();
    static int createRpt(ReportFormatBean *bean);
    static int updateRpt(ReportFormatBean *bean);
    static int delRpt(ReportFormatBean *bean);
    static QList<ReportFormatBean *> queryRpt();
    static QList<ReportFormatBean *> queryRptBy(QString winId);
    static ReportFormatBean * getRptById(QString id);
};

#endif // REPORTDAO_H
