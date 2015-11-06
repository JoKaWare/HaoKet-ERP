#include "fatransceiverssummaryqueryform.h"
#include "bean/SupplieBean.h"
#include "bean/SupplieTypeBean.h"
#include "bean/WareHouseBean.h"
#include "bean/DepBean.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "dao/waredao.h"
#include "dao/depdao.h"
#include "haokeapp.h"
#include "wfaplugin.h"
FaTransceiversSummaryQueryForm::FaTransceiversSummaryQueryForm(QWidget *parent) :
    SingleQueryForm(parent)
{
    QString dSql1 = " SELECT t.* FROM fa_transceivers_summary(?, ?, ?, ?, ?) "
            " t(product_code varchar , be_quantity numeric , be_cost numeric , be_money numeric , "
            " in_quantity numeric , in_cost numeric , in_money numeric ,"
            " out_quantity numeric , out_cost numeric , out_money numeric ,"
            " st_quantity numeric , st_cost numeric , st_money numeric ,"
            " product_name varchar, style varchar, unit varchar) ";

    QString dSql2 = "";
    childItemProperties childItem[] = {
            { "product_code","编码","商品", 0,80, true, true },
            { "product_name","名称","商品", 1,100, true, true },
            { "style","规格","商品",2,80, true, false },
            { "unit","单位","单位", 3,60, true, false },
            { "be_quantity","数量","期初", 4, 80,true, true },
            { "be_cost","单价","期初", 5, 80,true, true },
            { "be_money","金额","期初", 6, 80,true, true },
            { "in_quantity","数量","入库", 7,80, true, true },
            { "in_cost","单价","入库", 8,80, true, true },
            { "in_money","金额","入库", 9,80, true, true },
            { "out_quantity","数量","出库", 10,80, true, true },
            { "out_cost","单价","出库", 11,80, true, true },
            { "out_money","金额","出库", 12,80, true, true },
            { "st_quantity","数量","期末", 13,80, true, true },
            { "st_cost","单价","期末", 14,80, true, true },
            { "st_money","金额","期末", 15,80, true, true }
    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }

    /*
    QList<DepBean *> depBeanList = DepDAO::queryDep();
    QStringList depList ;
    for(int i =0 ; i < depBeanList.size(); i++){
        depList << depBeanList.at(i)->depId() + " - " +depBeanList.at(i)->depName();
    }
    dwNameQks->setListModel(true);
    dwNameQks->setItems(depList);
    dwNameLabel->setText("部    门:");
    */
    dwNameQks->setVisible(false);
    dwNameLabel->setVisible(false);
    QList<WareHouseBean *> whBeanList = WareDAO::queryWarehouse();
    QStringList whList ;
    for(int i =0 ; i < whBeanList.size(); i++){
        whList << whBeanList.at(i)->whCode() + " - " +whBeanList.at(i)->whName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(whList);
    dwTypeLabel->setText("仓    库:");
    idLabel->setVisible(false);
    noEdit->setVisible(false);
    Label->setVisible(false);
    rBnt1->setVisible(false);
    rBnt2->setVisible(false);
    rBnt3->setVisible(false);
    QString formId = HaoKeApp::faSubId() + WFaPlugin::faTransceiversSummaryWinId();
    QString winTitle = "收货存汇总表";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::faSubId().toInt(),formId.toInt(),0,"");
    QDate oneDate = QDate(HaoKeApp::getInstance()->getOperateDate().year(),HaoKeApp::getInstance()->getOperateDate().month(),1);
    sDateEdit1->setDate(oneDate);
    setFormId(formId);
    setTabDetailText("收货存汇总表");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 4 << 6 << 7 << 9 << 10 << 12 << 13 << 15;
    setTotalItem(totalItem);
    initData(dItem,dSql1,dSql2);
    initTableHead();

    //设定是否根据审核状态查询
    //setHandleFiled("c.is_complete");

    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
}

void FaTransceiversSummaryQueryForm::sTableClicked(QString no){

}
