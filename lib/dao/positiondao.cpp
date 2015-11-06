#include "positiondao.h"

PositionDAO::PositionDAO()
{
}

int PositionDAO::createPosition(PositionBean *bean){
    QString sql = "INSERT INTO position("
            " position_code, position_name, wh_code, position_unit, top_sum, "
            " position_desc, position_area, position_level, status, memo)"
            " VALUES (?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int PositionDAO::updatePosition(PositionBean *bean){
    QString sql = "UPDATE position"
                " SET position_name=?, wh_code=?, position_unit=?, "
                " top_sum=?, position_desc=?, position_area=?, position_level=?, "
                " status=?, memo=? "
            " WHERE position_code='" + bean->positionCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int PositionDAO::delPosition(PositionBean *bean){
    QString sql = "DELETE FROM position "
                " WHERE position_code='" + bean->positionCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<PositionBean *> PositionDAO::queryPosition(){
    QString sql = "SELECT position_code, position_name, wh_code, position_unit, top_sum, "
            " position_desc, position_area, position_level, status, memo"
            " FROM position ORDER BY position_code ASC";
    QueryRunner query=QueryRunner();
    QList<PositionBean *> pList = query.query<PositionBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

PositionBean * PositionDAO::getPositionById(QString code){
    QString sql = "SELECT position_code, position_name, wh_code, position_unit, top_sum, "
            " position_desc, position_area, position_level, status, memo"
            " FROM position WHERE position_code='" + code + "'";
    QueryRunner query = QueryRunner();
    PositionBean *dBean = new PositionBean;
    return query.read<PositionBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
