#include "customerdao.h"
static QList<CustomerBean *> g_cusList;
static bool g_isCusLoad = false;
CustomerDAO::CustomerDAO()
{
}

int CustomerDAO::createCus(CustomerBean *bean){
    QString sql="INSERT INTO ba_customer("
            " cus_code, cus_name, cus_alias, cus_type, area_city, trade, pinyin_code,"
            " address, post, cus_reg_code, cus_bank, cus_account, dev_date,"
            " corporate, email, contacts, tel, fax, phone, cus_address, cus_person, dep_code,"
            " is_credit, cus_cre_grade, cus_cre_line, cus_cre_date, is_shop,"
            " licence_sdate, licence_edate, memo, cus_define1, cus_define2,"
            " cus_define3) "
        " VALUES (?, ?, ?, ?, ?, ?, "
          " ?, ?, ?, ?, ?, ?, ?, "
          " ?, ?, ?, ?, ?, ?, ?, ?, "
          " ?, ?, ?, ?, ?, ?, "
          " ?, ?, ?, ?, ?, "
          " ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int CustomerDAO::updateCus(CustomerBean *bean){
    QString sql="UPDATE ba_customer "
            " SET id=?, cus_code=?, cus_name=?, cus_alias=?, cus_type=?, area_city=?, pinyin_code=?, "
                " trade=?, address=?, post=?, cus_reg_code=?, cus_bank=?, cus_account=?, dep_code=?, "
                " dev_date=?, corporate=?, email=?, contacts=?, tel=?, fax=?, phone=?, "
                " cus_address=?, cus_person=?, is_credit=?, cus_cre_grade=?, cus_cre_line=?, "
                " cus_cre_date=?, is_shop=?, licence_sdate=?, licence_edate=?, "
                " memo=?, cus_define1=?, cus_define2=?, cus_define3=? "
            " WHERE cus_code ='" + bean->cusCode() + "'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int CustomerDAO::delCus(CustomerBean *bean){
    QString sql = "DELETE FROM ba_customer "
            " WHERE cus_code ='" + bean->cusCode() + "'";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}


QString CustomerDAO::getMaxId(){
    QString sql="SELECT cus_code FROM ba_customer ORDER BY cus_code DESC limit 1 offset 0;";
    QueryRunner query=QueryRunner();
    return query.getValue(DBManager::getDBManager()->getGoinDBConnection(),sql,"00000");
}

int CustomerDAO::getByTypeCount(QString type){
    QString sql="SELECT count(cus_code) FROM ba_customer WHERE cus_code like '" + type + "%'";
    QueryRunner query=QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<CustomerBean *> CustomerDAO::queryCus(){
    if(g_isCusLoad){
        return g_cusList;
    }else{
        g_isCusLoad = true;
        QString sql = "SELECT id, cus_code, cus_name, cus_alias, cus_type, area_city, trade, "
                " address, post, cus_reg_code, cus_bank, cus_account, dev_date, pinyin_code, "
                " corporate, email, contacts, tel, fax, phone, cus_address, cus_person, dep_code, "
                " is_credit, cus_cre_grade, cus_cre_line, cus_cre_date, is_shop, "
                " licence_sdate, licence_edate, memo, cus_define1, cus_define2, "
                " cus_define3 "
            " FROM ba_customer WHERE status=0 order by cus_code asc";
        QueryRunner query=QueryRunner();
        g_cusList = query.query<CustomerBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
        return g_cusList;
    }
}

QList<CustomerBean *> CustomerDAO::queryCusAll(){

    QString sql =  "SELECT id, cus_code, cus_name, cus_alias, cus_type, area_city, trade, "
            " address, post, cus_reg_code, cus_bank, cus_account, dev_date, pinyin_code, "
            " corporate, email, contacts, tel, fax, phone, cus_address, cus_person, dep_code,"
            " is_credit, cus_cre_grade, cus_cre_line, cus_cre_date, is_shop, "
            " licence_sdate, licence_edate, memo, cus_define1, cus_define2, "
            " cus_define3 "
            " FROM ba_customer order by cus_code asc";
    QueryRunner query=QueryRunner();

    QList<CustomerBean *> list=query.query<CustomerBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int CustomerDAO::getByCodeCount(QString code){
    QString sql="SELECT count(cus_code) FROM ba_customer WHERE cus_code='" + code + "'";
    QueryRunner query=QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

CustomerBean * CustomerDAO::getCusById(QString id){

    QString sql =  "SELECT id, cus_code, cus_name, cus_alias, cus_type, area_city, trade, "
            " address, post, cus_reg_code, cus_bank, cus_account, dev_date, pinyin_code, "
            " corporate, email, contacts, tel, fax, phone, cus_address, cus_person, dep_code,"
            " is_credit, cus_cre_grade, cus_cre_line, cus_cre_date, is_shop, "
            " licence_sdate, licence_edate, memo, cus_define1, cus_define2, "
            " cus_define3 "
            " FROM ba_customer where id="+id;
    QueryRunner query=QueryRunner();

    CustomerBean *dBean= new CustomerBean;
    return query.read<CustomerBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);


}
CustomerBean * CustomerDAO::getCusByCode(QString code){

    QString sql =  "SELECT id, cus_code, cus_name, cus_alias, cus_type, area_city, trade, "
            " address, post, cus_reg_code, cus_bank, cus_account, dev_date, pinyin_code, "
            " corporate, email, contacts, tel, fax, phone, cus_address, cus_person, dep_code, "
            " is_credit, cus_cre_grade, cus_cre_line, cus_cre_date, is_shop, "
            " licence_sdate, licence_edate, memo, cus_define1, cus_define2, "
            " cus_define3 "
            " FROM ba_customer WHERE cus_code ='" + code + "'";
    QueryRunner query=QueryRunner();

    CustomerBean *dBean= new CustomerBean;
    return query.read<CustomerBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);


}
