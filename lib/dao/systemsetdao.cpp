#include "systemsetdao.h"

SystemSetDAO::SystemSetDAO()
{
}

int SystemSetDAO::createSystemSet(SystemSetBean *bean){
    QString sql = "INSERT INTO system_set( "
            " id, sub_id, name, value, caption, yes_no, memo) "
            " VALUES (?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SystemSetDAO::updateSystemSet(SystemSetBean *bean){
    QString sql = "UPDATE system_set "
             " SET value=?,name=?,caption=?, yes_no=?, memo=?, sub_id=? "
            " WHERE id ='" + bean->id() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SystemSetDAO::delSystemSet(SystemSetBean *bean){
    QString sql = "DELETE FROM  system_set "
                " WHERE id ='" + bean->id() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

SystemSetBean * SystemSetDAO::getBean(QString id){
    QString sql = "SELECT id, sub_id, name, value, caption, yes_no, memo "
                " FROM system_set "
                " WHERE id ='" + id + "'";
    QueryRunner query=QueryRunner();
    SystemSetBean *qBean= new SystemSetBean();
    return query.read<SystemSetBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

QList<SystemSetBean *> SystemSetDAO::queryBean(){
    QString sql = "SELECT id, sub_id, name, value, caption, yes_no, memo "
                " FROM system_set ";
    QueryRunner query  =QueryRunner();
    QList<SystemSetBean *> list = query.query<SystemSetBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

