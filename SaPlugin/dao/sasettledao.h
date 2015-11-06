#ifndef SASETTLEDAO_H
#define SASETTLEDAO_H
#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/SaSettleVouchBean.h"
#include "bean/SaSettleVouchsBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
class SaSettleDAO
{
public:
    SaSettleDAO();
    static int createSaSettle(SaSettleVouchBean *bean);
    static int updateSaSettle(SaSettleVouchBean *bean);
    static int delSaSettle(SaSettleVouchBean *bean);
    static int delSaSettleByNo(SaSettleVouchBean *bean);
    static int getSaSettleCount(QString bus_type);
    static int getSaSettleRowNumber(int id);
    static int getSaSettleCount(QDate date);
    static int getSaSettleCountByNo(QString no);
    static SaSettleVouchBean *getSaSettleByNo(QString no);
    static QList<SaSettleVouchBean *> querySaSettleByPage(int page ,int maxResult,QString bus_type);
    static QList<SaSettleVouchBean *> querySaSettleBy(QDate date);
    static QList<SaSettleVouchBean *> querySaSettleBy(QDate start,QDate end);

    static int createSaSettleVouchs(SaSettleVouchsBean *bean);
    static int updateSaSettleVouchs(SaSettleVouchsBean *bean);
    static int delSaSettleVouchs(SaSettleVouchsBean *bean);
    static int delSaSettleVouchsByNo(QString no);
    static QList<SaSettleVouchsBean *> querySaSettleVouchsByNo(QString no);

    static QSqlQueryModel *querySqlModelSaSettleBy(QString no);
    static QSqlQueryModel *querySqlModelSaSettleBy(QDate start, QDate end);
    static SaSettleVouchsBean *getSaSettleRdsBy(QString rd_no, QString productCode);
    static int getSaSettleRdsCount(QString rd_no);
};

#endif // SASETTLEDAO_H
