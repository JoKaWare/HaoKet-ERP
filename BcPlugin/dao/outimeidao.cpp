#include "outimeidao.h"

OutImeiDAO::OutImeiDAO()
{
}

int OutImeiDAO::createImei(RdInImeiBean *bean){
    QString sql = "INSERT INTO rd_out_imei( "
            " imei, msn, no, src_no, vouchs_id, vouch_type, wh_code, bus_code,"
            " product_code, bus_date, created, creater, memo)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int OutImeiDAO::updateImei(RdInImeiBean *bean){
    QString sql = "UPDATE rd_out_imei "
            " SET imei=?, msn=?, no=?, src_no=?, vouchs_id=?, vouch_type=?, wh_code=?, "
               " bus_code=?, product_code=?, bus_date=?, created=?, creater=?, "
               " memo=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int OutImeiDAO::delImei(RdInImeiBean *bean){
    QString sql = "DELETE FROM rd_out_imei "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int OutImeiDAO::delImeiByIdx(QString idx){
    QString sql = "DELETE FROM rd_out_imei "
            " WHERE vouchs_id=" + idx;
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int OutImeiDAO::delImeiByNo(QString no){
    QString sql = "DELETE FROM rd_out_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int OutImeiDAO::getImeiCountByIdx(QString idx){
    if(idx.length() < 1) idx = "";
    QString sql = "SELECT count(*) FROM rd_out_imei "
            " WHERE vouchs_id=" + idx;
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int OutImeiDAO::getImeiCountByNo(QString no){
    QString sql = "SELECT count(*) FROM rd_out_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<RdInImeiBean *> OutImeiDAO::queryImeiBy(QString idx){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.vouch_type, a.wh_code, a.bus_code, a.src_no, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM rd_out_imei a, ba_product b WHERE vouchs_id=" + idx + " AND a.product_code=b.product_code ORDER BY a.id";

    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> OutImeiDAO::queryImeiByNo(QString no){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.vouch_type, a.wh_code, a.bus_code, a.src_no, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM rd_out_imei a, ba_product b WHERE a.no='" + no + "' AND a.product_code=b.product_code ORDER BY a.vouchs_id";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> OutImeiDAO::queryImeiByImei(QString imei){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.vouch_type, a.wh_code, a.bus_code, a.src_no, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM rd_out_imei a, ba_product b WHERE a.imei='" + imei + "' AND a.product_code=b.product_code ORDER BY a.vouchs_id";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> OutImeiDAO::queryImeiIsStock(QString no){
    QString sql = "SELECT a.* FROM rd_out_imei a, stock_imei b where a.no='" + no + "' AND a.imei= b.imei";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> OutImeiDAO::queryImeiNotStock(QString no){
    QString sql = "SELECT a.* FROM rd_out_imei a where a.no='" + no + "' AND a.imei NOT IN (SELECT imei FROM stock_imei) ";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> OutImeiDAO::queryImeiNotStock(QString no,QString whCode){
    QString sql = "SELECT a.* FROM rd_out_imei a where a.no='" + no +
            "' AND a.imei NOT IN (SELECT imei FROM stock_imei WHERE wh_code='" + whCode + "') ";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

