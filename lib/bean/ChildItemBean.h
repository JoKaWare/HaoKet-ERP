#ifndef CHILDITEMBEAN_H
#define CHILDITEMBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT ChildItemBean:public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString cnName READ cnName WRITE setCnName)
    Q_PROPERTY(int width READ width WRITE setWidth)
    Q_PROPERTY(bool visible READ visible WRITE setVisible)
    Q_PROPERTY(bool edit READ edit WRITE setEdit)
public:
    int id(){return m_id;}
    void setId(int id){ m_id = id;}
    QString name(){ return m_name;}
    void setName(QString name){ m_name = name;}
    QString cnName(){ return m_cn_name;}
    void setCnName(QString name){ m_cn_name = name;}
    int width(){return m_width;}
    void setWidth(int width){ m_width = width;}
    bool visible() { return m_visible;}
    void setVisible(bool b){ m_visible = b;}
    bool edit(){ return m_edit;}
    void setEdit(bool b){ m_edit = b;}

private:
    int m_id;
    QString m_name;
    QString m_cn_name;
    int m_width;
    bool m_visible;
    bool m_edit;

};
#endif // CHILDITEMBEAN_H
