#include "productdao.h"

ProductDAO::ProductDAO()
{
}

int ProductDAO::createProduct(ProductBean *bean){
    QString sql="INSERT INTO ba_product("
            " product_name, product_code, product_no, pinyin_code, style,"
            " type_id, supplier_id, wh_code, position_code, is_raw, is_sale,"
            " is_purchase, is_comsume, purchase_unit, stock_unit, pu_st_unit,"
            " st_do_unit, dose_unit, sale_unit, is_pos_purchase, is_pos_down,"
            " is_sale_consumption, is_weighing_conf, low_sum, top_sum, pu_price,"
            " created_by, created, status, memo, is_imei)"
            " VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?,"
            " ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ProductDAO::updateProduct(ProductBean *bean){
    QString sql="UPDATE ba_product"
                " SET product_name=?, product_code=?, product_no=?, pinyin_code=?,"
                " style=?, type_id=?, supplier_id=?, wh_code=?, position_code=?,"
                " is_raw=?, is_sale=?, is_purchase=?, is_comsume=?, purchase_unit=?,"
                " stock_unit=?, pu_st_unit=?, st_do_unit=?, dose_unit=?, sale_unit=?,"
                " is_pos_purchase=?, is_pos_down=?, is_sale_consumption=?, is_weighing_conf=?,"
                " low_sum=?, top_sum=?, pu_price=?, created_by=?, created=?, status=?,"
                " memo=?, is_imei=? "
                " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int ProductDAO::delProduct(ProductBean *bean){
    QString sql="DELETE FROM ba_product "
                " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<ProductBean *> ProductDAO::queryProduct(){
    QString sql="SELECT id, product_name, product_code, product_no, pinyin_code, style,"
                " type_id, supplier_id, wh_code, position_code, is_raw, is_sale,"
                " is_purchase, is_comsume, purchase_unit, stock_unit, pu_st_unit,"
                " st_do_unit, dose_unit, sale_unit, is_pos_purchase, is_pos_down,"
                " is_sale_consumption, is_weighing_conf, low_sum, top_sum, pu_price,"
                " created_by, created, status, memo, is_imei"
                " FROM ba_product WHERE is_raw=true OR is_purchase=true ORDER BY product_code ASC";
    QueryRunner query=QueryRunner();
    QList<ProductBean *> pList = query.query<ProductBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

QList<ProductBean *> ProductDAO::queryProductByType(QString typeCode){
    QString sql="SELECT id, product_name, product_code, product_no, pinyin_code, style,"
                " type_id, supplier_id, wh_code, position_code, is_raw, is_sale,"
                " is_purchase, is_comsume, purchase_unit, stock_unit, pu_st_unit,"
                " st_do_unit, dose_unit, sale_unit, is_pos_purchase, is_pos_down,"
                " is_sale_consumption, is_weighing_conf, low_sum, top_sum, pu_price,"
                " created_by, created, status, memo, is_imei"
            " FROM ba_product WHERE type_id='" + typeCode + "' AND is_raw=true ORDER BY product_code ASC";
    QueryRunner query = QueryRunner();
    QList<ProductBean *> pList = query.query<ProductBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

ProductBean* ProductDAO::getProductById(QString id){
    QString sql="SELECT id, product_name, product_code, product_no, pinyin_code, style,"
                " type_id, supplier_id, wh_code, position_code, is_raw, is_sale,"
                " is_purchase, is_comsume, purchase_unit, stock_unit, pu_st_unit,"
                " st_do_unit, dose_unit, sale_unit, is_pos_purchase, is_pos_down,"
                " is_sale_consumption, is_weighing_conf, low_sum, top_sum, pu_price,"
                " created_by, created, status, memo, is_imei"
            " FROM ba_product WHERE id=" + id ;
    QueryRunner query = QueryRunner();
    ProductBean *dBean = new ProductBean;
    return query.read<ProductBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

ProductBean* ProductDAO::getProductByCode(QString code){
    QString sql="SELECT id, product_name, product_code, product_no, pinyin_code, style,"
                " type_id, supplier_id, wh_code, position_code, is_raw, is_sale,"
                " is_purchase, is_comsume, purchase_unit, stock_unit, pu_st_unit,"
                " st_do_unit, dose_unit, sale_unit, is_pos_purchase, is_pos_down,"
                " is_sale_consumption, is_weighing_conf, low_sum, top_sum, pu_price,"
                " created_by, created, status, memo, is_imei"
            " FROM ba_product WHERE product_code='" + code + "'";
    QueryRunner query = QueryRunner();
    ProductBean *dBean = new ProductBean;
    return query.read<ProductBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

QString ProductDAO::getMaxId(){
    QString sql="SELECT product_code FROM ba_product ORDER BY product_code DESC limit 1 offset 0;";
    QueryRunner query=QueryRunner();
    return query.getValue(DBManager::getDBManager()->getGoinDBConnection(),sql,"00000");
}

int ProductDAO::getByTypeCount(QString type){
    QString sql="SELECT count(product_code) FROM ba_product WHERE product_code like '" + type + "%'";
    QueryRunner query=QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

int ProductDAO::getByCodeCount(QString code){
    QString sql="SELECT count(product_code) FROM ba_product WHERE product_code='" + code + "'";
    QueryRunner query=QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}
QSqlQueryModel* ProductDAO::querySqlModelProductByType(QString typeCode){
    QString sql="SELECT id,product_code, product_name, pinyin_code, product_no, style,"
                " type_id, purchase_unit, stock_unit, pu_st_unit,st_do_unit, dose_unit, sale_unit, "
                " low_sum, top_sum, pu_price,is_purchase, is_comsume, is_raw, is_sale,"
                " is_pos_purchase, is_pos_down,is_sale_consumption, is_weighing_conf,"
                " created_by, created, status, memo, is_imei"
            " FROM ba_product WHERE type_id LIKE '" + typeCode + "%' AND is_raw=true ORDER BY product_code ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Product Code"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Product Name"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Pinyin Code"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Assisted Code"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Style"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Product Type"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Purchase Unit"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Stock Unit"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Pu St Unit"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("St Do Unit"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("Dose Unit"));
    model->setHeaderData(12, Qt::Horizontal,QObject::tr("Sale Unit"));
    model->setHeaderData(13, Qt::Horizontal,QObject::tr("Low Sum"));
    model->setHeaderData(14, Qt::Horizontal,QObject::tr("Top Sum"));
    model->setHeaderData(15, Qt::Horizontal,QObject::tr("Purchase Price"));
    model->setHeaderData(16, Qt::Horizontal,QObject::tr("Is Purchase"));
    model->setHeaderData(17, Qt::Horizontal,QObject::tr("Is Comsume"));
    model->setHeaderData(18, Qt::Horizontal,QObject::tr("Is Raw"));
    model->setHeaderData(19, Qt::Horizontal,QObject::tr("Is Sale"));
    model->setHeaderData(20, Qt::Horizontal,QObject::tr("Is Pos Purchase"));
    model->setHeaderData(21, Qt::Horizontal,QObject::tr("Is Pos Down"));
    model->setHeaderData(22, Qt::Horizontal,QObject::tr("Is Sale Consumption"));
    model->setHeaderData(23, Qt::Horizontal,QObject::tr("Is Weighing Conf"));
    model->setHeaderData(24, Qt::Horizontal,QObject::tr("Create By"));
    model->setHeaderData(25, Qt::Horizontal,QObject::tr("Create Time"));
    model->setHeaderData(26, Qt::Horizontal,QObject::tr("Status"));
    model->setHeaderData(27, Qt::Horizontal,QObject::tr("Memo"));
    return model;
}

QSqlQueryModel* ProductDAO::querySqlModelProductBy(QString typeCode, QString name, QString pinyin){

    QString sql="SELECT id,product_code, product_name, pinyin_code, product_no, style,"
                " type_id, purchase_unit, stock_unit, pu_st_unit,st_do_unit, dose_unit, sale_unit, "
                " low_sum, top_sum, pu_price,is_purchase, is_comsume, is_raw, is_sale,"
                " is_pos_purchase, is_pos_down,is_sale_consumption, is_weighing_conf,"
                " created_by, created, status, memo, is_imei"
            " FROM ba_product WHERE type_id LIKE '" + typeCode + "%' "
            " AND product_name LIKE '%" + name +"%' AND pinyin_code LIKE '%" + pinyin + "%' AND is_raw=true ORDER BY product_code ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Product Code"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Product Name"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Pinyin Code"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Assisted Code"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Style"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Product Type"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Purchase Unit"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Stock Unit"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Pu St Unit"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("St Do Unit"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("Dose Unit"));
    model->setHeaderData(12, Qt::Horizontal,QObject::tr("Sale Unit"));
    model->setHeaderData(13, Qt::Horizontal,QObject::tr("Low Sum"));
    model->setHeaderData(14, Qt::Horizontal,QObject::tr("Top Sum"));
    model->setHeaderData(15, Qt::Horizontal,QObject::tr("Purchase Price"));
    model->setHeaderData(16, Qt::Horizontal,QObject::tr("Is Purchase"));
    model->setHeaderData(17, Qt::Horizontal,QObject::tr("Is Comsume"));
    model->setHeaderData(18, Qt::Horizontal,QObject::tr("Is Raw"));
    model->setHeaderData(19, Qt::Horizontal,QObject::tr("Is Sale"));
    model->setHeaderData(20, Qt::Horizontal,QObject::tr("Is Pos Purchase"));
    model->setHeaderData(21, Qt::Horizontal,QObject::tr("Is Pos Down"));
    model->setHeaderData(22, Qt::Horizontal,QObject::tr("Is Sale Consumption"));
    model->setHeaderData(23, Qt::Horizontal,QObject::tr("Is Weighing Conf"));
    model->setHeaderData(24, Qt::Horizontal,QObject::tr("Create By"));
    model->setHeaderData(25, Qt::Horizontal,QObject::tr("Create Time"));
    model->setHeaderData(26, Qt::Horizontal,QObject::tr("Status"));
    model->setHeaderData(27, Qt::Horizontal,QObject::tr("Memo"));
    return model;
}

