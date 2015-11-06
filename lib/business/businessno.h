#ifndef BUSINESSNO_H
#define BUSINESSNO_H
#include <QDate>

#include "bean/userbean.h"
#include "dao/tabledao.h"

#include "dao/userdao.h"
#include "common/qkstringutils.h"

class LIBSHARED_EXPORT BusinessNo
{
public:
    BusinessNo();

    static QString userToName(int id,int result);

    static void updateCache();
};

#endif // BUSINESSNO_H
