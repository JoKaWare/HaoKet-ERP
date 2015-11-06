#include "outimeiqueryform.h"
#include "bcplugin.h"
#include "haokeapp.h"
#include "rdoutimeiwin.h"
OutImeiQueryForm::OutImeiQueryForm(QWidget *parent) :
    SingleQueryForm(parent)
{
    QString dSql1 = "SELECT a.*, c.emp_name, b.dep_name "
                " FROM rd_record a "
                " LEFT JOIN ba_department b ON a.dep_code=b.dep_id "
                " LEFT JOIN ba_employee c ON a.person_code=c.emp_code "
                " WHERE a.bus_date>=? AND a.bus_date<=? "
                " AND ( a.vouch_type='02' OR a.vouch_type='14' OR a.vouch_type='11' "
                " OR (a.vouch_type='07' AND a.bus_type<>'调拨出库') ) "
                " AND is_handle=true "
                " ORDER BY a.bus_date,a.id ASC";
    QString dSql2 = " ";
    childItemProperties childItem[] = {
            { "rd_no","单号","单号", 0,100, true, true },
            { "bus_date","单据日期","单据日期", 1,80, true, true },
            { "bus_type","单据类型","单据类型", 2,80, true, false },
            { "bus_no","业务单号","业务单号", 3,100, true, false },
            { "dep_name","部门","部门", 4,120, true, false },
            { "emp_name","业务员","业务员", 5,60, true, false },
            { "is_handle","单据审核","单据审核", 6,60, true, false },
            { "handler","审核人","审核人", 7,60, true, false },
            { "audit_time","审核时间","审核时间", 8,140, true, false },
            { "creater","制单","制单", 9,60, true, false },
            { "imei_audit","串号审核","串号审核", 10,60, true, false },
            { "memo","备注","备注", 11,200, true, false },

    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }
    idLabel->setVisible(false);
    noEdit->setVisible(false);
    dwNameQks->setVisible(false);
    dwTypeQks->setVisible(false);
    dwNameLabel->setVisible(false);
    dwTypeLabel->setVisible(false);
    proNameLabel->setVisible(false);
    proNameQks->setVisible(false);
    proTypeLabel->setVisible(false);
    proTypeQks->setVisible(false);
    Label->setText("串码审核:");
    rBnt2->setText("末审核");
    rBnt3->setText("已审核");
    rBnt2->setChecked(true);
    //verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);
    //gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);
    QString formId = HaoKeApp::bcSubId() + BcPlugin::rdInListQueryWinId();
    setFormId(formId);
    setTabDetailText("出库单/采购退货单列表");

    initData(dItem,dSql1,dSql2);
    initTableHead();
    setHandleFiled("imei_audit");

    connect(this,SIGNAL(tableClicked(QString)),this,SLOT(sTableClicked(QString)));
}

void OutImeiQueryForm::sTableClicked(QString no){
    if(no.length()>1){
        if(!HaoKeApp::getInstance()->gui()->subWinIsOpen("串码出库")){
            RdOutImeiWin *pWin = new RdOutImeiWin(no,this);
            pWin->setWindowTitle("串码出库");
            HaoKeApp::getInstance()->gui()->addSubWin(pWin);
            pWin->showMaximized();
        }
    }
}

