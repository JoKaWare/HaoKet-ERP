#include "stimeidao.h"

StImeiDAO::StImeiDAO()
{
}

int StImeiDAO::createImei(RdInImeiBean *bean){
    QString sql = "INSERT INTO stock_imei( "
            " imei, msn, no, vouchs_id, wh_code, bus_code,"
            " product_code, bus_date, created, creater, memo)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StImeiDAO::updateImei(RdInImeiBean *bean){
    QString sql = "UPDATE stock_imei "
            " SET imei=?, msn=?, no=?, vouchs_id=?, wh_code=?, "
               " bus_code=?, product_code=?, bus_date=?, created=?, creater=?, "
               " memo=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StImeiDAO::delImei(RdInImeiBean *bean){
    QString sql = "DELETE FROM stock_imei "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StImeiDAO::delImeiByIdx(QString idx){
    QString sql = "DELETE FROM stock_imei "
            " WHERE vouchs_id=" + idx;
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StImeiDAO::delImeiByImei(QString imei, QString whCode){
    QString sql = "DELETE FROM stock_imei "
            " WHERE imei='" + imei + "' AND wh_code='" + whCode + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StImeiDAO::delImeiByNo(QString no){
    QString sql = "DELETE FROM stock_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StImeiDAO::getImeiCountByIdx(QString idx){
    if(idx.length() < 1) idx = "";
    QString sql = "SELECT count(*) FROM stock_imei "
            " WHERE vouchs_id=" + idx;
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StImeiDAO::getImeiCountByNo(QString no){
    QString sql = "SELECT count(*) FROM stock_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StImeiDAO::getImeiCountByImei(QString imei){
    QString sql = "SELECT count(*) FROM stock_imei "
            " WHERE imei='" + imei + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StImeiDAO::getImeiCountByImei(QString imei, QString wh_code){
    QString sql = "SELECT count(*) FROM stock_imei "
            " WHERE imei='" + imei + "' AND wh_code='" + wh_code + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

RdInImeiBean *StImeiDAO::getStImeiBy(QString imei){
    QString sql = "SELECT * FROM stock_imei "
            " WHERE imei='" + imei + "'";
    QueryRunner query = QueryRunner();
    RdInImeiBean *qBean= new RdInImeiBean;
    return query.read<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

QList<RdInImeiBean *> StImeiDAO::queryImeiBy(QString idx){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.wh_code, a.bus_code, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM stock_imei a, ba_product b WHERE vouchs_id=" + idx + " AND a.product_code=b.product_code ORDER BY a.id";

    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdInImeiBean *> StImeiDAO::queryImeiByNo(QString no){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.wh_code, a.bus_code, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM stock_imei a, ba_product b WHERE a.no='" + no + "' AND a.product_code=b.product_code ORDER BY a.vouchs_id";
    QueryRunner query  =QueryRunner();
    QList<RdInImeiBean *> list = query.query<RdInImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

