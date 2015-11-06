#ifndef DEPDAO_H
#define DEPDAO_H
#include <QList>
#include "bean/DepBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"
class LIBSHARED_EXPORT DepDAO
{
public:
    DepDAO();
    static int createDep(DepBean *bean);
    static int updateDep(DepBean *bean);
    static int delDep(DepBean *bean);
    static QList<DepBean *> queryDep();
    static QList<DepBean *> queryDepByEnd();
    static QList<DepBean *> queryDepFirst();
    static QList<DepBean *> queryDepBy(QString id);
    static DepBean * getDepById(QString id);
};

#endif // DEPDAO_H
