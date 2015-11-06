#include "rdinimeiwin.h"
#include "ui_rdinimeiwin.h"
#include "haokeapp.h"
#include "bean/DepBean.h"
#include "bean/SupplieBean.h"
#include "bean/EmployeeBean.h"
#include "bean/WareHouseBean.h"
#include "bean/ProductBean.h"
#include "bean/SystemSetBean.h"
#include "bean/SupplieTypeBean.h"
#include "bean/CustomerBean.h"
#include "dao/depdao.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "dao/customerdao.h"
#include "dao/employeedao.h"
#include "dao/waredao.h"
#include "dao/productdao.h"
#include "dao/rddao.h"
#include "dao/imeidao.h"
#include "dao/systemsetdao.h"
#include "common/cachebabeancommon.h"
#include "common/printutils.h"
#include "qtrpt.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"
#include "widget/designoptdialog.h"
#include "widget/choosevouchdialog.h"
#include "bean/StockBean.h"
#include "dao/stockdao.h"
#include "dao/inimeidao.h"
#include "dao/outimeidao.h"
#include "dao/stimeidao.h"
#include "importdialog.h"
#include "bcplugin.h"

RdInImeiWin::RdInImeiWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RdInImeiWin)
{
    ui->setupUi(this);
    mRdFlag = RdFlag::RdInFlag;
    //01 采购入库单 查看vouch_type表
    mVouchType = HaoKeApp::getVouchRdPuIn();
    mVouchSource = "";
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = ImeiDAO::getRdCount(mVouchType) - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    mRecord = mCountRecord;
    QList<RdBean *> rdBeanList = ImeiDAO::queryRdByPage(mVouchType,mCountRecord,1);
    ui->toolBar->actions().at(4)->setEnabled(true);
    ui->toolBar->actions().at(5)->setEnabled(true);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(false);
    readAuthority();


}

RdInImeiWin::RdInImeiWin(int rdf, QString vouchType, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RdInImeiWin)
{
    ui->setupUi(this);
    mRdFlag = RdFlag::RdInFlag;
    mRdRed = rdf;
    //01 采购入库单 查看vouch_type表
    mVouchType = vouchType;
    mVouchSource = "";
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = ImeiDAO::getRdCount(mVouchType) - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    mRecord = mCountRecord;
    QList<RdBean *> rdBeanList = ImeiDAO::queryRdByPage(mVouchType,mCountRecord,1);
    ui->toolBar->actions().at(4)->setEnabled(true);
    ui->toolBar->actions().at(5)->setEnabled(true);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(false);
    readAuthority();


}

RdInImeiWin::RdInImeiWin(QString no,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RdInImeiWin)
{
    ui->setupUi(this);
    RdBean *bean = ImeiDAO::getRdByNo(no);
    if(bean != NULL && bean->rdNo().length() > 0){
        mRdFlag = bean->rdFlag();
        mVouchType = bean->vouchType();
        mVouchSource = bean->vouchSource();
        init();
        //qApp->setStyle("Plastique");
        setupContextMenu();
        mCountRecord = ImeiDAO::getRdCount(mVouchType) - 1;
        if(mCountRecord < 0) mCountRecord = 0;
        ui->toolBar->actions().at(4)->setEnabled(true);

        mRecord = ImeiDAO::getRdRowNumber(mVouchType,bean->id()) - 1;
        if(mRecord == 0){
            baseToolBar->actions().at(0)->setEnabled(false);
            baseToolBar->actions().at(2)->setEnabled(false);
        }else if(mRecord >= mCountRecord ){
            baseToolBar->actions().at(1)->setEnabled(false);
            baseToolBar->actions().at(3)->setEnabled(false);
        }
        delete bean;
        ui->toolBar->actions().at(0)->setEnabled(true);
        ui->toolBar->actions().at(4)->setEnabled(true);
        ui->toolBar->actions().at(5)->setEnabled(true);
        read(no);
        if(ui->noEdit->text().length() >0){
            ui->toolBar->actions().at(1)->setEnabled(true);
        }

    }else{
        init();
        QMessageBox::critical(this,"错误","此单不存在！");
    }
    readAuthority();

}

void RdInImeiWin::readAuthority(){
    LimitsCommon::authority(ui->toolBar,mWinId.toInt());
}
RdInImeiWin::~RdInImeiWin()
{
    delete ui;
}

