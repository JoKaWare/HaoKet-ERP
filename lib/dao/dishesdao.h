#ifndef DISHESDAO_H
#define DISHESDAO_H
#include <QList>
#include <QSqlQueryModel>
#include "bean/DishesBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"
class LIBSHARED_EXPORT DishesDAO
{
public:
    DishesDAO();
    static int createDishes(DishesBean *bean);
    static int updateDishes(DishesBean *bean);
    static int delDishes(DishesBean *bean);
    static int getByCodeCount(QString code);
    static int getByTypeCount(QString type);
    static QList<DishesBean *> queryDishes();
    static QList<DishesBean *> queryDishesBy();
    static QList<DishesBean *> queryDishesByType(QString type);
    static QList<DishesBean *> queryDishesByTypeF(QString type);
    static DishesBean * getDishesById(QString id);
    static DishesBean * getDishesByCode(QString code);
    static QSqlQueryModel * querySqlModelDishes();
    static QSqlQueryModel * querySqlModelDishesByType(QString type);
    static QSqlQueryModel * querySqlModelDishesBy(QString type,QString name,QString pinyin);
    static QString getMaxId();
};

#endif // DISHESDAO_H
