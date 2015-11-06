#include "apbillwin.h"
#include "ui_apbillwin.h"
#include "haokeapp.h"
#include "bean/DepBean.h"
#include "bean/SupplieBean.h"
#include "bean/EmployeeBean.h"
#include "bean/WareHouseBean.h"
#include "bean/KmCodeBean.h"
#include "dao/depdao.h"
#include "dao/suppliedao.h"
#include "dao/employeedao.h"
#include "dao/waredao.h"
#include "dao/kmcodedao.h"
#include "dao/rddao.h"
#include "dao/apclosebilldao.h"
#include "common/cachebabeancommon.h"
#include "common/printutils.h"
#include "common/itemutil.h"
#include "system/limitscommon.h"
#include "qtrpt.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"
#include "widget/designoptdialog.h"
#include "wfaplugin.h"

ApBillWin::ApBillWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ApBillWin)
{
    ui->setupUi(this);
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = ApCloseBillDAO::getApCloseBillCount(RdFlag::RdOutFlag) - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    mRecord = mCountRecord;
    QList<ApCloseBillBean *> vouchBeanList = ApCloseBillDAO::queryApCloseBillByPage(mCountRecord,1,RdFlag::RdOutFlag);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->apNo());
    }
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(false);
    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);
    ui->toolBar->actions().at(7)->setEnabled(true);
    if(ui->noEdit->text().length() >0){
        ui->toolBar->actions().at(2)->setEnabled(true);
    }
    readAuthority();
}

ApBillWin::ApBillWin(QString no, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ApBillWin)
{
    ui->setupUi(this);
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = ApCloseBillDAO::getApCloseBillCount(RdFlag::RdOutFlag) - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);
    ui->toolBar->actions().at(7)->setEnabled(true);

    ApCloseBillBean *bean = ApCloseBillDAO::getApCloseBillByNo(no);
    if(bean != NULL && bean->apNo().length() > 0){
        mRecord = ApCloseBillDAO::getApCloseBillRowNumber(bean->id()) - 1;
        if(mRecord == 0){
            baseToolBar->actions().at(0)->setEnabled(false);
            baseToolBar->actions().at(2)->setEnabled(false);
        }else if(mRecord >= mCountRecord ){
            baseToolBar->actions().at(1)->setEnabled(false);
            baseToolBar->actions().at(3)->setEnabled(false);
        }
        delete bean;
        read(no);
        if(ui->noEdit->text().length() >0){
            ui->toolBar->actions().at(2)->setEnabled(true);
        }
    }else{
        QMessageBox::critical(this,"错误","此单不存在！");
    }
    readAuthority();
}

ApBillWin::~ApBillWin()
{
    delete ui;
}

void ApBillWin::readAuthority(){
    LimitsCommon::authority(ui->toolBar,mWinId.toInt());
}

