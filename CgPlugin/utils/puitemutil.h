#ifndef PUITEMUTIL_H
#define PUITEMUTIL_H
#include "bean/ChildItemBean.h"
#include <QObject>
#include "bean/TableIdBean.h"
#include "bean/PuOrderVouchBean.h"
#include "dao/tabledao.h"
#include "dao/orderdao.h"
#include "dao/arrivaldao.h"
#include "common/qkstringutils.h"

class PuItemUtil: public QObject
{
    Q_OBJECT
public:
    PuItemUtil();
    static QString getToDayMaxNo(QString formId,QString table,QDate date,int nCount);
    static QString getToDayMaxOrderId(QString formId,QString table,QDate date);
    static QString getToDayMaxArrivalId(QString formId,QString table,QDate date);
    static QString getToDayMaxOrderId(QDate date);
    static QString getToDayMaxArrivalId(QDate date);

};

#endif // PUITEMUTIL_H