void RdInImeiWin::createActions(){
    QIcon saveIcon;
    saveIcon.addPixmap(QPixmap(":/image/save.png"),  QIcon::Normal, QIcon::Off);
    ui->saveButton->setIcon(saveIcon);
    QIcon clearIcon;
    clearIcon.addPixmap(QPixmap(":/image/cross_48.png"),  QIcon::Normal, QIcon::Off);
    ui->clearButton->setIcon(clearIcon);
    QIcon importIcon;
    importIcon.addPixmap(QPixmap(":/image/page_add.png"),  QIcon::Normal, QIcon::Off);
    ui->importButton->setIcon(importIcon);
    QIcon delRowIcon;
    delRowIcon.addPixmap(QPixmap(":/image/minus.png"),  QIcon::Normal, QIcon::Off);
    ui->delButton->setIcon(delRowIcon);

    mActDelRow = new QAction("删行",this);
    mActDelRow->setEnabled(false);
    connect(mActDelRow,SIGNAL(triggered()),this,SLOT(sDelRow()));
    addAction(mActDelRow);
    ui->saveButton->setEnabled(false);
    ui->clearButton->setEnabled(false);
    ui->importButton->setEnabled(false);
    ui->delButton->setEnabled(false);

}
void RdInImeiWin::init(){
    createActions();
    //窗体ID号
    mWinId = HaoKeApp::bcSubId() + BcPlugin::rdInImeiWinId();
    mWinTitle = "串码入库";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::bcSubId().toInt(),mWinId.toInt(),0,"");
    ui->rdLabel->setText("");

    //功能菜单
    actionProperties actsBase[]= {
        { "RdInImei.edit",tr("&Edit"),SLOT(sEdit()), NULL, "Edit", QPixmap(":/image/edit.png"), NULL,  true, tr("Edit") },
        { "RdInImei.delete",tr("&Delete"),SLOT(sDelete()), NULL, "Delete", QPixmap(":/image/cross_48.png"), NULL,  true, tr("Delete") },
        { "RdInImei.audit",tr("&Audit"),SLOT(sAudit()), NULL, "Audit", QPixmap(":/image/stamp_48.png"), NULL,  true, tr("Audit") },
        { "RdInImei.abandonAudit",tr("&Abandon Audit"),SLOT(sAbAudit()), NULL, "Abandon Audit", QPixmap(":/image/c_stamp_48.png"), NULL,  true, tr("Abandon Audit") },
        { "RdInImei.print",tr("&Print"),SLOT(sPrint()), NULL, "Print", QPixmap(":/image/printer.png"), NULL,  true, tr("Print") },
        { "RdInImei.export",tr("&Export"),SLOT(sExport()), NULL, "Export", QPixmap(":/image/next.png"), NULL,  true, tr("Export") },
        { "RdInImei.first",tr("&First"),SLOT(sFirst()), NULL, "First", QPixmap(":/image/first48.png"), NULL,  true, tr("First") },
        { "RdInImei.next",tr("&Next"),SLOT(sNext()), NULL, "Next", QPixmap(":/image/n-next48.png"), NULL,  true, tr("Next") },
        { "RdInImei.previous",tr("&Previous"),SLOT(sPrevious()), NULL, "Previous", QPixmap(":/image/n-previous48.png"), NULL,  true, tr("Previous") },
        { "RdInImei.end",tr("&End"),SLOT(sEnd()), NULL, "End", QPixmap(":/image/end48.png"), NULL,  true, tr("End") },
        { "RdInImei.cancel",tr("&Cancel"),SLOT(sCancel()), NULL, "Cancel", QPixmap(":/image/cancel.png"), NULL,  true, tr("Cancel") }

    };
    addActionsTo(actsBase,sizeof(actsBase) / sizeof(actsBase[0]));

    mIsEdit =false;
    mEditStatus = 0;
    ui->dateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
    mIsChoose = false;
    mIsImport = false;
    mIsHathOrder = false; //采购业务必有订单
    mIsMakeRd = false; //审核是否生成入库单
    SystemSetBean *hathOrderBean = SystemSetDAO::getBean("001");
    if(hathOrderBean && hathOrderBean->id().length() > 0){
        mIsHathOrder = hathOrderBean->yesNo();
    }

    SystemSetBean *makeRdBean = SystemSetDAO::getBean("002");
    if(makeRdBean && makeRdBean->id().length() > 0){
        mIsMakeRd = makeRdBean->yesNo();
    }
    //初始化表体格式
    setInputEnable(false);
    childItemProperties childItem[] = {
            { "id","ID","ID", 0,60, true, true },
            { "productCode","商品编码","商品编码", 1,100, true, true },
            { "productName","商品名称","商品名称", 2,180, true, true },
            { "quantity","数量","数量", 3, 60,true, true },
            { "imeiCount","串码数量","串码数量", 4,100, true, true }
    };
    int size = sizeof(childItem) / sizeof(childItem[0]);

    childItemProperties imeiItem[] = {
            { "imei","IMEI","IMEI",0,120, true, true },
            { "productCode","商品编码","商品编码", 1,80, true, false },
            { "productName","商品名称","商品名称", 2,120, true, false },
            { "vouchsId","序列ID","序列ID", 3,60, true, false },
            { "created","录入时间","录入时间", 4,120, true, false },
            { "memo","备注","备注", 5, 180,true, true },
            { "id","ID","ID", 6,60, false, false }


    };
    int imei_size = sizeof(imeiItem) / sizeof(imeiItem[0]);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(size);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(22);
    ui->tableWidget2->setRowCount(1);
    ui->tableWidget2->setColumnCount(imei_size);
    ui->tableWidget2->verticalHeader()->setDefaultSectionSize(22);
    //qDebug() << size;
    for(int i =0 ; i < size ; i ++){
        mChildItem << childItem[i];
    }

    for(int i =0 ; i < imei_size ; i ++){
        mImeiItem << imeiItem[i];
    }


    //初始化表头数据
    if(mVouchType == HaoKeApp::getVouchRdPuIn()){
        QList<SupplieBean *> venBeanList = SupplieDAO::querySupplie();
        QStringList venList ;
        for(int i =0 ; i < venBeanList.size(); i++){
            venList << venBeanList.at(i)->supplieCode() + " - " +venBeanList.at(i)->supplieName();
        }
        ui->venSearchEditbox->setListModel(true);
        ui->venSearchEditbox->setItems(venList);
    }else if(mVouchType == HaoKeApp::getVouchRdOtherIn()){
        //其他入库

        ui->label_16->setText("<html><head/><body><p><span style=\" color:#ff0000;\">其他入库</span></p></body></html>");


    }else if(mVouchType == HaoKeApp::getVouchRdSaRe()){
        //15销售退货单

        ui->rdLabel->setText("<html><head/><body><p><span style=\" color:#ff0000;\">红字出库</span></p></body></html>");
        ui->label_16->setText("<html><head/><body><p><span style=\" color:#ff0000;\">销售退货</span></p></body></html>");
        QList<CustomerBean *> cusBeanList = CustomerDAO::queryCus();
        QStringList cusList;
        for(int i =0 ; i < cusBeanList.size(); i++){
            cusList << cusBeanList.at(i)->cusCode() + " - " +cusBeanList.at(i)->cusName();
        }
        ui->venSearchEditbox->setListModel(true);
        ui->venSearchEditbox->setItems(cusList);
        ui->label_3->setText("客    户:");
        ui->arrivalLabel->setText("退货单号:");

    }else if(mVouchType == HaoKeApp::getVouchRdCtRe()){
        //12委托代销退货单

        ui->rdLabel->setText("<html><head/><body><p><span style=\" color:#ff0000;\">红字出库</span></p></body></html>");
        ui->label_16->setText("<html><head/><body><p><span style=\" color:#ff0000;\">委托代销退货</span></p></body></html>");
        QList<CustomerBean *> cusBeanList = CustomerDAO::queryCus();
        QStringList cusList;
        for(int i =0 ; i < cusBeanList.size(); i++){
            cusList << cusBeanList.at(i)->cusCode() + " - " +cusBeanList.at(i)->cusName();
        }
        ui->venSearchEditbox->setListModel(true);
        ui->venSearchEditbox->setItems(cusList);
        ui->label_3->setText("客    户:");
        ui->arrivalLabel->setText("退货单号:");
    }


    QList<DepBean *> depBeanList = DepDAO::queryDepByEnd();
    QStringList depList ;
    for(int i =0 ; i < depBeanList.size(); i++){
        depList << depBeanList.at(i)->depId() + " - " +depBeanList.at(i)->depName();
    }
    ui->depSearchEditbox->setListModel(true);
    ui->depSearchEditbox->setItems(depList);

    QList<EmployeeBean *> employeeBeanList = EmployeeDAO::queryEmp();
    QStringList empList ;
    for(int i =0 ; i < employeeBeanList.size(); i++){
        empList << employeeBeanList.at(i)->empCode() + " - " +employeeBeanList.at(i)->empName();
    }
    ui->userSearchEditbox->setListModel(true);
    ui->userSearchEditbox->setItems(empList);

    QList<WareHouseBean *> whBeanList = WareDAO::queryWarehouse();
    QStringList whList ;
    for(int i =0 ; i < whBeanList.size(); i++){
        whList << whBeanList.at(i)->whCode() + " - " +whBeanList.at(i)->whName();
    }
    ui->whSearchEditbox->setListModel(true);
    ui->whSearchEditbox->setItems(whList);

    QList<ProductBean *> proBeanList = ProductDAO::queryProduct();
    QStandardItemModel *model = new QStandardItemModel(proBeanList.size(),1);
    for(int i=0;i < proBeanList.size();i++){
        QStandardItem *itemName = new QStandardItem(proBeanList.at(i)->productCode() + " - " +proBeanList.at(i)->productName());
        model->setItem(i,0,itemName);
    }
    //初始化表尾
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(22);
    ui->tableWidget->verticalHeader()->setMaximumWidth(42);
    mFootView = new HierarchicalHeaderView(Qt::Horizontal);
    ui->gridLayout->addWidget(mFootView);
    mFootView->setClickable(true);
    //mFootView->setMovable(false);
    mFootView->setResizeMode(QHeaderView::Fixed);
    mFootView->setHighlightSections(true);
    mFootModel = new FootTableModel(1,mChildItem.size() + 1,this);
    mFootModel->setItem(0,new QStandardItem(""));
    mFootModel->setItem(1,new QStandardItem("合计:"));
    mFootView->setModel(mFootModel);


    mFootView->resizeSection(0,ui->tableWidget->verticalHeader()->width());
    mFootView->setFixedHeight(22);
    mFootModel->setItem(size - 1,new QStandardItem(""));

    mFootModel->setItem(5,new QStandardItem(""));
    QObject::connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionResized(int,int,int)),this,SLOT(footResized(int,int,int)));

    refreshData();
    /*
    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    */
    mFootView->setDefaultAlignment (Qt::AlignLeft | Qt::AlignVCenter);
    mFootView->setTextElideMode (Qt::ElideLeft); //...效果

    QkEditDelegate *delegate = new QkEditDelegate(model,this);


    //ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);
    //行选择模式
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setItemDelegateForColumn(0,delegate);




}

