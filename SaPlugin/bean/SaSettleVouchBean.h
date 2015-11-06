#ifndef SASETTLEVOUCHBEAN_H
#define SASETTLEVOUCHBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"
class SaSettleVouchBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString no READ no WRITE setNo)
    Q_PROPERTY(QString orderNo READ orderNo WRITE setOrderNo)
    Q_PROPERTY(QString rdNo READ rdNo WRITE setRdNo)
    Q_PROPERTY(QString busType READ busType WRITE setBusType)
    Q_PROPERTY(QString ptCode READ ptCode WRITE setPtCode)
    Q_PROPERTY(QDate settleDate READ settleDate WRITE setSettleDate)
    Q_PROPERTY(int settleType READ settleType WRITE setSettleType)
    Q_PROPERTY(QString apNo READ apNo WRITE setApNo)
    Q_PROPERTY(double apMoeny READ apMoeny WRITE setApMoney)
    Q_PROPERTY(QString profitNo READ profitNo WRITE setProfitNo)
    Q_PROPERTY(double profitMoeny READ profitMoeny WRITE setProfitMoney)
    Q_PROPERTY(QString cusCode READ cusCode WRITE setCusCode)
    Q_PROPERTY(QString depCode READ depCode WRITE setDepCode)
    Q_PROPERTY(QString personCode READ personCode WRITE setPersonCode)
    Q_PROPERTY(QDateTime auditTime READ auditTime WRITE setAuditTime)
    Q_PROPERTY(QString handler READ handler WRITE setHandler)
    Q_PROPERTY(bool isHandle READ isHandle WRITE setIsHandle)
    Q_PROPERTY(QString payCode READ payCode WRITE setPayCode)
    Q_PROPERTY(QString cexchName READ cexchName WRITE setCexchName)
    Q_PROPERTY(QString closer READ closer WRITE setCloser)
    Q_PROPERTY(int status READ status WRITE setStatus)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(QDateTime updated READ updated WRITE setUpdated)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(int updatedBy READ updatedBy WRITE setUpdatedBy)
    Q_PROPERTY(QString creater READ creater WRITE setCreater)
    Q_PROPERTY(QString updater READ updater WRITE setUpdater)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString no() { return m_no;}
    void setNo(QString no) { m_no = no;}
    QString orderNo() { return m_order_no;}
    void setOrderNo(QString no) { m_order_no = no;}
    QString rdNo() { return m_rd_no;}
    void setRdNo(QString no) { m_rd_no = no;}
    QString busType() { return m_bus_type;}
    void setBusType(QString type){ m_bus_type = type;}
    QString ptCode() { return m_pt_code;}
    void setPtCode(QString code){ m_pt_code = code;}
    QDate settleDate() { return m_settle_date;}
    void setSettleDate(QDate date){ m_settle_date = date;}
    int settleType() { return m_settle_type;}
    void setSettleType(int type){ m_settle_type = type;}
    QString apNo() { return m_ap_no;}
    void setApNo(QString no) { m_ap_no = no;}
    double apMoeny() { return m_ap_money;}
    void setApMoney(double value){ m_ap_money = value;}
    QString profitNo() { return m_profit_no;}
    void setProfitNo(QString no) { m_profit_no = no;}
    double profitMoeny() { return m_profit_money;}
    void setProfitMoney(double value){ m_profit_money = value;}
    QString cusCode() { return m_cus_code;}
    void setCusCode(QString value){ m_cus_code = value;}

    QString depCode() { return m_dep_code;}
    void setDepCode(QString code) { m_dep_code = code;}
    QString personCode() { return m_person_code;}
    void setPersonCode(QString code){ m_person_code = code;}
    QString handler() { return m_handler;}
    void setHandler(QString value){ m_handler = value;}
    bool isHandle() { return m_is_handle;}
    void setIsHandle(bool b){ m_is_handle = b;}
    QDateTime auditTime(){ return m_audit_time;}
    void setAuditTime(QDateTime time){ m_audit_time = time;}
    QString payCode() { return m_pay_code;}
    void setPayCode(QString value){ m_pay_code = value;}
    QString cexchName() { return m_cexch_name;}
    void setCexchName(QString value){ m_cexch_name = value;}
    QString closer() { return m_closer;}
    void setCloser(QString value){ m_closer = value;}

    int status(){ return m_status;}
    void setStatus(int status){ m_status = status;}

    QDateTime created(){ return m_created; }
    void setCreated(QDateTime time){m_created = time;}
    QDateTime updated(){ return m_updated; }
    void setUpdated(QDateTime time){m_updated = time;}

    void setCreatedBy(int user){ m_created_by = user;}
    int createdBy(){return m_created_by; }
    void setUpdatedBy(int user){ m_updated_by = user;}
    int updatedBy(){return m_updated_by; }
    void setCreater(QString user){ m_creater = user;}
    QString creater(){return m_creater; }
    void setUpdater(QString user){ m_updater = user;}
    QString updater(){return m_updater; }
    QString memo(){return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}
private:
    int m_id;
    QString m_no;
    QString m_pt_code;
    QString m_order_no;
    QString m_rd_no;
    QString m_bus_type;
    QDate m_settle_date;
    int m_settle_type;
    QString m_ap_no;
    double m_ap_money;
    QString m_profit_no;
    double m_profit_money;
    QString m_cus_code;
    QString m_dep_code;
    QString m_person_code;

    QString m_pay_code;
    QString m_cexch_name;
    QString m_handler;
    bool m_is_handle;
    QDateTime m_audit_time;
    QString m_closer;
    int m_status;
    QDateTime m_created;
    int m_created_by;
    QDateTime m_updated;
    int m_updated_by;
    QString m_creater;
    QString m_updater;
    QString m_memo;
};
#endif // SASETTLEVOUCHBEAN_H
