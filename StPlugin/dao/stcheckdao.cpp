#include "stcheckdao.h"

StCheckDAO::StCheckDAO()
{
}

int StCheckDAO::createCheck(CheckVouchBean *bean){
    QString sql = "INSERT INTO st_check_vouch( "
            " no, bus_date, bus_type, sa_type, cus_code,  "
            " wh_code, dep_code, person_code, handler, audit_time, "
            " is_handle, is_complete, created_by, creater, created, closer, "
            " updated_by, updater, updated, status, memo) "
        " VALUES (?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, "
            " ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StCheckDAO::updateCheck(CheckVouchBean *bean){
    QString sql = "UPDATE st_check_vouch "
                " SET no=?, bus_date=?, bus_type=?, sa_type=?, cus_code=?,  "
                " wh_code=?, dep_code=?, person_code=?, handler=?, "
                " audit_time=?, is_handle=?, is_complete=?, created_by=?, creater=?, "
                " created=?, closer=?, updated_by=?, updater=?, updated=?, status=?, "
                " memo=?"
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StCheckDAO::delCheck(CheckVouchBean *bean){
    QString sql = "DELETE FROM st_check_vouch "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StCheckDAO::delCheckByNo(CheckVouchBean *bean){
    QString sql = "DELETE FROM st_check_vouch "
            " WHERE no='" + bean->no() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

CheckVouchBean * StCheckDAO::getCheckByNo(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, creater, "
            " closer, updated_by, updated, updater, status, memo,is_handle, is_complete"
            " FROM st_check_vouch WHERE no='" + no + "'";
    QueryRunner query=QueryRunner();
    CheckVouchBean *qBean= new CheckVouchBean;
    return query.read<CheckVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}
int StCheckDAO::getCheckCount(){
    QString sql = "SELECT count(*) FROM st_check_vouch ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StCheckDAO::getCheckCount(QString bus_type){
    QString sql = "SELECT count(*) FROM st_check_vouch WHERE bus_type='" + bus_type + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StCheckDAO::getCheckRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by no nulls last) as rownum, id"
            " from st_check_vouch "
            " order by no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StCheckDAO::getCheckCount(QDate date){
    QString sql = "SELECT count(*) FROM st_check_vouch WHERE date_trunc('DAY', created)='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int StCheckDAO::getCheckCountByNo(QString no){
    QString sql = "SELECT count(*) FROM st_check_vouch WHERE no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<CheckVouchBean *> StCheckDAO::queryCheckByPage(int page ,int maxResult){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM st_check_vouch ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<CheckVouchBean *> list = query.query<CheckVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}


QList<CheckVouchBean *> StCheckDAO::queryCheckByPage(int page ,int maxResult,QString bus_type){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM st_check_vouch WHERE bus_type='" + bus_type + "' ORDER BY no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<CheckVouchBean *> list = query.query<CheckVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<CheckVouchBean *> StCheckDAO::queryCheckBy(QDate date){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type, "
            " person_code, handler, audit_time, created_by, created, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM st_check_vouch WHERE bus_date='" + date.toString("yyyy-MM-dd")+ "'";
    QueryRunner query  =QueryRunner();
    QList<CheckVouchBean *> list = query.query<CheckVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<CheckVouchBean *> StCheckDAO::queryCheckBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete"
            " FROM st_check_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+ "' AND bus_date<='" + end.toString("yyyy-MM-dd")+ "'";

    QueryRunner query  =QueryRunner();
    QList<CheckVouchBean *> list = query.query<CheckVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int StCheckDAO::createCheckVouchs(CheckVouchsBean *bean){
    QString sql = "INSERT INTO st_check_vouchs( "
            " check_no, wh_code, cus_code, product_code, product_style, unit, "
            " quantity, price, tax_price, money) "
            " VALUES (?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ? )";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
int StCheckDAO::updateCheckVouchs(CheckVouchsBean *bean){
    QString sql = "UPDATE st_check_vouchs "
            " SET cus_code=?, product_code=?, product_style=?, "
             " unit=?, quantity=?, price=?, tax_price=?, money=?, wh_code=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StCheckDAO::delCheckVouchs(CheckVouchsBean *bean){
    QString sql = "DELETE FROM st_check_vouchs "
            " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StCheckDAO::delCheckVouchsByNo(QString no){
    QString sql = "DELETE FROM st_check_vouchs "
            " WHERE check_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

QList<CheckVouchsBean *> StCheckDAO::queryCheckVouchsByNo(QString no){
    QString sql = "SELECT a.id, a.check_no,a.wh_code, a.cus_code, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money "
            " FROM st_check_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code WHERE check_no='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<CheckVouchsBean *> list = query.query<CheckVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<CheckVouchsBean *> StCheckDAO::queryCheckVouchsByOrderNo(QString no){
    QString sql = "SELECT a.id, a.check_no,a.wh_code, a.cus_code, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money "
            " FROM st_check_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code WHERE wh_code='" + no + "' ORDER BY a.id ASC";
    QueryRunner query  =QueryRunner();
    QList<CheckVouchsBean *> list = query.query<CheckVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

CheckVouchsBean * StCheckDAO::getCheckBy(QString no,QString productCode){
    QString sql = "SELECT a.id, a.check_no,a.wh_code, a.cus_code, a.product_code, b.product_name, a.product_style, a.unit, "
            " quantity, price, tax_price, money "
            " FROM st_check_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code "
            " WHERE check_no='" + no +"' AND a.product_code='" + productCode + "' ORDER BY a.id ASC";
    QueryRunner query=QueryRunner();
    CheckVouchsBean *qBean= new CheckVouchsBean;
    return query.read<CheckVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);

}

QSqlQueryModel *StCheckDAO::querySqlModelArrivalBy(QString no){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
                " person_code, handler, audit_time, created_by, created, "
                " closer, updated_by, updated, status, memo "
                " FROM st_check_vouch WHERE no like '" + no + "%'";

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

QSqlQueryModel *StCheckDAO::querySqlModelArrivalBy(QDate start, QDate end){
    QString sql = "SELECT id, no, bus_date, bus_type, cus_code, wh_code, dep_code, sa_type,"
            " person_code, handler, audit_time, created_by, created, "
            " closer, updated_by, updated, status, memo,is_handle, is_complete "
            " FROM st_check_vouch WHERE bus_date>='" + start.toString("yyyy-MM-dd")+
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
