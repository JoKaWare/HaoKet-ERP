#include "possetdao.h"

PosSetDAO::PosSetDAO()
{
}

int PosSetDAO::createPosSet(PosSetBean *bean){
    QString sql = "INSERT INTO system_set( "
            " id, sub_id, name, value, caption, yes_no, memo) "
            " VALUES (?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int PosSetDAO::updatePosSet(PosSetBean *bean){
    QString sql = "UPDATE system_set "
             " SET value=?,name=?,caption=?, yes_no=?, memo=?, sub_id=? "
            " WHERE id ='" + bean->id() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int PosSetDAO::delPosSet(PosSetBean *bean){
    QString sql = "DELETE FROM  system_set "
                " WHERE id ='" + bean->id() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

PosSetBean * PosSetDAO::getBean(QString id){
    QString sql = "SELECT id, sub_id, name, value, caption, yes_no, memo "
                " FROM system_set "
                " WHERE id ='" + id + "'";
    QueryRunner query=QueryRunner();
    PosSetBean *qBean= new PosSetBean();
    return query.read<PosSetBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

QList<PosSetBean *> PosSetDAO::queryBean(){
    QString sql = "SELECT id, sub_id, name, value, caption, yes_no, memo "
                " FROM system_set ";
    QueryRunner query  =QueryRunner();
    QList<PosSetBean *> list = query.query<PosSetBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}
