#ifndef TRANSIMEIBEAN_H
#define TRANSIMEIBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"
class TransImeiBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString no READ no WRITE setNo)
    Q_PROPERTY(QString srcNo READ srcNo WRITE setSrcNo)
    Q_PROPERTY(QString imei READ imei WRITE setImei)
    Q_PROPERTY(QString msn READ msn WRITE setMsn)
    Q_PROPERTY(int vouchsId READ vouchsId WRITE setVouchsId)
    Q_PROPERTY(QString productCode READ productCode WRITE setProductCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString busCode READ busCode WRITE setBusCode)
    Q_PROPERTY(QString vouchType READ vouchType WRITE setVouchType)
    Q_PROPERTY(QString outWhCode READ outWhCode WRITE setOutWhCode)
    Q_PROPERTY(QString inWhCode READ inWhCode WRITE setInWhCode)
    Q_PROPERTY(QDate busDate READ busDate WRITE setBusDate)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(QString creater READ creater WRITE setCreater)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString no() { return m_no;}
    void setNo(QString no) { m_no = no;}
    QString srcNo() { return m_src_no;}
    void setSrcNo(QString no) { m_src_no = no;}
    QString imei() { return m_imei;}
    void setImei(QString imei) { m_imei = imei;}
    QString msn() { return m_msn;}
    void setMsn(QString msn) { m_msn = msn;}

    int vouchsId() { return m_vouchs_id;}
    void setVouchsId(int s){ m_vouchs_id = s;}

    QString productCode() { return m_product_code;}
    void setProductCode(QString code) { m_product_code = code;}
    QString productName() { return m_product_name;}
    void setProductName(QString name){ m_product_name = name;}
    QString busCode() { return m_bus_code;}
    void setBusCode(QString code) { m_bus_code = code;}

    QString vouchType() { return m_vouch_type;}
    void setVouchType(QString type){ m_vouch_type = type;}
    QString outWhCode() { return m_out_wh_code;}
    void setOutWhCode(QString code){ m_out_wh_code = code;}
    QString inWhCode() { return m_in_wh_code;}
    void setInWhCode(QString code){ m_in_wh_code = code;}
    QDate busDate() { return m_bus_date;}
    void setBusDate(QDate date){ m_bus_date = date;}
    QDateTime created(){ return m_created; }
    void setCreated(QDateTime time){m_created = time;}
    void setCreater(QString user){ m_creater = user;}
    QString creater(){return m_creater; }

    QString memo(){return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}
private:
    int m_id;
    QString m_no;
    QString m_src_no;
    QString m_imei;
    QString m_msn;
    int m_vouchs_id;
    QString m_product_code;
    QString m_product_name;
    QString m_vouch_type;
    QString m_bus_code;
    QString m_out_wh_code;
    QString m_in_wh_code;
    QDate m_bus_date;

    QDateTime m_created;
    QString m_creater;
    QString m_memo;

};
#endif // TRANSIMEIBEAN_H
