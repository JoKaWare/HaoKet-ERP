#ifndef SYSTEMSETBEAN_H
#define SYSTEMSETBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT SystemSetBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(QString id READ id WRITE setId)
    Q_PROPERTY(int subId READ subId WRITE setSubId)
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString value READ value WRITE setValue)
    Q_PROPERTY(QString caption READ caption WRITE setCaption)
    Q_PROPERTY(bool yesNo READ yesNo WRITE setYesNo)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
public:
    QString id() { return m_id;}
    void setId(QString id) { m_id = id;}
    int subId() { return m_sub_id;}
    void setSubId(int id) { m_sub_id = id;}
    QString name() { return m_name;}
    void setName(QString n) { m_name = n;}
    QString value() { return m_value;}
    void setValue(QString value) { m_value = value;}
    QString caption() { return m_caption;}
    void setCaption(QString c) { m_caption =c ; }
    bool yesNo() { return m_yes_no;}
    void setYesNo(bool b) { m_yes_no = b ;}
    QString memo() { return m_memo;}
    void setMemo(QString m ) { m_memo = m;}
private:
    QString m_id;
    int m_sub_id;
    QString m_name;
    QString m_value;
    QString m_caption;
    bool m_yes_no;
    QString m_memo;
};
#endif // SYSTEMSETBEAN_H
