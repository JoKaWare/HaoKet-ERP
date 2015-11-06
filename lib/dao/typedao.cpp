#include "typedao.h"

TypeDAO::TypeDAO()
{
}


int TypeDAO::createType(TypeBean *bean){
    QString sql="INSERT INTO ba_type("
            "type_id, type_name, type_end, type_grade, type_superior, explian, is_disc, low_discount, memo )"
            " VALUES (?,?,?,?,?,?,?,?,?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TypeDAO::updateType(TypeBean *bean){
    QString sql="UPDATE ba_type "
            "SET type_name=?,type_end=?, type_grade=?, type_superior=?, explian=?, is_disc=?, low_discount=?, memo=?  "
            " WHERE type_id='"+bean->typeId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TypeDAO::delType(TypeBean *bean){
    QString sql="DELETE FROM ba_type "
            " WHERE type_id='"+bean->typeId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<TypeBean *> TypeDAO::queryType(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, is_disc, low_discount, memo  "
            " FROM ba_type order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<TypeBean *> depList=query.query<TypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<TypeBean *> TypeDAO::queryTypeBy(QString id){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, is_disc, low_discount, memo  "
            " FROM ba_type WHERE type_grade=2 AND type_superior='"+id+"' order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<TypeBean *> depList=query.query<TypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<TypeBean *> TypeDAO::queryTypeByFirst(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, is_disc, low_discount, memo  "
            " FROM ba_type WHERE type_grade=1 order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<TypeBean *> depList=query.query<TypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<TypeBean *> TypeDAO::queryTypeByEnd(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, is_disc, low_discount, memo  "
            " FROM ba_type WHERE type_end='true' order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<TypeBean *> depList=query.query<TypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}
TypeBean *TypeDAO::getTypeById(QString id){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, is_disc, low_discount, memo  "
            " FROM ba_type where type_id='"+id+"'";
    QueryRunner query=QueryRunner();
    TypeBean *dBean= new TypeBean;
    return query.read<TypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

