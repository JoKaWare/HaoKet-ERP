#ifndef INIMEIDAO_H
#define INIMEIDAO_H
#include <QSqlQueryModel>
#include "bean/RdInImeiBean.h"
#include "bean/RdBean.h"
#include "bean/RdsBean.h"
#include "common/dbmanager.h"
#include "dao/queryrunner.h"
class InImeiDAO
{
public:
    InImeiDAO();
    static int createImei(RdInImeiBean *bean);
    static int updateImei(RdInImeiBean *bean);
    static int delImei(RdInImeiBean *bean);
    static int delImeiByIdx(QString idx);
    static int delImeiByNo(QString no);
    static int getImeiCountByIdx(QString idx);
    static int getImeiCountByNo(QString no);
    static QList<RdInImeiBean *> queryImeiBy(QString idx);
    static QList<RdInImeiBean *> queryImeiByNo(QString no);
    static QList<RdInImeiBean *> queryImeiIsStock(QString no);
    static QList<RdInImeiBean *> queryImeiNotStock(QString no);
    static QList<RdInImeiBean *> queryImeiNotStock(QString no,QString whCode);
};

#endif // INIMEIDAO_H
