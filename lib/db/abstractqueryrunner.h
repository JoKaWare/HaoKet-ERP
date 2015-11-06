#ifndef ABSTRACTQUERYRUNNER_H
#define ABSTRACTQUERYRUNNER_H
#include <QObject>
#include <QtCore/QMetaObject>
#include <QtCore/QMetaProperty>
#include <QtCore/QVariantHash>
#include <QtCore/QStringList>
#include "utils/inflection.h"
#include "log4qt/logger.h"
#include "lib_global.h"

class AbstractQueryRunner
{   
public:
    AbstractQueryRunner();
    QString tableNameForObject(QObject* o);
    QList<QString> propertyListForObject(QObject* o);
    QVariantHash  propertyValuesForObject(QObject* o);
    void parserField(QString sql);
    QStringList getSqlField(){return sqlField;}
    QList<QVariant> toParamValue(QVariantHash vales,QStringList strList);

    bool bSqlParser;
    int paramCount;
    QString strErrorOutText;
private :
    Log4Qt::Logger *logger;
protected:
    QStringList sqlField;
};

#endif // ABSTRACTQUERYRUNNER_H
