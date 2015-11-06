#include "inimeidao.h"

InImeiDAO::InImeiDAO()
{
}

int InImeiDAO::createImei(RdInImeiBean *bean){
    QString sql = "INSERT INTO rd_in_imei( "
            " imei, msn, no, src_no, vouchs_id, vouch_type, wh_code, bus_code,"
            " product_code, bus_date, created, creater, memo)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int InImeiDAO::updateImei(RdInImeiBean *bean){
    QString sql = "UPDATE rd_in_imei "
            " SET imei=?, msn=?, no=?, src_no=?, vouchs_id=?, vouch_type=?, wh_code=?, "
               " bus_code=?, product_code=?, bus_date=?, created=?, creater=?, "
               " memo=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int InImeiDAO::delImei(RdInImeiBean *bean){
    QString sql = "DELETE FROM rd_in_imei "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int InImeiDAO::delImeiByIdx(QString idx){
    QString sql = "DELETE FROM rd_in_imei "
            " WHERE vouchs_id=" + idx;
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int InImeiDAO::delImeiByNo(QString no){
    QString sql = "DELETE FROM rd_in_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int InImeiDAO::getImeiCountByIdx(QString idx){
    if(idx.length() < 1) idx = "";
    QString sql = "SELECT count(*) FROM rd_in_imei "
            " WHERE vouchs_id=" + idx;
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int InImeiDAO::getImeiCountByNo(QString no){
    QString sql = "SELECT count(*) FROM rd_in_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<RdInImeiBean *> InImeiDAO::queryImeiBy(QString idx){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.vouch_type, a.wh_code, a.bus_code, a.src_no, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM rd_in_imei a, ba_product b WHERE vouchs_id=" + idx + " AND a.product_code=b.product_code ORDER BY a.id";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> InImeiDAO::queryImeiByNo(QString no){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.vouch_type, a.wh_code, a.bus_code, a.src_no, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM rd_in_imei a, ba_product b WHERE a.no='" + no + "' AND a.product_code=b.product_code ORDER BY a.vouchs_id";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> InImeiDAO::queryImeiIsStock(QString no){
    QString sql = "SELECT a.* FROM rd_in_imei a, stock_imei b where a.no='" + no + "' AND a.imei= b.imei";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> InImeiDAO::queryImeiNotStock(QString no){
    QString sql = "SELECT a.* FROM rd_in_imei a where a.no='" + no + "' AND a.imei NOT IN (SELECT imei FROM stock_imei) ";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> InImeiDAO::queryImeiNotStock(QString no,QString whCode){
    QString sql = "SELECT a.* FROM rd_in_imei a where a.no='" + no +
            "' AND a.imei NOT IN (SELECT imei FROM stock_imei WHERE no='" + no +"' AND wh_code='" + whCode + "') ";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}
