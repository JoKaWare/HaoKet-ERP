#ifndef SARDDAO_H
#define SARDDAO_H
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/SaOrderVouchBean.h"
#include "bean/SaOrderVouchsBean.h"
#include "bean/SaDispatchVouchBean.h"
#include "bean/SaDispatchVouchsBean.h"
#include "bean/StockBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
class SaRdDAO
{
public:
    SaRdDAO();
    static int getRdImeiCount(QString no);
    static QList<StockBean *> queryStockBy(QString whCode);
};

#endif // SARDDAO_H
