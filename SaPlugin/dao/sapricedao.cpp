#include "sapricedao.h"

SaPriceDAO::SaPriceDAO()
{
}

int SaPriceDAO::createSaPrice(SaPriceBean *bean){
    QString sql = "INSERT INTO sa_price_report("
            " no, product_code, price, uprice1, uprice2, uprice3, sales_cost, "
            " low_sum, description, updated_by, updated) "
        " VALUES (?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaPriceDAO::updateSaPrice(SaPriceBean *bean){
    QString sql = "UPDATE sa_price_report "
                " SET no=?, product_code=?, price=?, uprice1=?, uprice2=?, uprice3=?, "
                " sales_cost=?, low_sum=?, description=?, updated_by=?, updated=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaPriceDAO::delSaPrice(SaPriceBean *bean){
    QString sql = "DELETE FROM sa_price_report WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int SaPriceDAO::delSaPrice(QString no){
    QString sql = "DELETE FROM sa_price_report WHERE no='" + no + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int SaPriceDAO::createSaPriceHis(SaPriceBean *bean){
    QString sql = "INSERT INTO sa_price_report_his("
            " no, product_code, price, uprice1, uprice2, uprice3, sales_cost, "
            " low_sum, description, updated_by, updated) "
        " VALUES (?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

SaPriceBean *SaPriceDAO::getSaPriceBy(QString code){
    QString sql = "SELECT a.*,b.product_name,b.style,b.stock_unit as unit "
            " FROM sa_price_report a, ba_product b WHERE a.product_code='" + code + "' AND a.product_code=b.product_code ";
    QueryRunner query=QueryRunner();
    SaPriceBean *qBean= new SaPriceBean;
    return query.read<SaPriceBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,qBean);
}

int SaPriceDAO::getSaPriceCount(){
    QString sql = "SELECT count(*) FROM sa_price_report ";
    QueryRunner query = QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<SaPriceBean *> SaPriceDAO::querySaPricee(){
    QString sql = "SELECT a.*,b.product_name,b.style,b.stock_unit as unit "
            " FROM sa_price_report a,ba_product b WHERE a.product_code=b.product_code ORDER BY a.id";
    QueryRunner query  =QueryRunner();
    QList<SaPriceBean *> list = query.query<SaPriceBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

QList<SaPriceBean *> SaPriceDAO::querySaPriceeByWh(QString whCode){
    QString sql = "SELECT a.*,b.product_name,b.style,b.stock_unit as unit,c.wh_code,c.sum "
            " FROM sa_price_report a,ba_product b,stock c "
            " WHERE a.product_code=b.product_code AND c.wh_code='" + whCode +
            "' AND c.product_code=a.product_code ORDER BY a.id";
    QueryRunner query  =QueryRunner();
    QList<SaPriceBean *> list = query.query<SaPriceBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}

