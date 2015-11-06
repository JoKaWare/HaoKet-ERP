#include "supplietypedao.h"

SupplieTypeDAO::SupplieTypeDAO()
{
}

int SupplieTypeDAO::createType(SupplieTypeBean *bean){
    QString sql="INSERT INTO ba_supplie_type("
            "type_id, type_name, type_end, type_grade, type_superior, explian, memo )"
            " VALUES (?,?,?,?,?,?,?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SupplieTypeDAO::updateType(SupplieTypeBean *bean){
    QString sql="UPDATE ba_supplie_type "
            "SET type_name=?,type_end=?, type_grade=?, type_superior=?, explian=?, memo=?  "
            " WHERE type_id='"+bean->typeId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SupplieTypeDAO::delType(SupplieTypeBean *bean){
    QString sql="DELETE FROM ba_supplie_type "
            " WHERE type_id='"+bean->typeId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<SupplieTypeBean *> SupplieTypeDAO::queryType(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_supplie_type order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<SupplieTypeBean *> depList=query.query<SupplieTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<SupplieTypeBean *> SupplieTypeDAO::queryTypeBy(QString id){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_supplie_type WHERE type_grade=2 AND type_superior='"+id+"' order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<SupplieTypeBean *> depList=query.query<SupplieTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<SupplieTypeBean *> SupplieTypeDAO::queryTypeByFirst(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_supplie_type WHERE type_grade=1 order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<SupplieTypeBean *> depList=query.query<SupplieTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<SupplieTypeBean *> SupplieTypeDAO::queryTypeByEnd(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_supplie_type WHERE type_end='true' order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<SupplieTypeBean *> depList=query.query<SupplieTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}
SupplieTypeBean *SupplieTypeDAO::getTypeById(QString id){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_supplie_type where type_id='"+id+"'";
    QueryRunner query=QueryRunner();
    SupplieTypeBean *dBean= new SupplieTypeBean;
    return query.read<SupplieTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
