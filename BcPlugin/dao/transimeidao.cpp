#include "transimeidao.h"

TransImeiDAO::TransImeiDAO()
{
}

int TransImeiDAO::createImei(TransImeiBean *bean){
    QString sql = "INSERT INTO rd_trans_imei( "
            " imei, msn, no, src_no, vouchs_id, vouch_type, out_wh_code, in_wh_code, bus_code,"
            " product_code, bus_date, created, creater, memo)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TransImeiDAO::updateImei(TransImeiBean *bean){
    QString sql = "UPDATE rd_trans_imei "
            " SET imei=?, msn=?, no=?, src_no=?, vouchs_id=?, vouch_type=?, out_wh_code=?, "
               " in_wh_code=?, bus_code=?, product_code=?, bus_date=?, created=?, creater=?, "
               " memo=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TransImeiDAO::delImei(TransImeiBean *bean){
    QString sql = "DELETE FROM rd_trans_imei "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransImeiDAO::delImeiByIdx(QString idx){
    QString sql = "DELETE FROM rd_trans_imei "
            " WHERE vouchs_id=" + idx;
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransImeiDAO::updateImeiWh(QString no, QString owh_code, QString iwh_code){
    QString sql = "update stock_imei set wh_code='" + iwh_code + "' "
            " where imei in (SELECT imei FROM rd_trans_imei where no='" + no + "') "
            " and wh_code='" + owh_code + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}
int TransImeiDAO::delImeiByNo(QString no){
    QString sql = "DELETE FROM rd_trans_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransImeiDAO::getImeiCountByIdx(QString idx){
    if(idx.length() < 1) idx = "";
    QString sql = "SELECT count(*) FROM rd_trans_imei "
            " WHERE vouchs_id=" + idx;
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransImeiDAO::getImeiCountByNo(QString no){
    QString sql = "SELECT count(*) FROM rd_trans_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<TransImeiBean *> TransImeiDAO::queryImeiBy(QString idx){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.vouch_type, a.out_wh_code, a.in_wh_code, a.bus_code, a.src_no, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM rd_trans_imei a, ba_product b WHERE vouchs_id=" + idx + " AND a.product_code=b.product_code ORDER BY a.id";
    QueryRunner query  =QueryRunner();
    QList<TransImeiBean *> list = query.query<TransImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<TransImeiBean *> TransImeiDAO::queryImeiByNo(QString no){
    QString sql = "SELECT a.id, a.imei, msn, a.no, a.vouchs_id, a.vouch_type, a.out_wh_code, a.in_wh_code, a.bus_code, a.src_no, "
                " a.product_code, b.product_name, a.bus_date, a.created, a.creater, a.memo "
            " FROM rd_trans_imei a, ba_product b WHERE a.no='" + no + "' AND a.product_code=b.product_code ORDER BY a.vouchs_id";
    QueryRunner query  =QueryRunner();
    QList<TransImeiBean *> list = query.query<TransImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<TransImeiBean *> TransImeiDAO::queryImeiIsStock(QString no){
    QString sql = "SELECT a.* FROM rd_trans_imei a, stock_imei b where a.no='" + no + "' AND a.imei= b.imei";
    QueryRunner query  =QueryRunner();
    QList<TransImeiBean *> list = query.query<TransImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<TransImeiBean *> TransImeiDAO::queryImeiNotStock(QString no){
    QString sql = "SELECT a.* FROM rd_trans_imei a where a.no='" + no + "' AND a.imei NOT IN (SELECT imei FROM stock_imei) ";
    QueryRunner query  =QueryRunner();
    QList<TransImeiBean *> list = query.query<TransImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<TransImeiBean *> TransImeiDAO::queryImeiNotStock(QString no,QString whCode){
    QString sql = "SELECT a.* FROM rd_trans_imei a where a.no='" + no +
            "' AND a.imei NOT IN (SELECT imei FROM stock_imei WHERE  wh_code='" + whCode + "') ";
    QueryRunner query  =QueryRunner();
    QList<TransImeiBean *> list = query.query<TransImeiBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}


int TransImeiDAO::updateTrans(TransVouchBean *bean){
    QString sql = "UPDATE st_trans_vouch"
                " SET tv_date=?, owh_code=?, iwh_code=?, dep_code=?, is_handle=?, imei_audit=?, "
                " person_code=?, ord_no=?, ird_no=?, handler=?, audit_time=?, status=?, "
                " created_by=?, created=?, creater=?, updated_by=?, updated=?, memo=? "
            " WHERE tv_no='" + bean->tvNo() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
int TransImeiDAO::getTransCount(){
    QString sql = "SELECT count(*) FROM st_trans_vouch ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransImeiDAO::getTransCount(QDate date){
    QString sql = "SELECT count(*) FROM st_trans_vouch WHERE created='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransImeiDAO::getTransRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by tv_no nulls last) as rownum, id"
            " from st_trans_vouch "
            " order by tv_no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

TransVouchBean *TransImeiDAO::getTransBeanByNo(QString no){
    QString sql = "SELECT id, tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, imei_audit, "
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, creater, "
                " updated_by, updated, memo "
            " FROM st_trans_vouch WHERE tv_no='" + no + "'";
    QueryRunner query=QueryRunner();
    TransVouchBean *qBean= new TransVouchBean;
    return query.read<TransVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

QList<TransVouchBean *> TransImeiDAO::queryTransByPage(int page, int maxResult){
    int offset = 0;
    if(page < 0){
        offset = 0;
    }else offset = page;
    QString sql = "SELECT id, tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, imei_audit, "
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, creater, "
                " updated_by, updated, memo "
            " FROM st_trans_vouch ORDER BY tv_no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(offset);
    QueryRunner query  =QueryRunner();
    QList<TransVouchBean *> list = query.query<TransVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<TransVouchsBean *> TransImeiDAO::queryTransVouchsByNo(QString no){
    QString sql = "SELECT COALESCE(i.imei_count,0) as imei_count,a.id, a.tv_no, a.product_code, b.product_name, a.product_style, a.unit, a.quantity,"
                " a.unit_price, a.money "
            " FROM st_trans_vouchs a INNER JOIN ba_product b ON a.product_code=b.product_code "
            " LEFT JOIN (SELECT vouchs_id,count(imei) as imei_count FROM rd_trans_imei "
                " WHERE no='" + no + "' GROUP BY vouchs_id) i "
            " ON a.id=i.vouchs_id;";
            " WHERE a.tv_no='" + no + "'";
    QueryRunner query  =QueryRunner();
    QList<TransVouchsBean *> list = query.query<TransVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}
