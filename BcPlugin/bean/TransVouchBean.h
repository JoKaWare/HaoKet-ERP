#ifndef TRANSVOUCHBEAN_H
#define TRANSVOUCHBEAN_H
#include <QObject>
#include <QDate>

class TransVouchBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString tvNo READ tvNo WRITE setTvNo)
    Q_PROPERTY(QDate tvDate READ tvDate WRITE setTvDate)
    Q_PROPERTY(QString busType READ busType WRITE setBusType)
    Q_PROPERTY(QString ordNo READ ordNo WRITE setOrdNo)
    Q_PROPERTY(QString irdNo READ irdNo WRITE setIrdNo)
    Q_PROPERTY(QString owhCode READ owhCode WRITE setOwhCode)
    Q_PROPERTY(QString iwhCode READ iwhCode WRITE setIwhCode)
    Q_PROPERTY(QString depCode READ depCode WRITE setDepCode)
    Q_PROPERTY(QString personCode READ personCode WRITE setPersonCode)

    Q_PROPERTY(QDateTime auditTime READ auditTime WRITE setAuditTime)
    Q_PROPERTY(QString handler READ handler WRITE setHandler)
    Q_PROPERTY(bool isHandle READ isHandle WRITE setIsHandle)
    Q_PROPERTY(int status READ status WRITE setStatus)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(QString creater READ creater WRITE setCreater)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(bool imeiAudit READ imeiAudit WRITE setImeiAudit)
public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString tvNo() { return m_tv_no;}
    void setTvNo(QString no) { m_tv_no = no;}

    QDate tvDate() { return m_tv_date;}
    void setTvDate(QDate date){ m_tv_date = date;}
    QString busType() { return m_bus_type;}
    void setBusType(QString type){ m_bus_type = type;}
    QString ordNo() { return m_ord_no;}
    void setOrdNo(QString no){ m_ord_no = no;}
    QString irdNo() { return m_ird_no;}
    void setIrdNo(QString no){ m_ird_no = no;}
    QString owhCode() { return m_owh_code;}
    void setOwhCode(QString code){ m_owh_code = code;}
    QString iwhCode() { return m_iwh_code;}
    void setIwhCode(QString code){ m_iwh_code = code;}
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
    int status(){ return m_status;}
    void setStatus(int status){ m_status = status;}

    QDateTime created(){ return m_created; }
    void setCreated(QDateTime time){m_created = time;}
    QDateTime updated(){ return m_updated; }
    void setUpdated(QDateTime time){m_updated = time;}

    void setCreatedBy(int user){ m_created_by = user;}
    int createdBy(){return m_created_by; }
    void setCreater(QString user){ m_creater = user;}
    QString creater(){return m_creater; }
    void setUpdatedBy(int user){ m_updated_by = user;}
    int updatedBy(){return m_updated_by; }
    QString memo(){return m_memo;}
    void setMemo(QString memo){ m_memo = memo;}
    bool imeiAudit() { return m_imei_audit;}
    void setImeiAudit(bool b){ m_imei_audit = b;}
private:
    int m_id;
    QString m_tv_no;
    QString m_bus_type;
    QDate m_tv_date;
    QString m_ord_no;
    QString m_ird_no;
    QString m_owh_code;
    QString m_iwh_code;
    QString m_dep_code;
    QString m_person_code;

    QString m_handler;
    bool m_is_handle;
    QDateTime m_audit_time;
    int m_status;
    QDateTime m_created;
    int m_created_by;
    QString m_creater;
    QDateTime m_updated;
    int m_updated_by;
    QString m_memo;
    bool m_imei_audit;
};
#endif // TRANSVOUCHBEAN_H
