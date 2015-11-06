#ifndef KMCODEDAO_H
#define KMCODEDAO_H
#include <QList>
#include <QSqlQueryModel>
#include "bean/KmCodeBean.h"
#include "bean/ApTypeBean.h"
#include "bean/SettleTypeBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
class KmCodeDAO
{
public:
    KmCodeDAO();
    static int createKmCode(KmCodeBean *bean);
    static int updateKmCode(KmCodeBean *bean);
    static int delKmCode(KmCodeBean *bean);
    static KmCodeBean *getKmCode(QString code);
    static QList<KmCodeBean *> queryKmCode();
    static QList<KmCodeBean *> queryKmCodeFirst();
    static QList<ApTypeBean *> queryApType(int flag);
    static QList<SettleTypeBean *> querySettleType();

};

#endif // KMCODEDAO_H
