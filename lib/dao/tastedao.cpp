#include "tastedao.h"

TasteDAO::TasteDAO()
{
}

int TasteDAO::createTaste(TasteBean *bean){
    QString sql = "INSERT INTO taste("
             " taste_name, taste_caption)"
            " VALUES (?, ?);";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TasteDAO::updateTaste(TasteBean *bean){
    QString sql = "UPDATE taste "
            " SET taste_name=?, taste_caption=? "
          " WHERE id=" + QString::number(bean->id()) ;
    QueryRunner query  =QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int TasteDAO::delTaste(TasteBean *bean){
    QString sql = "DELETE FROM taste "
            " WHERE id=" + QString::number(bean->id()) ;
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<TasteBean *> TasteDAO::queryTaste(){
    QString sql = "SELECT id, taste_name, taste_caption"
            " FROM taste ORDER BY id asc";
    QueryRunner query  =QueryRunner();
    QList<TasteBean *> list = query.query<TasteBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return list;
}
TasteBean * TasteDAO::getTaste(QString id){
    QString sql = "SELECT id, taste_name, taste_caption"
            " FROM taste WHERE id=" + id;
    QueryRunner query=QueryRunner();
    TasteBean *dBean= new TasteBean;
    return query.read<TasteBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

