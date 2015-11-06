#ifndef IMEIDAO_H
#define IMEIDAO_H
#include <QSqlQueryModel>
#include "bean/RdInImeiBean.h"
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "common/dbmanager.h"
#include "dao/queryrunner.h"
class ImeiDAO
{
public:
    ImeiDAO();
    static RdBean *getRdByNo(QString no);
    static QList<RdsBean *> queryRdsBy(QString no);
    static QList<RdsBean *> queryOutRdsBy(QString no);
    static QList<RdBean *>  queryRdByPage(QString vouchType,int page, int maxResult);
    static int getRdCount(QString vouchType);
    static int getRdRowNumber(QString vouchType,int id);

};

#endif // IMEIDAO_H
