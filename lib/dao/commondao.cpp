#include "commondao.h"

CommonDAO::CommonDAO()
{
}

QList<UnitBean *> CommonDAO::queryUnit(){
    QString sql="SELECT id, unit_name, translated_unit, scalings"
                " FROM ba_unit ORDER BY id ASC";
    QueryRunner query=QueryRunner();
    QList<UnitBean *> pList = query.query<UnitBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;

}

QList<DefineBean *> CommonDAO::queryDefine(){
    QString sql="SELECT id, code, name, describe, is_view "
                " FROM ba_define ORDER BY id ASC";
    QueryRunner query=QueryRunner();
    QList<DefineBean *> pList = query.query<DefineBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}
