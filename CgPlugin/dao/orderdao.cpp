#include "orderdao.h"
#include <QDebug>
OrderDAO::OrderDAO()
{
}

int OrderDAO::createPuOrder(PuOrderVouchBean *bean){
    QString sql = "INSERT INTO pu_order_vouch( "
            " no, bus_date, bus_type, supplier_id, wh_code, dep_code, demand_date, "
            " project_date, person_code, handler, audit_time, created_by, created, creater, "
            " closer, updated_by, updated, updater, status, memo, is_handle, is_complete)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int OrderDAO::updatePuOrder(PuOrderVouchBean *bean){
    QString sql = "UPDATE pu_order_vouch "
            " SET bus_date=?, bus_type=?, supplier_id=?, wh_code=?, "
              " dep_code=?, demand_date=?, project_date=?, person_code=?, handler=?, "
              " audit_time=?, created_by=?, created=?, creater=?, closer=?, updated_by=?, "
              " updated=?, updater=?, status=?, memo=?, is_handle=?, is_complete=? "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int OrderDAO::delPuOrder(PuOrderVouchBean *bean){
    QString sql = "DELETE FROM pu_order_vouch "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int OrderDAO::delPuOrderByNo(PuOrderVouchBean *bean){
    QString sql = "DELETE FROM pu_order_vouch "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

PuOrderVouchBean * OrderDAO::getPuOrderByNo(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created, creater,"
            " closer, updated_by, updated, updater, status, memo,is_handle, is_complete"
            " FROM pu_order_vouch WHERE no='" + no + "'";
    QueryRunner query=QueryRunner();
    PuOrderVouchBean *qBean= new PuOrderVouchBean;
    return query.read<PuOrderVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}
int OrderDAO::getPuOrderCount(){
    QString sql = "SELECT count(*) FROM pu_order_vouch ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int OrderDAO::getPuOrderRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by no nulls last) as rownum, id"
            " from pu_order_vouch "
            " order by no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int OrderDAO::getPuOrderCount(QDate date){
    QString sql = "SELECT count(*) FROM pu_order_vouch WHERE date_trunc('DAY', created)='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int OrderDAO::getPuOrderCountByNo(QString no){
    QString sql = "SELECT count(*) FROM pu_order_vouch WHERE no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<PuOrderVouchBean *> OrderDAO::queryPuOrderByPage(int page ,int maxResult){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM pu_order_vouch ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<PuOrderVouchBean *> list = query.query<PuOrderVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<PuOrderVouchBean *> OrderDAO::queryPuOrderBy(QDate date){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM pu_order_vouch WHERE bus_date='" + date.toString("yyyy-MM-dd")+ "'";
    QueryRunner query  =QueryRunner();
    QList<PuOrderVouchBean *> list = query.query<PuOrderVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<PuOrderVouchBean *> OrderDAO::queryPuOrderBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM pu_order_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+ "' AND bus_date<='" + end.toString("yyyy-MM-dd")+ "'";

    QueryRunner query  =QueryRunner();
    QList<PuOrderVouchBean *> list = query.query<PuOrderVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int OrderDAO::createPuOrderVouchs(PuOrderVouchsBean *bean){
    QString sql = "INSERT INTO pu_order_vouchs( "
            " order_no,origin_no, supplier_id, product_code, product_style, unit, is_complete, "
            " quantity, price, tax_price, money, toq, in_quantity, re_quantity , memo, define1, "
            " define2, define3, define4, define5, define6) "
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?,"
            " ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
int OrderDAO::updatePuOrderVouchs(PuOrderVouchsBean *bean){
    QString sql = "UPDATE pu_order_vouchs "
            " SET supplier_id=?, origin_no=?, product_code=?, product_style=?, is_complete=?, "
             " unit=?, quantity=?, price=?, tax_price=?, money=?, toq=? ,in_quantity=?, re_quantity=?, "
            " memo=?, define1=?, define2=?, define3=?, define4=?, define5=?, define6=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int OrderDAO::delPuOrderVouchs(PuOrderVouchsBean *bean){
    QString sql = "DELETE FROM pu_order_vouchs "
            " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int OrderDAO::delPuOrderVouchsByNo(QString no){
    QString sql = "DELETE FROM pu_order_vouchs "
            " WHERE order_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

QList<PuOrderVouchsBean *> OrderDAO::queryPuOrderVouchsByNo(QString no){
    QString sql = "SELECT a.id, a.order_no, a.origin_no, a.supplier_id, a.product_code, b.product_name, a.product_style, a.unit, a.is_complete,"
            " quantity, in_quantity, re_quantity, price, tax_price, money, toq, a.memo, define1, "
            " define2, define3, define4, define5, define6 "
            " FROM pu_order_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code WHERE order_no='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<PuOrderVouchsBean *> list = query.query<PuOrderVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

PuOrderVouchsBean *OrderDAO::getPuOrderVouchsBy(QString no, QString productCode){
    QString sql = "SELECT g.id, g.order_no, g.origin_no,g.supplier_id, g.product_code, g.product_name, g.product_style, g.unit,g.is_complete, "
            " quantity,in_quantity,re_quantity, quantity-in_quantity-COALESCE(sum_qunatity,0) as real_quantity , price, tax_price, money, toq, "
            " g.memo, g.define1, g.define2, g.define3, g.define4, g.define5, g.define6 "
            " FROM (SELECT a.*,b.product_name FROM pu_order_vouchs a LEFT JOIN ba_product b on a.product_code=b.product_code "
            " WHERE order_no='" + no + "' AND a.product_code='" + productCode + "') g LEFT JOIN ( "
            " SELECT e.order_no,e.product_code,sum(quantity) as sum_qunatity  from pu_arrival_vouchs e inner join pu_arrival_vouch f ON e.arrival_no=f.no where f.is_handle=false AND f.bus_type='01'"
            " GROUP BY e.order_no,e.product_code) h "
            " ON g.order_no=h.order_no AND g.product_code=h.product_code ";
    QueryRunner query=QueryRunner();
    qDebug() << sql ;
    PuOrderVouchsBean *qBean= new PuOrderVouchsBean;
    return query.read<PuOrderVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}


PuOrderVouchsBean *OrderDAO::getPuReOrderVouchsBy(QString no, QString productCode){
    QString sql = "SELECT g.id, g.order_no, g.origin_no,g.supplier_id, g.product_code, g.product_name, g.product_style, g.unit,g.is_complete, "
            " quantity,in_quantity,re_quantity, in_quantity-re_quantity-COALESCE(sum_qunatity,0) as real_quantity , price, tax_price, money, toq, "
            " g.memo, g.define1, g.define2, g.define3, g.define4, g.define5, g.define6 "
            " FROM (SELECT a.*,b.product_name FROM pu_order_vouchs a LEFT JOIN ba_product b on a.product_code=b.product_code "
            " WHERE order_no='" + no + "' AND a.product_code='" + productCode + "') g LEFT JOIN ( "
            " SELECT e.order_no,e.product_code,sum(quantity) as sum_qunatity  from pu_arrival_vouchs e inner join pu_arrival_vouch f ON e.arrival_no=f.no where f.is_handle=false AND f.bus_type='02'"
            " GROUP BY e.order_no,e.product_code) h "
            " ON g.order_no=h.order_no AND g.product_code=h.product_code ";
    QueryRunner query=QueryRunner();
    qDebug() << sql ;
    PuOrderVouchsBean *qBean= new PuOrderVouchsBean;
    return query.read<PuOrderVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

QSqlQueryModel *OrderDAO::querySqlModelOrderBy(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, demand_date,"
                " project_date, person_code, handler, audit_time, created_by, created, "
                " closer, updated_by, updated, status, memo "
                " FROM pu_order_vouch WHERE no like '" + no + "%'";

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

QSqlQueryModel *OrderDAO::querySqlModelOrderBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete "
            " FROM pu_order_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+
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
 * 读取销售订单子表Bean
 * @brief OrderDAO::getSaOrderVouchsBy
 * @param no
 * @param productCode
 * @return
 */
SaOrderVouchsBean *OrderDAO::getSaOrderVouchsBy(QString no, QString productCode){
    QString sql = "SELECT g.id, g.order_no, g.cus_code, g.product_code, g.product_name, g.product_style, g.unit,g.is_complete, "
            " quantity,out_quantity,re_quantity, quantity-out_quantity-COALESCE(sum_qunatity,0) as real_quantity , price, tax_price, money, toq, pu_quantity "
            " FROM (SELECT a.*,b.product_name FROM sa_order_vouchs a LEFT JOIN ba_product b on a.product_code=b.product_code "
            " WHERE order_no='" + no + "' AND a.product_code='" + productCode + "') g LEFT JOIN ( "
            " SELECT e.order_no,e.product_code,sum(quantity) as sum_qunatity  from sa_dispatch_vouchs e inner join sa_dispatch_vouch f ON e.dispatch_no=f.no where f.is_handle=false AND f.bus_type='01'"
            " GROUP BY e.order_no,e.product_code) h "
            " ON g.order_no=h.order_no AND g.product_code=h.product_code ";
    QueryRunner query=QueryRunner();
    qDebug() << sql ;
    SaOrderVouchsBean *qBean= new SaOrderVouchsBean;
    return query.read<SaOrderVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

int OrderDAO::updateSaOrderVouchs(SaOrderVouchsBean *bean){
    QString sql = "UPDATE sa_order_vouchs "
            " SET pu_quantity=?"
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
