#ifndef WINDOWBEAN_H
#define WINDOWBEAN_H
#include <QObject>

class WindowBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int adWindowId READ adWindowId WRITE setAdWindowId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString description READ description WRITE setDescription)
    Q_PROPERTY(QString help READ help WRITE setHelp)
    Q_PROPERTY(QString windowType READ windowType WRITE setWindowType)
    Q_PROPERTY(int adSubId READ adSubId WRITE setAdSubId)

public:
    Q_INVOKABLE WindowBean(QObject* parent = 0){};
    int adWindowId() { return m_ad_window_id;}
    void setAdWindowId(int id) { m_ad_window_id = id;}
    QString name() { return m_name;}
    void setName(QString name) { m_name = name;}
    QString description() { return m_description;}
    void setDescription(QString s){ m_description = s;}
    QString help() { return m_help;}
    void setHelp(QString s){ m_help = s;}
    QString windowType() { return m_window_type;}
    void setWindowType(QString type){ m_window_type = type;}
    int adSubId() { return m_ad_sub_id;}
    void setAdSubId(int id) { m_ad_sub_id = id;}
private:

    int m_ad_window_id;
    QString m_name;
    QString m_description;
    QString m_help;
    QString m_window_type;
    int m_ad_sub_id;

};
#endif // WINDOWBEAN_H
