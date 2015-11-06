#ifndef REPORTFORMATBEAN_H
#define REPORTFORMATBEAN_H
#include <QObject>
#include <QDateTime>
#include "lib_global.h"

class LIBSHARED_EXPORT ReportFormatBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(int winId READ winId WRITE setWinId)
    Q_PROPERTY(QString reportTitle READ reportTitle WRITE setReportTitle)
    Q_PROPERTY(QString reportFormat READ reportFormat WRITE setReportFormat)
    Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
    Q_PROPERTY(QString creater READ creater WRITE setCreater)
    Q_PROPERTY(QDateTime created READ created WRITE setCreated)
public:
    int id(){return m_id;}
    void setId(int id){ m_id = id;}
    int winId(){ return m_win_id;}
    void setWinId(int winId){ m_win_id = winId;}
    QString reportTitle(){ return m_report_title;}
    void setReportTitle(QString title){ m_report_title = title;}
    QString reportFormat(){ return m_report_format;}
    void setReportFormat(QString format){ m_report_format = format;}
    int createdBy(){return m_created_by; }
    void setCreatedBy(int user){ m_created_by = user;}
    QString creater(){return m_creater; }
    void setCreater(QString user){ m_creater = user;}
    QDateTime created(){ return m_created; }
    void setCreated(QDateTime time){m_created = time;}
private:
    int m_id;
    int m_win_id;
    QString m_report_title;
    QString m_report_format;
    int m_created_by;
    QString m_creater;
    QDateTime m_created;
};
#endif // REPORTFORMATBEAN_H
