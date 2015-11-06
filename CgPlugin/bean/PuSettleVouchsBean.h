#ifndef PUSETTLEVOUCHSBEAN_H
#define PUSETTLEVOUCHSBEAN_H
#include <QObject>
#include <QDate>
#include "lib_global.h"

class PuSettleVouchsBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString settleNo READ settleNo WRITE setSettleNo)
    Q_PROPERTY(QString rdNo READ rdNo WRITE setRdNo)
    Q_PROPERTY(QString rdsNote READ rdsNote WRITE setRdsNote)
    Q_PROPERTY(QString busNo READ busNo WRITE setBusNo)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString productStyle READ productStyle WRITE setProductStyle)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)
    Q_PROPERTY(double quantity READ quantity WRITE setQuantity)
    Q_PROPERTY(double price READ price WRITE setPrice)
    Q_PROPERTY(double sPrice READ sPrice WRITE setSPrice)
    Q_PROPERTY(double taxPrice READ taxPrice WRITE setTaxPrice)
    Q_PROPERTY(double amount READ amount WRITE setAmount)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)

public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString settleNo() { return m_settle_no;}
    void setSettleNo(QString no) { m_settle_no = no;}
    QString rdNo() { return m_rd_no;}
    void setRdNo(QString no){ m_rd_no = no;}
    QString rdsNote() { return m_rds_note;}
    void setRdsNote(QString no){ m_rds_note = no;}
    QString busNo() { return m_bus_no;}
    void setBusNo(QString no) { m_bus_no = no;}
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
    double sPrice() { return m_s_price;}
    void setSPrice(double price){ m_s_price = price;}
    double taxPrice() { return m_tax_price;}
    void setTaxPrice(double price){ m_tax_price = price;}
    double amount() { return m_amount;}
    void setAmount(double value){ m_amount = value;}
    QString memo(){return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}

private:
    int m_id;
    QString m_settle_no;
    QString m_rd_no;
    QString m_rds_note;
    QString m_bus_no;
    QString m_product_code;
    QString m_product_name;
    QString m_product_style;
    QString m_unit;
    double m_quantity;
    double m_price;
    double m_s_price;
    double m_tax_price;
    double m_amount;
    QString m_memo;

};
#endif // PUSETTLEVOUCHSBEAN_H
