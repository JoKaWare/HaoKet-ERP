#ifndef QUERYTOOL_H
#define QUERYTOOL_H
#include <QObject>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlField>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantHash>
#include <QVector>
#include <db/abstractqueryrunner.h>
#include "log4qt/logger.h"
#include "lib_global.h"
class LIBSHARED_EXPORT QueryTool:public QObject,public AbstractQueryRunner
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    QueryTool();
    int save(QSqlDatabase conn, QObject *o);
    int save(QSqlDatabase conn, QString sql, QObject *o);
    int getCount(QSqlDatabase conn, QString sql);

    int update(QSqlDatabase conn, QString sql);
    int update(QSqlDatabase conn, QString sql, QObject *o);
    int update(QSqlDatabase conn, QString sql,QVector<QVariant> qvar);
    QString getValue(QSqlDatabase conn, QString sql,QString s);
    QString getError();
private:
    int firstRow;
    int maxRows;
    bool isFnPage;
    QList<QVariant> paramsList;
    QVariantHash values;
    QSqlError dbErr;
    QString dbErrStr;
    QString queryString;

};

#endif // QUERYTOOL_H
