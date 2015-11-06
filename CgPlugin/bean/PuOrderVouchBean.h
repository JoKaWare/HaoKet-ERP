#ifndef PUORDERVOUCHBEAN_H
#define PUORDERVOUCHBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"

class PuOrderVouchBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString no READ no WRITE setNo)
    Q_PROPERTY(QDate busDate READ busDate WRITE setBusDate)
    Q_PROPERTY(QString busType READ busType WRITE setBusType)
    Q_PROPERTY(QString supplierId READ supplierId WRITE setSupplierId)
    Q_PROPERTY(QString whCode READ whCode WRITE setWhCode)
    Q_PROPERTY(QString depCode READ depCode WRITE setDepCode)
    Q_PROPERTY(QDate demandDate READ demandDate WRITE setDemandDate)
    Q_PROPERTY(QDate projectDate READ projectDate WRITE setProjectDate)
    Q_PROPERTY(QString personCode READ personCode WRITE setPersonCode)
    Q_PROPERTY(QDateTime auditTime READ auditTime WRITE setAuditTime)
    Q_PROPERTY(QString handler READ handler WRITE setHandler)
    Q_PROPERTY(bool isHandle READ isHandle WRITE setIsHandle)
    Q_PROPERTY(bool isComplete READ isComplete WRITE setIsComplete)
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
    QDate busDate() { return m_bus_date;}
    void setBusDate(QDate date){ m_bus_date = date;}
    QString busType() { return m_bus_type;}
    void setBusType(QString type){ m_bus_type = type;}
    QString supplierId() { return m_supplier_id;}
    void setSupplierId(QString value){ m_supplier_id = value;}
    QString whCode() { return m_wh_code;}
    void setWhCode(QString code){ m_wh_code = code;}
    QString depCode() { return m_dep_code;}
    void setDepCode(QString code) { m_dep_code = code;}
    QDate demandDate() { return m_demand_date;}
    void setDemandDate(QDate date){ m_demand_date = date;}
    QDate projectDate() { return m_project_date;}
    void setProjectDate(QDate date){ m_project_date = date;}
    QString personCode() { return m_person_code;}
    void setPersonCode(QString code){ m_person_code = code;}
    QDateTime auditTime(){ return m_audit_time;}
    void setAuditTime(QDateTime time){ m_audit_time = time;}
    QString handler() { return m_handler;}
    void setHandler(QString value){ m_handler = value;}
    bool isHandle() { return m_is_handle;}
    void setIsHandle(bool b){ m_is_handle = b;}
    bool isComplete() { return m_is_complete;}
    void setIsComplete(bool b){ m_is_complete = b;}
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
    QDate m_bus_date;
    QString m_bus_type;
    QString m_supplier_id;
    QString m_wh_code;
    QString m_dep_code;
    QDate m_demand_date;
    QDate m_project_date;
    QString m_person_code;
    QString m_handler;
    bool m_is_handle;
    bool m_is_complete;
    QDateTime m_audit_time;
    QString m_closer;
    int m_status;
    QDateTime m_created;
    int m_created_by;
    QString m_creater;
    QDateTime m_updated;
    int m_updated_by;
    QString m_updater;
    QString m_memo;
}
;
#endif // PUORDERVOUCHBEAN_H
