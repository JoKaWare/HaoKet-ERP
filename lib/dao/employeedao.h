#ifndef EMPLOYEEDAO_H
#define EMPLOYEEDAO_H
#include <QList>
#include "bean/EmployeeBean.h"
#include "common/dbmanager.h"
#include "db/queryrunner.h"
#include "lib_global.h"

class LIBSHARED_EXPORT EmployeeDAO
{
public:
    EmployeeDAO();
    static int createEmp(EmployeeBean *bean);
    static int updateEmp(EmployeeBean *bean);
    static int delEmp(EmployeeBean *bean);
    static QList<EmployeeBean *> queryEmp();
    static QList<EmployeeBean *> queryEmpAll();
    static QList<EmployeeBean *> queryEmpBy(QString id);
    static EmployeeBean * getEmpById(QString id);
    static EmployeeBean * getEmpByCode(QString code);
};

#endif // EMPLOYEEDAO_H
