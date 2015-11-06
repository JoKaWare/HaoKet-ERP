#ifndef TYPEDAO_H
#define TYPEDAO_H
#include <QList>
#include "bean/TypeBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT TypeDAO
{
public:
    TypeDAO();
    static int createType(TypeBean *bean);
    static int updateType(TypeBean *bean);
    static int delType(TypeBean *bean);
    static QList<TypeBean *> queryType();
    static QList<TypeBean *> queryTypeBy(QString id);
    static QList<TypeBean *> queryTypeByFirst();
    static QList<TypeBean *> queryTypeByEnd();
    static TypeBean * getTypeById(QString id);
};

#endif // TYPEDAO_H