void ApBillWin::init(){
    //窗体ID号
    mWinId = HaoKeApp::faSubId() + WFaPlugin::apBillWinId();
    mWinTitle = "付款单";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::faSubId().toInt(),mWinId.toInt(),0,"");

    //功能菜单
    actionProperties actsBase[]= {
        { "faApBill.new",tr("&New"),SLOT(sNew()), NULL, "New", QPixmap(":/image/Add.png"), NULL,  true, tr("New") },
        { "faApBill.edit",tr("&Edit"),SLOT(sEdit()), NULL, "Edit", QPixmap(":/image/edit.png"), NULL,  true, tr("Edit") },
        { "faApBill.delete",tr("&Delete"),SLOT(sDelete()), NULL, "Delete", QPixmap(":/image/cross_48.png"), NULL,  true, tr("Delete") },
        { "faApBill.save",tr("&Save"),SLOT(sSave()), NULL, "Save", QPixmap(":/image/save.png"), NULL,  true, tr("Save") },
        { "faApBill.audit",tr("&Audit"),SLOT(sAudit()), NULL, "Audit", QPixmap(":/image/stamp_48.png"), NULL,  true, tr("Audit") },
        { "faApBill.abandonAudit",tr("&Abandon Audit"),SLOT(sAbAudit()), NULL, "Abandon Audit", QPixmap(":/image/c_stamp_48.png"), NULL,  true, tr("Abandon Audit") },
        { "faApBill.delRow",tr("&DelRow"),SLOT(sDelRow()), NULL, "DelRow", QPixmap(":/image/minus.png"), NULL,  true, tr("DelRow") },
        { "faApBill.print",tr("&Print"),SLOT(sPrint()), NULL, "Print", QPixmap(":/image/printer.png"), NULL,  true, tr("Print") },
        { "faApBill.first",tr("&First"),SLOT(sFirst()), NULL, "First", QPixmap(":/image/first48.png"), NULL,  true, tr("First") },
        { "faApBill.next",tr("&Next"),SLOT(sNext()), NULL, "Next", QPixmap(":/image/n-next48.png"), NULL,  true, tr("Next") },
        { "faApBill.previous",tr("&Previous"),SLOT(sPrevious()), NULL, "Previous", QPixmap(":/image/n-previous48.png"), NULL,  true, tr("Previous") },
        { "faApBill.end",tr("&End"),SLOT(sEnd()), NULL, "End", QPixmap(":/image/end48.png"), NULL,  true, tr("End") },
        { "faApBill.cancel",tr("&Cancel"),SLOT(sCancel()), NULL, "Cancel", QPixmap(":/image/cancel.png"), NULL,  true, tr("Cancel") }

    };
    addActionsTo(actsBase,sizeof(actsBase) / sizeof(actsBase[0]));

    mIsEdit =false;

    ui->dateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());

    //初始化表体格式
    setInputEnable(false);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(7);

    childItemProperties childItem[] = {
            { "kmCode","科目编码","科目编码", 0,180, true, true },
            { "kmName","科目名称","科目名称", 1,120, true, true },
            { "digest","摘要","摘要", 2,180, true, true },
            { "amount","付款金额","付款金额", 3,80, true, true },
            { "busNo","结算单号","结算单号", 4, 100,true, true },
            { "apBill","支票号","支票号", 5, 100,true, true },
            { "id","ID","ID",6,60, false, false },
    };
    mChildItem << childItem[0] << childItem[1] << childItem[2] << childItem[3] << childItem[4] << childItem[5] <<childItem[6];

    //初始化表尾
    mFootView = new HierarchicalHeaderView(Qt::Horizontal);
    mFootView->setClickable(true);
    //mFootView->setMovable(false);
    mFootView->setResizeMode(QHeaderView::Fixed);
    mFootView->setHighlightSections(true);
    mFootModel = new FootTableModel(1,mChildItem.size(),this);
    mFootModel->setItem(0,new QStandardItem(""));
    mFootModel->setItem(1,new QStandardItem("合计:"));
    mFootView->setModel(mFootModel);

    mFootView->resizeSection(0,ui->tableWidget->verticalHeader()->width());
    mFootView->setFixedHeight(22);

    ui->verticalLayout_2->addWidget(mFootView);
    mFootModel->setItem(6,new QStandardItem(""));
    QObject::connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionResized(int,int,int)),this,SLOT(footResized(int,int,int)));
    refreshData();
    /*
    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    */
    mFootView->setDefaultAlignment (Qt::AlignLeft | Qt::AlignVCenter);
    mFootView->setTextElideMode (Qt::ElideLeft); //...效果


    //初始化表头数据
    QStringList  busTypeList;
    QList<ApTypeBean *> apTypeBeanList = KmCodeDAO::queryApType(RdFlag::RdOutFlag);
    for(int i = 0 ; i < apTypeBeanList.size() ; i ++ ){
        busTypeList << apTypeBeanList.at(i)->typeName();
    }
    QStringList  settleTypeList;
    QList<SettleTypeBean *> settleTypeBeanList = KmCodeDAO::querySettleType();
    for(int i = 0 ; i < settleTypeBeanList.size() ; i ++ ){
        settleTypeList << settleTypeBeanList.at(i)->settleName();
    }


    ui->busTypeCmb->addItems(busTypeList);
    ui->settleCmb->addItems(settleTypeList);
    QList<SupplieBean *> venBeanList = SupplieDAO::querySupplie();
    QStringList venList ;
    for(int i =0 ; i < venBeanList.size(); i++){
        venList << venBeanList.at(i)->supplieCode() + " - " +venBeanList.at(i)->supplieName();
    }
    ui->busQsk->setListModel(true);
    ui->busQsk->setItems(venList);

    QList<DepBean *> depBeanList = DepDAO::queryDepByEnd();
    QStringList depList ;
    for(int i =0 ; i < depBeanList.size(); i++){
        depList << depBeanList.at(i)->depId() + " - " +depBeanList.at(i)->depName();
    }
    ui->depQsk->setListModel(true);
    ui->depQsk->setItems(depList);

    QList<EmployeeBean *> employeeBeanList = EmployeeDAO::queryEmp();
    QStringList empList ;
    for(int i =0 ; i < employeeBeanList.size(); i++){
        empList << employeeBeanList.at(i)->empCode() + " - " +employeeBeanList.at(i)->empName();
    }
    ui->personQsk->setListModel(true);
    ui->personQsk->setItems(empList);

    QList<KmCodeBean *> codeBeanList = KmCodeDAO::queryKmCode();
    QStandardItemModel *model = new QStandardItemModel(codeBeanList.size(),1);
    for(int i=0;i < codeBeanList.size();i++){
        QStandardItem *itemName = new QStandardItem(codeBeanList.at(i)->kmCode() + " - " + codeBeanList.at(i)->kmName());
        model->setItem(i,0,itemName);
    }
    QkEditDelegate *delegate = new QkEditDelegate(model,this);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(22);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setItemDelegateForColumn(0,delegate);

}

