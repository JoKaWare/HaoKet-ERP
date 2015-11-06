#include "faaccntdao.h"

FaAccntDAO::FaAccntDAO()
{
}

int FaAccntDAO::getSqlCount(QString sql){
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int FaAccntDAO::updateFaWay(FaWayBean *bean){
    QString sql = "UPDATE fa_cost_accounting_way "
            " SET way_name=?, way_note=?, memo=?, status=? "
            " WHERE way_id=" + QString::number(bean->wayId());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int FaAccntDAO::updateFaWayStatus(int wayId){
    QString sql = "UPDATE fa_cost_accounting_way SET status=1  WHERE way_id=" + QString::number(wayId) + "; "
            " UPDATE fa_cost_accounting_way SET status=0  WHERE way_id<>" + QString::number(wayId);
    QueryRunner query = QueryRunner();
    FaWayBean *bean = new FaWayBean;
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

FaWayBean *FaAccntDAO::getFayWay(){
    QString sql = "SELECT * "
            " FROM fa_cost_accounting_way WHERE status=1 ";
    QueryRunner query=QueryRunner();
    FaWayBean *qBean= new FaWayBean;
    return query.read<FaWayBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

QList<RdBean *> FaAccntDAO::queryRdList(QString sql){

    QueryRunner query  =QueryRunner();
    QList<RdBean *> list = query.query<RdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int FaAccntDAO::createSubsidiary(FaSubsidiaryBean *bean){
    QString sql = "INSERT INTO fa_subsidiary( "
            " rd_flag, vouch_no, vouch_type, bus_type, vouch_source, bus_no, batch_id, batch_amount, "
            " order_no, dv_no, dv_id, settle_no, wh_code, dep_code, person_code, cus_code, "
            " sup_code, pt_code, st_code, bus_date, keep_date, month, pz_id, "
            " pz_date, pz_type, pz_digest, vouchs_id, product_code, in_quantity, "
            " out_quantity, st_quantity, in_cost, out_cost, out_price, in_money, "
            " out_money, st_money, accounter, created_by, creater, created) "
        " VALUES (?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int FaAccntDAO::updateSubsidiary(FaSubsidiaryBean *bean){
    QString sql = "UPDATE fa_subsidiary "
            " SET rd_flag=?, vouch_no=?, vouch_type=?, bus_type=?, vouch_source=?, batch_id=?, batch_amount=?, "
                " bus_no=?, order_no=?, dv_no=?, dv_id=?, settle_no=?, wh_code=?, dep_code=?, "
                " person_code=?, cus_code=?, sup_code=?, pt_code=?, st_code=?, "
                " bus_date=?, keep_date=?, month=?, pz_id=?, pz_date=?, pz_type=?, "
                " pz_digest=?, vouchs_id=?, product_code=?, in_quantity=?, out_quantity=?, "
                " st_quantity=?, in_cost=?, out_cost=?, out_price=?, in_money=?, "
                " out_money=?, st_money=?, accounter=?, created_by=?, creater=?, created=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int FaAccntDAO::deleteSubsidiary(FaSubsidiaryBean *bean){
    QString sql = "DELETE FROM fa_subsidiary "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<FaSubsidiaryBean *> FaAccntDAO::queryFaSubsidiaryByNo(QString no){
    QString sql = "SELECT * FROM fa_subsidiary "
            " WHERE vouch_no='" + no + "'";
    QueryRunner query  =QueryRunner();
    QList<FaSubsidiaryBean *> list = query.query<FaSubsidiaryBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<FaSubsidiaryBean *> FaAccntDAO::queryFaSubsidiaryByEndDate(QDate eDate){
    QString sql = "SELECT * FROM fa_subsidiary "
            " WHERE bus_date>'" + eDate.toString("yyyy-MM-dd") + "'";
    QueryRunner query  =QueryRunner();
    QList<FaSubsidiaryBean *> list = query.query<FaSubsidiaryBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<FaSubsidiaryBean *> FaAccntDAO::queryFaSubsidiaryByDate(QDate sDate,QDate eDate){
    QString sql = "SELECT * FROM fa_subsidiary "
            " WHERE bus_date>='" + sDate.toString("yyyy-MM-dd") + "' AND bus_date<='" + eDate.toString("yyyy-MM-dd") + "' ORDER BY id DESC ";
    QueryRunner query  =QueryRunner();
    QList<FaSubsidiaryBean *> list = query.query<FaSubsidiaryBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

/**
 * 移动平均根据仓库与商品取最后一条记帐存货明细单据
 * @brief FaAccntDAO::queryFaSubsidiaryByBottom
 * @param whCode
 * @param productCode
 * @return
 */

QList<FaSubsidiaryBean *> FaAccntDAO::queryFaSubsidiaryByBottom(QString whCode, QString productCode){
    QString sql = "SELECT * FROM fa_subsidiary "
            " WHERE wh_code='" + whCode + "' AND product_code='" + productCode + "'"
            " ORDER BY id DESC LIMIT 1 ";
    QueryRunner query  =QueryRunner();
    QList<FaSubsidiaryBean *> list = query.query<FaSubsidiaryBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

/**
 * 先进先出 根据仓库与商品取可出库的记帐存货明细入库单据列表
 * @brief FaAccntDAO::queryFIFOFaSubsidiaryByBottom
 * @param whCode
 * @param productCode
 * @return
 */
QList<FaSubsidiaryBean *> FaAccntDAO::queryFIFOFaSubsidiaryBy(QString whCode, QString productCode){
    QString sql = "SELECT * FROM fa_subsidiary "
            " WHERE wh_code='" + whCode + "' AND product_code='" + productCode + "'"
            " AND batch_amount>0 AND rd_flag=1 AND vouch_type<>'14' ORDER BY id ASC";
    QueryRunner query  =QueryRunner();
    QList<FaSubsidiaryBean *> list = query.query<FaSubsidiaryBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

/**
 * 先进先出 销售退货 根据仓库与商品取可返回的记帐存货明细入库单据列表
 * @brief FaAccntDAO::queryFIFOFaSubsidiaryReByBottom
 * @param whCode
 * @param productCode
 * @return
 */
QList<FaSubsidiaryBean *> FaAccntDAO::queryFIFOFaSubsidiaryReByBottom(QString whCode, QString productCode){
    QString sql = "SELECT * FROM fa_subsidiary "
            " WHERE wh_code='" + whCode + "' AND product_code='" + productCode + "'"
            "  AND in_quantity-batch_amount>0 AND rd_flag=1 AND vouch_type<>'14' ORDER BY id DESC ";
    QueryRunner query  =QueryRunner();
    QList<FaSubsidiaryBean *> list = query.query<FaSubsidiaryBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

/**
 * 先进先出 恢复记帐  根据仓库与商品取可返回的记帐存货明细入库单据列表
 * @brief FaAccntDAO::queryReFIFOFaSubsidiaryBy
 * @param whCode
 * @param productCode
 * @return
 */
QList<FaSubsidiaryBean *> FaAccntDAO::queryReFIFOFaSubsidiaryBy(QString whCode, QString productCode){
    QString sql = "SELECT * FROM fa_subsidiary "
            " WHERE wh_code='" + whCode + "' AND product_code='" + productCode + "'"
            " AND batch_amount<>in_quantity AND vouch_type<>'14' ORDER BY id DESC ";
    QueryRunner query  =QueryRunner();
    QList<FaSubsidiaryBean *> list = query.query<FaSubsidiaryBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<FaSubsidiaryBean *> FaAccntDAO::queryReFIFOFaSubsidiaryByDvId(int id){
    QString sql = "SELECT * FROM fa_subsidiary "
            " WHERE id=" + QString::number(id) ;
    QueryRunner query  =QueryRunner();
    QList<FaSubsidiaryBean *> list = query.query<FaSubsidiaryBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}