void RdInImeiWin::footResized(int logicalIndex, int oldSize, int newSize){
    mFootView->resizeSection(logicalIndex + 1,newSize);

}


void RdInImeiWin::refreshData(){
    ui->tableWidget->clear();
    QStringList headerLabels;
    for (int i = 0; i < mChildItem.size(); i++){
        headerLabels.append(mChildItem[i].cnName);
        ui->tableWidget->setColumnWidth(mChildItem[i].id,mChildItem[i].width);
        mFootView->resizeSection(mChildItem[i].id + 1,mChildItem[i].width);
        if(!mChildItem[i].visible)ui->tableWidget->hideColumn(mChildItem[i].id);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget2->clear();
    QStringList imeiHeaderLabels;
    for (int i = 0; i < mImeiItem.size(); i++){
        imeiHeaderLabels.append(mImeiItem[i].cnName);
        ui->tableWidget2->setColumnWidth(mImeiItem[i].id,mImeiItem[i].width);
        if(!mImeiItem[i].visible)ui->tableWidget2->hideColumn(mImeiItem[i].id);
    }
    ui->tableWidget2->setHorizontalHeaderLabels(imeiHeaderLabels);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void RdInImeiWin::initTableHead2(){
    ui->tableWidget2->clear();
    QStringList imeiHeaderLabels;
    for (int i = 0; i < mImeiItem.size(); i++){
        imeiHeaderLabels.append(mImeiItem[i].cnName);
        ui->tableWidget2->setColumnWidth(mImeiItem[i].id,mImeiItem[i].width);
        if(!mImeiItem[i].visible)ui->tableWidget2->hideColumn(mImeiItem[i].id);
    }
    ui->tableWidget2->setHorizontalHeaderLabels(imeiHeaderLabels);
}

void RdInImeiWin::read(QString no){
    RdBean *bean = ImeiDAO::getRdByNo(no);
    mEditStatus = 0;
    mIsEditMode = false;
    mNo = no;
    if(bean != NULL && bean->rdNo().length() > 0){
        ui->noEdit->setText(bean->rdNo());
        ui->dateEdit->setDate(bean->busDate());
        mVouchType = bean->vouchType();
        if(mVouchType == HaoKeApp::getVouchRdCtRe()
                || mVouchType == HaoKeApp::getVouchRdSaRe()){
            CustomerBean *cusBean = CustomerDAO::getCusByCode(bean->cusCode());
            ui->venSearchEditbox->setText(bean->cusCode() + " - " + cusBean->cusName());

        }else{
            SupplieBean *venBean = SupplieDAO::getSupplieByCode(bean->supplierId());
            ui->venSearchEditbox->setText(bean->supplierId() + " - " + venBean->supplieName());
        }
        WareHouseBean *whBean = WareDAO::getWarehouseById(bean->whCode());
        ui->whSearchEditbox->setText(bean->whCode() + " - " + whBean->whName());;
        DepBean *depBean = DepDAO::getDepById(bean->depCode());
        ui->depSearchEditbox->setText(bean->depCode() + " - " + depBean->depName());
        ui->userSearchEditbox->setText(bean->personCode() + " - " + CacheBaBeanCommon::personToName(bean->personCode()));
        ui->memoEdit->setText(bean->memo());
        ui->makerEdit->setText(CacheBaBeanCommon::userToName(bean->createdBy(),1));
        ui->auditEdit->setText(bean->handler());
        ui->arrivalNoEdit->setText(bean->busNo());
        ui->busTypeEdit->setText(bean->busType());

        ui->toolBar->actions().at(0)->setEnabled(true);
        if(bean->imeiAudit()){
            ui->toolBar->actions().at(0)->setEnabled(false);
            ui->toolBar->actions().at(1)->setEnabled(false);
            ui->toolBar->actions().at(2)->setEnabled(false);
            ui->toolBar->actions().at(3)->setEnabled(true);
        }else{
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
        }
        mDelChildList.clear();
        mAddChildVouchsList.clear();
        mChildVouchsList.clear();
        readAuthority();
        QList<RdsBean *> pBeanList = ImeiDAO::queryRdsBy(no);
        ui->tableWidget->setRowCount(pBeanList.size() + 1);
        mTotalQuantity = 0;
        mTotalSum = 0;
        for(int i =0; i < pBeanList.size(); i++){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget,i,mChildItem,pBeanList.at(i));
            mTotalQuantity = mTotalQuantity + pBeanList.at(i)->quantity();
            mTotalSum = mTotalSum + pBeanList.at(i)->money();
        }
        QApplication::setOverrideCursor(Qt::WaitCursor);
        mIdx = "";
        mInvCode = "";
        ui->idxEdit->setText("");
        ui->nameEdit->setText("");
        QList<RdInImeiBean *> imeiListBean = InImeiDAO::queryImeiByNo(mNo);
        ui->tableWidget2->setRowCount(imeiListBean.size() + 1);
        for(int i =0; i < imeiListBean.size(); i++){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget2,i,mImeiItem,imeiListBean.at(i));
        }
        QApplication::restoreOverrideCursor();
        mImeiCount = imeiListBean.size();
        ui->label_14->setText(QString::number(mImeiCount));
        mFootModel->setItem(4,new QStandardItem(QString::number(mTotalQuantity)));
        if(pBeanList.size() > 99){
            mFootView->resizeSection(0,31);
        }else if(pBeanList.size() > 9){
            mFootView->resizeSection(0,23);

        }else mFootView->resizeSection(0,16);

        //mFootView->resizeSection(0,ui->tableWidget->verticalHeader()->width());
        mFootView->reset();
    }
}

