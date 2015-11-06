#ifndef STRUCTURESBEAN_H
#define STRUCTURESBEAN_H
#include <QObject>
#include "lib_global.h"

class StructuresBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString pspCode READ pspCode WRITE setPspCode)
    Q_PROPERTY(QString psCode READ psCode WRITE setPsCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(QString wasteUnit READ wasteUnit WRITE setWasteUnit)
    Q_PROPERTY(double quantity READ quantity WRITE setQuantity)
    Q_PROPERTY(double realityQuantity READ realityQuantity WRITE setRealityQuantity)
    Q_PROPERTY(double wasteRate READ wasteRate WRITE setWasteRate)
    Q_PROPERTY(double changRate READ changRate WRITE setChangRate)
public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString pspCode() { return m_psp_code;}
    void setPspCode(QString code) { m_psp_code = code;}

    QString psCode() { return m_ps_code;}
    void setPsCode(QString code){ m_ps_code = code;}
    QString productName() { return m_product_name;}
    void setProductName(QString name){ m_product_name = name;}
    QString style() { return m_style;}
    void setStyle(QString style){ m_style = style;}
    QString wasteUnit() { return m_waste_unit;}
    void setWasteUnit(QString unit) { m_waste_unit = unit;}
    double quantity() { return m_quantity;}
    void setQuantity(double quantity) { m_quantity = quantity;}
    double realityQuantity() { return m_reality_quantity;}
    void setRealityQuantity(double quantity){ m_reality_quantity = quantity;}

    double wasteRate() { return m_waste_rate;}
    void setWasteRate(double rate){ m_waste_rate = rate;}
    double changRate() { return m_chang_rate;}
    void setChangRate(double rate){ m_chang_rate = rate;}
private:
    int m_id;
    QString m_psp_code;
    QString m_ps_code;
    QString m_product_name;
    QString m_style;
    QString m_waste_unit;
    double m_quantity;
    double m_reality_quantity;
    double m_waste_rate;
    double m_chang_rate;
};

#endif // STRUCTURESBEAN_H
