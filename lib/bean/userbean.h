#ifndef USERBEAN_H
#define USERBEAN_H

#include <QObject>
#include <QDateTime>
#include "lib_global.h"

class LIBSHARED_EXPORT UserBean :public QObject{
Q_OBJECT
Q_PROPERTY(int adUserid READ adUserid WRITE setAdUserid)
Q_PROPERTY(QString adUsername READ adUsername WRITE setAdUsername)
Q_PROPERTY(QString isAction READ isAction WRITE setIsAction)
Q_PROPERTY(QString description READ description WRITE setDescription)
Q_PROPERTY(QString password READ password WRITE setPassword)
Q_PROPERTY(QString email READ email WRITE setEmail)
Q_PROPERTY(QString emailUser READ emailUser WRITE setEmailUser)
Q_PROPERTY(QString emailUserPw READ emailUserPw WRITE setEmailUserPw)
Q_PROPERTY(QString phone1 READ phone1 WRITE setPhone1)
Q_PROPERTY(QString phone2 READ phone2 WRITE setPhone2)
Q_PROPERTY(QString fax READ fax WRITE setFax)
Q_PROPERTY(QString title READ title WRITE setTitle)
Q_PROPERTY(QDateTime birthday READ birthday WRITE setBirthday)
Q_PROPERTY(double supervisorId READ supervisorId WRITE setSupervisorId)
Q_PROPERTY(QDateTime created READ created WRITE setCreated)
Q_PROPERTY(QDateTime updated READ updated WRITE setUpdated)
Q_PROPERTY(int createdBy READ createdBy WRITE setCreatedBy)
Q_PROPERTY(int updatedBy READ updatedBy WRITE setUpdatedBy)
Q_PROPERTY(int userLevel READ userLevel WRITE setUserLevel)
public:
    Q_INVOKABLE UserBean(QObject* parent = 0){};
    virtual ~UserBean() {}
    static UserBean *getInstance(){
        static UserBean userbean;
        return &userbean;
    }
    void setAdUserid(int userid) { m_ad_userid = userid; }
    int adUserid() const { return m_ad_userid; }

    void setUserLevel(int level){ m_user_level=level;}
    int userLevel() const {return m_user_level; }
    void setAdUsername(QString username){m_ad_username = username;}
    QString adUsername() const { return m_ad_username; }

    void setIsAction(QString isaction){m_is_action = isaction; }
    QString isAction() const{ return m_is_action;}

    void setDescription(QString desc){m_description=desc;}
    QString description() const { return m_description;}

    void setPassword(QString pass){m_password=pass;}
    QString password() const { return m_password;}

    void setEmail(QString email){m_email=email;}
    QString email() const { return m_email;}

    void setEmailUser(QString email){m_email_user=email;}
    QString emailUser() const { return m_email_user;}

    void setEmailUserPw(QString pw){m_email_user_pw=pw;}
    QString emailUserPw() const { return m_email_user_pw;}

    void setPhone1(QString phone){m_phone1=phone;}
    QString phone1() const { return m_phone1;}

    void setPhone2(QString phone){m_phone2=phone;}
    QString phone2() const { return m_phone2;}

    void setFax(QString fax){m_fax=fax;}
    QString fax() const { return m_fax;}

    void setTitle(QString title){m_title=title;}
    QString title() const { return m_title;}

    void setBirthday(QDateTime time){m_birthday=time;}
    QDateTime birthday() const { return m_birthday; }

    void setSupervisorId(double super){m_supervisor_id=super;}
    double supervisorId() const { return m_supervisor_id;}

    void setCreated(QDateTime time){m_created=time;}
    QDateTime created() const { return m_created; }

    void setUpdated(QDateTime time){m_updated=time;}
    QDateTime updated() const { return m_updated; }

    void setCreatedBy(int user){ m_created_by=user;}
    int createdBy() const {return m_created_by; }

    void setUpdatedBy(int user){ m_updated_by=user;}
    int updatedBy() const {return m_updated_by; }
private:
    int m_ad_userid;
    QString m_ad_username;
    QString m_is_action;
    QString m_description;
    QString m_password;
    QString m_email;
    QString m_email_user;
    QString m_email_user_pw;
    QString m_phone1;
    QString m_phone2;
    QString m_fax;
    QString m_title;
    QDateTime m_birthday;
    double m_supervisor_id;
    QDateTime m_created;
    QDateTime m_updated;
    int m_created_by;
    int m_updated_by;
    int m_user_level;


};

#endif // USERBEAN_H
