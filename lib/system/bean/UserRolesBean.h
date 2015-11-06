#ifndef USERROLESBEAN_H
#define USERROLESBEAN_H
#include <QObject>
#include <QDateTime>
class UserRolesBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(int adUserid READ adUserid WRITE setAdUserid)
    Q_PROPERTY(int adRoleId READ adRoleId WRITE setAdRoleId)
    Q_PROPERTY(int adAccountId READ adAccountId WRITE setAdAccountId)
    Q_PROPERTY(int adOrgId READ adOrgId WRITE setAdOrgId)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)


public:
    Q_INVOKABLE UserRolesBean(QObject* parent = 0){};
    int id(){ return m_id;}
    void setId(int id){ m_id = id;}
    int adUserid(){ return m_ad_userid;}
    void setAdUserid(int id) { m_ad_userid = id;}
    int adRoleId() { return m_ad_role_id;}
    void setAdRoleId(int id) { m_ad_role_id = id;}
    int adAccountId() { return m_ad_account_id;}
    void setAdAccountId(int id) { m_ad_account_id = id;}
    int adOrgId() { return m_ad_org_id;}
    void setAdOrgId(int id) { m_ad_org_id = id;}
    QDateTime created(){ return m_created;}
    void setCreated(QDateTime t){ m_created = t;}
    int createdBy() { return m_created_by;}
    void setCreatedBy(int by){ m_created_by = by;}
private:
    int m_id;
    int m_ad_userid;
    int m_ad_role_id;
    int m_ad_account_id;
    int m_ad_org_id;
    QDateTime m_created;
    int m_created_by;
};
#endif // USERROLESBEAN_H
