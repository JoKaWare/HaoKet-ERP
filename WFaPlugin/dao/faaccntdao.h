#ifndef FAACCNTDAO_H
#define FAACCNTDAO_H
#include <QList>
#include <QSqlQueryModel>
#include "bean/ProductTypeBean.h"
#include "bean/ProductBean.h"
#include "bean/FaWayBean.h"
#include "bean/RdBean.h"
#include "bean/FaSubsidiaryBean.h"
#include "common/dbmanager.h"
#include "queryrunner.h"
#include "dao/producttypedao.h"
#include "log4qt/propertyconfigurator.h"
#include "log4qt/logger.h"
class FaAccntDAO
{
public:
    FaAccntDAO();
    static int getSqlCount(QString sql);
    static int updateFaWay(FaWayBean *bean);
    static int updateFaWayStatus(int wayId);
    static FaWayBean *getFayWay();
    static QList<RdBean *> queryRdList(QString sql);

    static int createSubsidiary(FaSubsidiaryBean *bean);
    static int updateSubsidiary(FaSubsidiaryBean *bean);
    static int deleteSubsidiary(FaSubsidiaryBean *bean);
    static QList<FaSubsidiaryBean *> queryFaSubsidiaryByEndDate(QDate eDate);
    static QList<FaSubsidiaryBean *> queryFaSubsidiaryByDate(QDate sDate,QDate eDate);
    static QList<FaSubsidiaryBean *> queryFaSubsidiaryByNo(QString no);
    static QList<FaSubsidiaryBean *> queryFaSubsidiaryByBottom(QString whCode,QString productCode);
    static QList<FaSubsidiaryBean *> queryFIFOFaSubsidiaryBy(QString whCode,QString productCode);
    static QList<FaSubsidiaryBean *> queryReFIFOFaSubsidiaryBy(QString whCode, QString productCode);
    static QList<FaSubsidiaryBean *> queryReFIFOFaSubsidiaryByDvId(int id);
    static QList<FaSubsidiaryBean *> queryFIFOFaSubsidiaryReByBottom(QString whCode,QString productCode);

};

#endif // FAACCNTDAO_H
