#include "customertypedao.h"

CustomerTypeDAO::CustomerTypeDAO()
{
}


int CustomerTypeDAO::createType(CustomerTypeBean *bean){
    QString sql="INSERT INTO ba_customer_type("
            "type_id, type_name, type_end, type_grade, type_superior, explian, memo )"
            " VALUES (?,?,?,?,?,?,?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int CustomerTypeDAO::updateType(CustomerTypeBean *bean){
    QString sql="UPDATE ba_customer_type "
            "SET type_name=?,type_end=?, type_grade=?, type_superior=?, explian=?, memo=?  "
            " WHERE type_id='"+bean->typeId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int CustomerTypeDAO::delType(CustomerTypeBean *bean){
    QString sql="DELETE FROM ba_customer_type "
            " WHERE type_id='"+bean->typeId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<CustomerTypeBean *> CustomerTypeDAO::queryType(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_customer_type order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<CustomerTypeBean *> depList=query.query<CustomerTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<CustomerTypeBean *> CustomerTypeDAO::queryTypeBy(QString id){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_customer_type WHERE type_grade>=2 AND type_superior='"+id+"' order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<CustomerTypeBean *> depList=query.query<CustomerTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<CustomerTypeBean *> CustomerTypeDAO::queryTypeByFirst(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_customer_type WHERE type_grade=1 order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<CustomerTypeBean *> depList=query.query<CustomerTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<CustomerTypeBean *> CustomerTypeDAO::queryTypeByEnd(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_customer_type WHERE type_end='true' order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<CustomerTypeBean *> depList=query.query<CustomerTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}
CustomerTypeBean *CustomerTypeDAO::getTypeById(QString id){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo  "
            " FROM ba_customer_type where type_id='"+id+"'";
    QueryRunner query=QueryRunner();
    CustomerTypeBean *dBean= new CustomerTypeBean;
    return query.read<CustomerTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

