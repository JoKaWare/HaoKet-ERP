#include "areadao.h"

AreaDAO::AreaDAO()
{
}

int AreaDAO::createArea(AreaBean *bean){
    QString sql="INSERT INTO ba_dinner_area("
            "area_name, area_explian)"
            " VALUES (?, ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int AreaDAO::updateArea(AreaBean *bean){
    QString sql="UPDATE ba_dinner_area "
            "SET area_name=?, area_explian=? "
            "WHERE area_id="+QString::number(bean->areaId());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int AreaDAO::delArea(AreaBean *bean){
    QString sql="DELETE FROM ba_dinner_area "
            " WHERE area_id="+QString::number(bean->areaId());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<AreaBean *> AreaDAO::queryArea(){
    QString sql="SELECT area_id, area_name, area_explian "
            " FROM ba_dinner_area order by area_id asc";
    QueryRunner query=QueryRunner();
    QList<AreaBean *> depList=query.query<AreaBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

AreaBean *AreaDAO::getAreaById(QString id){
    QString sql="SELECT area_id, area_name, area_explian  "
            " FROM ba_dinner_area where area_id="+id;
    QueryRunner query=QueryRunner();
    AreaBean *dBean= new AreaBean;
    return query.read<AreaBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
