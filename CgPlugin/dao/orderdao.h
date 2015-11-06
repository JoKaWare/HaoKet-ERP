#ifndef ORDERDAO_H
#define ORDERDAO_H
#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/PuOrderVouchBean.h"
#include "bean/PuOrderVouchsBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
#include "../SaPlugin/bean/SaOrderVouchsBean.h"

class OrderDAO
{
public:
    OrderDAO();
    static int createPuOrder(PuOrderVouchBean *bean);
    static int updatePuOrder(PuOrderVouchBean *bean);
    static int delPuOrder(PuOrderVouchBean *bean);
    static int delPuOrderByNo(PuOrderVouchBean *bean);
    static int getPuOrderCount();
    static int getPuOrderRowNumber(int id);
    static int getPuOrderCount(QDate date);
    static int getPuOrderCountByNo(QString no);
    static PuOrderVouchBean *getPuOrderByNo(QString no);
    static QList<PuOrderVouchBean *> queryPuOrderByPage(int page ,int maxResult);
    static QList<PuOrderVouchBean *> queryPuOrderBy(QDate date);
    static QList<PuOrderVouchBean *> queryPuOrderBy(QDate start,QDate end);

    static int createPuOrderVouchs(PuOrderVouchsBean *bean);
    static int updatePuOrderVouchs(PuOrderVouchsBean *bean);
    static int delPuOrderVouchs(PuOrderVouchsBean *bean);
    static int delPuOrderVouchsByNo(QString no);
    static QList<PuOrderVouchsBean *> queryPuOrderVouchsByNo(QString no);
    static PuOrderVouchsBean *getPuOrderVouchsBy(QString no,QString productCode);
    static PuOrderVouchsBean *getPuReOrderVouchsBy(QString no,QString productCode);
    static QSqlQueryModel *querySqlModelOrderBy(QString no);
    static QSqlQueryModel *querySqlModelOrderBy(QDate start, QDate end);

    static SaOrderVouchsBean *getSaOrderVouchsBy(QString no,QString productCode);
    static int updateSaOrderVouchs(SaOrderVouchsBean *bean);
};

#endif // ORDERDAO_H
