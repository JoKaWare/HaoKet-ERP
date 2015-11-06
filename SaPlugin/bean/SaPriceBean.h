#ifndef SAPRICEBEAN_H
#define SAPRICEBEAN_H
#include <QObject>
#include <QDateTime>

#include "lib_global.h"
class SaPriceBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString no READ no WRITE setNo)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)
    Q_PROPERTY(QString whCode READ whCode WRITE setWhCode)
    Q_PROPERTY(double sum READ sum WRITE setSum)
    Q_PROPERTY(double price READ price WRITE setPrice)
    Q_PROPERTY(double uprice1 READ uprice1 WRITE setUprice1)
    Q_PROPERTY(double uprice2 READ uprice2 WRITE setUprice2)
    Q_PROPERTY(double uprice3 READ uprice3 WRITE setUprice3)
    Q_PROPERTY(double salesCost READ salesCost WRITE setSalesCost)
    Q_PROPERTY(double lowSum READ lowSum WRITE setLowSum)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QDateTime updated READ updated WRITE setUpdated)
    Q_PROPERTY(int updatedBy READ updatedBy WRITE setUpdatedBy)

public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString no() { return m_no;}
    void setNo(QString no) { m_no = no;}
    QString productCode() { return m_product_code;}
    void setProductCode(QString code){ m_product_code = code;}
    QString productName() { return m_product_name;}
    void setProductName(QString name){ m_product_name = name;}
    QString style() { return m_style;}
    void setStyle(QString style){ m_style = style;}
    QString unit() { return m_unit;}
    void setUnit(QString unit) { m_unit = unit;}
    QString whCode() { return m_wh_code;}
    void setWhCode(QString code) { m_wh_code = code ;}
    double sum() { return m_sum;}
    void setSum(double sum){ m_sum = sum;}
    double price() { return m_price;}
    void setPrice(double price){ m_price = price;}
    double uprice1() { return m_uprice1;}
    void setUprice1(double price){ m_uprice1 = price;}
    double uprice2() { return m_uprice2;}
    void setUprice2(double price){ m_uprice2 = price;}
    double uprice3() { return m_uprice1;}
    void setUprice3(double price){ m_uprice3 = price;}
    double salesCost(){ return m_sales_cost;}
    void setSalesCost(double cost){ m_sales_cost = cost;}
    double lowSum(){ return m_low_sum; }
    void setLowSum(double v){ m_low_sum = v;}
    QString description() { return m_description;}
    void setDescription(QString desc){ m_description = desc;}
    QDateTime updated(){ return m_updated; }
    void setUpdated(QDateTime time){m_updated = time;}
    void setUpdatedBy(int user){ m_updated_by = user;}
    int updatedBy(){return m_updated_by; }

private:
    int m_id;
    QString m_no;
    QString m_product_code;
    QString m_product_name;
    QString m_style;
    QString m_unit;
    QString m_wh_code;
    double m_sum;
    double m_price;
    double m_uprice1;
    double m_uprice2;
    double m_uprice3;
    double m_sales_cost;
    double m_low_sum;
    QString m_description;
    QDateTime m_updated;
    int m_updated_by;
};
#endif // SAPRICEBEAN_H
