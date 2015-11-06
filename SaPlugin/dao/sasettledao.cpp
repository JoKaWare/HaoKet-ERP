#include "sasettledao.h"

SaSettleDAO::SaSettleDAO()
{
}

int SaSettleDAO::createSaSettle(SaSettleVouchBean *bean){
    QString sql = "INSERT INTO sa_settle_vouch( "
            " no, pt_code, order_no, rd_no, settle_date, ap_no, ap_money, profit_no, profit_money, settle_type, cus_code, "
            " dep_code, person_code, pay_code, cexch_name, handler, audit_time, is_handle, bus_type, "
            " status, created_by, created, creater, closer, updated_by, updated, updater, memo)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, "
               " ?, ?, ?, ?, ?, ?,? ,?, ?, ?, "
               " ?, ?, ?, ?, ?, ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaSettleDAO::updateSaSettle(SaSettleVouchBean *bean){
    QString sql = "UPDATE sa_settle_vouch "
                " SET pt_code=?, order_no=?, rd_no=?, settle_date=?, settle_type=?, ap_no=?, ap_money=?, profit_no=?,"
                " profit_money=?, is_handle=?, bus_type=?, "
                " cus_code=?, dep_code=?, person_code=?, pay_code=?, cexch_name=?, "
                " handler=?, audit_time=?, status=?, created_by=?, created=?, closer=?, "
                " creater=?, updated_by=?, updated=?, updater=?, memo=? "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaSettleDAO::delSaSettle(SaSettleVouchBean *bean){
    QString sql = "DELETE FROM sa_settle_vouch "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaSettleDAO::delSaSettleByNo(SaSettleVouchBean *bean){
    QString sql = "DELETE FROM sa_settle_vouch "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaSettleDAO::getSaSettleCount(QString bus_type){
    QString sql = "SELECT count(*) FROM sa_settle_vouch WHERE bus_type='" + bus_type + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaSettleDAO::getSaSettleRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by no nulls last) as rownum, id"
            " from sa_settle_vouch "
            " order by no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaSettleDAO::getSaSettleCount(QDate date){
    QString sql = "SELECT count(*) FROM sa_settle_vouch WHERE date_trunc('DAY', created)='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaSettleDAO::getSaSettleCountByNo(QString no){
    QString sql = "SELECT count(*) FROM sa_settle_vouch WHERE no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}


SaSettleVouchBean *SaSettleDAO::getSaSettleByNo(QString no){
    QString sql = "SELECT id, no, pt_code, order_no, rd_no, settle_date, settle_type, cus_code, bus_type, "
            " dep_code, person_code, pay_code, cexch_name, handler, audit_time, is_handle, creater, updater, "
            " status, created_by, created, closer, updated_by, updated, ap_no, ap_money, profit_no, profit_money, memo"
            " FROM sa_settle_vouch WHERE no='" + no + "' ";
    QueryRunner query=QueryRunner();
    SaSettleVouchBean *qBean= new SaSettleVouchBean;
    return query.read<SaSettleVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

QList<SaSettleVouchBean *> SaSettleDAO::querySaSettleBy(QDate date){
    QString sql = "SELECT id, no, pt_code, order_no, rd_no, settle_date, settle_type, cus_code, bus_type, "
            " dep_code, person_code, pay_code, cexch_name, handler, audit_time, is_handle, creater, updater, "
            " status, created_by, created, closer, updated_by, updated, ap_no, ap_money, profit_no, profit_money,memo"
            " FROM sa_settle_vouch WHERE settle_date='" + date.toString("yyyy-MM-dd")+ "' ORDER BY no ASC";
    QueryRunner query  =QueryRunner();
    QList<SaSettleVouchBean *> list = query.query<SaSettleVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SaSettleVouchBean *> SaSettleDAO::querySaSettleBy(QDate start, QDate end){
    QString sql = "SELECT id, no, pt_code, order_no, rd_no, settle_date, settle_type, cus_code, bus_type, "
            " dep_code, person_code, pay_code, cexch_name, handler, audit_time, is_handle, creater, updater, "
            " status, created_by, created, closer, updated_by, updated, ap_no, ap_money, profit_no, profit_money,memo"
            " FROM sa_settle_vouch WHERE settle_date>='" + start.toString("yyyy-MM-dd") +
            "' AND settle_date<='" + end.toString("yyyy-MM-dd") + "' ORDER BY no ASC";
    QueryRunner query  =QueryRunner();
    QList<SaSettleVouchBean *> list = query.query<SaSettleVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SaSettleVouchBean *> SaSettleDAO::querySaSettleByPage(int page, int maxResult,QString bus_type){
    QString sql = "SELECT id, no, pt_code, order_no, rd_no, settle_date, settle_type, cus_code, bus_type, "
            " dep_code, person_code, pay_code, cexch_name, handler, audit_time, is_handle, creater, updater, "
            " status, created_by, created, closer, updated_by, updated, ap_no, ap_money, profit_no, profit_money,memo"
            " FROM sa_settle_vouch WHERE bus_type='" + bus_type + "' "
            " ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<SaSettleVouchBean *> list = query.query<SaSettleVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int SaSettleDAO::createSaSettleVouchs(SaSettleVouchsBean *bean){
    QString sql = "INSERT INTO sa_settle_vouchs("
                " settle_no, rd_no, rds_note, bus_no, product_code, product_style,"
                " unit, quantity, price, s_price, tax_price, amount, memo)"
            " VALUES (?, ?, ?, ?, ?, ?,"
            " ?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaSettleDAO::updateSaSettleVouchs(SaSettleVouchsBean *bean){
    QString sql = " UPDATE sa_settle_vouchs "
                " SET id=?, settle_no=?, rd_no=?, rds_note=?, bus_no=?, product_code=?, "
                " product_style=?, unit=?, quantity=?, price=?, s_price=?, tax_price=?, "
                " amount=?, memo=? "
                " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaSettleDAO::delSaSettleVouchs(SaSettleVouchsBean *bean){
    QString sql = "DELETE FROM sa_settle_vouchs "
            " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaSettleDAO::delSaSettleVouchsByNo(QString no){
    QString sql = "DELETE FROM sa_settle_vouchs "
            " WHERE settle_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

QList<SaSettleVouchsBean *> SaSettleDAO::querySaSettleVouchsByNo(QString no){
    QString sql = "SELECT a.*,b.product_name "
                " FROM sa_settle_vouchs a,ba_product b "
                " WHERE settle_no='" + no + "' AND a.product_code=b.product_code ORDER BY id ASC";
    QueryRunner query  =QueryRunner();
    QList<SaSettleVouchsBean *> list = query.query<SaSettleVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QSqlQueryModel * SaSettleDAO::querySqlModelSaSettleBy(QDate start, QDate end){
    QString sql = "SELECT id, no, pt_code, order_no, rd_no, settle_date, settle_type, cus_code, bus_type, "
            " dep_code, person_code, pay_code, cexch_name, handler, audit_time, is_handle, creater, updater, "
            " status, created_by, created, closer, updated_by, updated, ap_no, ap_money, profit_no, profit_money, memo"
            " FROM sa_settle_vouch WHERE settle_date>='" + start.toString("yyyy-MM-dd") +
            "' AND settle_date<='" + end.toString("yyyy-MM-dd") + "' ORDER BY no ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;
}

QSqlQueryModel * SaSettleDAO::querySqlModelSaSettleBy(QString no){
    QString sql = "SELECT id, no, pt_code, order_no, rd_no, settle_date, settle_type, cus_code, bus_type, "
            " dep_code, person_code, pay_code, cexch_name, handler, audit_time, is_handle, creater, updater, "
            " status, created_by, created, closer, updated_by, updated, ap_no, ap_money, profit_no, profit_money, memo"
            " FROM sa_settle_vouch WHERE no='" + no + "' ";
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;
}

/**
 * 提取出库单末结算数量
 * @brief SaSettleDAO::getSaSettleRdsBy
 * @param rd_no
 * @param productCode
 * @return
 */
SaSettleVouchsBean *SaSettleDAO::getSaSettleRdsBy(QString rd_no, QString productCode){
    QString sql = "SELECT g.rd_no ,g.product_code , g.quantity-COALESCE(h.sum_qunatity,0) as quantity "
                   " from rd_records g "
                   " LEFT JOIN "
                        " ( SELECT e.rd_no,e.product_code,sum(quantity) as sum_qunatity "
                           " from sa_settle_vouchs e "
                           " inner join sa_settle_vouch f "
                           " ON e.settle_no=f.no "
                           " where f.is_handle=true AND e.rd_no='" + rd_no + "' "
                           " GROUP BY e.rd_no,e.product_code) h "
                   " ON g.rd_no=h.rd_no AND g.product_code=h.product_code "
                   " where g.rd_no='" + rd_no +"' AND g.product_code='" + productCode + "' ";
            QueryRunner query=QueryRunner();
    //qDebug() << sql ;
    SaSettleVouchsBean *qBean= new SaSettleVouchsBean;
    return query.read<SaSettleVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

/**
 * 判断出库记录是否全部结算完,如结算完返回0
 * @brief PuSettleDAO::getPuSettleRdsCount
 * @param rd_no
 * @return
 */
int SaSettleDAO::getSaSettleRdsCount(QString rd_no){
    QString sql = "SELECT count(*) "
                   " from rd_records g "
                   " LEFT JOIN "
                        " ( SELECT e.rd_no,e.product_code,sum(quantity) as sum_qunatity "
                           " from sa_settle_vouchs e "
                           " inner join sa_settle_vouch f "
                           " ON e.settle_no=f.no "
                           " where f.is_handle=true AND e.rd_no='" + rd_no + "' "
                           " GROUP BY e.rd_no,e.product_code) h "
                   " ON g.rd_no=h.rd_no AND g.product_code=h.product_code "
                   " where g.rd_no='" + rd_no +"' AND g.quantity-COALESCE(h.sum_qunatity,0)<>0 ";
    QueryRunner query=QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}
