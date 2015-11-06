#include "basedao.h"

BaseDAO::BaseDAO()
{
}

int BaseDAO::getRdByCus(QString code){
    QString sql = "SELECT count(*) FROM rd_record WHERE cus_code='" + code + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int BaseDAO::getRdByEmp(QString code){
    QString sql = "SELECT count(*) FROM rd_record WHERE person_code='" + code + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int BaseDAO::getRdByInv(QString code){
    QString sql = "SELECT count(*) FROM rd_records WHERE product_code='" + code + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int BaseDAO::getRdByVen(QString code){
    QString sql = "SELECT count(*) FROM rd_record WHERE supplier_id='" + code + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int BaseDAO::getRdByWh(QString code){
    QString sql = "SELECT count(*) FROM rd_record WHERE wh_code='" + code + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}
