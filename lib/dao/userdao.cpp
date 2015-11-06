#include <QVector>
#include "userdao.h"
#include "db/queryrunner.h"
#include "db/abstractqueryrunner.h"
#include "common/dbmanager.h"

UserDAO::UserDAO()
{
}

int UserDAO::createUser(UserBean *user){
    QString sql="INSERT INTO ad_user (ad_username, is_action, description, password, email, supervisor_id, "
            "created, created_by,updated_by, user_level,email_user, email_user_pw, phone1, phone2, fax, birthday, title)"
            " VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getDBConnection(),sql,user);
}

int UserDAO::modiPassword(int userid, QString newPw){
    QString sql="UPDATE ad_user SET password=? WHERE ad_userid=?";
    QVector<QVariant> qvar(0);
    qvar.append(QVariant(newPw));
    qvar.append(QVariant(userid));
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getDBConnection(),sql,qvar);

}

int UserDAO::updateUser(UserBean *user){
    QString sql="UPDATE ad_user SET is_action=?, description=?,email=?, supervisor_id=?, updated_by=?,updated=?,"
            " user_level=?,email_user=?, email_user_pw=?, phone1=?, phone2=?, fax=?, birthday=?, title=?"
            " WHERE ad_userid="+QString::number(user->adUserid());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getDBConnection(),sql,user);
}

int UserDAO::deleteUser(UserBean *user){
    QString sql="DELETE FROM ad_user "
            " WHERE ad_userid="+QString::number(user->adUserid());
    QueryRunner query=QueryRunner();
    return query.update(DBManager::getDBManager()->getDBConnection(),sql);
}
UserBean *UserDAO::getUserById(int id){
    QString sql="select ad_userid, ad_username, is_action, description, password, email, supervisor_id, "
            "email_user, email_user_pw, phone1, phone2, fax, birthday, title, "
            "created,user_level from ad_user where ad_userid="+QString::number(id);
    QueryRunner query=QueryRunner();
    UserBean *userbean= new UserBean;
    return query.read<UserBean>(DBManager::getDBManager()->getDBConnection(),sql,userbean);


}
UserBean *UserDAO::getUser(QString username){
    QString sql="select ad_userid, ad_username, is_action, description, password, email, supervisor_id, "
            "email_user, email_user_pw, phone1, phone2, fax, birthday, title, user_level, "
            "created,user_level from ad_user where ad_username='"+username+"'";
    QueryRunner query=QueryRunner();
    UserBean *userbean= new UserBean;
    return query.read<UserBean>(DBManager::getDBManager()->getDBConnection(),sql,userbean);

}

QList<UserBean *> UserDAO::getAllUser(){

    QString sql="select ad_userid, ad_username, is_action, description, password, email, supervisor_id, "
            "created,user_level from ad_user order by ad_userid asc";
    QueryRunner query=QueryRunner();
    QList<UserBean *> userList=query.query<UserBean>(DBManager::getDBManager()->getDBConnection(),sql);
    return userList;
}


QList<UserBean *> UserDAO::getUserByAction(QString action){
    QString sql="select ad_userid, ad_username, is_action, description, password, email, supervisor_id, "
            "created,user_level from ad_user where is_action = ? ";
    QVector<QVariant> qvar(0);
    qvar.append(QVariant(action));

    QueryRunner query=QueryRunner();
    QList<UserBean *> userList=query.query<UserBean>(DBManager::getDBManager()->getDBConnection(),sql,qvar);
    return userList;

}
