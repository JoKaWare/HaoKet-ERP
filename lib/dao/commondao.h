#ifndef COMMONDAO_H
#define COMMONDAO_H
#include <QList>
#include "bean/UnitBean.h"
#include "bean/DefineBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT CommonDAO
{
public:
    CommonDAO();
    static QList<UnitBean *> queryUnit();
    static QList<DefineBean *> queryDefine();
};

#endif // COMMONDAO_H