void ApBillWin::footResized(int logicalIndex, int oldSize, int newSize){
    mFootView->resizeSection(logicalIndex + 1,newSize);
}
void ApBillWin::refreshData(){

    QStringList headerLabels;
    for (int i = 0; i < mChildItem.size(); i++){
        headerLabels.append(mChildItem[i].cnName);
        ui->tableWidget->setColumnWidth(mChildItem[i].id,mChildItem[i].width);
        mFootView->resizeSection(mChildItem[i].id + 1,mChildItem[i].width);
        if(!mChildItem[i].visible)ui->tableWidget->hideColumn(mChildItem[i].id);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
}

void ApBillWin::read(QString no){
    ApCloseBillBean *bean = ApCloseBillDAO::getApCloseBillByNo(no);
    mNo = no;
    if(bean != NULL && bean->apNo().length() > 0){
        ui->noEdit->setText(bean->apNo());
        ui->dateEdit->setDate(bean->busDate());

        SupplieBean *venBean = SupplieDAO::getSupplieByCode(bean->busCode());
        ui->busQsk->setText(bean->busCode() + " - " + venBean->supplieName());
        DepBean *depBean = DepDAO::getDepById(bean->depCode());
        ui->depQsk->setText(bean->depCode() + " - " + depBean->depName());
        ui->personQsk->setText(bean->personCode() + " - " + CacheBaBeanCommon::personToName(bean->personCode()));
        ui->memoEdit->setText(bean->memo());
        ui->makerEdit->setText(CacheBaBeanCommon::userToName(bean->createdBy(),1));
        ui->auditEdit->setText(bean->handler());
        for(int i = 0; i < ui->busTypeCmb->count(); i++){
            if(bean->vouchType() == ui->busTypeCmb->itemText(i)){
                ui->busTypeCmb->setCurrentIndex(i);
            }
        }
        ui->toolBar->actions().at(0)->setEnabled(true);
        ui->toolBar->actions().at(1)->setEnabled(true);
        ui->toolBar->actions().at(3)->setEnabled(false);
        ui->toolBar->actions().at(6)->setEnabled(false);

        if(bean->handler().length() > 1){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
        }else{
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
        }
        QList<ApCloseBillsBean *> pBeanList = ApCloseBillDAO::queryApCloseBillsByNo(no);
        mChildVouchsList = ApCloseBillDAO::queryApCloseBillsByNo(no);
        ui->tableWidget->setRowCount(pBeanList.size() + 1);
        mTotalQuantity = 0;
        mTotalSum = 0;
        for(int i =0; i < pBeanList.size(); i++){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget,i,mChildItem,pBeanList.at(i));
            mTotalSum = mTotalSum + pBeanList.at(i)->amount();
        }

        mFootModel->setItem(4,new QStandardItem(QString::number(mTotalSum,'f',2)));
        mFootView->reset();
        readAuthority();
    }
}

void ApBillWin::inputClear(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->headGridLayout);


}

void ApBillWin::setInputEnable(bool b){
     WidgetBeanUtil::setLayoutWidgetEnable(ui->headGridLayout,b);
     if(b){
         ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
     }else{
         ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     }
}

void ApBillWin::addActionsTo(actionProperties acts[], unsigned int numElems){
    baseToolBar = addToolBar(tr("Base"));
    baseToolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    baseToolBar->setIconSize(QSize(24, 24));
    ui->toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->toolBar->setIconSize(QSize(24, 24));
    for (unsigned int i = 0; i < numElems; i++){
        QAction *act = new QAction(acts[i].actionName, this);
        QIcon icon;
        icon.addPixmap(acts[i].pixmap,  QIcon::Normal, QIcon::Off);

        act->setText(acts[i].actionTitle);
        act->setObjectName(acts[i].actionName);
        act->setIcon(icon);

        connect(act, SIGNAL(triggered()), this, acts[i].slot);

        if(i<8){
            QString proceccId = mWinId + QString::number(i);
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::faSubId().toInt(),mWinId.toInt(),proceccId.toInt(),acts[i].toolTip,acts[i].actionName);

            act->setEnabled(false);
            ui->toolBar->addAction(act);
            addAction(act);
        }
        else
            baseToolBar->addAction(act);
    }

}
void ApBillWin::sFirst(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    mRecord = 0;
    ui->tableWidget->clear();
    refreshData();
    QList<ApCloseBillBean *> vouchBeanList = ApCloseBillDAO::queryApCloseBillByPage(0,1,RdFlag::RdOutFlag);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->apNo());

    }
    baseToolBar->actions().at(0)->setEnabled(false);
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(2)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(true);
}
\
void ApBillWin::sNext(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    if(mRecord < mCountRecord)
        mRecord = mRecord + 1;
    if(mRecord == mCountRecord){
        baseToolBar->actions().at(3)->setEnabled(false);
        baseToolBar->actions().at(1)->setEnabled(false);
    }
    ui->tableWidget->clear();
    refreshData();
    QList<ApCloseBillBean *> vouchBeanList = ApCloseBillDAO::queryApCloseBillByPage(mRecord,1,RdFlag::RdOutFlag);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->apNo());
    }
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(0)->setEnabled(true);
}

