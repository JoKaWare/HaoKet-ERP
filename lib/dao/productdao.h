#ifndef PRODUCTDAO_H
#define PRODUCTDAO_H
#include <QList>
#include <QSqlQueryModel>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "dao/producttypedao.h"
#include "lib_global.h"

class LIBSHARED_EXPORT ProductDAO
{
public:
    ProductDAO();
    static int createProduct(ProductBean *bean);
    static int updateProduct(ProductBean *bean);
    static int delProduct(ProductBean *bean);
    static QList<ProductBean *> queryProduct();
    static QList<ProductBean *> queryProductByType(QString typeCode);
    static ProductBean * getProductById(QString id);
    static ProductBean * getProductByCode(QString id);
    static QSqlQueryModel * querySqlModelProductByType(QString typeCode);
    static QSqlQueryModel * querySqlModelProductBy(QString typeCode,QString name,QString pinyin);
    static QString getMaxId();
    static int getByCodeCount(QString code);
    static int getByTypeCount(QString type);
};

#endif // PRODUCTDAO_H
