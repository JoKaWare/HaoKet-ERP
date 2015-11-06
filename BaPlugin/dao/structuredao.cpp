#include "structuredao.h"

StructureDAO::StructureDAO()
{
}

int StructureDAO::createStructure(StructureBean *bean){
    QString sql = "INSERT INTO product_structure("
                " psp_code, dep_code, is_expand, is_reckon, unit, handler, audit_time, "
                " status, created_by, created, updated_by, updated)"
        "VALUES ( ?, ?, ?, ?, ?, ?, ?,"
                " ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StructureDAO::updateStructure(StructureBean *bean){
    QString sql = "UPDATE product_structure "
                " SET psp_code=?, dep_code=?, is_expand=?, is_reckon=?, unit=?, handler=?, "
                " audit_time=?, status=?, created_by=?, created=?, updated_by=?, "
                " updated=? "
            " WHERE psp_code='" + bean->pspCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StructureDAO::delStructure(StructureBean *bean){
    QString sql = "DELETE FROM product_structure"
                " WHERE psp_code='" + bean->pspCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StructureDAO::getByCodeCount(QString code){
    QString sql="SELECT count(*) FROM product_structure WHERE psp_code='" + code + "'";
    QueryRunner query=QueryRunner();
    return query.getCount(DBManager::getDBManager()->getGoinDBConnection(),sql);
}

QList<StructureBean *> StructureDAO::queryStructure(){
    QString sql = "SELECT a.id, psp_code,b.product_name,b.style, dep_code, is_expand, a.unit, handler, audit_time, "
            " a.is_reckon, a.status, a.created_by,a.created, a.updated_by, a.updated"
        " FROM product_structure a INNER JOIN product b ON a.psp_code=b.product_code "
        " WHERE a.status=0 ";
    QueryRunner query=QueryRunner();
    QList<StructureBean *> pList = query.query<StructureBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

QList<StructureBean *> StructureDAO::queryAllStructure(){
    QString sql = "SELECT a.id, psp_code,b.product_name,b.style, dep_code, is_expand, a.unit, handler, audit_time, "
                " a.is_reckon, a.status, a.created_by,a.created, a.updated_by, a.updated"
        " FROM product_structure a INNER JOIN product b ON a.psp_code=b.product_code ORDER BY a.id ASC";
    QueryRunner query=QueryRunner();
    QList<StructureBean *> pList = query.query<StructureBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

StructureBean * StructureDAO::getStructureByPsCode(QString code){
    QString sql = "SELECT a.id, psp_code,b.product_name,b.style, dep_code, is_expand, a.unit, handler, audit_time, "
                " a.is_reckon, a.status, a.created_by,a.created, a.updated_by, a.updated"
        " FROM product_structure a INNER JOIN product b ON a.psp_code=b.product_code"
            " WHERE psp_code='" + code + "' ORDER BY a.id ASC";
    QueryRunner query = QueryRunner();
    StructureBean *dBean = new StructureBean;
    return query.read<StructureBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

int StructureDAO::createStructures(StructuresBean *bean){
    QString sql = "INSERT INTO product_structures("
                " psp_code, ps_code, quantity, reality_quantity, waste_unit, "
                " waste_rate, chang_rate)"
        " VALUES ( ?, ?, ?, ?, ?, "
                " ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StructureDAO::updateStructures(StructuresBean *bean){
    QString sql = "UPDATE product_structures "
                " SET ps_code=?, quantity=?, reality_quantity=?, "
                " waste_unit=?, waste_rate=?, chang_rate=? "
            " WHERE id=" + QString::number(bean->id());
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StructureDAO::delStructures(StructuresBean *bean){
    QString sql = "DELETE FROM product_structures"
                " WHERE id=" + QString::number(bean->id()) + "";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int StructureDAO::delStructuresByCode(QString pspCode){
    QString sql = "DELETE FROM product_structures"
                " WHERE psp_code='" + pspCode + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,NULL);
}



QList<StructuresBean *> StructureDAO::queryStructuresByPspCode(QString code){
    QString sql = "SELECT a.id, a.psp_code, a.ps_code,b.product_name,b.style ,a.quantity, reality_quantity, waste_unit,"
                " waste_rate, chang_rate "
            " FROM product_structures a INNER JOIN product b ON a.ps_code=b.product_code "
            " WHERE psp_code='" + code + "' ORDER BY a.id ASC";
    QueryRunner query=QueryRunner();
    QList<StructuresBean *> pList = query.query<StructuresBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return pList;
}

QSqlQueryModel *StructureDAO::querySqlModelStructureBy(QString type, QString name, QString pinyin){
    QString sql = "SELECT a.id, psp_code,b.product_name,b.style, dep_code, is_expand, a.unit, handler, audit_time, "
                " a.status, a.created_by,a.created, a.updated_by, a.updated"
        " FROM product_structure a INNER JOIN product b ON a.psp_code=b.product_code"
        " WHERE b.type_id LIKE '" + type + "%' AND b.product_name LIKE '" + name + "%' AND b.pinyin_code LIKE '" + pinyin +"%'"
        " ORDER BY a.id ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Dishes Code"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Dishes Name"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Sytle"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Dep Code"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Is Expand"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Unit"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Handler"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Audit Time"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Status"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("Created By"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("Created"));
    model->setHeaderData(12, Qt::Horizontal,QObject::tr("Updated By"));
    model->setHeaderData(13, Qt::Horizontal,QObject::tr("Updated"));

    return model;
}

QSqlQueryModel *StructureDAO::querySqlModelStructureByType(QString type){
    QString sql = "SELECT a.id, psp_code,b.product_name,b.style, dep_code, is_expand, a.unit, handler, audit_time, "
                " a.status, a.created_by,a.created, a.updated_by, a.updated"
        " FROM product_structure a INNER JOIN product b ON a.psp_code=b.product_code"
        " WHERE b.type_id LIKE '" + type + "%' ORDER BY a.id ASC";
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery(sql,DBManager::getDBManager()->getGoinDBConnection());
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Dishes Code"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Dishes Name"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Sytle"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Dep Code"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Is Expand"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("Unit"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Handler"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Audit Time"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Status"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("Created By"));
    model->setHeaderData(11, Qt::Horizontal,QObject::tr("Created"));
    model->setHeaderData(12, Qt::Horizontal,QObject::tr("Updated By"));
    model->setHeaderData(13, Qt::Horizontal,QObject::tr("Updated"));
    return model;
}
