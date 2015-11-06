#include "stockdao.h"

StockDAO::StockDAO()
{

}

int StockDAO::createStock(StockBean *bean){
    QString sql = "INSERT INTO stock("
                  " product_code, wh_code, style, position_code, unit, sum, ready_sum, "
                  " can_sum, status, memo)"
                  " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);

}

int StockDAO::updateStock(StockBean *bean){
    QString sql = "UPDATE stock"
                " SET product_code=?, wh_code=?, style=?, position_code=?, unit=?,"
                " sum=?, ready_sum=?, can_sum=?, status=?, memo=?"
                " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StockDAO::delStock(StockBean *bean){
    QString sql = "DELETE FROM stock "
                " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<StockBean *> StockDAO::queryStock(){
    QString sql = "SELECT id, product_code, wh_code, style, position_code, unit, sum, ready_sum, "
                " can_sum, status, memo"
                " FROM stock";
    QueryRunner query=QueryRunner();
    QList<StockBean *> pList = query.query<StockBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

StockBean * StockDAO::getStockById(QString id){
    QString sql = "SELECT id, product_code, wh_code, style, position_code, unit, sum, ready_sum, "
                " can_sum, status, memo"
                " FROM stock WHERE id=" + id;
    QueryRunner query = QueryRunner();
    StockBean *dBean = new StockBean;
    return query.read<StockBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

StockBean * StockDAO::getStockBy(QString whCode, QString productCode){
    QString sql = "SELECT id, product_code, wh_code, style, position_code, unit, sum, ready_sum, "
                " can_sum, status, memo"
            " FROM stock WHERE wh_code='" + whCode + "' AND product_code='" + productCode + "'" ;
    QueryRunner query = QueryRunner();
    StockBean *dBean = new StockBean;
    return query.read<StockBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

QList<StockBean *> StockDAO::queryStockBy(QString typeCode){
    QString sql = "SELECT a.id, a.wh_code, d.wh_name,a.position_code, a.product_code, a.product_name,a.style, a.unit, "
            "  a.sum, a.ready_sum, a.can_sum "
            " FROM (SELECT c.*,b.product_name FROM stock c INNER JOIN product b ON c.product_code=b.product_code"
            " WHERE b.type_id like '"+ typeCode+"%') a INNER JOIN ware_house d ON a.wh_code= d.wh_code"
            " ORDER BY d.wh_name,a.product_code ASC";

    QueryRunner query=QueryRunner();
    QList<StockBean *> pList = query.query<StockBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

QList<StockBean *> StockDAO::queryStockByWh(QString whCode){
    QString sql = "SELECT a.*,a.sum-a.c_sum+a.r_sum as can_sum FROM st_stock_query a "
                "WHERE wh_code='" + whCode + "'";
    QueryRunner query  =QueryRunner();
    QList<StockBean *> list = query.query<StockBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<StockBean *> StockDAO::queryStockBy(QString whCode, QString typeCode, QString name, QString pinyin){
    QString sql = "SELECT a.id, a.wh_code, d.wh_name,a.position_code, a.product_code, a.product_name,a.style, a.unit, "
            "  a.sum, a.ready_sum, a.can_sum "
            " FROM (SELECT c.*,b.product_name FROM stock c INNER JOIN product b ON c.product_code=b.product_code"
            " WHERE b.type_id like '"+ typeCode+"%' AND b.product_name like '%" + name + "%'"
            " AND b.pinyin_code LIKE '%" + pinyin +  + "%') a INNER JOIN ware_house d ON a.wh_code= d.wh_code"
            " WHERE a.wh_code like '%" + whCode + "' ORDER BY d.wh_name,a.product_code ASC";

    QueryRunner query=QueryRunner();
    QList<StockBean *> pList = query.query<StockBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

QSqlQueryModel* StockDAO::querySqlModelStockBy(QString whCode,QString typeCode, QString name, QString pinyin){
    QString sql = "SELECT a.id, a.wh_code, d.wh_name,a.position_code, a.product_code, a.product_name,a.style, a.unit, "
            "  a.sum, a.ready_sum, a.can_sum ,a.can_sum "
            " FROM (SELECT c.*,b.product_name FROM stock c INNER JOIN product b ON c.product_code=b.product_code"
            " WHERE b.type_id like '"+ typeCode+"%' AND b.product_name like '%" + name + "%'"
            " AND b.pinyin_code LIKE '%" + pinyin +  + "%') a INNER JOIN ware_house d ON a.wh_code= d.wh_code"
            " WHERE a.wh_code like '%" + whCode + "' ORDER BY d.wh_name,a.product_code ASC";
    Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
    logger->debug(sql);
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Warehouse Code"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Warehouse Name"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Position"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Product Code"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Product Name"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Style"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Stock Unit"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Stock Sum"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Ready Sum"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("Can Sum"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("Ready In Sum"));
    return model;
}

QSqlQueryModel* StockDAO::queryModelReInStock(){
    QString sql = "SELECT c.*,c.sum*d.pu_st_unit as read_sum,d.pu_st_unit "
                " FROM (SELECT a.wh_code,b.product_code,b.unit,sum(b.quantity) as sum "
                " FROM rd_record a INNER JOIN rd_records b ON a.rd_no=b.rd_no where rd_flag=1 "
              " and handler='' GROUP BY a.wh_code,b.product_code,b.unit) c "
              " INNER JOIN product d ON c.product_code=d.product_code";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    return model;
}

QSqlQueryModel* StockDAO::queryModelReOutStock(){
    QString sql = "SELECT c.*,c.sum*d.pu_st_unit as read_sum,d.pu_st_unit "
                " FROM (SELECT a.wh_code,b.product_code,b.unit,sum(b.quantity) as sum "
                " FROM rd_record a INNER JOIN rd_records b ON a.rd_no=b.rd_no where rd_flag=2 "
              " and handler='' GROUP BY a.wh_code,b.product_code,b.unit) c "
              " INNER JOIN product d ON c.product_code=d.product_code";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    return model;
}
