#include "dinnerdao.h"
#include <QObject>
DinnerDAO::DinnerDAO()
{
}

int DinnerDAO::createDinner(DinnerBean *bean){
    QString sql="INSERT INTO ba_dinner("
            "dinner_id, dinner_name, area_id, dinner_type, number, is_service, lost_consumption, memo)"
            " VALUES (?,?,?,?,?,?,?,?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int DinnerDAO::updateDinner(DinnerBean *bean){
    QString sql="UPDATE ba_dinner "
            " SET id=?, dinner_id=?, dinner_name=?, area_id=?, dinner_type=?, number=?,is_service=?, lost_consumption=?, memo=?"
            " WHERE id="+QString::number(bean->id());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int DinnerDAO::delDinner(DinnerBean *bean){
    QString sql="DELETE FROM ba_dinner "
            " WHERE dinner_id='"+bean->dinnerId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<DinnerBean *> DinnerDAO::queryDinner(){
    QString sql="SELECT id, dinner_id, dinner_name, area_id, dinner_type, number, is_service, lost_consumption, memo  "
            " FROM ba_dinner order by dinner_id asc";
    QueryRunner query=QueryRunner();
    QList<DinnerBean *> list=query.query<DinnerBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<DinnerBean *> DinnerDAO::queryDinnerByAreaId(QString id){
    QString sql="SELECT id, dinner_id, dinner_name, area_id, dinner_type, number, is_service, lost_consumption, memo  "
            " FROM ba_dinner WHERE area_id="+id+" order by id asc";
    QueryRunner query=QueryRunner();
    QList<DinnerBean *> list=query.query<DinnerBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

DinnerBean *DinnerDAO::getDinnerById(QString id){
    QString sql="SELECT id, dinner_id, dinner_name, area_id, dinner_type, number, is_service, lost_consumption, memo "
            " FROM ba_dinner where dinner_id='"+id+"'";
    QueryRunner query=QueryRunner();
    DinnerBean *dBean= new DinnerBean;
    return query.read<DinnerBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
