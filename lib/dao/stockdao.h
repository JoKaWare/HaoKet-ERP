#ifndef STOCKDAO_H
#define STOCKDAO_H
#include <QList>
#include <QSqlQueryModel>

#include "bean/StockBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"

class LIBSHARED_EXPORT StockDAO
{
public:
    StockDAO();
    static int createStock(StockBean *bean);
    static int updateStock(StockBean *bean);
    static int delStock(StockBean *bean);
    static QList<StockBean *> queryStock();

    static StockBean * getStockById(QString id);
    static StockBean * getStockBy(QString whCode,QString productCode);

    static QList<StockBean *> queryStockBy(QString whCode,QString typeCode, QString name, QString pinyin);
    static QList<StockBean *> queryStockBy(QString typeCode);
    static QList<StockBean *> queryStockByWh(QString whCode);
    static QSqlQueryModel *querySqlModelStockBy(QString whCode,QString typeCode, QString name, QString pinyin);
    static QSqlQueryModel *queryModelReInStock();
    static QSqlQueryModel *queryModelReOutStock();
};

#endif // STOCKDAO_H
