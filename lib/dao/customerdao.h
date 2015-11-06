#ifndef CUSTOMERDAO_H
#define CUSTOMERDAO_H

#include <QList>
#include "bean/CustomerBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT CustomerDAO
{
public:
    CustomerDAO();
    static int createCus(CustomerBean *bean);
    static int updateCus(CustomerBean *bean);
    static int delCus(CustomerBean *bean);
    static QString getMaxId();
    static int getByTypeCount(QString type);
    static QList<CustomerBean *> queryCus();
    static QList<CustomerBean *> queryCusAll();
    static int getByCodeCount(QString code);
    static CustomerBean * getCusById(QString id);
    static CustomerBean * getCusByCode(QString code);
};

#endif // CUSTOMERDAO_H
