#include "employeedao.h"

EmployeeDAO::EmployeeDAO()
{
}

int EmployeeDAO::createEmp(EmployeeBean *bean){
    QString sql = "INSERT INTO ba_employee("
            " emp_name, emp_code, dep_id, emp_attr, entry_date, memo, created_by, "
            " created, sex, height, weight, nation, hometown, birth, educational, "
            " graduation_date, graduation_shcool, phone, card_number, addr, "
            " zip, residence_addr, tel, guarantor, guarantor_tel, guarantor_number, "
            " guarantor_addr, guarantor_relation,status) "
        " VALUES (?, ?, ?, ?, ?, ?, ?, ?, "
            " ?, ?, ?, ?, ?, ?, ?, ?,"
            " ?, ?, ?, ?, ?, ?, ?, ?,"
            " ?, ?, ?, ?, ?)";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int EmployeeDAO::updateEmp(EmployeeBean *bean){
    QString sql = "UPDATE ba_employee "
            " SET emp_name=?, emp_code=?, dep_id=?, emp_attr=?, entry_date=?, memo=?,"
                 "  sex=?, height=?, weight=?, nation=?,"
                 "  hometown=?, birth=?, educational=?, graduation_date=?, graduation_shcool=?,"
                 "  phone=?, card_number=?, addr=?, zip=?, residence_addr=?, tel=?,"
                 "  guarantor=?, guarantor_tel=?, guarantor_number=?, guarantor_addr=?,"
                 "  guarantor_relation=?, status=? "
            " WHERE emp_code='" + bean->empCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

int EmployeeDAO::delEmp(EmployeeBean *bean){
    QString sql = "DELETE FROM ba_employee "
            " WHERE emp_code='" + bean->empCode() + "'";
    QueryRunner query = QueryRunner();
    return query.update(DBManager::getDBManager()->getGoinDBConnection(),sql,bean);
}

QList<EmployeeBean *> EmployeeDAO::queryEmp(){
    QString sql = "SELECT emp_id, emp_code, emp_name, dep_id, emp_attr, entry_date, memo, created_by, "
            " created, sex, height, weight, nation, hometown, birth, educational, "
            " graduation_date, graduation_shcool, phone, card_number, addr, "
            " zip, residence_addr, tel, guarantor, guarantor_tel, guarantor_number,"
            " guarantor_addr, guarantor_relation,status "
            " FROM ba_employee WHERE status=0 order by emp_id asc";
    QueryRunner query = QueryRunner();
    QList<EmployeeBean *> depList = query.query<EmployeeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<EmployeeBean *> EmployeeDAO::queryEmpAll(){
    QString sql = "SELECT emp_id, emp_code, emp_name, dep_id, emp_attr, entry_date, memo, created_by, "
            " created, sex, height, weight, nation, hometown, birth, educational, "
            " graduation_date, graduation_shcool, phone, card_number, addr, "
            " zip, residence_addr, tel, guarantor, guarantor_tel, guarantor_number,"
            " guarantor_addr, guarantor_relation,status "
            " FROM ba_employee order by emp_id asc";
    QueryRunner query = QueryRunner();
    QList<EmployeeBean *> depList = query.query<EmployeeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

QList<EmployeeBean *> EmployeeDAO::queryEmpBy(QString id){
    QString sql = "SELECT * "
            " FROM ba_employee WHERE dep_id='"+id+"' order by emp_id asc";
    QueryRunner query=QueryRunner();
    QList<EmployeeBean *> depList = query.query<EmployeeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql);
    return depList;
}

EmployeeBean *EmployeeDAO::getEmpById(QString id){
    QString  sql = "SELECT emp_id, emp_code, emp_name, dep_id, emp_attr, entry_date, memo, created_by, "
            " created, sex, height, weight, nation, hometown, birth, educational, "
            " graduation_date, graduation_shcool, phone, card_number, addr, "
            " zip, residence_addr, tel, guarantor, guarantor_tel, guarantor_number,"
            " guarantor_addr, guarantor_relation,status"
            " FROM ba_employee where emp_id="+id;
    QueryRunner query = QueryRunner();
    EmployeeBean *dBean = new EmployeeBean;
    return query.read<EmployeeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}

EmployeeBean *EmployeeDAO::getEmpByCode(QString code){
    QString  sql = "SELECT emp_id, emp_code, emp_name, dep_id, emp_attr, entry_date, memo, created_by, "
            " created, sex, height, weight, nation, hometown, birth, educational, "
            " graduation_date, graduation_shcool, phone, card_number, addr, "
            " zip, residence_addr, tel, guarantor, guarantor_tel, guarantor_number,"
            " guarantor_addr, guarantor_relation,status"
            " FROM ba_employee where emp_code='" + code + "'";
    QueryRunner query = QueryRunner();
    EmployeeBean *dBean = new EmployeeBean;
    return query.read<EmployeeBean>(DBManager::getDBManager()->getGoinDBConnection(),sql,dBean);
}