void RdInImeiWin::inputClear(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->headGridLayout);


}

void RdInImeiWin::setInputEnable(bool b){
    if(b)
        WidgetBeanUtil::setLayoutWidgetReadOnly(ui->headGridLayout,false);
    else{
        WidgetBeanUtil::setLayoutWidgetReadOnly(ui->headGridLayout,true);
        ui->tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }


}

void RdInImeiWin::addActionsTo(actionProperties acts[], unsigned int numElems){
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

        if(i < 6){
            QString proceccId = mWinId + QString::number(i);
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::bcSubId().toInt(),mWinId.toInt(),proceccId.toInt(),acts[i].toolTip,acts[i].actionName);

            act->setEnabled(false);
            ui->toolBar->addAction(act);
            addAction(act);
        }
        else
            baseToolBar->addAction(act);
    }
    connect(ui->toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(toolBarActTriggered(QAction*)));
}

void RdInImeiWin::toolBarActTriggered(QAction *act){
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::bcSubId().toInt(),mWinId.toInt(),act->objectName());

}

void RdInImeiWin::sFirst(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);

            setInputEnable(false);
        }else{
            return ;
        }
    }
    mRecord = 0;
    ui->tableWidget->clear();
    refreshData();
    QList<RdBean *> rdBeanList = ImeiDAO::queryRdByPage(mVouchType,0,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
        mNo = rdBeanList.at(0)->rdNo();
    }
    baseToolBar->actions().at(0)->setEnabled(false);
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(2)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(true);
    ui->saveButton->setEnabled(false);
    ui->clearButton->setEnabled(false);
    ui->importButton->setEnabled(false);
    ui->delButton->setEnabled(false);
    mActDelRow->setEnabled(false);
}
\
void RdInImeiWin::sNext(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);

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
    QList<RdBean *> rdBeanList = ImeiDAO::queryRdByPage(mVouchType,mRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(0)->setEnabled(true);
    ui->saveButton->setEnabled(false);
    ui->clearButton->setEnabled(false);
    ui->importButton->setEnabled(false);
    ui->delButton->setEnabled(false);
    mActDelRow->setEnabled(false);
}

void RdInImeiWin::sPrevious(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
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
    QList<RdBean *> rdBeanList = ImeiDAO::queryRdByPage(mVouchType,mRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(true);
    ui->saveButton->setEnabled(false);
    ui->clearButton->setEnabled(false);
    ui->importButton->setEnabled(false);
    ui->delButton->setEnabled(false);
    mActDelRow->setEnabled(false);
}

void RdInImeiWin::sEnd(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);

            setInputEnable(false);
        }else{
            return ;
        }
    }
    ui->tableWidget->clear();
    refreshData();
    mCountRecord = ImeiDAO::getRdCount(mVouchType) - 1;
    mRecord = mCountRecord;
    QList<RdBean *> rdBeanList = ImeiDAO::queryRdByPage(mVouchType,mCountRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(0)->setEnabled(true);
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(false);
    ui->saveButton->setEnabled(false);
    ui->clearButton->setEnabled(false);
    ui->importButton->setEnabled(false);
    ui->delButton->setEnabled(false);
    mActDelRow->setEnabled(false);
}

