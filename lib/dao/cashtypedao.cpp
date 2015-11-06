#include "cashtypedao.h"

CashTypeDAO::CashTypeDAO()
{
}

int CashTypeDAO::createCashType(SettleTypeBean *bean){
    QString sql = " INSERT INTO settle_type("
                " id, settle_name, settle_nature, settle_caption) "
                " VALUES (?, ?, ?, ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int CashTypeDAO::updateCashType(SettleTypeBean *bean){
    QString sql = "UPDATE settle_type"
                " SET id=?, settle_name=?, settle_nature=?, settle_caption=? "
                " WHERE id="+QString::number(bean->id());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int CashTypeDAO::delCashType(SettleTypeBean *bean){
    QString sql="DELETE FROM settle_type "
            " WHERE id="+QString::number(bean->id());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<SettleTypeBean *> CashTypeDAO::queryCashType(){
    QString sql="SELECT id, settle_name, settle_nature, settle_caption "
            " FROM settle_type order by id asc";
    QueryRunner query=QueryRunner();
    QList<SettleTypeBean *> sList=query.query<SettleTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return sList;
}

SettleTypeBean *CashTypeDAO::getCashTypeById(QString id){
    QString sql = "SELECT id, settle_name, settle_nature, settle_caption  "
            " FROM settle_type where id="+id;
    QueryRunner query = QueryRunner();
    SettleTypeBean *dBean = new SettleTypeBean;
    return query.read<SettleTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

SettleTypeBean *CashTypeDAO::getCashTypeByName(QString name){
    QString sql = "SELECT id, settle_name, settle_nature, settle_caption  "
            " FROM settle_type where settle_name='" + name + "'";
    QueryRunner query = QueryRunner();
    SettleTypeBean *dBean = new SettleTypeBean;
    return query.read<SettleTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
