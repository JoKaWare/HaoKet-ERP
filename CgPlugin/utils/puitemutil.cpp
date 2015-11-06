#include "puitemutil.h"
#include "haokeapp.h"
#include "cgplugin.h"
PuItemUtil::PuItemUtil()
{
}
QString PuItemUtil::getToDayMaxNo(QString formId,QString table,QDate date,int nCount){
    TableIdBean * bean = TableDAO::getTableById(formId);
    int no = 0;
    QString s = date.toString("yyyyMMdd");
    if(bean != NULL && bean->tableCode().length() > 0){}
    else{
        TableIdBean * tbean = new TableIdBean();
        tbean->setTableCode(formId);
        tbean->setTableDate(QDate::currentDate());
        tbean->setTableName(table);
        tbean->setTableLength(3);
        tbean->setTableNo(0);
        tbean->setMemo(table);
        int result = TableDAO::createTable(tbean);
        if(result < 1){

        }
        bean = TableDAO::getTableById(formId);

    }
    if(bean !=NULL && bean->tableCode().length()>0){
        no = bean->tableNo();
        if(date == bean->tableDate()){
            if(no <= 0){
                int count = nCount;
                no = count + 1;
            }else{
                no = no + 1;
            }
            bean->setTableNo(no);

        }else{
            int count = nCount;
            no = count + 1;
            bean->setTableNo(no);
            bean->setTableDate(date);
        }
        int result = TableDAO::updateTable(bean);
        if(result > 0){

            return s + QkStringUtils::numberToString(no,bean->tableLength());
        }else{
            return "error";
        }
    }else{
        return "NO";
    }
}

QString PuItemUtil::getToDayMaxOrderId(QString formId,QString table,QDate date){
    int count = OrderDAO::getPuOrderCount(date);
    return getToDayMaxNo(formId,table,date,count);

}

QString PuItemUtil::getToDayMaxArrivalId(QString formId,QString table,QDate date){
    int count = ArrivalDAO::getPuArrivalCount(date);
    return getToDayMaxNo(formId,table,date,count);

}

QString PuItemUtil::getToDayMaxOrderId(QDate date){
    int count = OrderDAO::getPuOrderCount(date);
    QString formId = HaoKeApp::puSubId() + CgPlugin::orderWinId();
    QString table = "pu_order_vouch";
    return getToDayMaxNo(formId,table,date,count);

}

QString PuItemUtil::getToDayMaxArrivalId(QDate date){
    int count = ArrivalDAO::getPuArrivalCount(date);
    QString formId = HaoKeApp::puSubId() + CgPlugin::arrivalWinId();
    QString table = "pu_arrival_vouch";
    return getToDayMaxNo(formId,table,date,count);

}
