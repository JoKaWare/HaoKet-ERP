#include "markettypedao.h"

MarketTypeDAO::MarketTypeDAO()
{
}

int MarketTypeDAO::createMarketType(MarketTypeBean *bean){
    QString sql="INSERT INTO market_type("
            "market_type_name, market_type_start,market_type_alia,memo)"
            " VALUES (?, ?, ?, ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int MarketTypeDAO::updateMarketType(MarketTypeBean *bean){
    QString sql="UPDATE market_type "
            "SET market_type_name=?, market_type_start=?, market_type_alia=?, memo=? "
            "WHERE market_type_id="+QString::number(bean->marketTypeId());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int MarketTypeDAO::delMarketType(MarketTypeBean *bean){
    QString sql="DELETE FROM market_type "
            " WHERE market_type_id="+QString::number(bean->marketTypeId());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<MarketTypeBean *> MarketTypeDAO::queryMarketType(){
    QString sql="SELECT market_type_id, market_type_name, market_type_start,market_type_alia,memo "
            " FROM market_type order by market_type_id asc";
    QueryRunner query=QueryRunner();
    QList<MarketTypeBean *> depList=query.query<MarketTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

MarketTypeBean *MarketTypeDAO::getMarketTypeById(QString id){
    QString sql="SELECT market_type_id, market_type_name, market_type_start,market_type_alia,memo  "
            " FROM market_type where market_type_id=" + id;
    QueryRunner query=QueryRunner();
    MarketTypeBean *dBean= new MarketTypeBean;
    return query.read<MarketTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

MarketTypeBean *MarketTypeDAO::getMarketTypeByName(QString name){
    QString sql="SELECT market_type_id, market_type_name, market_type_start,market_type_alia,memo  "
            " FROM market_type where market_type_name='" + name + "'";
    QueryRunner query=QueryRunner();
    MarketTypeBean *dBean= new MarketTypeBean;
    return query.read<MarketTypeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
