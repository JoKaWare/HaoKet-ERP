#ifndef AREADAO_H
#define AREADAO_H
#include <QList>
#include "bean/AreaBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"
class LIBSHARED_EXPORT AreaDAO
{
public:
    AreaDAO();
    static int createArea(AreaBean *bean);
    static int updateArea(AreaBean *bean);
    static int delArea(AreaBean *bean);
    static QList<AreaBean *> queryArea();
    static AreaBean * getAreaById(QString id);
};

#endif // AREADAO_H
