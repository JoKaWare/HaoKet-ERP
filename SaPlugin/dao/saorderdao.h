#ifndef SAORDERDAO_H
#define SAORDERDAO_H

#include <QList>
#include <QSqlQueryModel>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"

#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "bean/SaOrderVouchBean.h"
#include "bean/SaOrderVouchsBean.h"
class SaOrderDAO
{
public:
    SaOrderDAO();
    static int createSaOrder(SaOrderVouchBean *bean);
    static int updateSaOrder(SaOrderVouchBean *bean);
    static int delSaOrder(SaOrderVouchBean *bean);
    static int delSaOrderByNo(SaOrderVouchBean *bean);
    static int getSaOrderCount();
    static int getSaOrderRowNumber(int id);
    static int getSaOrderCount(QDate date);
    static int getSaOrderCountByNo(QString no);
    static SaOrderVouchBean *getSaOrderByNo(QString no);
    static QList<SaOrderVouchBean *> querySaOrderByPage(int page ,int maxResult);
    static QList<SaOrderVouchBean *> querySaOrderBy(QDate date);
    static QList<SaOrderVouchBean *> querySaOrderBy(QDate start,QDate end);

    static int createSaOrderVouchs(SaOrderVouchsBean *bean);
    static int updateSaOrderVouchs(SaOrderVouchsBean *bean);
    static int delSaOrderVouchs(SaOrderVouchsBean *bean);
    static int delSaOrderVouchsByNo(QString no);
    static QList<SaOrderVouchsBean *> querySaOrderVouchsByNo(QString no);
    static SaOrderVouchsBean *getSaOrderVouchsBy(QString no,QString productCode);
    static SaOrderVouchsBean *getSaReOrderVouchsBy(QString no,QString productCode);
    static QSqlQueryModel *querySqlModelOrderBy(QString no);
    static QSqlQueryModel *querySqlModelOrderBy(QDate start, QDate end);
};

#endif // SAORDERDAO_H
