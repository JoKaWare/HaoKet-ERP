#include "accountdao.h"
#include "db/queryrunner.h"
#include "db/abstractqueryrunner.h"
#include "common/dbmanager.h"
AccountDAO::AccountDAO()
{
}

int AccountDAO::createAccount(AccountBean *abean){
    QString sql="INSERT INTO ad_account (ad_system_id, name, description, acc_path, acc_master, "
            "year, month, unit_name, unit_abbre, unit_addr, unit_zip, unit_tel, "
            "unit_fax, unit_email, unit_taxno, unit_lp, domain, "
            "created, created_by, updated, updated_by, start_date, end_date,is_action) "
            " VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, "
            "?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getDBConnection(),sql,abean);
}

QList<AccountBean *> AccountDAO::queryAccount(){

    QString sql="select ad_account_id, ad_system_id, name, description, acc_path, acc_master, "
            "year, month, unit_name, unit_abbre, unit_addr, unit_zip, unit_tel, "
            "unit_fax, unit_email, unit_taxno, unit_lp, domain, created, created_by, updated,"
            " updated_by, start_date, end_date,is_action from ad_account order by ad_system_id desc";
    QueryRunner query=QueryRunner();
    QList<AccountBean *> accountList=query.query<AccountBean>(DBManager::getDBManager()->getDBConnection(),sql);
    return accountList;
}

AccountBean *AccountDAO::getAccountById(QString id){
    QString sql="select ad_account_id, ad_system_id, name, description, acc_path, acc_master, "
            "year, month, unit_name, unit_abbre, unit_addr, unit_zip, unit_tel, "
            "unit_fax, unit_email, unit_taxno, unit_lp, domain, created, created_by, updated,"
            " updated_by, start_date, end_date,is_action from ad_account where ad_system_id='"+id+"'";
    QueryRunner query=QueryRunner();
    AccountBean *accBean= new AccountBean;
    return query.read<AccountBean>(DBManager::getDBManager()->getDBConnection(),sql,accBean);
}
