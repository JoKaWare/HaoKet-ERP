#ifndef TABLEIDBEAN_H
#define TABLEIDBEAN_H
#include <QObject>
#include <QDate>
#include "lib_global.h"

class LIBSHARED_EXPORT TableIdBean:public QObject{
    Q_OBJECT
    Q_PROPERTY(QString tableCode READ tableCode WRITE setTableCode)
    Q_PROPERTY(QString tableName READ tableName WRITE setTableName)
    Q_PROPERTY(int tableNo READ tableNo WRITE setTableNo)
    Q_PROPERTY(QDate tableDate READ tableDate WRITE setTableDate)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(int tableLength READ tableLength WRITE setTableLength)
public:
    QString tableCode() { return m_table_code;}
    void setTableCode(QString code){ m_table_code = code;}
    QString tableName() { return m_table_name;}
    void setTableName(QString name){ m_table_name = name;}
    int tableNo() { return m_table_no;}
    void setTableNo(int no){ m_table_no = no;}
    QDate tableDate(){ return m_table_date;}
    void setTableDate(QDate date){ m_table_date = date;}
    QString memo() { return m_memo;}
    void setMemo(QString memo) { m_memo = memo;}
    int tableLength(){ return m_table_length;}
    void setTableLength(int l){ m_table_length = l;}
private:
    QString m_table_code;
    QString m_table_name;
    int m_table_no;
    int     m_table_length;
    QDate m_table_date;
    QString m_memo;

};
#endif // TABLEIDBEAN_H
