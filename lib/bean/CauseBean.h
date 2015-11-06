#ifndef CAUSEBEAN_H
#define CAUSEBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT CauseBean:public QObject{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId)
    Q_PROPERTY(QString causeName READ causeName WRITE setCauseName)
    Q_PROPERTY(bool isDiscounts READ isDiscounts WRITE setIsDiscounts)
    Q_PROPERTY(bool isBack READ isBack WRITE setIsBack)
public:
    int id(){return m_id;}
    void setId(int id){ m_id = id;}
    QString causeName(){ return m_cause_name;}
    void setCauseName(QString name){ m_cause_name = name;}
    bool isDiscounts() { return m_is_discounts;}
    void setIsDiscounts(bool b){ m_is_discounts = b;}
    bool isBack(){ return m_is_back;}
    void setIsBack(bool b){ m_is_back = b;}

private:
    int m_id;
    QString m_cause_name;
    bool m_is_discounts;
    bool m_is_back;
};
#endif // CAUSEBEAN_H
