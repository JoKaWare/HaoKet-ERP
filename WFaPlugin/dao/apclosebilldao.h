#ifndef APCLOSEBILLDAO_H
#define APCLOSEBILLDAO_H
#include <QList>
#include <QSqlQueryModel>
#include "bean/ApCloseBillBean.h"
#include "bean/ApCloseBillsBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
class ApCloseBillDAO
{
public:
    ApCloseBillDAO();
    static int createApCloseBill(ApCloseBillBean *bean);
    static int updateApCloseBill(ApCloseBillBean *bean);
    static int delApCloseBill(ApCloseBillBean *bean);
    static int delApCloseBillByNo(ApCloseBillBean *bean);
    static int getApCloseBillCount();
    static int getApCloseBillCount(int flag);
    static int getApCloseBillRowNumber(int id);
    static int getApCloseBillCount(QDate date);
    static int getApCloseBillCountByNo(QString no);
    static ApCloseBillBean *getApCloseBillByNo(QString no);
    static QList<ApCloseBillBean *> queryApCloseBillByPage(int page ,int maxResult);
    static QList<ApCloseBillBean *> queryApCloseBillByPage(int page ,int maxResult, int bus_flag);
    static QList<ApCloseBillBean *> queryApCloseBillBy(QDate date);
    static QList<ApCloseBillBean *> queryApCloseBillBy(QDate start,QDate end);

    static int createApCloseBills(ApCloseBillsBean *bean);
    static int updateApCloseBills(ApCloseBillsBean *bean);
    static int delApCloseBills(ApCloseBillsBean *bean);
    static int delApCloseBillsByNo(QString no);
    static QList<ApCloseBillsBean *> queryApCloseBillsByNo(QString no);
};

#endif // APCLOSEBILLDAO_H
