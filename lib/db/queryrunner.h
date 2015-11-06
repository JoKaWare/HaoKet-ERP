#ifndef QUERYRUNNER_H
#define QUERYRUNNER_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantHash>
#include <QVector>
#include <db/abstractqueryrunner.h>
#include "querytool.h"
#include "log4qt/logger.h"
#include "lib_global.h"

class QueryRunner:public QueryTool
{

public:
    QueryRunner();

    template <class T>
    QList<T *> query(QSqlDatabase conn, QString sql){
        QList<T *> list;
        QSqlQuery query(conn);
        query.setForwardOnly(true);
        if(!query.exec(sql)){
            dbErrStr= tr("database error type id:")+QString::number(query.lastError().type())+"  "+query.lastError().text();
            logger()->error(dbErrStr);
            if(query.lastError().type() == QSqlError::ConnectionError)
                conn.close();
            return list;
        }else{
            while(query.next()){
                QSqlRecord sqlResult=query.record();
                QObject *bean=new T;
                for(int i=0;i<sqlResult.count();i++){
                    QByteArray ba = Utils::camelize2(sqlResult.fieldName(i)).toLatin1();
                    //logger()->info(QString::number(sqlResult.field(i).type()));
                    char *name=ba.data();
                    int k=bean->metaObject()->indexOfProperty(name);
                    if(k>=0)
                        bean->metaObject()->property(k).write(bean,sqlResult.value(i));
                }
                T *result=qobject_cast<T *>(bean);

                list.append(result);
            }
        }

        return list;
    }

    template <class T>
    QList<T *> query(QSqlDatabase conn, QString sql,QVector<QVariant> qvar){
        QList<T *> list;
        QSqlQuery query(conn);
        query.prepare(sql);
        for(int i=0;i<qvar.size();i++){
            query.addBindValue(qvar[i]);
        }
        query.setForwardOnly(true);
        if(!query.exec()){
            dbErrStr= tr("database error type id:")+QString::number(query.lastError().type())+"  "+query.lastError().text();
            logger()->error(dbErrStr);
            if(query.lastError().type() == QSqlError::ConnectionError)
                conn.close();
            return list;
        }else{
            while(query.next()){
                QSqlRecord sqlResult=query.record();
                QObject *bean=new T;
                for(int i=0;i<sqlResult.count();i++){
                    QByteArray ba = Utils::camelize2(sqlResult.fieldName(i)).toLatin1();
                    char *name=ba.data();
                    int k=bean->metaObject()->indexOfProperty(name);
                    if(k>=0)
                        bean->metaObject()->property(k).write(bean,sqlResult.value(i));
                }
                T *result=qobject_cast<T *>(bean);

                list.append(result);
            }
        }

        return list;
    }

    template <class T>
    T *read(QSqlDatabase conn, QString sql,QObject *bean){
        QSqlQuery query(conn);
        query.setForwardOnly(true);
        if(!query.exec(sql)){
            dbErrStr= tr("database error type id:")+QString::number(query.lastError().type())+"  "+query.lastError().text();
            logger()->error(dbErrStr);
            if(query.lastError().type() == QSqlError::ConnectionError)
                conn.close();
            return NULL;
        }else{
            if(query.next()){
                QSqlRecord sqlResult=query.record();

                for(int i=0;i<sqlResult.count();i++){
                    QByteArray ba = Utils::camelize2(sqlResult.fieldName(i)).toLatin1();
                    char *name=ba.data();
                    int k=bean->metaObject()->indexOfProperty(name);
                    if(k>=0)
                        bean->metaObject()->property(k).write(bean,sqlResult.value(i));
                }
            }else{
                T *r=new T;
                return r;
            }
        }
        T *result=qobject_cast<T *>(bean);

        return result;
    }


private:
    QString dbErrStr;

};

#endif // QUERYRUNNER_H
