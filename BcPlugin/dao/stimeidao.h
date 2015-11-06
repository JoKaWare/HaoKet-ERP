#ifndef STIMEIDAO_H
#define STIMEIDAO_H
#include <QSqlQueryModel>
#include "bean/RdInImeiBean.h"
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "common/dbmanager.h"
#include "dao/queryrunner.h"
class StImeiDAO
{
public:
    StImeiDAO();
    static int createImei(RdInImeiBean *bean);
    static int updateImei(RdInImeiBean *bean);
    static int delImei(RdInImeiBean *bean);
    static int delImeiByIdx(QString idx);
    static int delImeiByNo(QString no);
    static int delImeiByImei(QString imei, QString whCode);
    static int getImeiCountByIdx(QString idx);
    static int getImeiCountByNo(QString no);
    static int getImeiCountByImei(QString imei);
    static int getImeiCountByImei(QString imei, QString wh_code);
    static RdInImeiBean *getStImeiBy(QString imei);
    static QList<RdInImeiBean *> queryImeiBy(QString idx);
    static QList<RdInImeiBean *> queryImeiByNo(QString no);
};

#endif // STIMEIDAO_H
