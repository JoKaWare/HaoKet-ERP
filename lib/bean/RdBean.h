#ifndef RDBEAN_H
#define RDBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"
class LIBSHARED_EXPORT RdBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString rdNo READ rdNo WRITE setRdNo)
    Q_PROPERTY(int rdFlag READ rdFlag WRITE setRdFlag)
    Q_PROPERTY(QString vouchType READ vouchType WRITE setVouchType)
    Q_PROPERTY(QString vouchSource READ vouchSource WRITE setVouchSource)
    Q_PROPERTY(QDate busDate READ busDate WRITE setBusDate)
    Q_PROPERTY(QString busType READ busType WRITE setBusType)
    Q_PROPERTY(QString busNo READ busNo WRITE setBusNo)
    Q_PROPERTY(QString supplierId READ supplierId WRITE setSupplierId)
    Q_PROPERTY(QString whCode READ whCode WRITE setWhCode)
    Q_PROPERTY(QString depCode READ depCode WRITE setDepCode)
    Q_PROPERTY(QString positionCode READ positionCode WRITE setPositionCode)
    Q_PROPERTY(QString personCode READ personCode WRITE setPersonCode)
    Q_PROPERTY(QString ptCode READ ptCode WRITE setPtCode)
    Q_PROPERTY(QString stCode READ stCode WRITE setStCode)
    Q_PROPERTY(QString cusCode READ cusCode WRITE setCusCode)
    Q_PROPERTY(QString orderNo READ orderNo WRITE setOrderNo)
    Q_PROPERTY(QString billNo READ billNo WRITE setBillNo)
    Q_PROPERTY(bool isBill READ isBill WRITE setIsBill)
    Q_PROPERTY(QDateTime auditTime READ auditTime WRITE setAuditTime)
    Q_PROPERTY(QString handler READ handler WRITE setHandler)
    Q_PROPERTY(bool isHandle READ isHandle WRITE setIsHandle)
    Q_PROPERTY(bool imeiAudit READ imeiAudit WRITE setImeiAudit)
    Q_PROPERTY(int status READ status WRITE setStatus)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(QString creater READ creater WRITE setCreater)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(QDateTime keepTime READ keepTime WRITE setKeepTime)
    Q_PROPERTY(QString accounter READ accounter WRITE setAccounter)
public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString rdNo() { return m_rd_no;}
    void setRdNo(QString no) { m_rd_no = no;}
    int rdFlag() { return m_rd_flag;}
    void setRdFlag(int flag){ m_rd_flag = flag;}
    QString vouchType() { return m_vouch_type;}
    void setVouchType(QString type){ m_vouch_type = type;}
    QString vouchSource() { return m_vouch_source;}
    void setVouchSource(QString s){ m_vouch_source = s;}
    QDate busDate() { return m_bus_date;}
    void setBusDate(QDate date){ m_bus_date = date;}
    QString busType() { return m_bus_type;}
    void setBusType(QString type){ m_bus_type = type;}
    QString busNo() { return m_bus_no;}
    void setBusNo(QString no){ m_bus_no = no;}
    QString supplierId() { return m_supplier_id;}
    void setSupplierId(QString value){ m_supplier_id = value;}
    QString whCode() { return m_wh_code;}
    void setWhCode(QString code){ m_wh_code = code;}
    QString depCode() { return m_dep_code;}
    void setDepCode(QString code) { m_dep_code = code;}
    QString positionCode() { return m_position_code;}
    void setPositionCode(QString code) { m_position_code = code;}
    QString personCode() { return m_person_code;}
    void setPersonCode(QString code){ m_person_code = code;}
    QString ptCode() { return m_pt_code;}
    void setPtCode(QString code){ m_pt_code = code;}
    QString stCode() { return m_st_code;}
    void setStCode(QString code){ m_st_code = code;}
    QString cusCode() { return m_cus_code;}
    void setCusCode(QString code){ m_cus_code = code;}
    QString orderNo() { return m_order_no;}
    void setOrderNo(QString no){ m_order_no = no;}
    QString billNo() { return m_bill_no;}
    void setBillNo(QString no){ m_bill_no = no;}
    bool isBill() { return m_is_bill;}
    void setIsBill(bool b){ m_is_bill = b;}
    QDateTime auditTime(){ return m_audit_time;}
    void setAuditTime(QDateTime time){ m_audit_time = time;}
    QString handler() { return m_handler;}
    void setHandler(QString value){ m_handler = value;}
    bool isHandle() { return m_is_handle;}
    void setIsHandle(bool b){ m_is_handle = b;}
    bool imeiAudit() { return m_imei_audit;}
    void setImeiAudit(bool b){ m_imei_audit = b;}
    int status(){ return m_status;}
    void setStatus(int status){ m_status = status;}

    QDateTime created(){ return m_created; }
    void setCreated(QDateTime time){m_created = time;}
    void setCreatedBy(int user){ m_created_by = user;}
    int createdBy(){return m_created_by; }
    void setCreater(QString user){ m_creater = user;}
    QString creater(){return m_creater; }

    QString memo(){return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}

    QDateTime keepTime(){ return m_keep_time; }
    void setKeepTime(QDateTime time){m_keep_time = time;}
    QString accounter(){return m_accounter; }
    void setAccounter(QString user){ m_accounter = user;}

private:
    int m_id;
    QString m_rd_no;
    int m_rd_flag;
    QString m_bus_type;
    QString m_vouch_type;
    QString m_vouch_source;
    QString m_bill_no;
    bool m_is_bill;
    QDate m_bus_date;
    QString m_bus_no;
    QString m_wh_code;
    QString m_position_code;
    QString m_dep_code;
    QString m_person_code;
    QString m_pt_code;
    QString m_st_code;
    QString m_cus_code;
    QString m_supplier_id;
    QString m_order_no;
    QString m_handler;
    bool m_is_handle;
    bool m_imei_audit;
    QDateTime m_audit_time;
    QString m_closer;
    int m_status;
    QDateTime m_created;
    int m_created_by;
    QString m_creater;
    QString m_memo;
    QString m_accounter;
    QDateTime m_keep_time;
};
#endif // RDBEAN_H