void ApBillWin::sPrevious(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    if(mRecord > 0)
        mRecord = mRecord - 1;
    if(mRecord == 0){
        baseToolBar->actions().at(0)->setEnabled(false);
        baseToolBar->actions().at(2)->setEnabled(false);
    }
    ui->tableWidget->clear();
    refreshData();
    QList<ApCloseBillBean *> vouchBeanList = ApCloseBillDAO::queryApCloseBillByPage(mRecord,1,RdFlag::RdOutFlag);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->apNo());
    }
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(true);
}

void ApBillWin::sEnd(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    ui->tableWidget->clear();
    refreshData();
    mCountRecord = ApCloseBillDAO::getApCloseBillCount(RdFlag::RdOutFlag) - 1;
    mRecord = mCountRecord;
    QList<ApCloseBillBean *> vouchBeanList = ApCloseBillDAO::queryApCloseBillByPage(mCountRecord,1,RdFlag::RdOutFlag);
    if(vouchBeanList.size()>0){
        read(vouchBeanList.at(0)->apNo());
    }
    baseToolBar->actions().at(0)->setEnabled(true);
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(false);
}

void ApBillWin::sNew(){
    inputClear();
    mIsEdit = true;
    mEditStatus = addFlag;
    setInputEnable(true);
    ui->dateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());

    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(false);
    ui->toolBar->actions().at(2)->setEnabled(false);
    ui->toolBar->actions().at(3)->setEnabled(true);
    ui->toolBar->actions().at(4)->setEnabled(false);
    ui->toolBar->actions().at(5)->setEnabled(false);
    ui->toolBar->actions().at(6)->setEnabled(true);
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    int nCount = ApCloseBillDAO::getApCloseBillCount(QDate::currentDate()) ;
    mNo = ItemUtil::getToDayMaxNo(mWinId,"ap_close_bill",QDate::currentDate(),nCount);
    ui->noEdit->setText(mNo);
    refreshData();

    mTotalQuantity = 0;
    mTotalSum = 0;

    mFootModel->setItem(4,new QStandardItem(QString::number(mTotalSum)));
    mFootView->reset();
    readAuthority();
}

void ApBillWin::sEdit(){
    if(ui->noEdit->text().length() < 1){
        QMessageBox::warning(this,"提示","无单不能修改！");
        return ;
    }
    if(ui->auditEdit->text().length() > 0){
        QMessageBox::warning(this,"提示","已审核，不能修改！");
        return ;
    }
    mIsEdit = true;
    setInputEnable(true);
    mEditStatus = editFlag;
    ui->noEdit->setEnabled(false);

    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(false);
    ui->toolBar->actions().at(2)->setEnabled(true);
    ui->toolBar->actions().at(3)->setEnabled(true);
    ui->toolBar->actions().at(4)->setEnabled(false);
    ui->toolBar->actions().at(5)->setEnabled(false);
    ui->toolBar->actions().at(6)->setEnabled(true);
    readAuthority();
}

