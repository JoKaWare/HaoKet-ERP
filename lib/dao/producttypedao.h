#ifndef PRODUCTTYPEDAO_H
#define PRODUCTTYPEDAO_H
#include <QList>
#include "bean/ProductTypeBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT ProductTypeDAO
{
public:
    ProductTypeDAO();
    static int createType(ProductTypeBean *bean);
    static int updateType(ProductTypeBean *bean);
    static int delType(ProductTypeBean *bean);
    static QList<ProductTypeBean *> queryType();
    static QList<ProductTypeBean *> queryTypeBy(QString id);
    static QList<ProductTypeBean *> queryTypeByFirst();
    static QList<ProductTypeBean *> queryTypeByEnd();
    static ProductTypeBean * getTypeById(QString id);
};

#endif // PRODUCTTYPEDAO_H
