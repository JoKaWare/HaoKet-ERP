#ifndef FAWAYBEAN_H
#define FAWAYBEAN_H
#include <QObject>

class FaWayBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int wayId READ wayId WRITE setWayId)
    Q_PROPERTY(QString wayName READ wayName WRITE setWayName)
    Q_PROPERTY(QString wayNote READ wayNote WRITE setWayNote)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(int status READ status WRITE setStatus)
public:
    int wayId() { return m_way_id;}
    void setWayId(int id){ m_way_id = id;}
    QString wayName(){ return m_way_name;}
    void setWayName(QString value){ m_way_name = value;}
    QString wayNote(){ return m_way_note;}
    void setWayNote(QString value){ m_way_note = value;}
    QString memo(){ return m_memo;}
    void setMemo(QString value){ m_memo = value;}
    int status() { return m_status;}
    void setStatus(int id){ m_status = id;}
private:
    int m_way_id;
    QString m_way_name;
    QString m_way_note;
    QString m_memo;
    int m_status;
};
#endif // FAWAYBEAN_H
