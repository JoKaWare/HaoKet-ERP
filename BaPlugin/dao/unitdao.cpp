#include "unitdao.h"

UnitDAO::UnitDAO()
{
}


int UnitDAO::createUnit(UnitBean *bean){
    QString sql = "INSERT INTO ba_unit( "
            " unit_name, translated_unit, scalings)"
        " VALUES (?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int UnitDAO::updateUnit(UnitBean *bean){

    QString sql = "UPDATE ba_unit "
                " SET unit_name=?, translated_unit=?, scalings=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int UnitDAO::delUnit(UnitBean *bean){
    QString sql = "DELETE FROM ba_unit "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

UnitBean *UnitDAO::getUnit(QString id){
    QString sql = "SELECT id, unit_name, translated_unit, scalings FROM ba_unit"
            " WHERE id=" + id;
    QueryRunner query=QueryRunner();
    UnitBean *qBean= new UnitBean;
    return query.read<UnitBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}
QList<UnitBean *> UnitDAO::queryUnit(){
    QString sql = "SELECT id, unit_name, translated_unit, scalings FROM ba_unit";

    QueryRunner query  =QueryRunner();
    QList<UnitBean *> list = query.query<UnitBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}