void ApBillWin::sSave(){
    if(ui->noEdit->text().length()< 1){
        QMessageBox::warning(this,"提示","出错，此单号为空，不能保存");
        return ;
    }

    QAbstractItemModel *model = ui->tableWidget->model();
    int rowNum = model->rowCount() -1;
    if(rowNum == 0){
        QMessageBox::warning(this,"提示","无数据，不能保存");
        return;
    }

    if(ui->busQsk->text().trimmed().length() < 1){
        QMessageBox::warning(this,"提示","请输入供应商");
        return ;
    }

    for(int i = 0;i < rowNum; i++){
        QString pCode = model->data(model->index(i,0)).toString();
        QString rdNo =  model->data(model->index(i,4)).toString().trimmed();
        /*
        if(rdNo.length() > 1){
            int rdNoCount =  RdDAO::getRdCountByNo(rdNo);
            if(rdNoCount < 1){
                QMessageBox::information(this,"提示","此结算单：" + rdNo + " 不存在");
                return ;
            }
        }
        */
        KmCodeBean *pBean = KmCodeDAO::getKmCode(pCode);
        if(pBean != NULL && pBean->kmCode().length() > 0){
            for(int j = 0; j < ui->tableWidget->rowCount(); j ++){
                if(i != j && ui->tableWidget->model()->data(ui->tableWidget->model()->index(j,0)).toString().trimmed() == pCode){
                    QMessageBox::information(this,"提示","此商品：" + pCode + " 重复！");
                    ui->tableWidget->model()->setData(ui->tableWidget->model()->index(j,0),"");
                    return;
                }
            }
        }else{
            QMessageBox::warning(this,"提示","此原商品编码，不存在，不能保存");
            return ;
        }
    }
    if(mEditStatus == addFlag){
        if(ApCloseBillDAO::getApCloseBillCountByNo(ui->noEdit->text()) > 0){
            QMessageBox::warning(this,"提示","出错，此单号重复，不能保存，重新生成新单号");
            int nCount = ApCloseBillDAO::getApCloseBillCount(QDate::currentDate()) ;
            mNo = ItemUtil::getToDayMaxNo(mWinId,"ap_close_bill",QDate::currentDate(),nCount);
            ui->noEdit->setText(mNo);
            return ;
        }
        mNo = ui->noEdit->text();
        ApCloseBillBean *apBillBean = new ApCloseBillBean();
        apBillBean->setApNo(ui->noEdit->text());
        QDateTime time = QDateTime::currentDateTime();
        apBillBean->setBusDate(ui->dateEdit->date());
        apBillBean->setVouchType(ui->busTypeCmb->currentText());
        apBillBean->setSettleCode(ui->settleCmb->currentText());
        //付款单
        apBillBean->setBusFlag(RdFlag::RdOutFlag);
        apBillBean->setBusCode(ui->busQsk->text());
        apBillBean->setDepCode(ui->depQsk->text());
        apBillBean->setPersonCode(ui->personQsk->text());
        apBillBean->setBankAccount(ui->bankCardEdit->text());
        apBillBean->setBankName(ui->bankNameEdit->text());
        apBillBean->setAmount(mTotalSum);
        apBillBean->setSum(0);
        apBillBean->setMemo(ui->memoEdit->text());
        apBillBean->setHandler("");
        apBillBean->setCreated(time);
        apBillBean->setIsHandle(false);
        apBillBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        apBillBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        apBillBean->setUpdated(time);
        apBillBean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        apBillBean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = ApCloseBillDAO::createApCloseBill(apBillBean);
        int cResult = 0;
        for(int i = 0;i < rowNum; i++){
            ApCloseBillsBean *apBillsBean = new ApCloseBillsBean();
            apBillsBean->setApNo(mNo);
            apBillsBean->setSum(0);
            WidgetBeanUtil::setItemModelToBean(model,i,mChildItem,apBillsBean);

            int c = ApCloseBillDAO::createApCloseBills(apBillsBean);
            if(c < 1){
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","此" + apBillsBean->kmCode() + " 数据提交出错,不能保存");
                return ;
            }
            cResult = cResult + c;
        }
        if(mResult > 0 && cResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->makerEdit->setText(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
            setInputEnable(false);
            mCountRecord = ApCloseBillDAO::getApCloseBillCount(RdFlag::RdOutFlag) - 1;
            mRecord = mCountRecord;

            mDelChildList.clear();
            mAddChildVouchsList.clear();
            mChildVouchsList.clear();

            ui->tableWidget->clear();
            refreshData();
            read(ui->noEdit->text());

            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"Prompt","数据提交出错");
            return ;
        }
        readAuthority();



    }else if(mEditStatus == editFlag){
        //修改数据保存
        ApCloseBillBean *apBillBean = ApCloseBillDAO::getApCloseBillByNo(mNo);
        if(apBillBean && apBillBean->isHandle()){
            QMessageBox::warning(this,"提示","此单已审核，不能修改");
            return ;
        }
        apBillBean->setApNo(ui->noEdit->text());
        QDateTime time = QDateTime::currentDateTime();
        apBillBean->setBusDate(ui->dateEdit->date());
        apBillBean->setVouchType(ui->busTypeCmb->currentText());
        apBillBean->setSettleCode(ui->settleCmb->currentText());
        apBillBean->setBusCode(ui->busQsk->text());
        apBillBean->setDepCode(ui->depQsk->text());
        apBillBean->setPersonCode(ui->personQsk->text());
        apBillBean->setBankAccount(ui->bankCardEdit->text());
        apBillBean->setBankName(ui->bankNameEdit->text());
        apBillBean->setAmount(mTotalSum);
        apBillBean->setSum(0);
        apBillBean->setMemo(ui->memoEdit->text());
        apBillBean->setUpdated(time);
        apBillBean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        apBillBean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = 0;
        mResult = ApCloseBillDAO::updateApCloseBill(apBillBean);
        int cResult = 0;
        //删除
        for(int i = 0; i < mDelChildList.size(); i++){
            ApCloseBillsBean *delBean = new ApCloseBillsBean;
            delBean->setId(mDelChildList.at(i));
            int c = ApCloseBillDAO::delApCloseBills(delBean);
            cResult = cResult + c;
        }
        //更新
        for(int i = 0; i < mChildVouchsList.size(); i++){
            int c = ApCloseBillDAO::updateApCloseBills(mChildVouchsList.at(i));
            ui->memoEdit->setText(mChildVouchsList.at(i)->apNo());
            cResult = cResult + c;
        }
        //添加
        for(int i = 0; i < mAddChildVouchsList.size(); i++){
            int c = ApCloseBillDAO::createApCloseBills(mAddChildVouchsList.at(i));
            cResult = cResult + c;
        }

        if(mResult > 0 && cResult>0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            ui->makerEdit->setText(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
            setInputEnable(false);
            mDelChildList.clear();
            mAddChildVouchsList.clear();
            mChildVouchsList.clear();

            ui->tableWidget->clear();
            refreshData();
            read(ui->noEdit->text());

            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this,"错误","数据提交出错");
            return ;
        }
        readAuthority();
    }

}

