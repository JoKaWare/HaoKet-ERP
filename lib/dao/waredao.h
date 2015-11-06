#ifndef WAREDAO_H
#define WAREDAO_H
#include <QList>
#include "bean/WareHouseBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"
class LIBSHARED_EXPORT WareDAO
{
public:
    WareDAO();
    static int createWarehouse(WareHouseBean *bean);
    static int updateWarehouse(WareHouseBean *bean);
    static int delWarehouse(WareHouseBean *bean);
    static QList<WareHouseBean *> queryWarehouse();
    static WareHouseBean * getWarehouseById(QString id);

};

#endif // WAREDAO_H
