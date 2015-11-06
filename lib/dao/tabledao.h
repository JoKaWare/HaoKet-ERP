#ifndef TABLEDAO_H
#define TABLEDAO_H
#include <QList>
#include "bean/TableIdBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT TableDAO
{
public:
    TableDAO();
    static int createTable(TableIdBean *bean);
    static int updateTable(TableIdBean *bean);
    static int delTable(TableIdBean *bean);
    static QList<TableIdBean *> queryTable();
    static int getTableCount(QString id);
    static TableIdBean * getTableById(QString id);
};

#endif // TABLEDAO_H
