#ifndef APCLOSEBILLBEAN_H
#define APCLOSEBILLBEAN_H
#include <QObject>
#include <QDateTime>

class ApCloseBillBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString apNo READ apNo WRITE setApNo)
    Q_PROPERTY(QDate busDate READ busDate WRITE setBusDate)
    Q_PROPERTY(int busFlag READ busFlag WRITE setBusFlag)
    Q_PROPERTY(QString vouchType READ vouchType WRITE setVouchType)
    Q_PROPERTY(QString busCode READ busCode WRITE setBusCode)
    Q_PROPERTY(QString settleCode READ settleCode WRITE setSettleCode)
    Q_PROPERTY(QString depCode READ depCode WRITE setDepCode)
    Q_PROPERTY(QString personCode READ personCode WRITE setPersonCode)
    Q_PROPERTY(double amount READ amount WRITE setAmount)
    Q_PROPERTY(QString digest READ digest WRITE setDigest)
    Q_PROPERTY(double sum READ sum WRITE setSum)
    Q_PROPERTY(QString kmCode READ kmCode WRITE setKmCode)
    Q_PROPERTY(QString bankAccount READ bankAccount WRITE setBankAccount)
    Q_PROPERTY(QString bankName READ bankName WRITE setBankName)
    Q_PROPERTY(QString contractId READ contractId WRITE setContractId)
    Q_PROPERTY(QString contractName READ contractName WRITE setContractName)
    Q_PROPERTY(bool isVoucher READ isVoucher WRITE setIsVoucher)
    Q_PROPERTY(QDateTime auditTime READ auditTime WRITE setAuditTime)
    Q_PROPERTY(QString handler READ handler WRITE setHandler)
    Q_PROPERTY(bool isHandle READ isHandle WRITE setIsHandle)
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
    QString apNo() { return m_ap_no;}
    void setApNo(QString no){ m_ap_no = no;}
    QDate busDate(){ return m_bus_date;}
    void setBusDate(QDate d){ m_bus_date = d;}
    int busFlag() { return m_bus_flag;}
    void setBusFlag(int flag){ m_bus_flag = flag; }
    QString vouchType(){ return m_vouch_type;}
    void setVouchType(QString type){ m_vouch_type = type;}
    QString busCode() { return m_bus_code;}
    void setBusCode(QString code){ m_bus_code = code;}
    QString settleCode(){ return m_settle_code;}
    void setSettleCode(QString code){ m_settle_code = code;}
    QString depCode() { return m_dep_code;}
    void setDepCode(QString code) { m_dep_code = code;}
    QString personCode() { return m_person_code;}
    void setPersonCode(QString code){ m_person_code = code;}
    double amount() { return m_amount;}
    void setAmount(double value){ m_amount = value;}
    double sum() { return m_sum;}
    void setSum(double value){ m_sum = value;}
    QString digest(){ return m_digest;}
    void setDigest(QString digest){ m_digest = digest;}
    QString kmCode(){ return m_km_code;}
    void setKmCode(QString code){ m_km_code = code;}
    QString bankAccount(){ return m_bank_account;}
    void setBankAccount(QString value){ m_bank_account = value;}
    QString bankName(){ return m_bank_name;}
    void setBankName(QString value){ m_bank_name = value;}
    QString contractId(){ return m_contract_id;}
    void setContractId(QString value){ m_contract_id = value;}
    QString contractName(){ return m_contract_name;}
    void setContractName(QString value){ m_contract_name = value;}

    bool isVoucher() { return m_is_voucher;}
    void setIsVoucher(bool b){ m_is_voucher = b;}
    QString handler() { return m_handler;}
    void setHandler(QString value){ m_handler = value;}
    bool isHandle() { return m_is_handle;}
    void setIsHandle(bool b){ m_is_handle = b;}
    QDateTime auditTime(){ return m_audit_time;}
    void setAuditTime(QDateTime time){ m_audit_time = time;}
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
    QString m_ap_no;
    QDate m_bus_date;
    int m_bus_flag;
    QString m_vouch_type;
    QString m_bus_code;
    QString m_settle_code;
    QString m_dep_code;
    QString m_person_code;
    double m_amount;
    QString m_digest;
    double m_sum;
    QString m_km_code;
    QString m_bank_account;
    QString m_bank_name;
    QString m_contract_id;
    QString m_contract_name;
    bool m_is_voucher;
    QString m_handler;
    bool m_is_handle;
    QDateTime m_audit_time;
    QDateTime m_created;
    int m_created_by;
    QDateTime m_updated;
    int m_updated_by;
    QString m_creater;
    QString m_updater;
    QString m_memo;

};
#endif // APCLOSEBILLBEAN_H
