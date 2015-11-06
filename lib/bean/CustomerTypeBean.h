#ifndef CUSTOMERTYPEBEAN_H
#define CUSTOMERTYPEBEAN_H
#include <QObject>
#include "lib_global.h"
class  LIBSHARED_EXPORT CustomerTypeBean: public QObject{
    Q_OBJECT
    Q_PROPERTY(QString typeId READ typeId WRITE setTypeId)
    Q_PROPERTY(QString typeName READ typeName WRITE setTypeName)
    Q_PROPERTY(QString typeSuperior READ typeSuperior WRITE setTypeSuperior)
    Q_PROPERTY(QString explian READ explian WRITE setExplian)
    Q_PROPERTY(QString memo READ memo WRITE setMemo)
    Q_PROPERTY(bool typeEnd READ typeEnd WRITE setTypeEnd)
    Q_PROPERTY(int typeGrade READ typeGrade WRITE setTypeGrade)
public:

    QString typeId() const {return m_type_id;}
    void setTypeId(QString id) { m_type_id=id;}
    QString typeName() const { return m_type_name;}
    void setTypeName(QString name) { m_type_name=name;}
    QString typeSuperior() const { return m_type_superior;}
    void setTypeSuperior(QString s){ m_type_superior=s;}
    QString explian() const { return m_explian;}
    void setExplian(QString s) { m_explian=s;}
    QString memo() const { return m_memo;}
    void setMemo(QString s){ m_memo=s;}
    bool typeEnd() const { return m_type_end;}
    void setTypeEnd(bool b){ m_type_end=b;}
    int typeGrade() const { return m_type_grade;}
    void setTypeGrade(int grade){ m_type_grade=grade;}
private:
    QString m_type_id;
    QString m_type_name;
    bool m_type_end;
    int m_type_grade;
    QString m_type_superior;
    QString m_explian;
    QString m_memo;

};
#endif // CUSTOMERTYPEBEAN_H
