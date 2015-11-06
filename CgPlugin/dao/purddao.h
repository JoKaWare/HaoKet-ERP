#ifndef PURDDAO_H
#define PURDDAO_H
#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/PuOrderVouchBean.h"
#include "bean/PuOrderVouchsBean.h"
#include "bean/PuArrivalVouchBean.h"
#include "bean/PuArrivalVouchsBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
class PuRdDAO
{
public:
    PuRdDAO();
    static int getRdImeiCount(QString no);
};

#endif // PURDDAO_H
