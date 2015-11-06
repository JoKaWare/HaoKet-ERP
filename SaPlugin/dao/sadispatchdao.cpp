#include "sadispatchdao.h"

SaDispatchDAO::SaDispatchDAO()
{
}

int SaDispatchDAO::createSaDispatch(SaDispatchVouchBean *bean){
    QString sql = "INSERT INTO sa_dispatch_vouch( "
            " no, bus_date, bus_type, sa_type, cus_code, ship_address, "
            " linkman, phone, wh_code, dep_code, person_code, handler, audit_time, "
            " is_handle, is_complete, created_by, creater, created, closer, "
            " updated_by, updater, updated, status, memo) "
        " VALUES (?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaDispatchDAO::updateSaDispatch(SaDispatchVouchBean *bean){
    QString sql = "UPDATE sa_dispatch_vouch "
                " SET no=?, bus_date=?, bus_type=?, sa_type=?, cus_code=?, ship_address=?, "
                " linkman=?, phone=?, wh_code=?, dep_code=?, person_code=?, handler=?, "
                " audit_time=?, is_handle=?, is_complete=?, created_by=?, creater=?, "
                " created=?, closer=?, updated_by=?, updater=?, updated=?, status=?, "
                " memo=?"
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaDispatchDAO::delSaDispatch(SaDispatchVouchBean *bean){
    QString sql = "DELETE FROM sa_dispatch_vouch "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaDispatchDAO::delSaDispatchByNo(SaDispatchVouchBean *bean){
    QString sql = "DELETE FROM sa_dispatch_vouch "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

SaDispatchVouchBean * SaDispatchDAO::getSaDispatchByNo(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, creater, linkman, phone, ship_address, "
            " closer, updated_by, updated, updater, status, memo,is_handle, is_complete"
            " FROM sa_dispatch_vouch WHERE no='" + no + "'";
    QueryRunner query=QueryRunner();
    SaDispatchVouchBean *qBean= new SaDispatchVouchBean;
    return query.read<SaDispatchVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}
int SaDispatchDAO::getSaDispatchCount(){
    QString sql = "SELECT count(*) FROM sa_dispatch_vouch ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaDispatchDAO::getSaDispatchCount(QString bus_type){
    QString sql = "SELECT count(*) FROM sa_dispatch_vouch WHERE bus_type='" + bus_type + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaDispatchDAO::getSaDispatchRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by no nulls last) as rownum, id"
            " from sa_dispatch_vouch "
            " order by no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaDispatchDAO::getSaDispatchCount(QDate date){
    QString sql = "SELECT count(*) FROM sa_dispatch_vouch WHERE date_trunc('DAY', created)='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaDispatchDAO::getSaDispatchCountByNo(QString no){
    QString sql = "SELECT count(*) FROM sa_dispatch_vouch WHERE no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<SaDispatchVouchBean *> SaDispatchDAO::querySaDispatchByPage(int page ,int maxResult){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, linkman, phone, ship_address, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM sa_dispatch_vouch ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<SaDispatchVouchBean *> list = query.query<SaDispatchVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}


QList<SaDispatchVouchBean *> SaDispatchDAO::querySaDispatchByPage(int page ,int maxResult,QString bus_type){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, linkman, phone, ship_address, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM sa_dispatch_vouch WHERE bus_type='" + bus_type + "' ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<SaDispatchVouchBean *> list = query.query<SaDispatchVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SaDispatchVouchBean *> SaDispatchDAO::querySaDispatchBy(QDate date){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type, "
            " person_code, handler, audit_time, created_by, created, linkman, phone, ship_address, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM sa_dispatch_vouch WHERE bus_date='" + date.toString("yyyy-MM-dd")+ "'";
    QueryRunner query  =QueryRunner();
    QList<SaDispatchVouchBean *> list = query.query<SaDispatchVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SaDispatchVouchBean *> SaDispatchDAO::querySaDispatchBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, linkman, phone, ship_address, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM sa_dispatch_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+ "' AND bus_date<='" + end.toString("yyyy-MM-dd")+ "'";

    QueryRunner query  =QueryRunner();
    QList<SaDispatchVouchBean *> list = query.query<SaDispatchVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int SaDispatchDAO::createSaDispatchVouchs(SaDispatchVouchsBean *bean){
    QString sql = "INSERT INTO sa_dispatch_vouchs( "
            " dispatch_no, order_no, src_no, cus_code, product_code, product_style, unit, "
            " quantity, price, tax_price, money, memo, define1, "
            " define2, define3, define4, define5, define6) "
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
int SaDispatchDAO::updateSaDispatchVouchs(SaDispatchVouchsBean *bean){
    QString sql = "UPDATE sa_dispatch_vouchs "
            " SET cus_code=?, product_code=?, product_style=?, src_no=?, "
             " unit=?, quantity=?, price=?, tax_price=?, money=?, order_no=? , "
            " memo=?, define1=?, define2=?, define3=?, define4=?, define5=?, define6=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaDispatchDAO::delSaDispatchVouchs(SaDispatchVouchsBean *bean){
    QString sql = "DELETE FROM sa_dispatch_vouchs "
            " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaDispatchDAO::delSaDispatchVouchsByNo(QString no){
    QString sql = "DELETE FROM sa_dispatch_vouchs "
            " WHERE dispatch_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

QList<SaDispatchVouchsBean *> SaDispatchDAO::querySaDispatchVouchsByNo(QString no){
    QString sql = "SELECT a.id, a.dispatch_no,a.order_no, src_no, a.cus_code, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money , a.memo, define1, "
            " define2, define3, define4, define5, define6 "
            " FROM sa_dispatch_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code WHERE dispatch_no='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<SaDispatchVouchsBean *> list = query.query<SaDispatchVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SaDispatchVouchsBean *> SaDispatchDAO::querySaDispatchVouchsByOrderNo(QString no){
    QString sql = "SELECT a.id, a.dispatch_no,a.order_no, src_no, a.cus_code, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money "
            " FROM sa_dispatch_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code WHERE order_no='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<SaDispatchVouchsBean *> list = query.query<SaDispatchVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

SaDispatchVouchsBean * SaDispatchDAO::getSaDispatchBy(QString no,QString productCode){
    QString sql = "SELECT a.id, a.dispatch_no,a.order_no, src_no, a.cus_code, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money "
            " FROM sa_dispatch_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code "
            " WHERE dispatch_no='" + no +"' AND a.product_code='" + productCode + "' ORDER BY a.id ASC";
    QueryRunner query=QueryRunner();
    SaDispatchVouchsBean *qBean= new SaDispatchVouchsBean;
    return query.read<SaDispatchVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

QSqlQueryModel *SaDispatchDAO::querySqlModelArrivalBy(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
                " person_code, handler, audit_time, created_by, created, linkman, phone, ship_address, "
                " closer, updated_by, updated, status, memo "
                " FROM sa_dispatch_vouch WHERE no like '" + no + "%'";

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

QSqlQueryModel *SaDispatchDAO::querySqlModelArrivalBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, linkman, phone, ship_address, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete "
            " FROM sa_dispatch_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+
            "' AND bus_date<='" + end.toString("yyyy-MM-dd") + "' ORDER BY id ASC";
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
 * 根据出库单号及商品型号返回出库单最大可退数量BEAN (过滤普通退货)
 * @brief SaDispatchDAO::getSaReRdsBy
 * @param src_no
 * @param productCode
 * @return
 */
SaDispatchVouchsBean *SaDispatchDAO::getSaReRdsBy(QString src_no, QString productCode){
    QString sql = "SELECT g.rd_no as src_no,g.product_code , g.quantity-COALESCE(h.sum_qunatity,0) as quantity "
                   " from rd_records g "
                   " LEFT JOIN "
                        " ( SELECT e.src_no,e.product_code,sum(quantity) as sum_qunatity "
                           " from sa_dispatch_vouchs e "
                           " inner join sa_dispatch_vouch f "
                           " ON e.dispatch_no=f.no "
                           " where f.bus_type='02' AND f.is_handle=true AND e.src_no='" + src_no + "' "
                           " GROUP BY e.src_no,e.product_code) h "
                   " ON g.rd_no=h.src_no AND g.product_code=h.product_code "
                   " where g.rd_no='" + src_no +"' AND g.product_code='" + productCode + "' ";
            QueryRunner query=QueryRunner();
    //qDebug() << sql ;
    SaDispatchVouchsBean *qBean= new SaDispatchVouchsBean;
    return query.read<SaDispatchVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

/**
 * 根据出库单号及商品型号返回出库单最大可退数量BEAN (过滤委代退货)
 * @brief SaDispatchDAO::getSaConReRdsBy
 * @param src_no
 * @param productCode
 * @return
 */
SaDispatchVouchsBean *SaDispatchDAO::getSaConReRdsBy(QString src_no, QString productCode){
    QString sql = "SELECT g.rd_no as src_no,g.product_code , g.quantity-COALESCE(h.sum_qunatity,0) as quantity "
                   " from rd_records g "
                   " LEFT JOIN "
                        " ( SELECT e.src_no,e.product_code,sum(quantity) as sum_qunatity "
                           " from sa_dispatch_vouchs e "
                           " inner join sa_dispatch_vouch f "
                           " ON e.dispatch_no=f.no "
                           " where f.bus_type='04' AND f.is_handle=true AND e.src_no='" + src_no + "' "
                           " GROUP BY e.src_no,e.product_code) h "
                   " ON g.rd_no=h.src_no AND g.product_code=h.product_code "
                   " where g.rd_no='" + src_no +"' AND g.product_code='" + productCode + "' ";
            QueryRunner query=QueryRunner();
    //qDebug() << sql ;
    SaDispatchVouchsBean *qBean= new SaDispatchVouchsBean;
    return query.read<SaDispatchVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}


