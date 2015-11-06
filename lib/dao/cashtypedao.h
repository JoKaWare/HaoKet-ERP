#ifndef CASHTYPEDAO_H
#define CASHTYPEDAO_H
#include <QList>
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "bean/SettleTypeBean.h"
#include "lib_global.h"
class LIBSHARED_EXPORT CashTypeDAO
{
public:
    CashTypeDAO();
    static int createCashType(SettleTypeBean *bean);
    static int updateCashType(SettleTypeBean *bean);
    static int delCashType(SettleTypeBean *bean);
    static QList<SettleTypeBean *> queryCashType();
    static SettleTypeBean * getCashTypeById(QString id);
    static SettleTypeBean * getCashTypeByName(QString name);
};

#endif // CASHTYPEDAO_H
