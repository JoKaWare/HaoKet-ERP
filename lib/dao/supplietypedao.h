#ifndef SUPPLIETYPEDAO_H
#define SUPPLIETYPEDAO_H

#include <QList>
#include "bean/SupplieTypeBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT SupplieTypeDAO
{
public:
    SupplieTypeDAO();
    static int createType(SupplieTypeBean *bean);
    static int updateType(SupplieTypeBean *bean);
    static int delType(SupplieTypeBean *bean);
    static QList<SupplieTypeBean *> queryType();
    static QList<SupplieTypeBean *> queryTypeBy(QString id);
    static QList<SupplieTypeBean *> queryTypeByFirst();
    static QList<SupplieTypeBean *> queryTypeByEnd();
    static SupplieTypeBean * getTypeById(QString id);
};

#endif // SUPPLIETYPEDAO_H
