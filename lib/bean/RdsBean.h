#ifndef RDSBEAN_H
#define RDSBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"
class LIBSHARED_EXPORT RdsBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString rdNo READ rdNo WRITE setRdNo)
    Q_PROPERTY(QString orderNo READ orderNo WRITE setOrderNo)
    Q_PROPERTY(QString busNo READ busNo WRITE setBusNo)
    Q_PROPERTY(QString srcNo READ srcNo WRITE setSrcNo)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString productStyle READ productStyle WRITE setProductStyle)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)
    Q_PROPERTY(double quantity READ quantity WRITE setQuantity)
    Q_PROPERTY(double unitPrice READ unitPrice WRITE setUnitPrice)
    Q_PROPERTY(double money READ money WRITE setMoney)
    Q_PROPERTY(double aMoney READ aMoney WRITE setAMoney)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(int imeiCount READ imeiCount WRITE setImeiCount)
    Q_PROPERTY(bool isAccount READ isAccount WRITE setIsAccount)
    Q_PROPERTY(QString define1 READ define1 WRITE setDefine1)
    Q_PROPERTY(QString define2 READ define2 WRITE setDefine2)
    Q_PROPERTY(QString define3 READ define3 WRITE setDefine3)
    Q_PROPERTY(QString define4 READ define4 WRITE setDefine4)
    Q_PROPERTY(QString define5 READ define5 WRITE setDefine5)
    Q_PROPERTY(QString define6 READ define6 WRITE setDefine6)
public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString rdNo() { return m_rd_no;}
    void setRdNo(QString no) { m_rd_no = no;}
    QString orderNo() { return m_order_no;}
    void setOrderNo(QString no) { m_order_no = no;}
    QString busNo() { return m_bus_no;}
    void setBusNo(QString no) { m_bus_no = no;}
    QString srcNo() { return m_src_no;}
    void setSrcNo(QString no) { m_src_no = no;}
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
    double aMoney() { return m_a_money;}
    void setAMoney(double money){ m_a_money = money;}
    QString memo(){return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}
    int imeiCount() { return m_imei_count;}
    void setImeiCount(int value) { m_imei_count = value ;}
    bool isAccount() { return m_is_account;}
    void setIsAccount(bool b){ m_is_account = b ;}
    QString define1() { return m_define1;}
    void setDefine1(QString define) { m_define1 = define;}
    QString define2() { return m_define2;}
    void setDefine2(QString define) { m_define2 = define;}
    QString define3() { return m_define3;}
    void setDefine3(QString define) { m_define3 = define;}
    QString define4() { return m_define4;}
    void setDefine4(QString define) { m_define4 = define;}
    QString define5() { return m_define5;}
    void setDefine5(QString define) { m_define5 = define;}
    QString define6() { return m_define6;}
    void setDefine6(QString define) { m_define6 = define;}
private:
    int m_id;
    QString m_rd_no;
    QString m_order_no;
    QString m_bus_no;
    QString m_src_no;
    QString m_product_code;
    QString m_product_name;
    QString m_product_style;
    QString m_unit;
    int m_imei_count;
    double m_quantity;
    double m_unit_price;
    double m_money;
    double m_a_money;
    QString m_memo;
    bool m_is_account;
    QString m_define1;
    QString m_define2;
    QString m_define3;
    QString m_define4;
    QString m_define5;
    QString m_define6;

};
#endif // RDSBEAN_H
