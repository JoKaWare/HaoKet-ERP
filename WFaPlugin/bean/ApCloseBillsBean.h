#ifndef APCLOSEBILLSBEAN_H
#define APCLOSEBILLSBEAN_H
#include <QObject>
class ApCloseBillsBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString apNo READ apNo WRITE setApNo)
    Q_PROPERTY(QString orderNo READ orderNo WRITE setOrderNo)
    Q_PROPERTY(QString busNo READ busNo WRITE setBusNo)
    Q_PROPERTY(QString busVouch READ busVouch WRITE setBusVouch)
    Q_PROPERTY(QString fundsType READ fundsType WRITE setFundsType)
    Q_PROPERTY(QString kmCode READ kmCode WRITE setKmCode)
    Q_PROPERTY(QString kmName READ kmName WRITE setKmName)
    Q_PROPERTY(QString digest READ digest WRITE setDigest)
    Q_PROPERTY(QString itemCode READ itemCode WRITE setItemCode)
    Q_PROPERTY(QString apBill READ apBill WRITE setApBill)
    Q_PROPERTY(double amount READ amount WRITE setAmount)
    Q_PROPERTY(double sum READ sum WRITE setSum)

public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString apNo() { return m_ap_no;}
    void setApNo(QString no){ m_ap_no = no;}
    QString orderNo() { return m_order_no;}
    void setOrderNo(QString no){ m_order_no = no;}
    QString busNo() { return m_bus_no;}
    void setBusNo(QString no){ m_bus_no = no;}
    QString busVouch() { return m_bus_vouch;}
    void setBusVouch(QString value){ m_bus_vouch = value;}
    QString fundsType() { return m_funds_type;}
    void setFundsType(QString value){ m_funds_type = value;}
    QString kmCode() { return m_km_code;}
    void setKmCode(QString value){ m_km_code = value;}
    QString kmName() { return m_km_name;}
    void setKmName(QString name){ m_km_name = name;}
    QString digest() { return m_digest;}
    void setDigest(QString value){ m_digest = value;}
    QString itemCode() { return m_item_code;}
    void setItemCode(QString value){ m_item_code = value;}
    QString apBill() { return m_ap_bill;}
    void setApBill(QString value){ m_ap_bill = value;}
    double amount() { return m_amount;}
    void setAmount(double value){ m_amount = value;}
    double sum() { return m_sum;}
    void setSum(double value) { m_sum = value;}

private:
    int m_id;
    QString m_ap_no;
    QString m_order_no;
    QString m_bus_no;
    QString m_bus_vouch;
    QString m_funds_type;
    QString m_km_code;
    QString m_km_name;
    QString m_digest;
    double m_amount;
    double m_sum;
    QString m_item_code;
    QString m_ap_bill;
};
#endif // APCLOSEBILLSBEAN_H
