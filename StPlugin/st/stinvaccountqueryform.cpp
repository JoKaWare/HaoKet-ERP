#include "stinvaccountqueryform.h"
#include "bean/SupplieBean.h"
#include "bean/SupplieTypeBean.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "bean/WareHouseBean.h"
#include "dao/waredao.h"
#include "dao/rddao.h"
#include "stinwin.h"
#include "stoutwin.h"
#include "strdwin.h"
#include "haokeapp.h"
#include "stplugin.h"

StInvAccountQueryForm::StInvAccountQueryForm(QWidget *parent) :
    AnyQueryForm(parent)
{
    QString dSql1 = " SELECT t.*,end_q-in_q+out_q as start_q FROM st_inv_account(?, ?, ?, ?, true) "
            " t(row_sum bigint , wh_name varchar , mx_id integer ,bus_date date,rd_no varchar,name varchar, "
            " wh_code varchar,cus_code varchar,product_code varchar,in_q numeric,out_q numeric,end_q integer,product_name varchar) ";
    QString dSql2 = "";
    childItemProperties childItem[] = {
            { "rd_no","单号","单号", 0,100, true, true },
            { "bus_date","日期","日期", 1,100, true, true },
            { "wh_code","编码","仓库", 2,60, true, true },
            { "wh_name","名称","仓库", 3,80, true, true },
            { "name","单据类型","单据类型", 4,80, true, true },
            { "product_code","编码","商品", 5,80, true, true },
            { "product_name","名称","商品", 6,100, true, true },
            { "start_q","期初量","期初量", 7, 80,true, true },
            { "in_q","收入数量","收入数量", 8, 80,true, true },
            { "out_q","发出数量","发出数量", 9, 80,true, true },
            { "end_q","结存数量","结存数量", 10,80, true, true }
    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }
    /*
    QList<CustomerBean *> venBeanList = CustomerDAO::queryCus();
    QStringList venList ;
    for(int i =0 ; i < venBeanList.size(); i++){
        venList << venBeanList.at(i)->cusCode() + " - " +venBeanList.at(i)->cusName();
    }
    dwNameQks->setListModel(true);
    dwNameQks->setItems(venList);
    */
    QDate oneDate = QDate(HaoKeApp::getInstance()->getOperateDate().year(),HaoKeApp::getInstance()->getOperateDate().month(),1);
    sDateEdit1->setDate(oneDate);
    dwNameQks->setVisible(false);
    dwNameLabel->setVisible(false);
    noEdit->setVisible(false);
    Label->setVisible(false);
    //idLabel->setVisible(false);
    QString note =  "<html><head/><body><p><span style=' font-weight:600; color:#ff0000;'> %1 </span></p></body></html>";

    idLabel->setText(note.arg("商品台帐查询必须选择仓库与商品"));
    QList<WareHouseBean *> beanList = WareDAO::queryWarehouse();
    QStringList typeList ;
    for(int i =0 ; i < beanList.size(); i++){
        typeList << beanList.at(i)->whCode() + " - " +beanList.at(i)->whName();
    }
    dwTypeQks->setListModel(true);
    dwTypeQks->setItems(typeList);
    dwTypeLabel->setText("仓    库");
    proTypeLabel->setVisible(false);
    proTypeQks->setVisible(false);
    Label->setVisible(false);
    rBnt1->setVisible(false);
    rBnt2->setVisible(false);
    rBnt3->setVisible(false);
    QString formId = HaoKeApp::stSubId() + StPlugin::invAccountQueryWinId();
    QString winTitle = "商品台帐";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,winTitle,HaoKeApp::saSubId().toInt(),formId.toInt(),0,"");

    setFormId(formId);
    setTabDetailText("商品台帐");
    //设置明细合计列号
    QList<int > totalItem;
    totalItem << 8 << 9;
    setTotalItem(totalItem);
    initData(dItem,dSql1,dSql2);
    initTableHead();


    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
}

void StInvAccountQueryForm::sTableClicked(QString no){
    if(no.length()>1){
        if(!HaoKeApp::getInstance()->gui()->subWinIsOpen("出入库单")){
            RdBean *bean = RdDAO::getRdByNo(no);
            if(bean && bean->rdNo().length() > 1){
                if(bean->vouchType() == HaoKeApp::getVouchRdOtherIn()){
                    StInWin *pWin = new StInWin(no,this);
                    pWin->setWindowTitle("出入库单");
                    HaoKeApp::getInstance()->gui()->addSubWin(pWin);
                    pWin->showMaximized();
                }else if(bean->vouchType() == HaoKeApp::getVouchRdOtherOut()){
                    StOutWin *pWin = new StOutWin(no,this);
                    pWin->setWindowTitle("出入库单");
                    HaoKeApp::getInstance()->gui()->addSubWin(pWin);
                    pWin->showMaximized();
                }else{
                    StRdWin *pWin = new StRdWin(no,this);
                    pWin->setWindowTitle("出入库单");
                    HaoKeApp::getInstance()->gui()->addSubWin(pWin);
                    pWin->showMaximized();
                }
            }
        }
    }
}
