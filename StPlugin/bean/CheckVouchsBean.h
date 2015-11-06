#ifndef CHECKVOUCHSBEAN_H
#define CHECKVOUCHSBEAN_H
#include <QObject>

class CheckVouchsBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString checkNo READ checkNo WRITE setCheckNo)
    Q_PROPERTY(QString whCode READ whCode WRITE setWhCode)
    Q_PROPERTY(QString cusCode READ cusCode WRITE setCusCode)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString productStyle READ productStyle WRITE setProductStyle)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)
    Q_PROPERTY(double quantity READ quantity WRITE setQuantity)
    Q_PROPERTY(double price READ price WRITE setPrice)
    Q_PROPERTY(double taxPrice READ taxPrice WRITE setTaxPrice)
    Q_PROPERTY(double money READ money WRITE setMoney)

public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString checkNo() { return m_check_no;}
    void setCheckNo(QString no) { m_check_no = no;}
    QString whCode() { return m_wh_code;}
    void setWhCode(QString code) { m_wh_code = code;}
    QString cusCode() { return m_cus_code;}
    void setCusCode(QString id){ m_cus_code = id;}
    QString productCode() { return m_product_code;}
    void setProductCode(QString code){ m_product_code = code;}
    QString productName() { return m_product_name;}
    void setProductName(QString name){ m_product_name = name;}
    QString productStyle() { return m_product_style;}
    void setProductStyle(QString style){ m_product_style = style;}
    QString unit() { return m_unit;}
    void setUnit(QString unit) { m_unit = unit;}
    double quantity() { return m_quantity;}
    void setQuantity(double quantity) { m_quantity = quantity;}
    double price() { return m_price;}
    void setPrice(double price){ m_price = price;}
    double taxPrice() { return m_tax_price;}
    void setTaxPrice(double price){ m_tax_price = price;}
    double money() { return m_money;}
    void setMoney(double money){ m_money = money;}

private:
    int m_id;
    QString m_check_no;
    QString m_wh_code;
    QString m_cus_code;
    QString m_product_code;
    QString m_product_name;
    QString m_product_style;
    QString m_unit;
    double m_quantity;
    double m_price;
    double m_tax_price;
    double m_money;
};
#endif // CHECKVOUCHSBEAN_H
