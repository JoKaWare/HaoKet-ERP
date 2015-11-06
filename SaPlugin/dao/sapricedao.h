#ifndef SAPRICEDAO_H
#define SAPRICEDAO_H

#include <QList>
#include <QSqlQueryModel>
#include "bean/SaPriceBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
class SaPriceDAO
{
public:
    SaPriceDAO();
    static int createSaPrice(SaPriceBean *bean);
    static int createSaPriceHis(SaPriceBean *bean);
    static int updateSaPrice(SaPriceBean *bean);
    static int delSaPrice(SaPriceBean *bean);
    static int delSaPrice(QString no);
    static int getSaPriceCount();
    static SaPriceBean *getSaPriceBy(QString code);

    static QList<SaPriceBean *> querySaPricee();
    static QList<SaPriceBean *> querySaPriceeByWh(QString whCode);
};

#endif // SAPRICEDAO_H