void RdInImeiWin::sDelRow(){

    if(!mIsEditMode){
        QMessageBox::information(this,"提示","不能修改！");
        return;
    }
    QAbstractItemModel *modelTotal = ui->tableWidget2->model();
    QItemSelectionModel *seleced = ui->tableWidget2->selectionModel();
    int row = seleced->currentIndex().row();

    if(row >= 0){
        int id = modelTotal->data(modelTotal->index(row,WidgetBeanUtil::getChildItemId(mImeiItem,"id"))).toInt();

        QString name = modelTotal->data(modelTotal->index(row,1)).toString();
        QString imei = modelTotal->data(modelTotal->index(row,WidgetBeanUtil::getChildItemId(mImeiItem,"imei"))).toString();
        if(name.length() < 1){
            QMessageBox::information(this,"提示","不能删除此行！");
            return;
        }
        if(QMessageBox::warning(this, tr("Prompt"),"是否要删除此 *" + imei + "*",
                                QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            if(mEditStatus == editFlag){

                for(int i =0 ; i < mChildVouchsList.size(); i++){
                    if(imei == mChildVouchsList.at(i)->imei()){
                        if(id >0)
                            mDelChildList.append(mChildVouchsList.at(i)->id());
                        mChildVouchsList.removeAt(i);
                    }
                }
                for(int i =0 ; i < mAddChildVouchsList.size(); i++){
                    if(imei == mAddChildVouchsList.at(i)->imei()){
                        mAddChildVouchsList.removeAt(i);
                    }
                }
                mIsEdit = true;
                modelTotal->removeRow(row);
            }
        }
    }else{
        QMessageBox::information(this,"Prompt","请选择要删除的行!");
    }
}
void RdInImeiWin::sEdit(){
    if(ui->noEdit->text().length() < 1){
        QMessageBox::warning(this,"提示","无单不能修改！");
        return ;
    }
    RdBean *bean = ImeiDAO::getRdByNo(ui->noEdit->text());
    if(bean->imeiAudit()){
        QMessageBox::warning(this,"提示","串码已审核，不能修改！");
        return ;
    }
    mIsEdit = false;
    setInputEnable(false);
    ui->tableWidget2->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
    mEditStatus = editFlag;
    ui->noEdit->setEnabled(false);

    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->clearButton->setEnabled(true);
    ui->importButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    mActDelRow->setEnabled(true);
    readAuthority();

}

void RdInImeiWin::sDelete(){

    if(QMessageBox::warning(this,"提示","是否删除？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){

        RdBean *bean = ImeiDAO::getRdByNo(ui->noEdit->text());
        if(bean ==NULL || (bean && bean->rdNo().length() < 2) ){
            QMessageBox::information(this,"提示","此原单不存在,不能删除！");
            return ;
        }

        if(bean && bean->imeiAudit()){
            QMessageBox::information(this,"提示","此单串码已审核,不能删除！");
            return ;
        }

        int count = InImeiDAO::getImeiCountByNo(ui->noEdit->text());

        if(count < 1){
            QMessageBox::information(this,"提示","无数据,不能删除！");
            return ;
        }

        int result = InImeiDAO::delImeiByNo(ui->noEdit->text());
        if(result > 0){
            ui->saveButton->setEnabled(false);
            ui->clearButton->setEnabled(false);
            ui->importButton->setEnabled(false);

            setInputEnable(false);
            ui->tableWidget2->setRowCount(1);
            refreshData();
            initTableHead2();
            mDelChildList.clear();
            mAddChildVouchsList.clear();
            mChildVouchsList.clear();
            read(ui->noEdit->text());


        }else{
            QMessageBox::critical(this,"错误","删除出错!");

        }



    }
    readAuthority();

}


void RdInImeiWin::sAudit(){
    if(mIsEdit){
        QMessageBox::information(this,"提示","数据未保存，不能审核！");
        return ;
    }
    RdBean *bean = ImeiDAO::getRdByNo(ui->noEdit->text());

    if(bean && bean->rdNo().length() > 0){
        if(bean->imeiAudit()&& bean->imeiAudit()){
            ui->toolBar->actions().at(0)->setEnabled(false);
            ui->toolBar->actions().at(1)->setEnabled(false);
            ui->toolBar->actions().at(2)->setEnabled(false);
            ui->toolBar->actions().at(3)->setEnabled(true);
            QMessageBox::information(this,"提示","已审核，不能再审核！");
            return ;
        }


        QList<RdInImeiBean *> stImeiList = InImeiDAO::queryImeiIsStock(ui->noEdit->text());
        if(stImeiList.size() > 0){
            QMessageBox::information(this,"提示","串码:" + stImeiList.at(0)->imei() + " 序列ID:"
                                     + QString::number(stImeiList.at(0)->vouchsId())
                                     + " 已在库存串码中,不能审核！");
            return ;
        }

        QList<RdsBean *> rdsBeanList = ImeiDAO::queryRdsBy(ui->noEdit->text());
        int totalImeiQuantity = 0;
        for(int i = 0 ; i < rdsBeanList.size(); i ++ ){
            ProductBean *invBean = ProductDAO::getProductByCode(rdsBeanList.at(i)->productCode());
            //是否串码管理
            if(invBean && invBean->isImei()){
                totalImeiQuantity = totalImeiQuantity + qAbs(rdsBeanList.at(i)->quantity());
                if(qAbs(rdsBeanList.at(i)->quantity()) != rdsBeanList.at(i)->imeiCount()){
                    QMessageBox::information(this,"提示","商品:" + rdsBeanList.at(i)->productName() + " 序列ID:"
                                             + QString::number(rdsBeanList.at(i)->id())
                                             + " 串码录入未完,不能审核！");
                    return ;
                }
            }
        }
        mImeiCount = InImeiDAO::getImeiCountByNo(ui->noEdit->text());
        ui->label_14->setText(QString::number(mImeiCount));
        if(mImeiCount != totalImeiQuantity){
            QMessageBox::information(this,"提示","串码数量与单据要录入串码总数量不符，不能审核！");
            return ;
        }
        QApplication::setOverrideCursor(Qt::WaitCursor);
        bean->setImeiAudit(true);
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        QList<RdInImeiBean *> imeiList = InImeiDAO::queryImeiByNo(ui->noEdit->text());
        int mResult = 0;
        QDateTime time = QDateTime::currentDateTime();
        for(int i = 0 ; i < imeiList.size(); i ++ ){
            imeiList.at(i)->setCreated(time);
            imeiList.at(i)->setCreater(HaoKeApp::getInstance()->getUserDesc());
            int c = StImeiDAO::createImei(imeiList.at(i));
            if(c < 1){
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QApplication::restoreOverrideCursor();
                QMessageBox::information(this,"提示","审核出错！IMEI:" + imeiList.at(i)->imei());

                return ;
            }
            mResult = mResult + c ;
        }
        int result = RdDAO::updateRd(bean);
        if(result > 0 && mResult == imeiList.size() && DBManager::getDBManager()->getGoinDBConnection().commit()){
            ui->toolBar->actions().at(0)->setEnabled(false);
            ui->toolBar->actions().at(1)->setEnabled(false);
            ui->toolBar->actions().at(2)->setEnabled(false);
            ui->toolBar->actions().at(3)->setEnabled(true);
            ui->saveButton->setEnabled(false);
            ui->delButton->setEnabled(false);
            ui->importButton->setEnabled(false);
            ui->clearButton->setEnabled(false);
            mIsEdit = false;
            mEditStatus = addFlag;
            setInputEnable(false);
            QApplication::restoreOverrideCursor();

            readAuthority();

            QMessageBox::information(this,"提示","审核成功！");
        }else{
            QApplication::restoreOverrideCursor();
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"提示","审核出错！");
        }

    }else{
        QMessageBox::critical(this,"错误","无此单据，不能审核");
    }
}

void RdInImeiWin::sAbAudit(){
    RdBean *bean = ImeiDAO::getRdByNo(ui->noEdit->text());
    if(bean !=NULL && bean->rdNo().length() > 0){
        if(!bean->imeiAudit()){
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            QMessageBox::information(this,"提示","未审核，不能弃审！");
            return ;
        }
        QList<RdInImeiBean *> stImeiList = InImeiDAO::queryImeiNotStock(ui->noEdit->text(),ui->whSearchEditbox->text());
        if(stImeiList.size() > 0){
            QMessageBox::information(this,"提示","串码:" + stImeiList.at(0)->imei() + " 序列ID:"
                                     + QString::number(stImeiList.at(0)->vouchsId())
                                     + " 仓库中：" + ui->whSearchEditbox->subText()
                                     + " 不存在库存串码,不能弃审！");
            return ;
        }

        DBManager::getDBManager()->getGoinDBConnection().transaction();
        bean->setImeiAudit(false);
        int result = RdDAO::updateRd(bean);
        int mResult = StImeiDAO::delImeiByNo(ui->noEdit->text());
        if(result > 0 && mResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            ui->auditEdit->setText(bean->handler());
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(true);
            ui->toolBar->actions().at(3)->setEnabled(false);
            readAuthority();
            QMessageBox::information(this,"提示","弃审成功！");
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"提示","弃审出错！");
        }

    }
}

