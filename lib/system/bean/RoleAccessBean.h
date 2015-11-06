#ifndef ROLEACCESSBEAN_H
#define ROLEACCESSBEAN_H
#include <QObject>
#include <QDateTime>
class RoleAccessBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(int adProcessId READ adProcessId WRITE setAdProcessId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(int adWindowId READ adWindowId WRITE setAdWindowId)
    Q_PROPERTY(int adRoleId READ adRoleId WRITE setAdRoleId)
    Q_PROPERTY(int adAccountId READ adAccountId WRITE setAdAccountId)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)


public:
    Q_INVOKABLE RoleAccessBean(QObject* parent = 0){};
    int id() { return m_id;}
    void setId(int id){ m_id = id;}
    int adProcessId(){ return m_ad_process_id;}
    void setAdProcessId(int id) { m_ad_process_id = id;}
    int adWindowId() { return m_ad_window_id;}
    void setAdWindowId(int id) { m_ad_window_id = id;}
    QString name() { return m_name;}
    void setName(QString name) { m_name = name;}

    int adRoleId() { return m_ad_role_id;}
    void setAdRoleId(int id) { m_ad_role_id = id;}
    int adAccountId() { return m_ad_account_id;}
    void setAdAccountId(int id) { m_ad_account_id = id;}

    QDateTime created(){ return m_created;}
    void setCreated(QDateTime t){ m_created = t;}
    int createdBy() { return m_created_by;}
    void setCreatedBy(int by){ m_created_by = by;}
private:
    int m_id;
    int m_ad_process_id;
    QString m_name;
    int m_ad_window_id;
    int m_ad_role_id;
    int m_ad_account_id;
    QDateTime m_created;
    int m_created_by;
};
#endif // ROLEACCESSBEAN_H
