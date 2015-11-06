#ifndef TRANSVOUCHSBEAN_H
#define TRANSVOUCHSBEAN_H
#include <QObject>
#include <QDate>


class TransVouchsBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString tvNo READ tvNo WRITE setTvNo)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString productStyle READ productStyle WRITE setProductStyle)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)
    Q_PROPERTY(double quantity READ quantity WRITE setQuantity)
    Q_PROPERTY(double unitPrice READ unitPrice WRITE setUnitPrice)
    Q_PROPERTY(double money READ money WRITE setMoney)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(int imeiCount READ imeiCount WRITE setImeiCount)
public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString tvNo() { return m_tv_no;}
    void setTvNo(QString no) { m_tv_no = no;}

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
    double unitPrice() { return m_unit_price;}
    void setUnitPrice(double price){ m_unit_price = price;}

    double money() { return m_money;}
    void setMoney(double money){ m_money = money;}

    QString memo(){return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}
    int imeiCount() { return m_imei_count;}
    void setImeiCount(int value) { m_imei_count = value ;}
private:
    int m_id;
    QString m_tv_no;
    QString m_product_code;
    QString m_product_name;
    QString m_product_style;
    QString m_unit;
    double m_quantity;
    double m_unit_price;
    double m_money;

    QString m_memo;
    int m_imei_count;
};
#endif // TRANSVOUCHSBEAN_H
