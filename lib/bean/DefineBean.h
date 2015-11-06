#ifndef DEFINEBEAN_H
#define DEFINEBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT DefineBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString code READ code WRITE setCode)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString describe READ describe WRITE setDescribe)
    Q_PROPERTY(bool isView READ isView WRITE setIsView)

public:
    Q_INVOKABLE DefineBean(QObject* parent = 0){};
    virtual ~DefineBean() {}
    int id() const { return m_id;}
    void setId(int id){ m_id=id;}
    QString code() const { return m_code;}
    void setCode(QString code){ m_code = code;}
    QString name() const { return m_name;}
    void setName(QString name){ m_name = name;}
    QString describe() const { return m_describe;}
    void setDescribe(QString desc){ m_describe = desc;}
    bool isView() const { return m_is_view; }
    void setIsView(bool b) { m_is_view = b;}


private:

    int m_id;
    QString m_code;
    QString m_name;
    QString m_describe;
    bool m_is_view;


};
#endif // DEFINEBEAN_H
