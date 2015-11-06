#include "dishesdao.h"
#include <QObject>
DishesDAO::DishesDAO()
{
}

int DishesDAO::createDishes(DishesBean *bean){
    QString sql="INSERT INTO product("
            " product_code, product_name, pinyin_code, assisted_code, pu_price, "
            "en_name, style, unit, type_id, purchase_unit, stock_unit, pu_st_unit, is_raw, price1, price2, price3, m_price1, "
            "m_price2, m_price3, low_discount, status, is_temp_dishes, is_weighing_conf, "
            "is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes, is_purchase, "
            "is_marketing, eat_type, picture1, picture2, picture3 ,created_by, created ) "
    " VALUES ( ?, ?, ?, ?, ?, "
            "?, ?, ?, ?, ?, ?, ?, ?, "
            "?, ?, ?, ?, ?, ?, ?, ?, ?,"
            "?, ?, ?, ?, ?, ?, ?, "
            "?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QString DishesDAO::getMaxId(){
    QString sql="SELECT product_code FROM product ORDER BY product_code desc limit 1 offset 0;";
    QueryRunner query=QueryRunner();
    return query.getValue(DBManager::getDBManager()->getGoinDBConnection(),sql,"00000");

}

int DishesDAO::getByCodeCount(QString code){
    QString sql="SELECT count(product_code) FROM product WHERE product_code='" + code + "'";
    QueryRunner query=QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int DishesDAO::getByTypeCount(QString type){
    QString sql="SELECT count(product_code) FROM product WHERE product_code like '" + type + "%'";
    QueryRunner query=QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int DishesDAO::updateDishes(DishesBean *bean){
    QString sql="UPDATE product "
            " SET product_code=?, product_name=?, pinyin_code=?, assisted_code=?, pu_price=?, "
              "  en_name=?, style=?, unit=?, type_id=?, purchase_unit=?, stock_unit=?, pu_st_unit=?, price1=?, price2=?, price3=?,"
              "  m_price1=?, m_price2=?, m_price3=?, status=?, is_temp_dishes=?,"
              "  is_weighing_conf=?, is_disc=?, is_current_prices=?, is_set=?,"
              "  is_down_pad=?, is_piece_dishes=?, is_marketing=?, eat_type=?,"
              "  picture1=?, picture2=?, picture3=?, low_discount=?, is_purchase=? "
         " WHERE id="+QString::number(bean->id());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);

}

int DishesDAO::delDishes(DishesBean *bean){
    QString sql="DELETE FROM product "
            " WHERE id="+QString::number(bean->id());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<DishesBean *> DishesDAO::queryDishes(){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, purchase_unit, stock_unit, pu_st_unit, price1, price2, price3, m_price1,"
            " m_price2, m_price3, low_discount, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes,"
            " is_marketing, eat_type, picture1, picture2, picture3"
       " FROM product WHERE is_raw=false ORDER BY id asc";
    QueryRunner query=QueryRunner();
    QList<DishesBean *> depList=query.query<DishesBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<DishesBean *> DishesDAO::queryDishesBy(){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, purchase_unit, stock_unit, pu_st_unit, price1, price2, price3, m_price1,"
            " m_price2, m_price3, low_discount, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes,"
            " is_marketing, eat_type, picture1, picture2, picture3"
       " FROM product WHERE status=0 AND is_raw=false ORDER BY id asc ";
    QueryRunner query=QueryRunner();
    QList<DishesBean *> depList=query.query<DishesBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<DishesBean *> DishesDAO::queryDishesByType(QString type){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, purchase_unit, stock_unit, pu_st_unit, price1, price2, price3, m_price1,"
            " m_price2, m_price3, low_discount, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes,"
            " is_marketing, eat_type, picture1, picture2, picture3"
            " FROM product WHERE type_id='"+type+"' AND is_raw=false ORDER BY id asc";
    QueryRunner query=QueryRunner();
    QList<DishesBean *> depList=query.query<DishesBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<DishesBean *> DishesDAO::queryDishesByTypeF(QString type){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, purchase_unit, stock_unit, pu_st_unit, price1, price2, price3, m_price1,"
            " m_price2, m_price3, low_discount, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes,"
            " is_marketing, eat_type, picture1, picture2, picture3"
            " FROM product WHERE status=0 AND type_id='"+type+"' AND is_raw=false ORDER BY id asc";
    QueryRunner query=QueryRunner();
    QList<DishesBean *> depList=query.query<DishesBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QSqlQueryModel * DishesDAO::querySqlModelDishes(){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, price1, price2, price3, m_price1,"
            " m_price2, m_price3, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes,"
            " is_marketing, eat_type ,low_discount"
       " FROM product WHERE is_raw=false ORDER BY id asc";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Dishes Code"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Dishes Name"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Pinyin Code"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Assisted Code"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("English Name"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Style"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Unit"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Price 1"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("Price 2"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("Price 3"));
    model->setHeaderData(12, Qt::Horizontal,QObject::tr("Member Price 1"));
    model->setHeaderData(13, Qt::Horizontal,QObject::tr("Member Price 2"));
    model->setHeaderData(14, Qt::Horizontal,QObject::tr("Member Price 3"));
    model->setHeaderData(15, Qt::Horizontal,QObject::tr("Status"));
    model->setHeaderData(16, Qt::Horizontal,QObject::tr("Is Temp Dishes"));
    model->setHeaderData(17, Qt::Horizontal,QObject::tr("Is Weighing Conf"));
    model->setHeaderData(18, Qt::Horizontal,QObject::tr("Is Disc"));
    model->setHeaderData(19, Qt::Horizontal,QObject::tr("Is Current Prices"));
    model->setHeaderData(20, Qt::Horizontal,QObject::tr("Is Set"));
    model->setHeaderData(21, Qt::Horizontal,QObject::tr("Is Down Pad"));
    model->setHeaderData(22, Qt::Horizontal,QObject::tr("Is Piece Dishes"));
    model->setHeaderData(23, Qt::Horizontal,QObject::tr("Is Marketing"));
    model->setHeaderData(24, Qt::Horizontal,QObject::tr("Eat Type"));
    model->setHeaderData(24, Qt::Horizontal,QObject::tr("Low Discount"));
    return model;
}

QSqlQueryModel * DishesDAO::querySqlModelDishesByType(QString type){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, price1, price2, price3, m_price1,"
            " m_price2, m_price3, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes,"
            " is_marketing, eat_type, picture1, picture2, picture3, low_discount"
       " FROM product WHERE type_id like '"+type+"%' AND is_raw=false ORDER BY id asc";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Dishes Code"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Dishes Name"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Pinyin Code"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Assisted Code"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("English Name"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Style"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Unit"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Price 1"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("Price 2"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("Price 3"));
    model->setHeaderData(12, Qt::Horizontal,QObject::tr("Member Price 1"));
    model->setHeaderData(13, Qt::Horizontal,QObject::tr("Member Price 2"));
    model->setHeaderData(14, Qt::Horizontal,QObject::tr("Member Price 3"));
    model->setHeaderData(15, Qt::Horizontal,QObject::tr("Status"));
    model->setHeaderData(16, Qt::Horizontal,QObject::tr("Is Temp Dishes"));
    model->setHeaderData(17, Qt::Horizontal,QObject::tr("Is Weighing Conf"));
    model->setHeaderData(18, Qt::Horizontal,QObject::tr("Is Disc"));
    model->setHeaderData(19, Qt::Horizontal,QObject::tr("Is Current Prices"));
    model->setHeaderData(20, Qt::Horizontal,QObject::tr("Is Set"));
    model->setHeaderData(21, Qt::Horizontal,QObject::tr("Is Down Pad"));
    model->setHeaderData(22, Qt::Horizontal,QObject::tr("Is Piece Dishes"));
    model->setHeaderData(23, Qt::Horizontal,QObject::tr("Is Marketing"));
    model->setHeaderData(24, Qt::Horizontal,QObject::tr("Eat Type"));
    model->setHeaderData(25, Qt::Horizontal,QObject::tr("Picture1"));
    model->setHeaderData(26, Qt::Horizontal,QObject::tr("Picture2"));
    model->setHeaderData(27, Qt::Horizontal,QObject::tr("Picture3"));
    model->setHeaderData(28, Qt::Horizontal,QObject::tr("Low Discount"));
    return model;
}

QSqlQueryModel * DishesDAO::querySqlModelDishesBy(QString type,QString name,QString pinyin){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, price1, price2, price3, m_price1,"
            " m_price2, m_price3, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes,"
            " is_marketing, eat_type, picture1, picture2, picture3, low_discount"
            " FROM product WHERE type_id like '"+type+"%' AND product_name like '"+name+"%' "
            " AND pinyin_code like '%"+pinyin+"%' AND is_raw=false ORDER BY id asc";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Dishes Code"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Dishes Name"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Pinyin Code"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Assisted Code"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("English Name"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Style"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Unit"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Type"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Price 1"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("Price 2"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("Price 3"));
    model->setHeaderData(12, Qt::Horizontal,QObject::tr("Member Price 1"));
    model->setHeaderData(13, Qt::Horizontal,QObject::tr("Member Price 2"));
    model->setHeaderData(14, Qt::Horizontal,QObject::tr("Member Price 3"));
    model->setHeaderData(15, Qt::Horizontal,QObject::tr("Status"));
    model->setHeaderData(16, Qt::Horizontal,QObject::tr("Is Temp Dishes"));
    model->setHeaderData(17, Qt::Horizontal,QObject::tr("Is Weighing Conf"));
    model->setHeaderData(18, Qt::Horizontal,QObject::tr("Is Disc"));
    model->setHeaderData(19, Qt::Horizontal,QObject::tr("Is Current Prices"));
    model->setHeaderData(20, Qt::Horizontal,QObject::tr("Is Set"));
    model->setHeaderData(21, Qt::Horizontal,QObject::tr("Is Down Pad"));
    model->setHeaderData(22, Qt::Horizontal,QObject::tr("Is Piece Dishes"));
    model->setHeaderData(23, Qt::Horizontal,QObject::tr("Is Marketing"));
    model->setHeaderData(24, Qt::Horizontal,QObject::tr("Eat Type"));
    model->setHeaderData(25, Qt::Horizontal,QObject::tr("Picture1"));
    model->setHeaderData(26, Qt::Horizontal,QObject::tr("Picture2"));
    model->setHeaderData(27, Qt::Horizontal,QObject::tr("Picture3"));
    model->setHeaderData(28, Qt::Horizontal,QObject::tr("Low Discount"));
    return model;
}

DishesBean * DishesDAO::getDishesById(QString id){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, purchase_unit, stock_unit, pu_st_unit, price1, price2, price3, m_price1,"
            " m_price2, m_price3, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes, pu_price, "
            " is_marketing, is_purchase, eat_type, picture1, picture2, picture3, low_discount"
       " FROM product WHERE id="+id;
    QueryRunner query=QueryRunner();
    DishesBean *dBean= new DishesBean;
    return query.read<DishesBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

DishesBean * DishesDAO::getDishesByCode(QString code){
    QString sql="SELECT id, product_code, product_name, pinyin_code, assisted_code,"
            " en_name, style, unit, type_id, purchase_unit, stock_unit, pu_st_unit, price1, price2, price3, m_price1,"
            " m_price2, m_price3, status, is_temp_dishes, is_weighing_conf,"
            " is_disc, is_current_prices, is_set, is_down_pad, is_piece_dishes, pu_price, "
            " is_marketing, is_purchase, eat_type, picture1, picture2, picture3"
            " FROM product WHERE product_code='" + code + "'";
    QueryRunner query=QueryRunner();
    DishesBean *dBean= new DishesBean;
    return query.read<DishesBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
