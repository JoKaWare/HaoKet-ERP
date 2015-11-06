#ifndef SUBSYSBEAN_H
#define SUBSYSBEAN_H
#include <QObject>

class SubSysBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int adSubId READ adSubId WRITE setAdSubId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString version READ version WRITE setVersion)
    Q_PROPERTY(int status READ status WRITE setStatus)
public:
    int adSubId() { return m_ad_sub_id;}
    void setAdSubId(int id) { m_ad_sub_id = id;}
    QString name() { return m_name;}
    void setName(QString name) { m_name = name;}
    QString version() { return m_version;}
    void setVersion(QString v) { m_version = v;}
    int status() { return m_status;}
    void setStatus(int status){ m_status = status;}
private:
    int m_ad_sub_id;
    QString m_name;
    QString m_version;
    int m_status;

};
#endif // SUBSYSBEAN_H
