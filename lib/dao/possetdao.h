#ifndef POSSETDAO_H
#define POSSETDAO_H
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "bean/PosSetBean.h"
#include "lib_global.h"

class LIBSHARED_EXPORT PosSetDAO
{
public:
    PosSetDAO();
    static int createPosSet(PosSetBean *bean);
    static int updatePosSet(PosSetBean *bean);
    static int delPosSet(PosSetBean *bean);
    static PosSetBean * getBean(QString id);
    static QList<PosSetBean *> queryBean();
};

#endif // POSSETDAO_H
