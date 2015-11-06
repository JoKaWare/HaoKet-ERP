#ifndef WIDGETBEANUTIL_H
#define WIDGETBEANUTIL_H
#include <QGridLayout>
#include <QLineEdit>
#include <QMetaObject>
#include <QMetaProperty>
#include <QTableWidget>
#include "qksearcheditbox.h"
#include "db/utils/inflection.h"
#include "common.h"
#include "log4qt/logger.h"
#include "lib_global.h"

class LIBSHARED_EXPORT WidgetBeanUtil : public QObject
{
    Q_OBJECT
    LOG4QT_DECLARE_QCLASS_LOGGER
public:
    WidgetBeanUtil();
    static void clearLayoutWidgetData(QGridLayout *layout);
    static void setLayoutWidgetEnable(QGridLayout *layout,bool b);
    static void setLayoutWidgetReadOnly(QGridLayout *layout,bool b);
    static bool setBeanToItemModel(QAbstractItemModel *model,int row, QList<struct childItemProperties > childItem,QObject *o);
    static bool setItemModelToBean(QAbstractItemModel *model,int row, QList<struct childItemProperties > childItem,QObject *o);
    static bool setBeanToTableWidget(QTableWidget *table,int row, QList<struct childItemProperties > childItem,QObject *o);
    static bool addBeanToTableWidget(QTableWidget *table,int row, QList<struct childItemProperties > childItem,QObject *o);
    static bool setValueToTableWidget(QTableWidget *table, int row, QList<childItemProperties> childItem,QString name, QVariant v);
    static int  getChildItemId(QList<struct childItemProperties > childItem,QString name);
private:
    QVariantHash propertyValuesForObject(QObject *o);
};

#endif // WIDGETBEANUTIL_H
