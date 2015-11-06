#ifndef CACHEBABEANCOMMON_H
#define CACHEBABEANCOMMON_H
#include <QDate>
#include "bean/MarketTypeBean.h"
#include "bean/EmployeeBean.h"
#include "bean/SettleTypeBean.h"
#include "bean/TableIdBean.h"

#include "bean/EmployeeBean.h"
#include "bean/TypeBean.h"
#include "bean/userbean.h"
#include "bean/DishesBean.h"
#include "bean/DepBean.h"
#include "bean/SupplieBean.h"
#include "bean/WareHouseBean.h"

#include "dao/tabledao.h"
#include "dao/employeedao.h"
#include "dao/typedao.h"
#include "dao/userdao.h"

#include "dao/dishesdao.h"
#include "dao/markettypedao.h"
#include "dao/employeedao.h"
#include "dao/cashtypedao.h"
#include "dao/depdao.h"
#include "dao/suppliedao.h"
#include "dao/waredao.h"
#include "common/qkstringutils.h"
class LIBSHARED_EXPORT CacheBaBeanCommon
{
public:
    CacheBaBeanCommon();
    static QString statusToStr(int status);
    static QString reserveStatusTo(int status);
    static QString marketToName(int id);
    static QString boolToStr(bool b);
    static QString boolToStrEn(bool b);
    static QString personToName(QString id);
    static QString userToName(int id,int result);
    static QString venToName(QString code);
    static QString rdFlagToName(int flag);
    static QString vouchTypeToName(QString typeCode);
    static QString wareToName(QString code);
    static QString depToName(QString code);
    static QString cashTypeToName(int id);
    static QString dishesTypeToName(QString id);
    static double caclDiscByCode(QString code,double lowDisc);
    static TypeBean *getTypeBean(QString id);
    static DishesBean *getDishesBean(QString code);
    static void updateCache();
};

#endif // CACHEBABEANCOMMON_H
