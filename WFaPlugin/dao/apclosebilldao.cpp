#include "apclosebilldao.h"
#include <QDebug>
ApCloseBillDAO::ApCloseBillDAO()
{
}


int ApCloseBillDAO::createApCloseBill(ApCloseBillBean *bean){
    QString sql = "INSERT INTO ap_close_bill( "
            " ap_no, bus_date, bus_flag, vouch_type, bus_code, settle_code, dep_code, person_code, "
            " amount, digest, sum, km_code, bank_account, bank_name, contract_id,"
            " contract_name, is_voucher, handler, is_handle, audit_time, created_by,"
            " creater, created, updated_by, updater, updated, memo)"
        " VALUES ( ?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?,"
            " ?, ?, ?, ?, ?, ?,"
            " ?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ApCloseBillDAO::updateApCloseBill(ApCloseBillBean *bean){
    QString sql = "UPDATE ap_close_bill "
                " SET ap_no=?, bus_date=?, bus_flag=?, vouch_type=?, bus_code=?, dep_code=?, person_code=?, "
                " settle_code=?, amount=?, digest=?, sum=?, km_code=?, bank_account=?, "
                " bank_name=?, contract_id=?, contract_name=?, is_voucher=?, handler=?, "
                " is_handle=?, audit_time=?, created_by=?, creater=?, created=?, "
                " updated_by=?, updater=?, updated=?, memo=? "
                " WHERE ap_no='" + bean->apNo() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ApCloseBillDAO::delApCloseBill(ApCloseBillBean *bean){
    QString sql = "DELETE FROM ap_close_bill "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ApCloseBillDAO::delApCloseBillByNo(ApCloseBillBean *bean){
    QString sql = "DELETE FROM ap_close_bill "
            " WHERE ap_no='" + bean->apNo() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

ApCloseBillBean * ApCloseBillDAO::getApCloseBillByNo(QString no){
    QString sql = "SELECT * "
            " FROM ap_close_bill WHERE ap_no='" + no + "'";
    QueryRunner query=QueryRunner();
    ApCloseBillBean *qBean= new ApCloseBillBean;
    return query.read<ApCloseBillBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}
int ApCloseBillDAO::getApCloseBillCount(){
    QString sql = "SELECT count(*) FROM ap_close_bill ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ApCloseBillDAO::getApCloseBillCount(int flag){
    QString sql = "SELECT count(*) FROM ap_close_bill WHERE bus_flag=" + QString::number(flag);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ApCloseBillDAO::getApCloseBillRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by ap_no nulls last) as rownum, id"
            " from ap_close_bill "
            " order by ap_no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ApCloseBillDAO::getApCloseBillCount(QDate date){
    QString sql = "SELECT count(*) FROM ap_close_bill WHERE date_trunc('DAY', created)='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ApCloseBillDAO::getApCloseBillCountByNo(QString no){
    QString sql = "SELECT count(*) FROM ap_close_bill WHERE ap_no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<ApCloseBillBean *> ApCloseBillDAO::queryApCloseBillByPage(int page ,int maxResult){
    QString sql = "SELECT * "
            " FROM ap_close_bill ORDER BY ap_no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<ApCloseBillBean *> list = query.query<ApCloseBillBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<ApCloseBillBean *> ApCloseBillDAO::queryApCloseBillByPage(int page ,int maxResult,int bus_flag){
    QString sql = "SELECT * "
            " FROM ap_close_bill WHERE bus_flag=" + QString::number(bus_flag) + " ORDER BY ap_no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<ApCloseBillBean *> list = query.query<ApCloseBillBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<ApCloseBillBean *> ApCloseBillDAO::queryApCloseBillBy(QDate date){
    QString sql = "SELECT * "
            " FROM ap_close_bill WHERE bus_date='" + date.toString("yyyy-MM-dd")+ "'";
    QueryRunner query  =QueryRunner();
    QList<ApCloseBillBean *> list = query.query<ApCloseBillBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<ApCloseBillBean *> ApCloseBillDAO::queryApCloseBillBy(QDate start, QDate end){
    QString sql = "SELECT * "
            " FROM ap_close_bill WHERE bus_date>='" + start.toString("yyyy-MM-dd")+ "' AND bus_date<='" + end.toString("yyyy-MM-dd")+ "'";

    QueryRunner query  =QueryRunner();
    QList<ApCloseBillBean *> list = query.query<ApCloseBillBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int ApCloseBillDAO::createApCloseBills(ApCloseBillsBean *bean){
    QString sql = "INSERT INTO ap_close_bills("
            " ap_no, order_no, bus_no, bus_vouch, funds_type, km_code, "
            " digest, amount, sum, item_code, ap_bill )"
        " VALUES (?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
int ApCloseBillDAO::updateApCloseBills(ApCloseBillsBean *bean){
    QString sql = "UPDATE ap_close_bills "
                " SET ap_no=?, order_no=?, bus_no=?, bus_vouch=?, funds_type=?,"
                " km_code=?, digest=?, amount=?, sum=?, item_code=?, ap_bill=?  "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ApCloseBillDAO::delApCloseBills(ApCloseBillsBean *bean){
    QString sql = "DELETE FROM ap_close_bills "
            " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ApCloseBillDAO::delApCloseBillsByNo(QString no){
    QString sql = "DELETE FROM ap_close_bills "
            " WHERE ap_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

QList<ApCloseBillsBean *> ApCloseBillDAO::queryApCloseBillsByNo(QString no){
    QString sql = "SELECT a.*,b.km_name "
            " FROM ap_close_bills a INNER JOIN ba_kcode b on a.km_code=b.km_code WHERE ap_no='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<ApCloseBillsBean *> list = query.query<ApCloseBillsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}



