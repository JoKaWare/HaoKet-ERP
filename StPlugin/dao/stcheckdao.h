#ifndef STCHECKDAO_H
#define STCHECKDAO_H

#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/CheckVouchBean.h"
#include "bean/CheckVouchsBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
class StCheckDAO
{
public:
    StCheckDAO();
    static int createCheck(CheckVouchBean *bean);
    static int updateCheck(CheckVouchBean *bean);
    static int delCheck(CheckVouchBean *bean);
    static int delCheckByNo(CheckVouchBean *bean);
    static int getCheckCount();
    static int getCheckCount(QString bus_type);
    static int getCheckRowNumber(int id);
    static int getCheckCount(QDate date);
    static int getCheckCountByNo(QString no);
    static CheckVouchBean *getCheckByNo(QString no);
    static QList<CheckVouchBean *> queryCheckByPage(int page ,int maxResult);
    static QList<CheckVouchBean *> queryCheckByPage(int page ,int maxResult,QString bus_type);
    static QList<CheckVouchBean *> queryCheckBy(QDate date);
    static QList<CheckVouchBean *> queryCheckBy(QDate start,QDate end);

    static int createCheckVouchs(CheckVouchsBean *bean);
    static int updateCheckVouchs(CheckVouchsBean *bean);
    static int delCheckVouchs(CheckVouchsBean *bean);
    static int delCheckVouchsByNo(QString no);
    static QList<CheckVouchsBean *> queryCheckVouchsByNo(QString no);
    static QList<CheckVouchsBean *> queryCheckVouchsByOrderNo(QString no);
    static CheckVouchsBean *getCheckBy(QString no,QString productCode);
    static QSqlQueryModel *querySqlModelArrivalBy(QString no);
    static QSqlQueryModel *querySqlModelArrivalBy(QDate start, QDate end);
};

#endif // STCHECKDAO_H