void ApBillWin::sDelete(){
    if(ui->auditEdit->text().length() > 0){
        QMessageBox::warning(this,"提示","已审核，不能删除！");
        return ;
    }
    mNo = ui->noEdit->text().trimmed();

    if(QMessageBox::warning(this,"提示","是否删除？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        ApCloseBillBean *bean = ApCloseBillDAO::getApCloseBillByNo(mNo);
        bean->setApNo(mNo);
        if(bean->isHandle()){
            QMessageBox::warning(this,"提示",bean->handler() + " 已审核，不能删除！");
            return ;
        }
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int mResult = ApCloseBillDAO::delApCloseBillByNo(bean);
        int cResult = ApCloseBillDAO::delApCloseBillsByNo(ui->noEdit->text());
        if(mResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit =false;
            setInputEnable(false);
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            if(mRecord ==0){
                sNext();
            }else sPrevious();
            mCountRecord = ApCloseBillDAO::getApCloseBillCount(RdFlag::RdOutFlag) - 1;
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this,"错误","删除出错");

        }

    }
    readAuthority();
}

void ApBillWin::sDelRow(){
    if(!mIsEdit){
        QMessageBox::information(this,"提示","不能修改！");
        return;
    }
    QAbstractItemModel *modelTotal = ui->tableWidget->model();
    QItemSelectionModel *seleced = ui->tableWidget->selectionModel();
    int row = seleced->currentIndex().row();

    if(row >= 0){

        QString name = modelTotal->data(modelTotal->index(row,1)).toString();
        QString code = modelTotal->data(modelTotal->index(row,0)).toString();
        if(name.length() < 1){
            QMessageBox::information(this,"提示","不能删除此行！");
            return;
        }
        if(QMessageBox::warning(this, tr("Prompt"),"是否要删除此 *" + name + "*",
                                QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            if(mEditStatus == addFlag){
                modelTotal->removeRow(row);
            }else{
                for(int i =0 ; i < mChildVouchsList.size(); i++){
                    if(code == mChildVouchsList.at(i)->kmCode()){
                        mDelChildList.append(mChildVouchsList.at(i)->id());
                        mChildVouchsList.removeAt(i);

                    }
                }
                for(int i =0 ; i < mAddChildVouchsList.size(); i++){
                    if(code == mAddChildVouchsList.at(i)->kmCode()){
                        mAddChildVouchsList.removeAt(i);
                    }
                }
                modelTotal->removeRow(row);
            }
            if(mIsEdit){
                mTotalQuantity = 0;
                mTotalSum = 0;
                QAbstractItemModel *model = ui->tableWidget->model();
                for(int i = 0 ; i < ui->tableWidget->rowCount(); i++){
                    double quantity = model->data(model->index(i,WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toDouble();
                    double money = model->data(model->index(i,WidgetBeanUtil::getChildItemId(mChildItem,"money"))).toDouble();

                    mTotalQuantity = mTotalQuantity + quantity;
                    mTotalSum = mTotalSum + money;

                }

                mFootModel->setItem(5,new QStandardItem(QString::number(mTotalQuantity)));
                mFootModel->setItem(7,new QStandardItem(QString::number(mTotalSum)));
                mFootView->reset();

            }


        }
    }else{
        QMessageBox::information(this,"Prompt","请选择要删除的行!");
    }
}

void ApBillWin::sAudit(){
    ApCloseBillBean *bean = ApCloseBillDAO::getApCloseBillByNo(ui->noEdit->text());
    if(bean && bean->apNo().length() > 0){
        if(bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
            QMessageBox::information(this,"提示","已审核，不能再审核！");
            return ;
        }
        bean->setIsHandle(true);
        bean->setHandler(CacheBaBeanCommon::userToName(HaoKeApp::getInstance()->getUserId(),1));
        bean->setAuditTime(QDateTime::currentDateTime());
        bean->setIsHandle(true);
        bean->setUpdated(QDateTime::currentDateTime());
        bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
        bean->setUpdater(HaoKeApp::getInstance()->getUserDesc());
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int result = ApCloseBillDAO::updateApCloseBill(bean);
        if(result>0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            ui->auditEdit->setText(bean->handler());
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
            readAuthority();
            QMessageBox::information(this,"提示","审核成功！");
            return ;
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this,"提示","审核出错！");
            return ;
        }
    }else{
        QMessageBox::critical(this,"提示","此单不存在，不能审核！");
        return ;
    }
}

void ApBillWin::sAbAudit(){
    ApCloseBillBean *bean = ApCloseBillDAO::getApCloseBillByNo(ui->noEdit->text());
    if(bean && bean->apNo().length() > 0){
        if(!bean->isHandle()){
            ui->toolBar->actions().at(4)->setEnabled(false);
            ui->toolBar->actions().at(5)->setEnabled(true);
            QMessageBox::information(this,"提示","未审核，不能弃审！");
            return ;
        }
        bean->setIsHandle(false);
        bean->setHandler("");

        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int result = ApCloseBillDAO::updateApCloseBill(bean);
        if(result>0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            ui->auditEdit->setText("");
            ui->toolBar->actions().at(4)->setEnabled(true);
            ui->toolBar->actions().at(5)->setEnabled(false);
            readAuthority();
            QMessageBox::information(this,"提示","弃审成功！");
            return ;
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::critical(this,"提示","弃审出错！");
            return ;
        }
    }else{
        QMessageBox::critical(this,"提示","此单不存在，不能弃审！");
        return ;
    }
}

void ApBillWin::sPrint(){

    QString fileName = "ReportfaApBill.xml";
    QString title = mWinTitle;
    QString formatData = "";
    QList<ReportFormatBean *> rptList = ReportDAO::queryRptBy(mWinId);

    if(rptList.size() > 0){
        formatData = rptList.at(rptList.size() - 1)->reportFormat();
    }else {
        formatData = PrintUtils::makeWinPrintFormatData(ui->headGridLayout,mChildItem,title,fileName);
        ReportFormatBean *rptBean = new ReportFormatBean();
        rptBean->setReportTitle(title);
        rptBean->setReportFormat(formatData);
        rptBean->setWinId(mWinId.toInt());
        rptBean->setCreated(QDateTime::currentDateTime());
        rptBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        rptBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
        int result = ReportDAO::createRpt(rptBean);

    }
    QtRPT *report = new QtRPT(this);
    report->setBackgroundImage(QPixmap("./qt_background_portrait.png"));
    connect(report,SIGNAL(setValue(int&,QString&,QVariant&,int)),this,SLOT(setValue(int&,QString&,QVariant&,int)));
    report->recordCount << ui->tableWidget->rowCount() - 1;
    if (report->loadReportFormat(formatData) == false) {
        qDebug()<<"Report's format is null";
    }
    report->setWindowTitle(title);
    report->setModel(ui->tableWidget->model());
    report->setChildItem(mChildItem);

    if(HaoKeApp::getInstance()->getUserLevel()>8){
        DesignOptDialog *designOptDlg = new DesignOptDialog(this);
        QString formatData2 = PrintUtils::makeWinPrintFormatData(ui->headGridLayout,mChildItem,title,fileName);
        designOptDlg->setPrintData(0,mWinId,title,formatData,formatData2);
        int r = designOptDlg->exec();
        if(r == QDialog::Accepted){
            ReportFormatBean *fBean = ReportDAO::getRptById(QString::number(designOptDlg->getPrintId()));
            if(fBean){
                formatData = fBean->reportFormat();
                if (report->loadReportFormat(formatData) == false) {
                    qDebug()<<"Report's file not found";
                }
            }
            report->printExec();
        }else{

        }
    }else{
        report->printExec();
    }

}

void ApBillWin::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage){
    Q_UNUSED(reportPage);
    QGridLayout *layout = ui->headGridLayout;
    for(int i = 0 ; i < layout->rowCount(); i ++){
        for(int j =0 ; j < layout->columnCount(); j ++ ){
            QLayoutItem *layoutItem = layout->itemAtPosition(i,j);

            if(layoutItem && !layoutItem->isEmpty()){
                QWidget *widget = layoutItem->widget();

                QString className = widget->metaObject()->className();
                if(className == "QLineEdit"){
                    QLineEdit *c = (QLineEdit *)layoutItem->widget();
                    if (paramName == c->objectName()){
                        paramValue = c->text();
                        return ;
                    }
                }else if(className == "QkSearchEditBox"){
                    QkSearchEditBox *c = (QkSearchEditBox *)layoutItem->widget();
                    if (paramName == c->objectName()){
                        //paramValue = c->text() + "  " + c->subText();
                        paramValue = c->subText();
                        return ;
                    }
                }else if(className == "QDateEdit"){
                    QDateEdit *c = (QDateEdit *)layoutItem->widget();
                    if (paramName == c->objectName()){
                        paramValue = c->text();
                        return ;
                    }
                }else if(className == "QComboBox"){
                    QComboBox *c = (QComboBox *)layoutItem->widget();
                    if (paramName == c->objectName()){
                        paramValue = c->currentText();
                        return ;
                    }
                }
            }

        }
    }

}

void ApBillWin::sCancel(){

    this->close();
}

void ApBillWin::closeEvent(QCloseEvent *event){

    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            event->ignore();
            return ;
        }
    }

    event->accept();
    HaoKeApp::getInstance()->gui()->removeSubWin(this);


}

