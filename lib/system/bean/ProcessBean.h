#ifndef PROCESSBEAN_H
#define PROCESSBEAN_H
#include <QObject>

class ProcessBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int adProcessId READ adProcessId WRITE setAdProcessId)
    Q_PROPERTY(int adWindowId READ adWindowId WRITE setAdWindowId)
    Q_PROPERTY(int adSubId READ adSubId WRITE setAdSubId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QString help READ help WRITE setHelp)
    Q_PROPERTY(QString isAction READ isAction WRITE setIsAction)

public:
    Q_INVOKABLE ProcessBean(QObject* parent = 0){};
    int adProcessId(){ return m_ad_process_id;}
    void setAdProcessId(int id) { m_ad_process_id = id;}
    int adWindowId() { return m_ad_window_id;}
    void setAdWindowId(int id) { m_ad_window_id = id;}
    int adSubId() { return m_ad_sub_id;}
    void setAdSubId(int id) { m_ad_sub_id = id;}
    QString name() { return m_name;}
    void setName(QString name) { m_name = name;}
    QString description() { return m_description;}
    void setDescription(QString s){ m_description = s;}
    QString help() { return m_help;}
    void setHelp(QString s){ m_help = s;}
    QString isAction() { return m_is_action;}
    void setIsAction(QString is){ m_is_action = is;}
private:
    int m_ad_process_id;
    int m_ad_window_id;
    int m_ad_sub_id;
    QString m_name;
    QString m_description;
    QString m_help;
    QString m_is_action;

};
#endif // PROCESSBEAN_H
