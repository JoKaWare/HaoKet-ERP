#include "imeidao.h"

ImeiDAO::ImeiDAO()
{
}

RdBean *ImeiDAO::getRdByNo(QString no){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit "
            " FROM rd_record WHERE rd_no='" + no + "' ";
    QueryRunner query=QueryRunner();
    RdBean *qBean= new RdBean;
    return query.read<RdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

/**
 * 查询入库单 与入库串码数量
 * @brief ImeiDAO::queryRdsBy
 * @param no
 * @return
 */
QList<RdsBean *> ImeiDAO::queryRdsBy(QString no){
    QString sql = "SELECT COALESCE(i.imei_count,0) as imei_count,f.* FROM "
            "(SELECT a.id, a.rd_no, a.product_code, b.product_name,a.unit, a.quantity, a.unit_price, a.money, a.a_money, "
                    " a.memo, a.product_style, a.bus_no, a.order_no "
                    " FROM rd_records a, ba_product b WHERE rd_no='" + no + "' "
                    " AND a.product_code=b.product_code ORDER BY a.id ASC ) f "
            " LEFT JOIN (SELECT vouchs_id,count(imei) as imei_count FROM rd_in_imei "
            " WHERE no='" + no + "' GROUP BY vouchs_id) i "
            " ON f.id=i.vouchs_id;";
    QueryRunner query  =QueryRunner();
    QList<RdsBean *> list = query.query<RdsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

/**
 * 查询出库单 与出库串码数量
 * @brief ImeiDAO::queryOutRdsBy
 * @param no
 * @return
 */
QList<RdsBean *> ImeiDAO::queryOutRdsBy(QString no){
    QString sql = "SELECT COALESCE(i.imei_count,0) as imei_count,f.* FROM "
            "(SELECT a.id, a.rd_no, a.product_code, b.product_name,a.unit, a.quantity, a.unit_price, a.money, a.a_money, "
                    " a.memo, a.product_style, a.bus_no, a.order_no "
                    " FROM rd_records a, ba_product b WHERE rd_no='" + no + "' "
                    " AND a.product_code=b.product_code ORDER BY a.id ASC ) f "
            " LEFT JOIN (SELECT vouchs_id,count(imei) as imei_count FROM rd_out_imei "
            " WHERE no='" + no + "' GROUP BY vouchs_id) i "
            " ON f.id=i.vouchs_id;";
    QueryRunner query  =QueryRunner();
    QList<RdsBean *> list = query.query<RdsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdBean *>  ImeiDAO::queryRdByPage(QString vouchType,int page, int maxResult){
    int offset = 0;
    if(page < 0){
        offset = 0;
    }else offset = page;
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE vouch_type='" + vouchType + "' AND is_handle=true"
            " ORDER BY rd_no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(offset);
    QueryRunner query  =QueryRunner();
    QList<RdBean *> list = query.query<RdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int ImeiDAO::getRdCount(QString vouchType){
    QString sql = "SELECT count(*) FROM rd_record WHERE vouch_type='" + vouchType + "'  AND is_handle=true";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ImeiDAO::getRdRowNumber(QString vouchType,int id){
    QString sql = "select * from (select row_number() over (order by rd_no nulls last) as rownum, id"
            " from rd_record where vouch_type='" + vouchType + "'  AND is_handle=true "
            " order by rd_no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}
