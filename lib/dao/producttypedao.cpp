#include "producttypedao.h"

ProductTypeDAO::ProductTypeDAO()
{
}

int ProductTypeDAO::createType(ProductTypeBean *bean){
    QString sql="INSERT INTO ba_product_type("
            "type_id, type_name, type_end, type_grade, type_superior, explian, memo, low_discount, is_disc, is_dishes )"
            " VALUES (?,?,?,?,?,?,?,?,?,?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ProductTypeDAO::updateType(ProductTypeBean *bean){
    QString sql="UPDATE ba_product_type "
            "SET type_name=?,type_end=?, type_grade=?, type_superior=?, explian=?, memo=?,  "
            " low_discount=?, is_disc=?, is_dishes=? "
            " WHERE type_id='"+bean->typeId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ProductTypeDAO::delType(ProductTypeBean *bean){
    QString sql="DELETE FROM ba_product_type "
            " WHERE type_id='"+bean->typeId()+"'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<ProductTypeBean *> ProductTypeDAO::queryType(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo, low_discount, is_disc, is_dishes  "
            " FROM ba_product_type order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<ProductTypeBean *> depList=query.query<ProductTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<ProductTypeBean *> ProductTypeDAO::queryTypeBy(QString id){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo, low_discount, is_disc, is_dishes  "
            " FROM ba_product_type WHERE type_grade>=2 AND type_superior='"+id+"' order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<ProductTypeBean *> depList=query.query<ProductTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<ProductTypeBean *> ProductTypeDAO::queryTypeByFirst(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo, low_discount, is_disc, is_dishes  "
            " FROM ba_product_type WHERE type_grade=1 order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<ProductTypeBean *> depList=query.query<ProductTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<ProductTypeBean *> ProductTypeDAO::queryTypeByEnd(){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo, low_discount, is_disc, is_dishes  "
            " FROM ba_product_type WHERE type_end='true' order by type_id asc";
    QueryRunner query=QueryRunner();
    QList<ProductTypeBean *> depList=query.query<ProductTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}
ProductTypeBean *ProductTypeDAO::getTypeById(QString id){
    QString sql="SELECT type_id, type_name, type_end, type_grade, type_superior, explian, memo, low_discount, is_disc, is_dishes  "
            " FROM ba_product_type where type_id='"+id+"'";
    QueryRunner query=QueryRunner();
    ProductTypeBean *dBean= new ProductTypeBean;
    return query.read<ProductTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}