void ApBillWin::setupContextMenu(){
    /*
    handleAct = new QAction(QIcon(":/images/connector.png"),tr("关联联赛"),this);

    connect(handleAct, SIGNAL(triggered()), this, SLOT(handleMatch()));
    */
    setContextMenuPolicy(Qt::ActionsContextMenu);
}
void ApBillWin::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if(item->column() == 0 && mIsEdit){
        QString code = item->data(Qt::EditRole).toString().trimmed();
        if(code.length() < 1){
            return ;
        }
        //重复判断
        for(int i = 0; i < ui->tableWidget->rowCount(); i ++){
            if(i != item->row() && ui->tableWidget->model()->data(ui->tableWidget->model()->index(i,0)).toString().trimmed() == code){
                QMessageBox::information(this,"提示","此科目编码：" + code + " 已输入！");
                ui->tableWidget->model()->setData(ui->tableWidget->model()->index(item->row(),0),"");
                return;
            }
        }

        //根据ID查询科目信息

        KmCodeBean *bean = KmCodeDAO::getKmCode(code);
        if(code.length() > 0 && bean != NULL && bean->kmCode() == code ){
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"kmName",bean->kmName());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"amount",0.00);

            if((ui->tableWidget->rowCount()-1) == item->row()){
                QAbstractItemModel *model = ui->tableWidget->model();
                int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
                if(mEditStatus == editFlag && id < 1){

                    //单据修改 增加数据
                    ApCloseBillsBean *billsBean = new ApCloseBillsBean();
                    billsBean->setApNo(ui->noEdit->text());
                    billsBean->setSum(0);
                    WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,billsBean);
                    mAddChildVouchsList.append(billsBean);
                }
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            }
        }else{
            QMessageBox::information(this,"提示","不存在此科目");
            return ;
        }

    }else if(item->column() == 3 ){

        if(mIsEdit){
            mTotalQuantity = 0;
            mTotalSum = 0;
            QAbstractItemModel *model = ui->tableWidget->model();
            for(int i = 0 ; i < ui->tableWidget->rowCount(); i++){
                double amount = model->data(model->index(i,WidgetBeanUtil::getChildItemId(mChildItem,"amount"))).toDouble();
                mTotalSum = mTotalSum + amount;

            }
            mFootModel->setItem(4,new QStandardItem(QString::number(mTotalSum,'f',2)));
            mFootView->reset();

        }

    }

    //单据修改
    if(mEditStatus == editFlag){
        QAbstractItemModel *model = ui->tableWidget->model();
        int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
        QString pCode = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"kmCode"))).toString();
        double amount = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"amount"))).toDouble();

        if(item->column() == 2 || item->column()==3 || item->column()==4 || item->column()==5){
            if(id < 1 ){
                for(int i =0; i < mAddChildVouchsList.size(); i++){
                    if(mAddChildVouchsList.at(i)->kmCode() == pCode){
                        WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,mAddChildVouchsList.at(i));
                        //mAddChildVouchsList.at(i)->setQuantity(quantity);

                    }

                }
            }
        }
        //单据修改 更新数据
        for(int i =0; i < mChildVouchsList.size(); i++){
            if(mChildVouchsList.at(i)->id() == id){
                WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,mChildVouchsList.at(i));

            }
        }

    }
}

void ApBillWin::on_busQsk_editChanged(const QString &arg1)
{
    SupplieBean *sBean = SupplieDAO::getSupplieByCode(arg1);
    if(sBean && sBean->supplieCode().length() > 1){
        ui->bankNameEdit->setText(sBean->bank());
        ui->bankCardEdit->setText(sBean->bankCard());
    }
}
