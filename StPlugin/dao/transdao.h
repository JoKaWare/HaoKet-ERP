#ifndef TRANSDAO_H
#define TRANSDAO_H
#include <QList>
#include <QSqlQueryModel>
#include <QApplication>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/TransVouchBean.h"
#include "bean/TransVouchsBean.h"
#include "common/dbmanager.h"
#include "dao/queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"

class TransDAO
{
public:
    TransDAO();
    static int createTrans(TransVouchBean *bean);
    static int updateTrans(TransVouchBean *bean);
    static int delTrans(TransVouchBean *bean);
    static TransVouchBean *getTransBeanByNo(QString no);
    static int delTransByNo(TransVouchBean *bean);
    static int getTransCount();
    static int getTransRowNumber(int id);
    static int getTransCount(QDate date);
    static int getTransCountByNo(QString no);
    static QList<TransVouchBean *> queryTransByPage(int page ,int maxResult);
    static QList<TransVouchBean *> queryTransBy(QDate date);
    static QList<TransVouchBean *> queryTransBy(QDate start,QDate end);

    static int createTransVouchs(TransVouchsBean *bean);
    static int updateTransVouchs(TransVouchsBean *bean);
    static int delTransVouchs(TransVouchsBean *bean);
    static int delTransVouchsByNo(QString no);

    static QList<TransVouchsBean *> queryTransVouchsByNo(QString no);

    static QSqlQueryModel *queryModelTransBy(QString no);
    static QSqlQueryModel *queryModelTransBy(QDate start, QDate end);

};

#endif // TRANSDAO_H
