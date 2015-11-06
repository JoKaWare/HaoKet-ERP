#include "kmcodedao.h"

KmCodeDAO::KmCodeDAO()
{
}

int KmCodeDAO::createKmCode(KmCodeBean *bean){
    QString sql = "INSERT INTO ba_kcode( "
                " km_code, km_name, grade, code, is_end, property, km_explain, "
                " is_cus, is_sup, is_cash, is_bank)"
        " VALUES (?, ?, ?, ?, ?, ?, ?, "
                " ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int KmCodeDAO::updateKmCode(KmCodeBean *bean){

    QString sql = "UPDATE ba_kcode "
                " SET km_name=?, grade=?, code=?, is_end=?, property=?, "
                " km_explain=?, is_cus=?, is_sup=?, is_cash=?, is_bank=? "
            " WHERE km_code='" +bean->kmCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int KmCodeDAO::delKmCode(KmCodeBean *bean){
    QString sql = "DELETE FROM ba_kcode "
            " WHERE km_code='" +bean->kmCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

KmCodeBean *KmCodeDAO::getKmCode(QString code){
    QString sql = "SELECT * FROM ba_kcode"
            " WHERE km_code='" + code + "'";
    QueryRunner query=QueryRunner();
    KmCodeBean *qBean= new KmCodeBean;
    return query.read<KmCodeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}
QList<KmCodeBean *> KmCodeDAO::queryKmCode(){
    QString sql = "SELECT * FROM ba_kcode";

    QueryRunner query  =QueryRunner();
    QList<KmCodeBean *> list = query.query<KmCodeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<KmCodeBean *> KmCodeDAO::queryKmCodeFirst(){
    QString sql = "SELECT * FROM ba_kcode WHERE grade=1 ORDER BY km_code ASC ";

    QueryRunner query  =QueryRunner();
    QList<KmCodeBean *> list = query.query<KmCodeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<ApTypeBean *> KmCodeDAO::queryApType(int flag){
    QString sql = "SELECT * FROM ba_ap_type WHERE flag=" + QString::number(flag) + " ORDER BY type_code ASC ";

    QueryRunner query  =QueryRunner();
    QList<ApTypeBean *> list = query.query<ApTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SettleTypeBean *> KmCodeDAO::querySettleType(){
    QString sql = "SELECT * FROM ba_settle_type ORDER BY id ASC ";
    QueryRunner query  =QueryRunner();
    QList<SettleTypeBean *> list = query.query<SettleTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

