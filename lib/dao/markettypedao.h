#ifndef MARKETTYPEDAO_H
#define MARKETTYPEDAO_H
#include "bean/MarketTypeBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT MarketTypeDAO
{
public:
    MarketTypeDAO();
    static int createMarketType(MarketTypeBean *bean);
    static int updateMarketType(MarketTypeBean *bean);
    static int delMarketType(MarketTypeBean *bean);
    static QList<MarketTypeBean *> queryMarketType();
    static MarketTypeBean * getMarketTypeById(QString id);
    static MarketTypeBean * getMarketTypeByName(QString name);
};

#endif // MARKETTYPEDAO_H
