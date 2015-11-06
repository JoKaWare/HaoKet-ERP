#ifndef ROLEBEAN_H
#define ROLEBEAN_H
#include <QObject>
#include <QDateTime>
class RoleBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int adRoleId READ adRoleId WRITE setAdRoleId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(int userLevel READ userLevel WRITE setUserLevel)
    Q_PROPERTY(QString accountList READ accountList WRITE setAccountList)
    Q_PROPERTY(QString orgList READ orgList WRITE setOrgList)
    Q_PROPERTY(QString isSuperAdmin READ isSuperAdmin WRITE setIsSuperAdmin)
    Q_PROPERTY(QString allowAccount READ allowAccount WRITE setAllowAccount)
    Q_PROPERTY(QString allowSale READ allowSale WRITE setAllowSale)
    Q_PROPERTY(QString allowProcurement READ allowProcurement WRITE setAllowProcurement)
    Q_PROPERTY(QString allowInout READ allowInout WRITE setAllowInout)
    Q_PROPERTY(QString allowInvoice READ allowInvoice WRITE setAllowInvoice)
    Q_PROPERTY(QString allowPartner READ allowPartner WRITE setAllowPartner)
    Q_PROPERTY(QString allowCashjournal READ allowCashjournal WRITE setAllowCashjournal)
    Q_PROPERTY(QString allowAsset READ allowAsset WRITE setAllowAsset)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
public:
    Q_INVOKABLE RoleBean(QObject* parent = 0){};
    int adRoleId() { return m_ad_role_id;}
    void setAdRoleId(int id) { m_ad_role_id = id;}
    QString name() { return m_name;}
    void setName(QString name) { m_name = name;}
    QString description() { return m_description;}
    void setDescription(QString s){ m_description = s;}
    int userLevel() { return m_user_level;}
    void setUserLevel(int level){ m_user_level = level;}
    QString accountList() { return m_account_list;}
    void setAccountList(QString s) { m_account_list = s;}
    QString orgList() { return m_org_list;}
    void setOrgList(QString s){ m_org_list = s;}
    QString isSuperAdmin() { return m_is_super_admin;}
    void setIsSuperAdmin(QString s){ m_is_super_admin = s;}
    QString allowAccount() { return m_allow_account;}
    void setAllowAccount(QString b){ m_allow_account = b;}
    QString allowSale(){ return m_allow_sale;}
    void setAllowSale(QString b){ m_allow_sale = b;}
    QString allowProcurement(){ return m_allow_procurement;}
    void setAllowProcurement(QString b){ m_allow_procurement = b;}
    QString allowInout(){ return m_allow_inout;}
    void setAllowInout(QString b){ m_allow_inout = b;}
    QString allowInvoice() { return m_allow_invoice;}
    void setAllowInvoice(QString b){ m_allow_invoice = b;}
    QString allowPartner(){ return m_allow_partner;}
    void setAllowPartner(QString b){ m_allow_partner = b;}
    QString allowCashjournal() { return m_allow_cashjournal;}
    void setAllowCashjournal(QString b){ m_allow_cashjournal = b;}
    QString allowAsset() { return m_allow_asset;}
    void setAllowAsset(QString b) { m_allow_asset = b;}

    QDateTime created(){ return m_created;}
    void setCreated(QDateTime t){ m_created = t;}
    int createdBy() { return m_created_by;}
    void setCreatedBy(int by){ m_created_by = by;}
private:
    int m_ad_role_id;
    QString m_name;
    QString m_description;
    int m_user_level;
    QString m_account_list;
    QString m_org_list;
    QString m_is_super_admin;
    QString m_allow_account;
    QString m_allow_sale;
    QString m_allow_procurement;
    QString m_allow_inout;
    QString m_allow_invoice;
    QString m_allow_partner;
    QString m_allow_cashjournal;
    QString m_allow_asset;
    QDateTime m_created;
    int m_created_by;
};
#endif // ROLEBEAN_H
