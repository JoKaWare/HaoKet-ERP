#ifndef DEPBEAN_H
#define DEPBEAN_H
#include <QObject>
#include "lib_global.h"

class LIBSHARED_EXPORT DepBean :public QObject{
    Q_OBJECT
    Q_PROPERTY(QString depId READ depId WRITE setDepId)
    Q_PROPERTY(QString depName READ depName WRITE setDepName)
    Q_PROPERTY(QString depPerson READ depPerson WRITE setDepPerson)
    Q_PROPERTY(QString depSuperior READ depSuperior WRITE setDepSuperior)
    Q_PROPERTY(QString depTel READ depTel WRITE setDepTel)
    Q_PROPERTY(QString depAddr READ depAddr WRITE setDepAddr)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(bool depEnd READ depEnd WRITE setDepEnd)
    Q_PROPERTY(int depGrade READ depGrade WRITE setDepGrade)
public:
    Q_INVOKABLE DepBean(QObject* parent = 0){};
    virtual ~DepBean() {}
    QString depId() const { return m_dep_id;}
    void setDepId(QString id){ m_dep_id=id;}
    QString depName() const { return m_dep_name;}
    void setDepName(QString name){ m_dep_name=name;}
    QString depPerson() const { return m_dep_person;}
    void setDepPerson(QString person){ m_dep_person=person;}
    QString depSuperior() const { return m_dep_superior;}
    void setDepSuperior(QString superior){ m_dep_superior=superior;}
    QString depTel() const { return m_dep_tel; }
    void setDepTel(QString tel){ m_dep_tel=tel;}
    QString depAddr() const { return m_dep_addr;}
    void setDepAddr(QString addr){ m_dep_addr=addr;}
    QString memo() const { return m_memo;}
    void setMemo(QString memo){ m_memo=memo;}
    bool depEnd() const { return m_dep_end;}
    void setDepEnd(bool end){ m_dep_end=end;}
    int depGrade() const { return m_dep_grade;}
    void setDepGrade(int grade){ m_dep_grade=grade;}
private:

    QString m_dep_name;
    QString m_dep_id;
    QString m_dep_person;
    QString m_dep_superior;
    QString m_dep_tel;
    QString m_dep_addr;
    QString m_memo;
    bool m_dep_end;
    int  m_dep_grade;

};
#endif // DEPBEAN_H
