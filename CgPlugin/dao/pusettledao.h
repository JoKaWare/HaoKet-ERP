#ifndef PUSETTLEDAO_H
#define PUSETTLEDAO_H
#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/PuSettleVouchBean.h"
#include "bean/PuSettleVouchsBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
class PuSettleDAO
{
public:
    PuSettleDAO();
    static int createPuSettle(PuSettleVouchBean *bean);
    static int updatePuSettle(PuSettleVouchBean *bean);
    static int delPuSettle(PuSettleVouchBean *bean);
    static int delPuSettleByNo(PuSettleVouchBean *bean);
    static int getPuSettleCount(QString bus_type);
    static int getPuSettleRowNumber(int id);
    static int getPuSettleCount(QDate date);
    static int getPuSettleCountByNo(QString no);
    static PuSettleVouchBean *getPuSettleByNo(QString no);
    static QList<PuSettleVouchBean *> queryPuSettleByPage(int page ,int maxResult,QString bus_type);
    static QList<PuSettleVouchBean *> queryPuSettleBy(QDate date);
    static QList<PuSettleVouchBean *> queryPuSettleBy(QDate start,QDate end);

    static int createPuSettleVouchs(PuSettleVouchsBean *bean);
    static int updatePuSettleVouchs(PuSettleVouchsBean *bean);
    static int delPuSettleVouchs(PuSettleVouchsBean *bean);
    static int delPuSettleVouchsByNo(QString no);
    static QList<PuSettleVouchsBean *> queryPuSettleVouchsByNo(QString no);

    static QSqlQueryModel *querySqlModelPuSettleBy(QString no);
    static QSqlQueryModel *querySqlModelPuSettleBy(QDate start, QDate end);
    static PuSettleVouchsBean *getPuSettleRdsBy(QString rd_no, QString productCode);
    static int getPuSettleRdsCount(QString rd_no);
};

#endif // PUSETTLEDAO_H
