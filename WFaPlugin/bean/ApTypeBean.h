#ifndef APTYPEBEAN_H
#define APTYPEBEAN_H
#include <QObject>

class ApTypeBean : public QObject{
    Q_OBJECT
    Q_PROPERTY(QString typeCode READ typeCode WRITE setTypeCode)
    Q_PROPERTY(QString typeName READ typeName WRITE setTypeName)
    Q_PROPERTY(int flag READ flag WRITE setFlag)
public:
    QString typeCode() { return m_type_code;}
    void setTypeCode(QString code){ m_type_code = code;}
    QString typeName() { return m_type_name;}
    void setTypeName(QString name){ m_type_name = name;}
    int flag() { return m_flag;}
    void setFlag(int flag){ m_flag = flag;}
private:
    QString m_type_code;
    QString m_type_name;
    int m_flag;
};
#endif // APTYPEBEAN_H
