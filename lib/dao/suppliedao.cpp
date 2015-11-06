#include "suppliedao.h"

SupplieDAO::SupplieDAO()
{
}

int SupplieDAO::createSupplie(SupplieBean *bean){
    QString sql="INSERT INTO ba_suppliers("
            "supplie_code, supplie_name, supplie_explian, supplie_type, addr, "
            "linkman, link_func, link_phone, tax, bank, bank_card, bank_name, "
            "memo, created_by, created, updated_by, updated,status) "
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?, ?, ?, ?, ?, ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SupplieDAO::updateSupplie(SupplieBean *bean){
    QString sql="UPDATE ba_suppliers "
            "SET supplie_name=?, supplie_explian=?, supplie_type=?, "
            "addr=?, linkman=?, link_func=?, link_phone=?, tax=?, bank=?, "
            "bank_card=?, bank_name=?, memo=?, updated_by=?, updated=?, status=? "
            " WHERE supplie_code ='" + bean->supplieCode() + "'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SupplieDAO::delSupplie(SupplieBean *bean){
    QString sql="DELETE FROM ba_suppliers "
            " WHERE supplie_code ='" + bean->supplieCode() + "'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<SupplieBean *> SupplieDAO::querySupplie(){

    QString sql="SELECT supplie_id,supplie_code,  supplie_name, supplie_explian, supplie_type, addr, "
            "linkman, link_func, link_phone, tax, bank, bank_card, bank_name, "
            "memo, created_by, created, updated_by, updated,status "
            " FROM ba_suppliers WHERE status=0 order by supplie_id asc";
    QueryRunner query=QueryRunner();

    QList<SupplieBean *> list=query.query<SupplieBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SupplieBean *> SupplieDAO::querySupplieAll(){

    QString sql="SELECT supplie_id,supplie_code,  supplie_name, supplie_explian, supplie_type, addr, "
            "linkman, link_func, link_phone, tax, bank, bank_card, bank_name, "
            "memo, created_by, created, updated_by, updated,status "
            " FROM ba_suppliers order by supplie_id asc";
    QueryRunner query=QueryRunner();

    QList<SupplieBean *> list=query.query<SupplieBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}
SupplieBean * SupplieDAO::getSupplieById(QString id){

    QString sql="SELECT  supplie_id,supplie_code, supplie_name, supplie_explian, supplie_type, addr, "
            "linkman, link_func, link_phone, tax, bank, bank_card, bank_name, "
            "memo, created_by, created, updated_by, updated, status "
            " FROM ba_suppliers where supplier_id="+id;
    QueryRunner query=QueryRunner();

    SupplieBean *dBean= new SupplieBean;
    return query.read<SupplieBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);


}
SupplieBean * SupplieDAO::getSupplieByCode(QString code){

    QString sql="SELECT  supplie_id,supplie_code, supplie_name, supplie_explian, supplie_type, addr, "
            "linkman, link_func, link_phone, tax, bank, bank_card, bank_name, "
            "memo, created_by, created, updated_by, updated, status "
            " FROM ba_suppliers WHERE supplie_code ='" + code + "'";
    QueryRunner query=QueryRunner();

    SupplieBean *dBean= new SupplieBean;
    return query.read<SupplieBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);


}

