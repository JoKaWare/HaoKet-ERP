#ifndef ITEMUTIL_H
#define ITEMUTIL_H

#include <QObject>
#include "bean/ChildItemBean.h"
#include <QObject>
#include "bean/TableIdBean.h"

#include "dao/tabledao.h"
#include "common/qkstringutils.h"
class LIBSHARED_EXPORT ItemUtil : public QObject
{
    Q_OBJECT
public:
    explicit ItemUtil(QObject *parent = 0);
    static QString getToDayMaxNo(QString formId,QString table,QDate date,int nCount);
    static QString getToDayMaxRdNo(QDate date);

signals:
    
public slots:
    
};

#endif // ITEMUTIL_H
