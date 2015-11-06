#ifndef STRUCTUREDAO_H
#define STRUCTUREDAO_H
#include <QList>
#include <QSqlQueryModel>

#include "bean/StructureBean.h"
#include "bean/StructuresBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
#include "lib_global.h"

class StructureDAO
{
public:
    StructureDAO();
    static int createStructure(StructureBean *bean);
    static int updateStructure(StructureBean *bean);
    static int delStructure(StructureBean *bean);
    static int getByCodeCount(QString code);
    static QList<StructureBean *> queryStructure();
    static QList<StructureBean *> queryAllStructure();
    static StructureBean * getStructureByPsCode(QString code);

    static int createStructures(StructuresBean *bean);
    static int updateStructures(StructuresBean *bean);
    static int delStructures(StructuresBean *bean);
    static int delStructuresByCode(QString pspCode);
    static QList<StructuresBean *> queryStructuresByPspCode(QString code);

    static QSqlQueryModel *querySqlModelStructureByType(QString type);
    static QSqlQueryModel *querySqlModelStructureBy(QString type,QString name,QString pinyin);
};

#endif // STRUCTUREDAO_H
