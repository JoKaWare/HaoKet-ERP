#include "saorderdao.h"
#include <QDebug>

SaOrderDAO::SaOrderDAO()
{
}


int SaOrderDAO::createSaOrder(SaOrderVouchBean *bean){
    QString sql = "INSERT INTO sa_order_vouch( "
            " no, bus_date, bus_type, cus_code, wh_code, dep_code, demand_date, "
            " project_date, person_code, handler, audit_time, created_by, created, creater, "
            " closer, updated_by, updated, updater, status, memo, is_handle, is_complete)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaOrderDAO::updateSaOrder(SaOrderVouchBean *bean){
    QString sql = "UPDATE sa_order_vouch "
            " SET bus_date=?, bus_type=?, cus_code=?, wh_code=?, "
              " dep_code=?, demand_date=?, project_date=?, person_code=?, handler=?, "
              " audit_time=?, created_by=?, created=?, creater=?, closer=?, updated_by=?, "
              " updated=?, updater=?, status=?, memo=?, is_handle=?, is_complete=? "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaOrderDAO::delSaOrder(SaOrderVouchBean *bean){
    QString sql = "DELETE FROM sa_order_vouch "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaOrderDAO::delSaOrderByNo(SaOrderVouchBean *bean){
    QString sql = "DELETE FROM sa_order_vouch "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

SaOrderVouchBean * SaOrderDAO::getSaOrderByNo(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created, creater,"
            " closer, updated_by, updated, updater, status, memo,is_handle, is_complete"
            " FROM sa_order_vouch WHERE no='" + no + "'";
    QueryRunner query=QueryRunner();
    SaOrderVouchBean *qBean= new SaOrderVouchBean;
    return query.read<SaOrderVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}
int SaOrderDAO::getSaOrderCount(){
    QString sql = "SELECT count(*) FROM sa_order_vouch ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaOrderDAO::getSaOrderRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by no nulls last) as rownum, id"
            " from sa_order_vouch "
            " order by no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaOrderDAO::getSaOrderCount(QDate date){
    QString sql = "SELECT count(*) FROM sa_order_vouch WHERE created='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaOrderDAO::getSaOrderCountByNo(QString no){
    QString sql = "SELECT count(*) FROM sa_order_vouch WHERE no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<SaOrderVouchBean *> SaOrderDAO::querySaOrderByPage(int page ,int maxResult){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM sa_order_vouch ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<SaOrderVouchBean *> list = query.query<SaOrderVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SaOrderVouchBean *> SaOrderDAO::querySaOrderBy(QDate date){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM sa_order_vouch WHERE bus_date='" + date.toString("yyyy-MM-dd")+ "'";
    QueryRunner query  =QueryRunner();
    QList<SaOrderVouchBean *> list = query.query<SaOrderVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SaOrderVouchBean *> SaOrderDAO::querySaOrderBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM sa_order_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+ "' AND bus_date<='" + end.toString("yyyy-MM-dd")+ "'";

    QueryRunner query  =QueryRunner();
    QList<SaOrderVouchBean *> list = query.query<SaOrderVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int SaOrderDAO::createSaOrderVouchs(SaOrderVouchsBean *bean){
    QString sql = "INSERT INTO sa_order_vouchs( "
            " order_no, cus_code, product_code, product_style, unit, is_complete, "
            " quantity, price, tax_price, money, toq, out_quantity, re_quantity, memo, define1, "
            " define2, define3, define4, define5, define6) "
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, ? , ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
int SaOrderDAO::updateSaOrderVouchs(SaOrderVouchsBean *bean){
    QString sql = "UPDATE sa_order_vouchs "
            " SET cus_code=?, product_code=?, product_style=?, is_complete=?, "
             " unit=?, quantity=?, price=?, tax_price=?, money=?, toq=? ,out_quantity=?, re_quantity=?, "
            " memo=?, define1=?, define2=?, define3=?, define4=?, define5=?, define6=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaOrderDAO::delSaOrderVouchs(SaOrderVouchsBean *bean){
    QString sql = "DELETE FROM sa_order_vouchs "
            " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaOrderDAO::delSaOrderVouchsByNo(QString no){
    QString sql = "DELETE FROM sa_order_vouchs "
            " WHERE order_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

QList<SaOrderVouchsBean *> SaOrderDAO::querySaOrderVouchsByNo(QString no){
    QString sql = "SELECT a.id, a.order_no, a.cus_code, a.product_code, b.product_name, a.product_style, a.unit, a.is_complete,"
            " quantity, out_quantity, re_quantity, price, tax_price, money, toq, a.memo, define1, "
            " define2, define3, define4, define5, define6 "
            " FROM sa_order_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code WHERE order_no='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<SaOrderVouchsBean *> list = query.query<SaOrderVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

SaOrderVouchsBean *SaOrderDAO::getSaOrderVouchsBy(QString no, QString productCode){
    QString sql = "SELECT g.id, g.order_no, g.cus_code, g.product_code, g.product_name, g.product_style, g.unit,g.is_complete, "
            " quantity,out_quantity,re_quantity, quantity-out_quantity-COALESCE(sum_qunatity,0) as real_quantity , price, tax_price, money, toq, "
            " g.memo, g.define1, g.define2, g.define3, g.define4, g.define5, g.define6 "
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


SaOrderVouchsBean *SaOrderDAO::getSaReOrderVouchsBy(QString no, QString productCode){
    QString sql = "SELECT g.id, g.order_no, g.cus_code, g.product_code, g.product_name, g.product_style, g.unit,g.is_complete, "
            " quantity,out_quantity,re_quantity, out_quantity-re_quantity-COALESCE(sum_qunatity,0) as real_quantity , price, tax_price, money, toq, "
            " g.memo, g.define1, g.define2, g.define3, g.define4, g.define5, g.define6 "
            " FROM (SELECT a.*,b.product_name FROM sa_order_vouchs a LEFT JOIN ba_product b on a.product_code=b.product_code "
            " WHERE order_no='" + no + "' AND a.product_code='" + productCode + "') g LEFT JOIN ( "
            " SELECT e.order_no,e.product_code,sum(quantity) as sum_qunatity  from sa_dispatch_vouchs e inner join sa_dispatch_vouch f ON e.dispatch_no=f.no where f.is_handle=false AND f.bus_type='02'"
            " GROUP BY e.order_no,e.product_code) h "
            " ON g.order_no=h.order_no AND g.product_code=h.product_code ";
    QueryRunner query=QueryRunner();
    qDebug() << sql ;
    SaOrderVouchsBean *qBean= new SaOrderVouchsBean;
    return query.read<SaOrderVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

QSqlQueryModel *SaOrderDAO::querySqlModelOrderBy(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, demand_date,"
                " project_date, person_code, handler, audit_time, created_by, created, "
                " closer, updated_by, updated, status, memo "
                " FROM sa_order_vouch WHERE no like '" + no + "%'";

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

QSqlQueryModel *SaOrderDAO::querySqlModelOrderBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, demand_date,"
            " project_date, person_code, handler, audit_time, created_by, created, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete "
            " FROM sa_order_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+
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

