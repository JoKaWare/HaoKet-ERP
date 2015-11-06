#include "sarddao.h"

SaRdDAO::SaRdDAO()
{
}

int SaRdDAO::getRdImeiCount(QString no){
    QString sql = "SELECT count(*) FROM rd_out_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<StockBean *> SaRdDAO::queryStockBy(QString whCode){
    QString sql = "SELECT a.*,a.sum-a.c_sum+a.r_sum as can_sum FROM st_stock_query a "
                "WHERE wh_code='" + whCode + "'";
    QueryRunner query  =QueryRunner();
    QList<StockBean *> list = query.query<StockBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}
