#ifndef DINNERDAO_H
#define DINNERDAO_H
#include "bean/DinnerBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT DinnerDAO
{
public:
    DinnerDAO();
    static int createDinner(DinnerBean *bean);
    static int updateDinner(DinnerBean *bean);
    static int delDinner(DinnerBean *bean);
    static QList<DinnerBean *> queryDinner();
    static QList<DinnerBean *> queryDinnerByAreaId(QString id);
    static DinnerBean * getDinnerById(QString id);

};

#endif // DINNERDAO_H
