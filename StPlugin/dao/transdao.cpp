#include "transdao.h"

TransDAO::TransDAO()
{
}

int TransDAO::createTrans(TransVouchBean *bean){
    QString sql = "INSERT INTO st_trans_vouch("
                " tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, creater,"
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, "
                " updated_by, updated, memo)"
        " VALUES (?, ?, ?, ?, ?, ?, ?, "
           " ?, ?, ?, ?, ?, ?, ?, "
           " ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TransDAO::updateTrans(TransVouchBean *bean){
    QString sql = "UPDATE st_trans_vouch"
                " SET tv_date=?, owh_code=?, iwh_code=?, dep_code=?, is_handle=?, "
                " person_code=?, ord_no=?, ird_no=?, handler=?, audit_time=?, status=?, "
                " created_by=?, created=?, creater=?, updated_by=?, updated=?, memo=? "
            " WHERE tv_no='" + bean->tvNo() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TransDAO::delTrans(TransVouchBean *bean){
    QString sql = "DELETE FROM st_trans_vouch "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TransDAO::delTransByNo(TransVouchBean *bean){
    QString sql = "DELETE FROM st_trans_vouch "
            " WHERE tv_no='" + bean->tvNo() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TransDAO::getTransCount(){
    QString sql = "SELECT count(*) FROM st_trans_vouch ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransDAO::getTransCount(QDate date){
    QString sql = "SELECT count(*) FROM st_trans_vouch WHERE created='" + date.toString("yyyy-MM-dd") + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransDAO::getTransCountByNo(QString no){
    QString sql = "SELECT count(*) FROM st_trans_vouch WHERE tv_no='" + no + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int TransDAO::getTransRowNumber(int id){
    QString sql = "select * from (select row_number() over (order by tv_no nulls last) as rownum, id"
            " from st_trans_vouch "
            " order by tv_no ) as b where b.id=" + QString::number(id);
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

TransVouchBean *TransDAO::getTransBeanByNo(QString no){
    QString sql = "SELECT id, tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, "
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, creater, "
                " updated_by, updated, memo "
            " FROM st_trans_vouch WHERE tv_no='" + no + "'";
    QueryRunner query=QueryRunner();
    TransVouchBean *qBean= new TransVouchBean;
    return query.read<TransVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

QList<TransVouchBean *> TransDAO::queryTransBy(QDate date){
    QString sql = "SELECT id, tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, "
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, creater, "
                " updated_by, updated, memo "
            " FROM st_trans_vouch WHERE tv_date='" + date.toString("yyyy-MM-dd")+ "' ORDER BY tv_no ASC";
    QueryRunner query  =QueryRunner();
    QList<TransVouchBean *> list = query.query<TransVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<TransVouchBean *> TransDAO::queryTransBy(QDate start, QDate end){
    QString sql = "SELECT id, tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, "
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, creater, "
                " updated_by, updated, memo "
            " FROM st_trans_vouch WHERE tv_date>='" + start.toString("yyyy-MM-dd")+ "'"
            " AND tv_date<='" + end.toString("yyyy-MM-dd") + "' ORDER BY tv_no ASC";
    QueryRunner query  =QueryRunner();
    QList<TransVouchBean *> list = query.query<TransVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<TransVouchBean *> TransDAO::queryTransByPage(int page, int maxResult){
    QString sql = "SELECT id, tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, "
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, creater, "
                " updated_by, updated, memo "
            " FROM st_trans_vouch ORDER BY tv_no ASC limit " + QString::number(maxResult) +
            " offset " + QString::number(page);
    QueryRunner query  =QueryRunner();
    QList<TransVouchBean *> list = query.query<TransVouchBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int TransDAO::createTransVouchs(TransVouchsBean *bean){
    QString sql = "INSERT INTO st_trans_vouchs( "
                " tv_no, product_code, product_style, unit, quantity, unit_price,"
                " money)"
        "VALUES (?, ?, ?, ?, ?, ?,"
                " ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TransDAO::updateTransVouchs(TransVouchsBean *bean){
    QString sql = "UPDATE st_trans_vouchs "
                " SET product_code=?, product_style=?, unit=?, quantity=?,"
                " unit_price=?, money=?"
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}



int TransDAO::delTransVouchs(TransVouchsBean *bean){
    QString sql = "DELETE FROM st_trans_vouchs "
            " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TransDAO::delTransVouchsByNo(QString no){
    QString sql = "DELETE FROM st_trans_vouchs "
            " WHERE tv_no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}

QList<TransVouchsBean *> TransDAO::queryTransVouchsByNo(QString no){
    QString sql = "SELECT a.id, a.tv_no, a.product_code, b.product_name, a.product_style, a.unit, a.quantity,"
                " a.unit_price, a.money "
            " FROM st_trans_vouchs a INNER JOIN ba_product b on a.product_code=b.product_code "
            " WHERE tv_no='" + no + "'";
    QueryRunner query  =QueryRunner();
    QList<TransVouchsBean *> list = query.query<TransVouchsBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QSqlQueryModel *TransDAO::queryModelTransBy(QDate start, QDate end){
    QString sql = "SELECT id, tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, "
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, creater, "
                " updated_by, updated, memo "
            " FROM st_trans_vouch WHERE tv_date>='" + start.toString("yyyy-MM-dd")+ "'"
            " AND tv_date<='" + end.toString("yyyy-MM-dd") + "' ORDER BY tv_no ASC";
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

QSqlQueryModel *TransDAO::queryModelTransBy(QString no){
    QString sql = "SELECT id, tv_no, tv_date, owh_code, iwh_code, dep_code, person_code, "
                " ord_no, ird_no, handler, is_handle, audit_time, status, created_by, created, creater, "
                " updated_by, updated, memo "
            " FROM st_trans_vouch WHERE tv_no='" + no + "'";
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


