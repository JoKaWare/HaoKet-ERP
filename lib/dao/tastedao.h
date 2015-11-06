#ifndef TASTEDAO_H
#define TASTEDAO_H
#include "bean/TasteBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT TasteDAO
{
public:
    TasteDAO();
    static int createTaste(TasteBean *bean);
    static int updateTaste(TasteBean *bean);
    static int delTaste(TasteBean *bean);
    static QList<TasteBean *> queryTaste();
    static TasteBean * getTaste(QString id);

};

#endif // TASTEDAO_H
