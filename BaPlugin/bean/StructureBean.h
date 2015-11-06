#ifndef STRUCTUREBEAN_H
#define STRUCTUREBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"

class StructureBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString pspCode READ pspCode WRITE setPspCode)
    Q_PROPERTY(QString productName READ productName WRITE setProductName)
    Q_PROPERTY(QString style READ style WRITE setStyle)
    Q_PROPERTY(QString depCode READ depCode WRITE setDepCode)
    Q_PROPERTY(bool isExpand READ isExpand WRITE setIsExpand)
    Q_PROPERTY(bool isReckon READ isReckon WRITE setIsReckon)
    Q_PROPERTY(QString unit READ unit WRITE setUnit)
    Q_PROPERTY(QDateTime auditTime READ auditTime WRITE setAuditTime)
    Q_PROPERTY(QString handler READ handler WRITE setHandler)
    Q_PROPERTY(int status READ status WRITE setStatus)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(QDateTime updated READ updated WRITE setUpdated)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(int updatedBy READ updatedBy WRITE setUpdatedBy)
public:
    int id() { return m_id;}
    void setId(int id) { m_id = id ;}
    QString pspCode() { return m_psp_code;}
    void setPspCode(QString code) { m_psp_code = code;}
    QString productName() { return m_product_name;}
    void setProductName(QString name){ m_product_name = name;}
    QString style() { return m_style;}
    void setStyle(QString style){ m_style = style;}
    bool isExpand() { return m_is_expand;}
    void setIsExpand(bool b){ m_is_expand = b;}
    bool isReckon() { return m_is_reckon;}
    void setIsReckon(bool b){ m_is_reckon = b;}
    QString unit() { return m_unit;}
    void setUnit(QString unit){ m_unit = unit;}
    QString depCode(){ return m_dep_code;}
    void setDepCode(QString code) { m_dep_code = code;}
    QDateTime auditTime(){ return m_audit_time;}
    void setAuditTime(QDateTime time){ m_audit_time = time;}
    QString handler() { return m_handler;}
    void setHandler(QString value){ m_handler = value;}
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
private:
    int m_id;
    QString m_psp_code;
    QString m_product_name;
    QString m_style;
    QString m_dep_code;
    bool m_is_expand;
    bool m_is_reckon;
    QString m_unit;
    QString m_handler;
    QDateTime m_audit_time;
    int m_status;
    int m_created_by;
    QDateTime m_created;
    int m_updated_by;
    QDateTime m_updated;
};
#endif // STRUCTUREBEAN_H
