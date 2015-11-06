#ifndef UNITBEAN_H
#define UNITBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT UnitBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString unitName READ unitName WRITE setUnitName)
    Q_PROPERTY(QString translatedUnit READ translatedUnit WRITE setTranslatedUnit)
    Q_PROPERTY(double scalings READ scalings WRITE setScalings)
public:
    int id(){ return m_id;}
    void setId(int id){ m_id = id;}
    QString unitName(){ return m_unit_name;}
    void setUnitName(QString name){ m_unit_name = name;}
    QString translatedUnit() { return m_translated_unit;}
    void setTranslatedUnit(QString unit){ m_translated_unit = unit;}
    double scalings() { return m_scalings;}
    void setScalings(double d){ m_scalings = d;}
private:
    int m_id;
    QString m_unit_name;
    QString m_translated_unit;
    double m_scalings;
};
#endif // UNITBEAN_H
