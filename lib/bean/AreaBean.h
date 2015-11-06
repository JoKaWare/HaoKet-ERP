#ifndef AREABEAN_H
#define AREABEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT AreaBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int areaId READ areaId WRITE setAreaId)
    Q_PROPERTY(QString areaName READ areaName WRITE setAreaName)
    Q_PROPERTY(QString areaExplian READ areaExplian WRITE setAreaExplian)
public:
    Q_INVOKABLE AreaBean(QObject* parent = 0){};
    virtual ~AreaBean() {}
    int areaId() const{ return m_area_id;}
    void setAreaId(int id){ m_area_id=id;}
    QString areaName() const { return m_area_name;}
    void setAreaName(QString name) { m_area_name=name;}
    QString areaExplian() const { return m_area_explian;}
    void setAreaExplian(QString explian) { m_area_explian=explian;}
private:
    int m_area_id;
    QString m_area_name;
    QString m_area_explian;
};
#endif // AREABEAN_H
