#include "purddao.h"

PuRdDAO::PuRdDAO()
{
}

int PuRdDAO::getRdImeiCount(QString no){
    QString sql = "SELECT count(*) FROM rd_in_imei "
            " WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}
