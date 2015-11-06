#ifndef TRANSIMEIDAO_H
#define TRANSIMEIDAO_H
#include <QSqlQueryModel>
#include "bean/TransImeiBean.h"
#include "bean/TransVouchBean.h"
#include "bean/TransVouchsBean.h"
#include "common/dbmanager.h"
#include "dao/queryrunner.h"
class TransImeiDAO
{
public:
    TransImeiDAO();
    static int createImei(TransImeiBean *bean);
    static int updateImei(TransImeiBean *bean);
    static int delImei(TransImeiBean *bean);
    static int delImeiByIdx(QString idx);
    static int delImeiByNo(QString no);
    static int getImeiCountByIdx(QString idx);
    static int getImeiCountByNo(QString no);
    static int updateImeiWh(QString no, QString owh_code, QString iwh_code);
    static QList<TransImeiBean *> queryImeiBy(QString idx);
    static QList<TransImeiBean *> queryImeiByNo(QString no);
    static QList<TransImeiBean *> queryImeiIsStock(QString no);
    static QList<TransImeiBean *> queryImeiNotStock(QString no);
    static QList<TransImeiBean *> queryImeiNotStock(QString no,QString whCode);

    static int updateTrans(TransVouchBean *bean);
    static int getTransCount();
    static int getTransRowNumber(int id);
    static int getTransCount(QDate date);
    static TransVouchBean *getTransBeanByNo(QString no);
    static QList<TransVouchBean *> queryTransByPage(int page ,int maxResult);
    static QList<TransVouchsBean *> queryTransVouchsByNo(QString no);
};

#endif // TRANSIMEIDAO_H
