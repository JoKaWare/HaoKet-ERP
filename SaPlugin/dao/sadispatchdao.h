#ifndef SADISPATCHDAO_H
#define SADISPATCHDAO_H

#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/SaOrderVouchBean.h"
#include "bean/SaOrderVouchsBean.h"
#include "bean/SaDispatchVouchBean.h"
#include "bean/SaDispatchVouchsBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
class SaDispatchDAO
{
public:
    SaDispatchDAO();
    static int createSaDispatch(SaDispatchVouchBean *bean);
    static int updateSaDispatch(SaDispatchVouchBean *bean);
    static int delSaDispatch(SaDispatchVouchBean *bean);
    static int delSaDispatchByNo(SaDispatchVouchBean *bean);
    static int getSaDispatchCount();
    static int getSaDispatchCount(QString bus_type);
    static int getSaDispatchRowNumber(int id);
    static int getSaDispatchCount(QDate date);
    static int getSaDispatchCountByNo(QString no);
    static SaDispatchVouchBean *getSaDispatchByNo(QString no);
    static QList<SaDispatchVouchBean *> querySaDispatchByPage(int page ,int maxResult);
    static QList<SaDispatchVouchBean *> querySaDispatchByPage(int page ,int maxResult,QString bus_type);
    static QList<SaDispatchVouchBean *> querySaDispatchBy(QDate date);
    static QList<SaDispatchVouchBean *> querySaDispatchBy(QDate start,QDate end);

    static int createSaDispatchVouchs(SaDispatchVouchsBean *bean);
    static int updateSaDispatchVouchs(SaDispatchVouchsBean *bean);
    static int delSaDispatchVouchs(SaDispatchVouchsBean *bean);
    static int delSaDispatchVouchsByNo(QString no);
    static QList<SaDispatchVouchsBean *> querySaDispatchVouchsByNo(QString no);
    static QList<SaDispatchVouchsBean *> querySaDispatchVouchsByOrderNo(QString no);
    static SaDispatchVouchsBean *getSaDispatchBy(QString no,QString productCode);
    static QSqlQueryModel *querySqlModelArrivalBy(QString no);
    static QSqlQueryModel *querySqlModelArrivalBy(QDate start, QDate end);
    static SaDispatchVouchsBean *getSaReRdsBy(QString src_no, QString productCode);
    static SaDispatchVouchsBean *getSaConReRdsBy(QString src_no, QString productCode);
};

#endif // SADISPATCHDAO_H
