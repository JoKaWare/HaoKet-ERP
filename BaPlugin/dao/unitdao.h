#ifndef UNITDAO_H
#define UNITDAO_H
#include "bean/UnitBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
class UnitDAO
{
public:
    UnitDAO();
    static int createUnit(UnitBean *bean);
    static int updateUnit(UnitBean *bean);
    static int delUnit(UnitBean *bean);
    static UnitBean *getUnit(QString id);
    static QList<UnitBean *> queryUnit();
};

#endif // UNITDAO_H