void RdInImeiWin::sPrint(){

    QString fileName = "ReportPuOrder.xml";
    QString title = "串码入库单";
    QString formatData = "";
    QList<ReportFormatBean *> rptList = ReportDAO::queryRptBy(mWinId);

    if(rptList.size() > 0){
        formatData = rptList.at(rptList.size() - 1)->reportFormat();
    }else {
        formatData = PrintUtils::makeWinPrintFormatData(ui->headGridLayout,mImeiItem,title,fileName);
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
    report->recordCount << ui->tableWidget2->rowCount() - 1;
    if (report->loadReportFormat(formatData) == false) {
        qDebug()<<"Report's format is null";
    }
    report->setWindowTitle(title);
    report->setModel(ui->tableWidget2->model());
    report->setChildItem(mImeiItem);

    if(HaoKeApp::getInstance()->getUserLevel()>8){
        DesignOptDialog *designOptDlg = new DesignOptDialog(this);
        QString formatData2 = PrintUtils::makeWinPrintFormatData(ui->headGridLayout,mImeiItem,title,fileName);
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

void RdInImeiWin::sExport(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                       tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
       return;

    if (exportExcel(fileName,ui->tableWidget2) )//调用导出Excel方法
    {
       QMessageBox::about(this, tr("Excel文件 导出完成"), "导出记录数: " + QString::number(ui->tableWidget2->rowCount()-1)  + " 条到" + fileName + "文件，导出完成");
       QSqlDatabase::removeDatabase("excelexport");
    }
}

bool RdInImeiWin::exportExcel(QString fileName, QTableWidget *tableWidget){
    QString sheetName;
    sheetName="Sheet1";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC", "excelexport");
    if(!db.isValid()){

        logger()->error("export2Excel failed: QODBC not supported.");
        return false;

    }
    // set the dsn string
    QString dsn = QString("Driver={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};DSN='';FIL=Excel 12.0;DriverID=790;READONLY=FALSE;CREATE_DB=\"%1\";DBQ=%2").
                  arg(fileName).arg(fileName);
    db.setDatabaseName(dsn);
    if(!db.open()){
        logger()->error("export2Excel failed: Create Excel file failed by DRIVER={Microsoft Excel Driver (*.xls)}.");
        QSqlDatabase::removeDatabase("excelexport");
        return false;
    }
    QSqlQuery query(db);
    QString sSql = "";
    QAbstractItemModel *model = tableWidget->model();
    //drop the table if it's already exists
    sSql = QString("DROP TABLE [%1] ").arg(sheetName);

    query.exec(sSql);
    int colCount = 	model->columnCount();

    sSql = QString("CREATE TABLE [%1] (").arg(sheetName);
    for(int i = 0; i < colCount-1 ; i ++){
        sSql += model->headerData(i,Qt::Horizontal).toString() + " varchar(100) ,  ";
    }
    sSql += model->headerData(colCount-1,Qt::Horizontal).toString() + " varchar(100) )";
    query.prepare(sSql);
    if(!query.exec())
    {
        logger()->error("export2Excel failed: Create Excel sheet failed.");
        db.close();
        QSqlDatabase::removeDatabase("excelexport");
        return false;
    }

    sSql = QString("INSERT INTO [%1] (").arg(sheetName);
    for(int i = 0; i < colCount-1 ; i ++){
        sSql += model->headerData(i,Qt::Horizontal).toString() + ",";
    }
    sSql += model->headerData(colCount-1,Qt::Horizontal).toString() + ") VALUES (";
    for(int i = 0; i < colCount-1 ; i ++){
        sSql += "?,";
    }
    sSql +=  "?)";
    QApplication::setOverrideCursor(Qt::WaitCursor);
    query.prepare(sSql);
    for(int i =0 ; i < model->rowCount() ; i ++){
        for(int j =0 ; j < colCount ; j ++){
            query.addBindValue(model->index(i, j).data().toString());
        }
        query.exec();
        QApplication::processEvents();
    }
    db.close();
    QApplication::restoreOverrideCursor();
    return true;

}
void RdInImeiWin::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage){
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

void RdInImeiWin::sCancel(){

    this->close();
}

void RdInImeiWin::closeEvent(QCloseEvent *event){

    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            event->ignore();
            return ;
        }
    }

    event->accept();
    HaoKeApp::getInstance()->gui()->removeSubWin(this);


}

void RdInImeiWin::setupContextMenu(){
    /*
    handleAct = new QAction(QIcon(":/images/connector.png"),tr("关联联赛"),this);

    connect(handleAct, SIGNAL(triggered()), this, SLOT(handleMatch()));
    */
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

void RdInImeiWin::on_tableWidget_clicked(const QModelIndex &index)
{
    QString id;
    QAbstractItemModel *childModel = ui->tableWidget->model();
    id = childModel->data(childModel->index(index.row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toString();
    if(id == mIdx )return ;
    if(id!=mIdx && mIsEdit && (mAddChildVouchsList.size() > 0 || mDelChildList.size() > 0)){
        if(QMessageBox::warning(this,"警告","有数据未保存,不能随便改变行！是否放弃保存数据",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            for(int h = 0; h < childModel->rowCount(); h ++){

                id = childModel->data(childModel->index(h,WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toString();

                if(mIdx == id){
                    qDebug() << id << h;
                    //ui->tableWidget->setCurrentCell(h,index.column());
                    //QModelIndex newIndex = childModel->index(h, index.column(), QModelIndex());

                    return ;
                }
            }
            return ;
        }
    }
    mChildVouchsList.clear();
    mAddChildVouchsList.clear();
    mDelChildList.clear();

    mIdx = childModel->data(childModel->index(index.row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toString();
    mInvCode = childModel->data(childModel->index(index.row(),WidgetBeanUtil::getChildItemId(mChildItem,"productCode"))).toString();
    mQuantity = childModel->data(childModel->index(index.row(),WidgetBeanUtil::getChildItemId(mChildItem,"quantity"))).toInt();
    mQuantity = qAbs(mQuantity);
    mRow = index.row();
    QString invName = ui->tableWidget->model()->data(ui->tableWidget->model()->index(index.row(),2)).toString();
    ui->idxEdit->setText(mIdx);
    ui->nameEdit->setText(invName);
    initTableHead2();
    QApplication::setOverrideCursor(Qt::WaitCursor);


    if(mIdx.length() > 0){
        QList<RdInImeiBean *> imeiListBean = InImeiDAO::queryImeiBy(mIdx);
        mChildVouchsList = InImeiDAO::queryImeiBy(mIdx);
        ui->tableWidget2->setRowCount(imeiListBean.size() + 1);
        if(mEditStatus == editFlag){
            ui->tableWidget2->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
            ui->saveButton->setEnabled(true);
            ui->importButton->setEnabled(true);
            ui->clearButton->setEnabled(true);
            ui->delButton->setEnabled(true);
        }
        mIsEditMode = false;
        for(int i =0; i < imeiListBean.size(); i++){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget2,i,mImeiItem,imeiListBean.at(i));
        }
        mIsEditMode = true;
    }else{
        ui->tableWidget2->setRowCount(1);
        ui->tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
    QApplication::restoreOverrideCursor();


}

void RdInImeiWin::on_saveButton_clicked()
{

    RdBean *bean = ImeiDAO::getRdByNo(ui->noEdit->text());
    if(bean ==NULL || (bean && bean->rdNo().length() < 2) ){
        QMessageBox::information(this,"提示","此原单不存在,不能保存！");
        return ;
    }

    if(bean && bean->imeiAudit()){
        QMessageBox::information(this,"提示","此单串码已审核,不能保存！");
        return ;
    }
    int size = ui->tableWidget2->rowCount() -1 ;
    if(mIdx.toInt() < 1 || size < 1 ){
        QMessageBox::information(this,"提示","无数据或序列ID 为空，不能保存！");
        return ;
    }
    if(size > qAbs(mQuantity) ){
        QMessageBox::information(this,"提示","输入串码超过实际数量，序列ID:" + mIdx + " 最大数量为 "+ QString::number(mQuantity) +",不能保存！");
        return ;
    }
    QAbstractItemModel *model = ui->tableWidget2->model();
    int rowNum = model->rowCount() -1;
    for(int i = 0; i < rowNum; i++ ){
        QString imei = model->data(model->index(i,0)).toString();
        int count = StImeiDAO::getImeiCountByImei(imei);
        if(count > 0){
            ui->tableWidget2->setCurrentCell(i,0);
            QMessageBox::information(this,"提示","IMEI:" + imei + "已在库存，不能保存！");
            return ;
        }
        //销售/委代退库判断
        if(mVouchType == HaoKeApp::getVouchRdSaRe()
                || mVouchType == HaoKeApp::getVouchRdCtRe() ){
            QList<RdInImeiBean *> outImeiList = OutImeiDAO::queryImeiByImei(imei);
            if(outImeiList.size() < 1){
                QMessageBox::information(this,"提示","此IMEI：" + imei + " 未发过货,不能退库！");
                return ;
            }
        }
    }
    QList<RdInImeiBean *> imeiList = InImeiDAO::queryImeiByNo(mNo);
    for(int i = 0; i < mAddChildVouchsList.size(); i++){
        for(int j = 0 ; j < imeiList.size(); j++){
            if(mAddChildVouchsList.at(i)->imei()==imeiList.at(j)->imei()){
                QAbstractItemModel *model = ui->tableWidget2->model();
                QString imei;
                for(int h = 0; h < model->rowCount(); h ++){
                    imei = model->data(model->index(h,WidgetBeanUtil::getChildItemId(mImeiItem,"imei"))).toString();
                    if(mAddChildVouchsList.at(i)->imei() == imei){
                        ui->tableWidget2->setCurrentCell(h,0);
                        break ;
                    }
                }
                QMessageBox::information(this,"提示","此串码:"+ mAddChildVouchsList.at(i)->imei() +" 在此单中已录入,序列ID为："
                                         + QString::number(imeiList.at(j)->vouchsId()) +",不能保存！");
                return ;
            }
        }
    }

    for(int i = 0; i < mAddChildVouchsList.size(); i++){
        for(int j =  i + 1 ; j < mAddChildVouchsList.size(); j++){
            if(mAddChildVouchsList.at(i)->imei() == mAddChildVouchsList.at(j)->imei()){
                QAbstractItemModel *model = ui->tableWidget2->model();
                QString imei;
                for(int h = 0; h < model->rowCount(); h ++){
                    imei = model->data(model->index(h,WidgetBeanUtil::getChildItemId(mImeiItem,"imei"))).toString();
                    if(mAddChildVouchsList.at(i)->imei() == imei){
                        ui->tableWidget2->setCurrentCell(h,0);
                        break ;
                    }
                }
                QMessageBox::information(this,"提示","新增串码:"+ mAddChildVouchsList.at(i)->imei() +" 重复,不能保存！");
                return ;
            }
        }
    }

    DBManager::getDBManager()->getGoinDBConnection().transaction();
    int mResult = 0;
    int cResult = 0;
    QDateTime time = QDateTime::currentDateTime();
    //删除
    for(int i = 0; i < mDelChildList.size(); i++){
        RdInImeiBean *delBean = new RdInImeiBean;
        delBean->setId(mDelChildList.at(i));
        int c = InImeiDAO::delImei(delBean);
        cResult = cResult + c;
    }
    //更新
    for(int i = 0; i < mChildVouchsList.size(); i++){
        qDebug() << mChildVouchsList.at(i)->imei();
        mChildVouchsList.at(i)->setCreated(time);
        mChildVouchsList.at(i)->setImei(mChildVouchsList.at(i)->imei().trimmed());
        int c = InImeiDAO::updateImei(mChildVouchsList.at(i));
        cResult = cResult + c;
    }
    //添加
    for(int i = 0; i < mAddChildVouchsList.size(); i++){
        mAddChildVouchsList.at(i)->setCreated(time);
        mAddChildVouchsList.at(i)->setImei(mAddChildVouchsList.at(i)->imei().trimmed());
        int c = InImeiDAO::createImei(mAddChildVouchsList.at(i));
        mResult = mResult + c;
    }

    if((mResult > 0 || cResult >0) && DBManager::getDBManager()->getGoinDBConnection().commit()){
        mIsEdit = false;
        ui->toolBar->actions().at(0)->setEnabled(true);
        ui->toolBar->actions().at(1)->setEnabled(true);
        ui->saveButton->setEnabled(false);
        ui->importButton->setEnabled(false);
        ui->delButton->setEnabled(false);
        WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,mRow,mChildItem,"imeiCount",ui->tableWidget2->rowCount() - 1);

        setInputEnable(false);
        mDelChildList.clear();
        mAddChildVouchsList.clear();
        mChildVouchsList.clear();
        readAuthority();
        //ui->tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }else{
        DBManager::getDBManager()->getGoinDBConnection().rollback();
        QMessageBox::information(this,"Prompt","数据提交出错");
        return ;
    }

}

void RdInImeiWin::on_importButton_clicked()
{
    if(mIdx.toInt() < 1 ){
        QMessageBox::information(this,"提示","没有选定序列ID，不能导入");
        return ;
    }
    if(mInvCode.length() < 1 ){
        QMessageBox::information(this,"提示","没有选定商品，不能导入");
        return ;
    }

    if(mEditStatus == editFlag && mIsEditMode){
        ImportDialog *iDlg = new ImportDialog(this);
        if(iDlg->exec() == QDialog::Accepted){
            QApplication::setOverrideCursor(Qt::WaitCursor);
            mIsImport = true;
            QDateTime time = QDateTime::currentDateTime();
            QString memo = ui->mEdit->text();
            QString invName = ui->nameEdit->text();
            QString vouchsId = ui->idxEdit->text();
            QString invCode = mInvCode;
            mIsEdit = true;
            QAbstractItemModel *model = ui->tableWidget2->model();
            int i = ui->tableWidget2->rowCount() - 1;
            ui->tableWidget2->setRowCount(ui->tableWidget2->rowCount() + iDlg->getCountNum());
            int j = 0;
            if(iDlg->sqlQuery()->isActive()){
                iDlg->sqlQuery()->seek(-1);
                while(iDlg->sqlQuery()->next()){
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,i,mImeiItem,"imei",iDlg->sqlQuery()->value(0).toString().trimmed());

                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,i,mImeiItem,"productCode",invCode);
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,i,mImeiItem,"productName",invName);
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,i,mImeiItem,"vouchsId",vouchsId);
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,i,mImeiItem,"created",time);
                    WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,i,mImeiItem,"memo",memo);


                    RdInImeiBean *sBean = new RdInImeiBean();
                    sBean->setNo(ui->noEdit->text());
                    sBean->setWhCode(ui->whSearchEditbox->text().trimmed());
                    sBean->setProductCode(invCode);
                    sBean->setVouchsId(vouchsId.toInt());
                    sBean->setBusCode(ui->venSearchEditbox->text());
                    sBean->setVouchType(mVouchType);
                    sBean->setBusDate(ui->dateEdit->date());
                    sBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
                    WidgetBeanUtil::setItemModelToBean(model,i,mImeiItem,sBean);
                    mAddChildVouchsList.append(sBean);

                    i = i + 1;
                    j = j + 1;
                    QApplication::processEvents();
                    ui->label_13->setText("" + QString::number(j));
                }
                if(iDlg->getCountNum() != j){
                    ui->tableWidget2->setRowCount( ui->tableWidget2->rowCount() - (iDlg->getCountNum() - j));
                    QMessageBox::information(this,"提示","导入串码存在重复串码");

                }
            }
            mIsImport = false;
            QApplication::restoreOverrideCursor();
        }
        delete iDlg;
    }else{
        QMessageBox::information(this,"提示","非编辑模式,不能导入");
    }
}

void RdInImeiWin::on_clearButton_clicked()
{
    RdBean *bean = ImeiDAO::getRdByNo(ui->noEdit->text());
    if(bean ==NULL || (bean && bean->rdNo().length() < 2) ){
        QMessageBox::information(this,"提示","此原单不存在,不能删除！");
        return ;
    }

    if(bean && bean->imeiAudit()){
        QMessageBox::information(this,"提示","此单串码已审核,不能删除！");
        return ;
    }
    int size = ui->tableWidget2->rowCount() -1 ;
    if(mIdx.toInt() < 1 || size < 1 ){
        QMessageBox::information(this,"提示","无数据或序列ID 为空，不能删除！");
        return ;
    }
    int count = InImeiDAO::getImeiCountByIdx(mIdx);

    if(count < 1){
        QMessageBox::information(this,"提示","无数据,不能删除！");
        return ;
    }
    if(QMessageBox::warning(this,"提示","是否清除？",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        int result = InImeiDAO::delImeiByIdx(mIdx);
        if(result > 0){
            ui->saveButton->setEnabled(false);
            ui->clearButton->setEnabled(false);
            ui->importButton->setEnabled(false);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,mRow,mChildItem,"imeiCount",0);
            setInputEnable(false);
            ui->tableWidget2->setRowCount(1);
            initTableHead2();
            mDelChildList.clear();
            mAddChildVouchsList.clear();
            mChildVouchsList.clear();
        }else{
            QMessageBox::critical(this,"错误","删除出错!");

        }
    }
}

void RdInImeiWin::on_delButton_clicked()
{
    sDelRow();
}

void RdInImeiWin::on_tableWidget2_itemChanged(QTableWidgetItem *item)
{
    if(item->column() == 0 && mEditStatus == editFlag && mIsEditMode && !mIsImport){
        QString imei = item->data(Qt::EditRole).toString().trimmed();
        if(imei.length() < 1)return ;
        if(mIdx.toInt() < 1 ){
            QMessageBox::information(this,"提示","没有选定序列ID，不能不空");
            return ;
        }
        if(mInvCode.length() < 1 ){
            QMessageBox::information(this,"提示","没有选定商品，不能不空");
            return ;
        }
        if(imei.length()!= 12 && imei.length() != 16 && imei.length() != 15){
            QMessageBox::information(this,"提示","IMEI 长度不正确");
            return ;
        }
        //重复判断
        int count = StImeiDAO::getImeiCountByImei(imei);
        if(count > 0){
            QMessageBox::information(this,"提示","IMEI:" + imei + "已在库存，不能录入！");
            return ;
        }
        for(int i = 0; i < ui->tableWidget2->rowCount(); i ++){
            if(i != item->row() && ui->tableWidget2->model()->data(ui->tableWidget2->model()->index(i,0)).toString().trimmed() == imei){
                QMessageBox::information(this,"提示","此IMEI：" + imei + " 已输入！");
                ui->tableWidget2->model()->setData(ui->tableWidget2->model()->index(item->row(),0),"");
                return;
            }
        }
        if(mVouchType == HaoKeApp::getVouchRdSaRe()
                || mVouchType == HaoKeApp::getVouchRdCtRe() ){
            QList<RdInImeiBean *> outImeiList = OutImeiDAO::queryImeiByImei(imei);
            if(outImeiList.size() < 1){
                QMessageBox::information(this,"提示","此IMEI：" + imei + " 未发过货,不能退库！");
                return ;
            }
        }
        QAbstractItemModel *model = ui->tableWidget2->model();
        int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mImeiItem,"id"))).toInt();
        if((ui->tableWidget2->rowCount()-1) == item->row()){
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,item->row(),mImeiItem,"productCode",mInvCode);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,item->row(),mImeiItem,"productName",ui->nameEdit->text());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,item->row(),mImeiItem,"vouchsId",ui->idxEdit->text());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,item->row(),mImeiItem,"created",QDateTime::currentDateTime());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget2,item->row(),mImeiItem,"memo",ui->mEdit->text());

            if(id < 1){
                RdInImeiBean *sBean = new RdInImeiBean();
                sBean->setNo(ui->noEdit->text());
                sBean->setWhCode(ui->whSearchEditbox->text().trimmed());
                sBean->setProductCode(mInvCode);
                sBean->setVouchsId(mIdx.toInt());
                sBean->setBusCode(ui->venSearchEditbox->text());
                sBean->setVouchType(mVouchType);
                sBean->setBusDate(ui->dateEdit->date());
                sBean->setCreater(HaoKeApp::getInstance()->getUserDesc());
                WidgetBeanUtil::setItemModelToBean(model,item->row(),mImeiItem,sBean);
                mAddChildVouchsList.append(sBean);
                mIsEdit = true;
                ui->tableWidget2->setRowCount(ui->tableWidget2->rowCount()+1);
                QKeyEvent *keyPressEvent = new QKeyEvent(QEvent::KeyPress ,Qt::Key_Down,Qt::NoModifier,"");
                QApplication::sendEvent(ui->tableWidget2,keyPressEvent);
                QKeyEvent *keyEvent = new QKeyEvent(QEvent::KeyRelease ,Qt::Key_Down,Qt::NoModifier,"");
                QApplication::sendEvent(ui->tableWidget2,keyEvent);

                //QWSServer::sendKeyEvent(0,Qt::Key_Down,Qt::NoModifier,false,false);
                //Qt::Key_A
            }
        }
        //单据修改 更新数据

        for(int i =0; i < mChildVouchsList.size(); i++){
            if(mChildVouchsList.at(i)->id() == id){
                WidgetBeanUtil::setItemModelToBean(model,item->row(),mImeiItem,mChildVouchsList.at(i));
                mChildVouchsList.at(i)->setImei(imei);
                mChildVouchsList.at(i)->setCreater(HaoKeApp::getInstance()->getUserDesc());
            }
        }

    }
}


void RdInImeiWin::on_tableWidget_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn)
{
    QString id;
    QAbstractItemModel *childModel = ui->tableWidget->model();
    id = childModel->data(childModel->index(currentRow,WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toString();
    if(id == mIdx )return ;
    QModelIndex index = childModel->index(currentRow, currentColumn, QModelIndex());
    on_tableWidget_clicked(index);
}
