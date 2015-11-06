#ifndef CUSTOMERTYPEDAO_H
#define CUSTOMERTYPEDAO_H

#include <QList>
#include "bean/CustomerTypeBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT CustomerTypeDAO
{
public:
    CustomerTypeDAO();
    static int createType(CustomerTypeBean *bean);
    static int updateType(CustomerTypeBean *bean);
    static int delType(CustomerTypeBean *bean);
    static QList<CustomerTypeBean *> queryType();
    static QList<CustomerTypeBean *> queryTypeBy(QString id);
    static QList<CustomerTypeBean *> queryTypeByFirst();
    static QList<CustomerTypeBean *> queryTypeByEnd();
    static CustomerTypeBean * getTypeById(QString id);
};

#endif // CUSTOMERTYPEDAO_H
