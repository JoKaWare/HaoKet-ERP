#include "waredao.h"

WareDAO::WareDAO()
{
}

int WareDAO::createWarehouse(WareHouseBean *bean){
    QString sql = "INSERT INTO ba_ware_house("
                "wh_code, wh_name, dep_code, wh_addr, wh_tel, wh_person, is_cargo,"
                "is_shop, memo) "
                " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int WareDAO::updateWarehouse(WareHouseBean *bean){
    QString sql = "UPDATE ba_ware_house "
                " SET wh_name=?, dep_code=?, wh_addr=?, wh_tel=?, wh_person=?, "
                " is_cargo=?, is_shop=?, memo=?"
                " WHERE wh_code='" + bean->whCode() + "'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int WareDAO::delWarehouse(WareHouseBean *bean){
    QString sql = "DELETE FROM ba_ware_house "
            " WHERE wh_code='" + bean->whCode() + "'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<WareHouseBean *> WareDAO::queryWarehouse(){
    QString sql = "SELECT wh_code, wh_name, dep_code, wh_addr, wh_tel, wh_person, is_cargo, "
            " is_shop, memo FROM ba_ware_house ORDER BY wh_code ASC";
    QueryRunner query=QueryRunner();
    QList<WareHouseBean *> list=query.query<WareHouseBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

WareHouseBean * WareDAO::getWarehouseById(QString code){
    QString sql = "SELECT wh_code, wh_name, dep_code, wh_addr, wh_tel, wh_person, is_cargo, "
                  " is_shop, memo FROM ba_ware_house"
                  " WHERE wh_code='" + code + "'";
    QueryRunner query=QueryRunner();
    WareHouseBean *dBean= new WareHouseBean;
    return query.read<WareHouseBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
