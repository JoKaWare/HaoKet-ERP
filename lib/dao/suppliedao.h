#ifndef SUPPLIEDAO_H
#define SUPPLIEDAO_H
#include <QList>
#include "bean/SupplieBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT SupplieDAO
{
public:
    SupplieDAO();
    static int createSupplie(SupplieBean *bean);
    static int updateSupplie(SupplieBean *bean);
    static int delSupplie(SupplieBean *bean);
    static QList<SupplieBean *> querySupplie();
    static QList<SupplieBean *> querySupplieAll();
    static SupplieBean * getSupplieById(QString id);
    static SupplieBean * getSupplieByCode(QString code);
};

#endif // SUPPLIEDAO_H
