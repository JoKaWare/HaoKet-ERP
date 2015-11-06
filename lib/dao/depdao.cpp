#include "depdao.h"

DepDAO::DepDAO()
{
}

int DepDAO::createDep(DepBean *bean){
    QString sql="INSERT INTO ba_department("
            "dep_id, dep_name, dep_end, dep_grade, dep_superior, dep_person, "
            "dep_tel, dep_addr, memo)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int DepDAO::updateDep(DepBean *bean){
    QString sql="UPDATE ba_department "
            "SET dep_name=?, dep_end=?, dep_grade=?, dep_superior=?, "
            "    dep_person=?, dep_tel=?, dep_addr=?, memo=? "
            "WHERE dep_id='"+bean->depId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int DepDAO::delDep(DepBean *bean){
    QString sql="DELETE FROM ba_department "
            " WHERE dep_id='"+bean->depId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<DepBean *> DepDAO::queryDep(){
    QString sql="SELECT dep_id, dep_name, dep_end, dep_grade, dep_superior, dep_person, "
            "dep_tel, dep_addr, memo "
            "FROM ba_department order by dep_id asc";
    QueryRunner query=QueryRunner();
    QList<DepBean *> depList=query.query<DepBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<DepBean *> DepDAO::queryDepFirst(){
    QString sql="SELECT dep_id, dep_name, dep_end, dep_grade, dep_superior, dep_person, "
            "dep_tel, dep_addr, memo "
            "FROM ba_department WHERE dep_grade=1 order by dep_id asc";
    QueryRunner query=QueryRunner();
    QList<DepBean *> depList=query.query<DepBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<DepBean *> DepDAO::queryDepByEnd(){
    QString sql="SELECT dep_id, dep_name, dep_end, dep_grade, dep_superior, dep_person, "
            "dep_tel, dep_addr, memo "
            "FROM ba_department WHERE dep_end='true' order by dep_id asc";
    QueryRunner query=QueryRunner();
    QList<DepBean *> depList=query.query<DepBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}
QList<DepBean *> DepDAO::queryDepBy(QString id){
    QString sql="SELECT dep_id, dep_name, dep_end, dep_grade, dep_superior, dep_person, "
            "dep_tel, dep_addr, memo "
            "FROM ba_department WHERE dep_grade=2 and dep_superior='"+id+"' order by dep_id asc";
    QueryRunner query=QueryRunner();
    QList<DepBean *> depList=query.query<DepBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}
DepBean *DepDAO::getDepById(QString id){
    QString sql="SELECT dep_id, dep_name, dep_end, dep_grade, dep_superior, dep_person, "
            "dep_tel, dep_addr, memo "
            "FROM ba_department where dep_id='"+id+"'";
    QueryRunner query=QueryRunner();
    DepBean *dBean= new DepBean;
    return query.read<DepBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
