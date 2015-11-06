#ifndef ARRIVALDAO_H
#define ARRIVALDAO_H
#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/PuOrderVouchBean.h"
#include "bean/PuOrderVouchsBean.h"
#include "bean/PuArrivalVouchBean.h"
#include "bean/PuArrivalVouchsBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
class ArrivalDAO
{
public:
    ArrivalDAO();
    static int createPuArrival(PuArrivalVouchBean *bean);
    static int updatePuArrival(PuArrivalVouchBean *bean);
    static int delPuArrival(PuArrivalVouchBean *bean);
    static int delPuArrivalByNo(PuArrivalVouchBean *bean);
    static int getPuArrivalCount();
    static int getPuArrivalCount(QString bus_type);
    static int getPuArrivalRowNumber(int id);
    static int getPuArrivalCount(QDate date);
    static int getPuArrivalCountByNo(QString no);
    static PuArrivalVouchBean *getPuArrivalByNo(QString no);
    static QList<PuArrivalVouchBean *> queryPuArrivalByPage(int page ,int maxResult);
    static QList<PuArrivalVouchBean *> queryPuArrivalByPage(int page ,int maxResult,QString bus_type);
    static QList<PuArrivalVouchBean *> queryPuArrivalBy(QDate date);
    static QList<PuArrivalVouchBean *> queryPuArrivalBy(QDate start,QDate end);

    static int createPuArrivalVouchs(PuArrivalVouchsBean *bean);
    static int updatePuArrivalVouchs(PuArrivalVouchsBean *bean);
    static int delPuArrivalVouchs(PuArrivalVouchsBean *bean);
    static int delPuArrivalVouchsByNo(QString no);
    static QList<PuArrivalVouchsBean *> queryPuArrivalVouchsByNo(QString no);
    static QList<PuArrivalVouchsBean *> queryPuArrivalVouchsByOrderNo(QString no);
    static PuArrivalVouchsBean *getPuArrivalBy(QString no,QString productCode);
    static QSqlQueryModel *querySqlModelArrivalBy(QString no);
    static QSqlQueryModel *querySqlModelArrivalBy(QDate start, QDate end);
    static PuArrivalVouchsBean *getPuReRdsBy(QString src_no, QString productCode);
};

#endif // ARRIVALDAO_H
