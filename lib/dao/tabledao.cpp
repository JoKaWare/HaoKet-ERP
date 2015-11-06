#include "tabledao.h"

TableDAO::TableDAO()
{
}

int TableDAO::createTable(TableIdBean *bean){
    QString sql = "INSERT INTO tableid("
            " table_code, table_name, table_no, table_length, table_date, memo)"
        " VALUES (?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TableDAO::updateTable(TableIdBean *bean){
    QString sql = "UPDATE tableid "
            " SET table_code=?, table_name=?, table_no=?, table_length=?, table_date=?, "
             "   memo=?  "
            " WHERE table_code='" + bean->tableCode() + "'";
    QueryRunner query  =QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TableDAO::delTable(TableIdBean *bean){
    QString sql = "DELETE FROM tableid "
            " WHERE table_code='" + bean->tableCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<TableIdBean *> TableDAO::queryTable(){
    QString sql = "SELECT table_code, table_name, table_no, table_length,table_date, memo "
            " FROM tableid";
    QueryRunner query  =QueryRunner();
    QList<TableIdBean *> list = query.query<TableIdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

int TableDAO::getTableCount(QString id){
    QString sql = "SELECT count(*) FROM tableid WHERE table_code='" + id + "' ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}
TableIdBean *TableDAO::getTableById(QString id){
    QString sql = "SELECT table_code, table_name, table_no, table_length,table_date, memo "
            " FROM tableid where table_code='" + id + "'";
    QueryRunner query=QueryRunner();
    TableIdBean *bean= new TableIdBean;
    return query.read<TableIdBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}
