#ifndef ACCOUNTBEAN_H
#define ACCOUNTBEAN_H
#include <QObject>
#include <QDateTime>
class AccountBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int adAccountId READ adAccountId WRITE setAdAccountId)
    Q_PROPERTY(QString adSystemId READ adSystemId WRITE setAdSystemId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QString accPath READ accPath WRITE setAccPath)
    Q_PROPERTY(QString accMaster READ accMaster WRITE setAccMaster)
    Q_PROPERTY(int year READ year WRITE setYear)
    Q_PROPERTY(int month READ month WRITE setMonth)
    Q_PROPERTY(QString unitName READ unitName WRITE setUnitName)
    Q_PROPERTY(QString unitAbbre READ unitAbbre WRITE setUnitAbbre)
    Q_PROPERTY(QString unitAddr READ unitAddr WRITE setUnitAddr)
    Q_PROPERTY(QString unitZip READ unitZip WRITE setUnitZip)
    Q_PROPERTY(QString unitTel READ unitTel WRITE setUnitTel)
    Q_PROPERTY(QString unitFax READ unitFax WRITE setUnitFax)
    Q_PROPERTY(QString unitEmail READ unitEmail WRITE setUnitEmail)
    Q_PROPERTY(QString unitTaxno READ unitTaxno WRITE setUnitTaxno)
    Q_PROPERTY(QString unitLp READ unitLp WRITE setUnitLp)
    Q_PROPERTY(QString domain READ domain WRITE setDomain)
    Q_PROPERTY(QDateTime updated READ updated WRITE setUpdated)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(int updatedBy READ updatedBy WRITE setUpdatedBy)
    Q_PROPERTY(QDateTime startDate READ startDate WRITE setStartDate)
    Q_PROPERTY(QDateTime endDate READ endDate WRITE setEndDate)
    Q_PROPERTY(QString isAction READ isAction WRITE setIsAction)

public:
    Q_INVOKABLE AccountBean(QObject* parent = 0){};
    virtual ~AccountBean() {}
    int adAccountId() const { return m_ad_account_id;}
    void setAdAccountId(int id){ m_ad_account_id=id;}
    QString adSystemId() const { return m_ad_system_id;}
    void setAdSystemId(QString sysid){ m_ad_system_id=sysid;}
    QString name() const { return m_name;}
    void setName(QString name){ m_name=name;}
    QString description() const { return m_description;}
    void setDescription(QString desc){ m_description=desc;}
    QString accPath() const { return m_acc_path;}
    void setAccPath(QString path){ m_acc_path=path;}
    QString accMaster() const { return m_acc_master;}
    void setAccMaster(QString master){ m_acc_master=master;}
    int year() const { return m_year;}
    void setYear(int year){ m_year=year;}
    int month() const { return m_month;}
    void setMonth(int month){ m_month=month;}
    QString unitName() const { return m_unit_name;}
    void setUnitName(QString name){ m_unit_name=name;}
    QString unitAbbre() const { return m_unit_abbre;}
    void setUnitAbbre(QString abbre){ m_unit_abbre=abbre;}
    QString unitAddr() const { return m_unit_addr;}
    void setUnitAddr(QString addr){ m_unit_addr=addr;}
    QString unitZip() const { return m_unit_zip;}
    void setUnitZip(QString zip) { m_unit_zip=zip;}
    QString unitTel() const { return m_unit_tel;}
    void setUnitTel(QString tel) { m_unit_tel=tel;}
    QString unitFax() const { return m_unit_fax;}
    void setUnitFax(QString fax){ m_unit_fax=fax;}
    QString unitEmail() const { return m_unit_email;}
    void setUnitEmail(QString email){ m_unit_email=email;}
    QString unitTaxno() const { return m_unit_taxno;}
    void setUnitTaxno(QString taxno){ m_unit_taxno=taxno;}
    QString unitLp() const { return m_unit_lp;}
    void setUnitLp(QString lp){ m_unit_lp=lp;}
    QString domain() const { return m_domain;}
    void setDomain(QString domain){ m_domain=domain;}
    QDateTime created() const { return m_created;}
    void setCreated(QDateTime time){ m_created=time;}
    QDateTime updated() const { return m_updated;}
    void setUpdated(QDateTime time){ m_updated=time;}
    int createdBy() const { return m_created_by;}
    void setCreatedBy(int by){ m_created_by=by;}
    int updatedBy() const { return m_updated_by;}
    void setUpdatedBy(int by){ m_updated_by=by;}
    QDateTime startDate() const { return m_start_date;}
    void setStartDate(QDateTime time){ m_start_date=time;}
    QDateTime endDate() const { return m_end_date;}
    void setEndDate(QDateTime time){ m_end_date=time;}
    QString isAction() const { return m_is_action;}
    void setIsAction(QString action){ m_is_action=action;}
private:
    int m_ad_account_id;
    QString m_ad_system_id;
    QString m_name;
    QString m_description;
    QString m_acc_path;
    QString m_acc_master;
    int m_year;
    int m_month;
    QString m_unit_name;
    QString m_unit_abbre;
    QString m_unit_addr;
    QString m_unit_zip;
    QString m_unit_tel;
    QString m_unit_fax;
    QString m_unit_email;
    QString m_unit_taxno;
    QString m_unit_lp;
    QString m_domain;
    QDateTime m_created;
    int m_created_by;
    QDateTime m_updated;
    int m_updated_by;
    QDateTime m_start_date;
    QDateTime m_end_date;
    QString m_is_action;


};
#endif // ACCOUNTBEAN_H
