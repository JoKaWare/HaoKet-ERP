#ifndef STOCKBEAN_H
#define STOCKBEAN_H

#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT StockBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString whCode READ whCode WRITE setWhCode)
    Q_PROPERTY(QString whName READ whName WRITE setWhName)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)
    Q_PROPERTY(double price READ price WRITE setPrice)
    Q_PROPERTY(QString positionCode READ positionCode WRITE setPositionCode)
    Q_PROPERTY(double sum READ sum WRITE setSum)
    Q_PROPERTY(double readySum READ readySum WRITE setReadySum)
    Q_PROPERTY(double canSum READ canSum WRITE setCanSum)
    Q_PROPERTY(int status READ status WRITE setStatus)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
public:
    int id() {return m_id;}
    void setId(int id) { m_id = id;}

    QString productCode() { return m_product_code;}
    void setProductCode(QString code) { m_product_code = code;}
    QString productName() { return m_product_name;}
    void setProductName(QString name){ m_product_name = name;}
    QString whCode() { return m_wh_code;}
    void setWhCode(QString code) { m_wh_code = code ;}
    QString whName(){ return m_wh_name;}
    void setWhName(QString name) { m_wh_name = name;}
    QString style() { return m_style;}
    void setStyle(QString style){ m_style = style;}
    QString unit() { return m_unit;}
    void setUnit(QString unit) { m_unit = unit;}
    double price() { return m_price;}
    void setPrice(double price){ m_price = price;}
    QString positionCode() { return m_position_code;}
    void setPositionCode(QString code) { m_position_code = code;}
    double sum() { return m_sum;}
    void setSum(double sum){ m_sum = sum;}
    double readySum() { return m_ready_sum;}
    void setReadySum(double sum){ m_ready_sum = sum;}
    double canSum(){ return m_can_sum;}
    void setCanSum(double sum){ m_can_sum = sum;}
    int status() { return m_status;}
    void setStatus(int status){ m_status = status;}
    QString memo() { return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}

private:
    int m_id;
    QString m_product_code;
    QString m_product_name;
    QString m_wh_code;
    QString m_wh_name;
    QString m_style;
    QString m_position_code;
    QString m_unit;
    double m_price;
    double m_sum;
    double m_ready_sum;
    double m_can_sum;
    int m_status;
    QString m_memo;
};
#endif // STOCKBEAN_H
