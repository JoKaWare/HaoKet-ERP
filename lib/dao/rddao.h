#ifndef RDDAO_H
#define RDDAO_H
#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"
class LIBSHARED_EXPORT RdDAO
{
public:
    RdDAO();
    static int createRd(RdBean *bean);
    static int updateRd(RdBean *bean);
    static int delRd(RdBean *bean);
    static int delRdByNo(RdBean *bean);
    static int getRdCount(QString vouchType);
    static int getRdRowNumber(QString vouchType,int id);
    static int getRdCount(QDate date);
    static int getRdCountByNo(QString no);
    static int getRdsCountByPr(QString productCode);
    static int getRdsCountByWh(QString whCode);
    static int getRdsCountByVen(QString venCode);
    static RdBean *getRdByNo(QString no);
    static RdBean *getRdByBusNo(QString no, QString vouch_type);
    static QList<RdBean *> queryRdByPage(QString vouchType,int page ,int maxResult);
    static QList<RdBean *> queryRdBy(QDate date);
    static QList<RdBean *> queryRdBy(QDate start,QDate end);

    static int createRds(RdsBean *bean);
    static int updateRds(RdsBean *bean);
    static int delRds(RdsBean *bean);
    static int delRdsByNo(QString no);
    static RdsBean *getRdsBy(QString id);
    static QList<RdsBean *> queryRdsBy(QString no);

    static QSqlQueryModel *querySqlModelRdByLike(QString no,int rdFlag,QString vouchType);
    static QSqlQueryModel *querySqlModelRdByLike(QDate start, QDate end,int rdFlag,QString vouchType);
    static QSqlQueryModel *querySqlModelRdByLike(QDate start, QDate end,QString vouchType);
    static QSqlQueryModel *querySqlModelRdBy(QString no,int rdFlag,QString vouchType);
    static QSqlQueryModel *querySqlModelRdBy(QDate start, QDate end,int rdFlag,QString vouchType);
    static QSqlQueryModel *querySqlModelRdBy(QString no,QString vouchType);
    static QSqlQueryModel *querySqlModelRdBy(QDate start, QDate end,QString vouchType);

    static int getRdInImeiCount(QString no);
    static int getRdOutImeiCount(QString no);
};

#endif // RDDAO_H
