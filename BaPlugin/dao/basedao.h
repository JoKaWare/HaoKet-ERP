#ifndef BASEDAO_H
#define BASEDAO_H
#include "common/dbmanager.h"
#include "db/queryrunner.h"
class BaseDAO
{
public:
    BaseDAO();
    static int getRdByInv(QString code);
    static int getRdByVen(QString code);
    static int getRdByCus(QString code);
    static int getRdByEmp(QString code);
    static int getRdByWh(QString code);
};

#endif // BASEDAO_H
