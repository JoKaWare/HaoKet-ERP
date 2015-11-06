#ifndef LOGBEAN_H
#define LOGBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"
class LIBSHARED_EXPORT LogBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int adLogId READ adLogId WRITE setAdLogId)
    Q_PROPERTY(int adProcessId READ adProcessId WRITE setAdProcessId)
    Q_PROPERTY(int adWindowId READ adWindowId WRITE setAdWindowId)
    Q_PROPERTY(int adSubId READ adSubId WRITE setAdSubId)
    Q_PROPERTY(int adUserid READ adUserid WRITE setAdUserid)
    Q_PROPERTY(QString adSystemId READ adSystemId WRITE setAdSystemId)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QString adLogName READ adLogName WRITE setAdLogName)
    Q_PROPERTY(QString adUsename READ adUsename WRITE setAdUsename)
    Q_PROPERTY(QDateTime procTime READ procTime WRITE setProcTime)

public:
    int adLogId(){ return m_ad_log_id;}
    void setAdLogId(int id) { m_ad_log_id = id;}
    int adWindowId() { return m_ad_window_id;}
    void setAdWindowId(int id) { m_ad_window_id = id;}
    int adProcessId(){ return m_ad_process_id;}
    void setAdProcessId(int id) { m_ad_process_id = id;}
    int adSubId() { return m_ad_sub_id;}
    void setAdSubId(int id) { m_ad_sub_id = id;}
    int adUserid() { return m_ad_userid;}
    void setAdUserid(int id) { m_ad_userid = id;}
    QString adSystemId() { return m_ad_system_id;}
    void setAdSystemId(QString value) { m_ad_system_id = value;}
    QString description() { return m_description;}
    void setDescription(QString s){ m_description = s;}
    QString adLogName() { return m_ad_log_name;}
    void setAdLogName(QString s){ m_ad_log_name = s;}
    QString adUsename() { return m_ad_usename;}
    void setAdUsename(QString s){ m_ad_usename = s;}
    QDateTime procTime(){ return m_proc_time;}
    void setProcTime(QDateTime time){ m_proc_time = time;}
private:
    int m_ad_log_id;
    int m_ad_window_id;
    int m_ad_sub_id;
    int m_ad_userid;
    int m_ad_process_id;
    QString m_ad_system_id;
    QString m_ad_log_name;
    QString m_ad_usename;
    QString m_description;
    QDateTime m_proc_time;
};
#endif // LOGBEAN_H
