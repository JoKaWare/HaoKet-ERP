#include "reportdao.h"

ReportDAO::ReportDAO()
{
}

int ReportDAO::createRpt(ReportFormatBean *bean){
    QString sql = "INSERT INTO report_format("
            " win_id, report_title, report_format, created_by, creater, "
            " created)"
        " VALUES (?, ?, ?, ?, ?, ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ReportDAO::updateRpt(ReportFormatBean *bean){
    QString sql = "UPDATE report_format "
            " SET report_title=?, report_format=?, created_by=?, "
               " creater=?, created=?"
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ReportDAO::delRpt(ReportFormatBean *bean){
    QString sql="DELETE FROM report_format "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<ReportFormatBean *> ReportDAO::queryRpt(){

    QString sql = "SELECT id, win_id, report_title, report_format, created_by, creater, "
            " created FROM report_format";
    QueryRunner query=QueryRunner();
    QList<ReportFormatBean *> list=query.query<ReportFormatBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}


QList<ReportFormatBean *> ReportDAO::queryRptBy(QString winId){

    QString sql = "SELECT id, win_id, report_title, report_format, created_by, creater, "
            " created FROM report_format WHERE win_id=" + winId + " ORDER BY id ASC";
    QueryRunner query=QueryRunner();
    QList<ReportFormatBean *> list=query.query<ReportFormatBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

ReportFormatBean * ReportDAO::getRptById(QString id){

    QString sql = "SELECT id, win_id, report_title, report_format, created_by, creater, "
            " created FROM report_format WHERE id=" + id;
    QueryRunner query=QueryRunner();

    ReportFormatBean *dBean= new ReportFormatBean;
    return query.read<ReportFormatBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);


}
