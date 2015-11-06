#include "rddao.h"

RdDAO::RdDAO()
{
}

int RdDAO::createRd(RdBean *bean){
    QString sql = "INSERT INTO rd_record("
            " bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code,"
            " st_code, cus_code, supplier_id, order_no, handler, audit_time,"
            " created_by, created, creater, memo, status, bill_no, is_bill,is_handle,imei_audit)"
        " VALUES (?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int RdDAO::updateRd(RdBean *bean){
    QString sql = "UPDATE rd_record"
            " SET bus_date=?, rd_flag=?, vouch_type=?, bus_type=?, "
               " vouch_source=?, bus_no=?, wh_code=?, position_code=?, dep_code=?, "
               " person_code=?, pt_code=?, st_code=?, cus_code=?, supplier_id=?, "
               " order_no=?, handler=?, audit_time=?, created_by=?, created=?, "
               " memo=?, status=?, bill_no=?, is_bill=?, is_handle=?, creater=?, "
               " imei_audit=?, accounter=?, keep_time=? "
            " WHERE rd_no='" + bean->rdNo() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int RdDAO::delRd(RdBean *bean){
    QString sql = "DELETE FROM rd_record WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int RdDAO::delRdByNo(RdBean *bean){
    QString sql = "DELETE FROM rd_record WHERE rd_no='" + bean->rdNo() + "' ";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int RdDAO::getRdCount(QString vouchType){
    QString sql = "SELECT count(*) FROM rd_record WHERE vouch_type='" + vouchType + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int RdDAO::getRdsCountByPr(QString productCode){
    QString sql = "SELECT count(*) FROM rd_records WHERE product_code='" + productCode + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int RdDAO::getRdsCountByVen(QString venCode){
    QString sql = "SELECT count(*) FROM rd_record WHERE supplier_id='" + venCode + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int RdDAO::getRdsCountByWh(QString whCode){
    QString sql = "SELECT count(*) FROM rd_record WHERE wh_code='" + whCode + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int RdDAO::getRdRowNumber(QString vouchType,int id){
    QString sql = "select * from (select row_number() over (order by rd_no nulls last) as rownum, id"
            " from rd_record where vouch_type='" + vouchType + "'"
            " order by rd_no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int RdDAO::getRdCount(QDate date){
    QString sql = "SELECT count(*) FROM rd_record WHERE date_trunc('DAY', created)='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}
int RdDAO::getRdCountByNo(QString no){
    QString sql = "SELECT count(*) FROM rd_record WHERE rd_no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

RdBean *RdDAO::getRdByNo(QString no){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, accounter, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit "
            " FROM rd_record WHERE rd_no='" + no + "' ";
    QueryRunner query=QueryRunner();
    RdBean *qBean= new RdBean;
    return query.read<RdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

RdBean *RdDAO::getRdByBusNo(QString no,QString vouch_type){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, accounter, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE bus_no='" + no + "' AND vouch_type='" + vouch_type + "'";
    QueryRunner query=QueryRunner();
    RdBean *qBean= new RdBean;
    return query.read<RdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}
QList<RdBean *> RdDAO::queryRdBy(QDate date){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, accounter, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE WHERE bus_date='" + date.toString("yyyy-MM-dd")+ "'";
    QueryRunner query  =QueryRunner();
    QList<RdBean *> list = query.query<RdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdBean *>  RdDAO::queryRdBy(QDate start, QDate end){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, accounter, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE bus_date>='" + start.toString("yyyy-MM-dd") +
            "' AND bus_date<='" + end.toString("yyyy-MM-dd")+ "'";
    QueryRunner query  =QueryRunner();
    QList<RdBean *> list = query.query<RdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<RdBean *>  RdDAO::queryRdByPage(QString vouchType,int page, int maxResult){
    int offset = 0;
    if(page < 0){
        offset = 0;
    }else offset = page;
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, accounter, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE vouch_type='" + vouchType + "'"
            " ORDER BY rd_no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(offset);
    QueryRunner query  =QueryRunner();
    QList<RdBean *> list = query.query<RdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int RdDAO::createRds(RdsBean *bean){
    QString sql = "INSERT INTO rd_records("
                " rd_no, product_code, unit, quantity, unit_price, money, a_money, "
                " memo, product_style, bus_no, order_no, src_no , define1, "
            " define2, define3, define4, define5, define6) "
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?,"
            " ?, ?, ?, ?, ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int RdDAO::updateRds(RdsBean *bean){
    QString sql = "UPDATE rd_records"
                " SET id=?, rd_no=?, product_code=?, unit=?, quantity=?, unit_price=?, "
                " money=?, a_money=?, memo=?, product_style=?, bus_no=?, order_no=?, src_no=?, is_account=?, "
                " define1=?, define2=?, define3=?, define4=?, define5=?, define6=? "
            "WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int RdDAO::delRds(RdsBean *bean){
    QString sql = "DELETE FROM rd_records WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int RdDAO::delRdsByNo(QString no){
    QString sql = "DELETE FROM rd_records WHERE rd_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

RdsBean *RdDAO::getRdsBy(QString id){
    QString sql = "SELECT a.id, a.rd_no, a.product_code, b.product_name,a.unit, a.quantity, a.unit_price, "
                " a.squantity, a.money, a.a_money, "
                " a.memo, a.product_style, a.bus_no, a.order_no, a.src_no, a.is_account, define1, "
                " define2, define3, define4, define5, define6 "
                " FROM rd_records a INNER JOIN ba_product b on a.product_code=b.product_code "
                " WHERE a.id=" + id + " ORDER BY id ASC";
    QueryRunner query=QueryRunner();
    RdsBean *qBean= new RdsBean;
    return query.read<RdsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}
QList<RdsBean *> RdDAO::queryRdsBy(QString no){
    QString sql = "SELECT a.id, a.rd_no, a.product_code, b.product_name,a.unit, a.quantity, a.unit_price, "
                " a.squantity, a.money, a.a_money, "
                " a.memo, a.product_style, a.bus_no, a.order_no, a.src_no, a.is_account, define1, "
                " define2, define3, define4, define5, define6 "
                " FROM rd_records a INNER JOIN ba_product b on a.product_code=b.product_code "
                " WHERE rd_no='" + no + "' ORDER BY id ASC";
    QueryRunner query  =QueryRunner();
    QList<RdsBean *> list = query.query<RdsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QSqlQueryModel *RdDAO::querySqlModelRdByLike(QString no,int rdFlag,QString vouchType){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, memo, status, bill_no, is_bill "
            " FROM rd_record WHERE no like '" + no + "%' AND rd_flag=" + QString::number(rdFlag) +
            " AND vouch_type LIKE '" + vouchType + "%'";

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::PropertyConfigurator::configure(QApplication::applicationDirPath() + "/log4j.properties");
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;

}

QSqlQueryModel *RdDAO::querySqlModelRdByLike(QDate start, QDate end,int rdFlag,QString vouchType){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, memo, creater, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE bus_date>='" + start.toString("yyyy-MM-dd") +
            "' AND bus_date<='" + end.toString("yyyy-MM-dd") + "' AND rd_flag=" + QString::number(rdFlag) +
            " AND vouch_type LIKE '" + vouchType + "%' ORDER BY id ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::PropertyConfigurator::configure(QApplication::applicationDirPath() + "/log4j.properties");
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;

}

QSqlQueryModel *RdDAO::querySqlModelRdByLike(QDate start, QDate end,QString vouchType){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, memo, creater, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE bus_date>='" + start.toString("yyyy-MM-dd") +
            "' AND bus_date<='" + end.toString("yyyy-MM-dd") + "' "
            " AND vouch_type LIKE '" + vouchType + "%' ORDER BY id ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::PropertyConfigurator::configure(QApplication::applicationDirPath() + "/log4j.properties");
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;

}

QSqlQueryModel *RdDAO::querySqlModelRdBy(QString no,int rdFlag,QString vouchType){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE no like '" + no + "%' AND rd_flag=" + QString::number(rdFlag) +
            " AND vouch_type='" + vouchType + "'";

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::PropertyConfigurator::configure(QApplication::applicationDirPath() + "/log4j.properties");
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;

}

QSqlQueryModel *RdDAO::querySqlModelRdBy(QDate start, QDate end,int rdFlag,QString vouchType){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE bus_date>='" + start.toString("yyyy-MM-dd") +
            "' AND bus_date<='" + end.toString("yyyy-MM-dd") + "' AND rd_flag=" + QString::number(rdFlag) +
            " AND vouch_type='" + vouchType + "' ORDER BY id ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::PropertyConfigurator::configure(QApplication::applicationDirPath() + "/log4j.properties");
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;

}

QSqlQueryModel *RdDAO::querySqlModelRdBy(QString no,QString vouchType){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE no like '" + no + "%'"
            " AND vouch_type='" + vouchType + "'";

    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::PropertyConfigurator::configure(QApplication::applicationDirPath() + "/log4j.properties");
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;

}

QSqlQueryModel *RdDAO::querySqlModelRdBy(QDate start, QDate end,QString vouchType){
    QString sql = "SELECT id, bus_date, rd_no, rd_flag, vouch_type, bus_type, vouch_source, "
            " bus_no, wh_code, position_code, dep_code, person_code, pt_code, "
            " st_code, cus_code, supplier_id, order_no, handler, is_handle, audit_time, "
            " created_by, created, creater, memo, status, bill_no, is_bill, imei_audit  "
            " FROM rd_record WHERE bus_date>='" + start.toString("yyyy-MM-dd") +
            "' AND bus_date<='" + end.toString("yyyy-MM-dd") + "'"
            " AND vouch_type='" + vouchType + "' ORDER BY id ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQuery query(DBManager::getDBManager()->getGoinDBConnection());
    if(!query.exec(sql)){
       QSqlError error = query.lastError() ;
       Log4Qt::PropertyConfigurator::configure(QApplication::applicationDirPath() + "/log4j.properties");
       Log4Qt::Logger *logger = Log4Qt::Logger::rootLogger();
       logger->error(error.text());
    }else{
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    }
    return model;

}

int RdDAO::getRdInImeiCount(QString no){
    QString sql = "SELECT count(*) FROM rd_in_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int RdDAO::getRdOutImeiCount(QString no){
    QString sql = "SELECT count(*) FROM rd_out_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

