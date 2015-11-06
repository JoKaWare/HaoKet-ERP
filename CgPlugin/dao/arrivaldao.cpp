#include "arrivaldao.h"

ArrivalDAO::ArrivalDAO()
{
}


int ArrivalDAO::createPuArrival(PuArrivalVouchBean *bean){
    QString sql = "INSERT INTO pu_arrival_vouch( "
            " no, bus_date, bus_type, pu_type,supplier_id, wh_code, dep_code, "
            " person_code, handler, audit_time, created_by, created, creater, "
            " closer, updated_by, updated, updater, status, memo, is_handle, is_complete)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ArrivalDAO::updatePuArrival(PuArrivalVouchBean *bean){
    QString sql = "UPDATE pu_arrival_vouch "
            " SET bus_date=?, bus_type=?, supplier_id=?, wh_code=?, "
              " dep_code=?, person_code=?, handler=?, pu_type=?, "
              " audit_time=?, created_by=?, created=?, creater=?, closer=?, updated_by=?, "
              " updated=?, updater=?, status=?, memo=?, is_handle=?, is_complete=? "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ArrivalDAO::delPuArrival(PuArrivalVouchBean *bean){
    QString sql = "DELETE FROM pu_arrival_vouch "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ArrivalDAO::delPuArrivalByNo(PuArrivalVouchBean *bean){
    QString sql = "DELETE FROM pu_arrival_vouch "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

PuArrivalVouchBean * ArrivalDAO::getPuArrivalByNo(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, pu_type,"
            " person_code, handler, audit_time, created_by, created, creater,"
            " closer, updated_by, updated, updater, status, memo,is_handle, is_complete"
            " FROM pu_arrival_vouch WHERE no='" + no + "'";
    QueryRunner query=QueryRunner();
    PuArrivalVouchBean *qBean= new PuArrivalVouchBean;
    return query.read<PuArrivalVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}
int ArrivalDAO::getPuArrivalCount(){
    QString sql = "SELECT count(*) FROM pu_arrival_vouch ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ArrivalDAO::getPuArrivalCount(QString bus_type){
    QString sql = "SELECT count(*) FROM pu_arrival_vouch WHERE bus_type='" + bus_type + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ArrivalDAO::getPuArrivalRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by no nulls last) as rownum, id"
            " from pu_arrival_vouch "
            " order by no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ArrivalDAO::getPuArrivalCount(QDate date){
    QString sql = "SELECT count(*) FROM pu_arrival_vouch WHERE date_trunc('DAY', created)='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ArrivalDAO::getPuArrivalCountByNo(QString no){
    QString sql = "SELECT count(*) FROM pu_arrival_vouch WHERE no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<PuArrivalVouchBean *> ArrivalDAO::queryPuArrivalByPage(int page ,int maxResult){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, pu_type,"
            " person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM pu_arrival_vouch ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<PuArrivalVouchBean *> list = query.query<PuArrivalVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}


QList<PuArrivalVouchBean *> ArrivalDAO::queryPuArrivalByPage(int page ,int maxResult,QString bus_type){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, pu_type,"
            " person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM pu_arrival_vouch WHERE bus_type='" + bus_type + "' ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<PuArrivalVouchBean *> list = query.query<PuArrivalVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<PuArrivalVouchBean *> ArrivalDAO::queryPuArrivalBy(QDate date){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, pu_type, "
            " person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM pu_arrival_vouch WHERE bus_date='" + date.toString("yyyy-MM-dd")+ "'";
    QueryRunner query  =QueryRunner();
    QList<PuArrivalVouchBean *> list = query.query<PuArrivalVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<PuArrivalVouchBean *> ArrivalDAO::queryPuArrivalBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, pu_type,"
            " person_code, handler, audit_time, created_by, created,"
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM pu_arrival_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+ "' AND bus_date<='" + end.toString("yyyy-MM-dd")+ "'";

    QueryRunner query  =QueryRunner();
    QList<PuArrivalVouchBean *> list = query.query<PuArrivalVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int ArrivalDAO::createPuArrivalVouchs(PuArrivalVouchsBean *bean){
    QString sql = "INSERT INTO pu_arrival_vouchs( "
            " arrival_no, order_no, src_no, supplier_id, product_code, product_style, unit, "
            " quantity, price, tax_price, money, memo, define1, "
            " define2, define3, define4, define5, define6) "
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
int ArrivalDAO::updatePuArrivalVouchs(PuArrivalVouchsBean *bean){
    QString sql = "UPDATE pu_arrival_vouchs "
            " SET supplier_id=?, product_code=?, product_style=?, "
            " unit=?, quantity=?, price=?, tax_price=?, money=?, order_no=?, src_no=?, "
            " memo=?, define1=?, define2=?, define3=?, define4=?, define5=?, define6=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ArrivalDAO::delPuArrivalVouchs(PuArrivalVouchsBean *bean){
    QString sql = "DELETE FROM pu_arrival_vouchs "
            " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ArrivalDAO::delPuArrivalVouchsByNo(QString no){
    QString sql = "DELETE FROM pu_arrival_vouchs "
            " WHERE arrival_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

QList<PuArrivalVouchsBean *> ArrivalDAO::queryPuArrivalVouchsByNo(QString no){
    QString sql = "SELECT a.id, a.arrival_no,a.order_no, a.src_no, a.supplier_id, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money, a.memo, define1, "
            " define2, define3, define4, define5, define6 "
            " FROM pu_arrival_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code WHERE arrival_no='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<PuArrivalVouchsBean *> list = query.query<PuArrivalVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<PuArrivalVouchsBean *> ArrivalDAO::queryPuArrivalVouchsByOrderNo(QString no){
    QString sql = "SELECT a.id, a.arrival_no,a.order_no, a.src_no, a.supplier_id, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money "
            " FROM pu_arrival_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code WHERE order_no='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<PuArrivalVouchsBean *> list = query.query<PuArrivalVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

PuArrivalVouchsBean * ArrivalDAO::getPuArrivalBy(QString no,QString productCode){
    QString sql = "SELECT a.id, a.arrival_no,a.order_no, a.src_no, a.supplier_id, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money "
            " FROM pu_arrival_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code "
            " WHERE arrival_no='" + no +"' AND a.product_code='" + productCode + "' ORDER BY a.id ASC";
    QueryRunner query=QueryRunner();
    PuArrivalVouchsBean *qBean= new PuArrivalVouchsBean;
    return query.read<PuArrivalVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

QSqlQueryModel *ArrivalDAO::querySqlModelArrivalBy(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, pu_type,"
                " person_code, handler, audit_time, created_by, created, "
                " closer, updated_by, updated, status, memo "
                " FROM pu_arrival_vouch WHERE no like '" + no + "%'";

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

QSqlQueryModel *ArrivalDAO::querySqlModelArrivalBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, supplier_id, wh_code, dep_code, pu_type,"
            " person_code, handler, audit_time, created_by, created, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete "
            " FROM pu_arrival_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+
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

PuArrivalVouchsBean *ArrivalDAO::getPuReRdsBy(QString src_no, QString productCode){
    QString sql = "SELECT g.rd_no as src_no,g.product_code , g.quantity-COALESCE(h.sum_qunatity,0) as quantity "
                   " from rd_records g "
                   " LEFT JOIN "
                        " ( SELECT e.src_no,e.product_code,sum(quantity) as sum_qunatity "
                           " from pu_arrival_vouchs e "
                           " inner join pu_arrival_vouch f "
                           " ON e.arrival_no=f.no "
                           " where f.bus_type='02' AND f.is_handle=true AND e.src_no='" + src_no + "' "
                           " GROUP BY e.src_no,e.product_code) h "
                   " ON g.rd_no=h.src_no AND g.product_code=h.product_code "
                   " where g.rd_no='" + src_no +"' AND g.product_code='" + productCode + "' ";
            QueryRunner query=QueryRunner();
    //qDebug() << sql ;
    PuArrivalVouchsBean *qBean= new PuArrivalVouchsBean;
    return query.read<PuArrivalVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

