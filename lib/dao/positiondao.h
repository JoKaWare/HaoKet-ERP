#ifndef POSITIONDAO_H
#define POSITIONDAO_H
#include <QList>
#include <QSqlQueryModel>

#include "bean/PositionBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "dao/producttypedao.h"
#include "lib_global.h"

class LIBSHARED_EXPORT PositionDAO
{
public:
    PositionDAO();
    static int createPosition(PositionBean *bean);
    static int updatePosition(PositionBean *bean);
    static int delPosition(PositionBean *bean);
    static QList<PositionBean *> queryPosition();

    static PositionBean * getPositionById(QString id);
};

#endif // POSITIONDAO_H
