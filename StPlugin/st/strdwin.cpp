#include "strdwin.h"
#include "ui_strdwin.h"
#include "haokeapp.h"
#include "bean/DepBean.h"
#include "bean/SupplieBean.h"
#include "bean/CustomerBean.h"
#include "bean/EmployeeBean.h"
#include "bean/WareHouseBean.h"
#include "bean/ProductBean.h"
#include "bean/SystemSetBean.h"
#include "bean/SupplieTypeBean.h"
#include "bean/DefineBean.h"
#include "dao/commondao.h"
#include "dao/depdao.h"
#include "dao/suppliedao.h"
#include "dao/supplietypedao.h"
#include "dao/customerdao.h"
#include "dao/employeedao.h"
#include "dao/waredao.h"
#include "dao/productdao.h"
#include "dao/rddao.h"
#include "dao/systemsetdao.h"
#include "common/itemutil.h"
#include "common/cachebabeancommon.h"
#include "common/printutils.h"
#include "qtrpt.h"
#include "bean/ReportFormatBean.h"
#include "dao/reportdao.h"
#include "widget/designoptdialog.h"
#include "widget/choosevouchdialog.h"
#include "stplugin.h"

StRdWin::StRdWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StRdWin)
{
    ui->setupUi(this);
    mWinTitle = "采购入库单";
    mRdFlag = RdFlag::RdInFlag;
    //01 采购入库单 查看vouch_type表
    mVouchType = HaoKeApp::getVouchRdPuIn();
    mVouchSource = "";
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();
    mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
    if(mCountRecord < 0) mCountRecord = 0;
    mRecord = mCountRecord;
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mCountRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(false);



}

StRdWin::StRdWin(QString no,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StRdWin)
{
    ui->setupUi(this);
    RdBean *bean = RdDAO::getRdByNo(no);
    if(bean != NULL && bean->rdNo().length() > 0){
        mRdFlag = bean->rdFlag();

        mVouchType = bean->vouchType();
        init();
        if(mVouchType == HaoKeApp::getVouchRdPuRe())
            mRdRed = RdFlag::RdOutFlag;

        //qApp->setStyle("Plastique");
        setupContextMenu();
        mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
        if(mCountRecord < 0) mCountRecord = 0;
        if(ui->noEdit->text().length() >0){

        }
        mRecord = RdDAO::getRdRowNumber(mVouchType,bean->id()) - 1;
        if(mRecord == 0){
            baseToolBar->actions().at(0)->setEnabled(false);
            baseToolBar->actions().at(2)->setEnabled(false);
        }else if(mRecord >= mCountRecord ){
            baseToolBar->actions().at(1)->setEnabled(false);
            baseToolBar->actions().at(3)->setEnabled(false);
        }
        delete bean;
        read(no);
        ui->toolBar->actions().at(7)->setEnabled(true);
    }else{
        init();
        QMessageBox::critical(this,"错误","此单不存在！");
    }
    readAuthority();

}


StRdWin::~StRdWin()
{
    delete ui;
}

void StRdWin::readAuthority(){

}

void StRdWin::init(){

    //功能菜单
    actionProperties actsBase[]= {
        { "puRd.new",tr("&New"),SLOT(sNew()), NULL, "New", QPixmap(":/image/Add.png"), NULL,  true, tr("New") },
        { "puRd.edit",tr("&Edit"),SLOT(sEdit()), NULL, "Edit", QPixmap(":/image/edit.png"), NULL,  true, tr("Edit") },
        { "puRd.delete",tr("&Delete"),SLOT(sDelete()), NULL, "Delete", QPixmap(":/image/cross_48.png"), NULL,  true, tr("Delete") },
        { "puRd.save",tr("&Save"),SLOT(sSave()), NULL, "Save", QPixmap(":/image/save.png"), NULL,  true, tr("Save") },
        { "puRd.audit",tr("&Audit"),SLOT(sAudit()), NULL, "Audit", QPixmap(":/image/stamp_48.png"), NULL,  true, tr("Audit") },
        { "puRd.abandonAudit",tr("&Abandon Audit"),SLOT(sAbAudit()), NULL, "Abandon Audit", QPixmap(":/image/c_stamp_48.png"), NULL,  true, tr("Abandon Audit") },
        { "puRd.delRow",tr("&DelRow"),SLOT(sDelRow()), NULL, "DelRow", QPixmap(":/image/minus.png"), NULL,  true, tr("DelRow") },
        { "puRd.print",tr("&Print"),SLOT(sPrint()), NULL, "Print", QPixmap(":/image/printer.png"), NULL,  true, tr("Print") },
        { "puRd.choose",tr("&Choose"),SLOT(sChoose()), NULL, "Choose", QPixmap(":/image/page_accept.png"), NULL,  true, tr("Choose") },
        { "puRd.first",tr("&First"),SLOT(sFirst()), NULL, "First", QPixmap(":/image/first48.png"), NULL,  true, tr("First") },
        { "puRd.next",tr("&Next"),SLOT(sNext()), NULL, "Next", QPixmap(":/image/n-next48.png"), NULL,  true, tr("Next") },
        { "puRd.previous",tr("&Previous"),SLOT(sPrevious()), NULL, "Previous", QPixmap(":/image/n-previous48.png"), NULL,  true, tr("Previous") },
        { "puRd.end",tr("&End"),SLOT(sEnd()), NULL, "End", QPixmap(":/image/end48.png"), NULL,  true, tr("End") },
        { "puRd.cancel",tr("&Cancel"),SLOT(sCancel()), NULL, "Cancel", QPixmap(":/image/cancel.png"), NULL,  true, tr("Cancel") }

    };
    addActionsTo(actsBase,sizeof(actsBase) / sizeof(actsBase[0]));

    mIsEdit =false;

    ui->dateEdit->setDate(HaoKeApp::getInstance()->getOperateDate());
    mIsChoose = false;

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
            { "productCode","商品编码","商品编码", 0,180, true, true },
            { "productName","商品名称","商品名称", 1,180, true, true },
            { "productStyle","商品规格","商品规格", 2,80, true, false },
            { "unit","单位","单位", 3,80, true, false },
            { "quantity","数量","数量", 4, 60,true, true },
            { "unitPrice","采购单价","采购单价", 5,80, true, true },
            { "money","采购金额","采购金额", 6,80, true, false },
            { "id","ID","ID", 7,60, false, false },
            { "busNo","到货单单号","到货单单号", 8,100, false, false },
            { "orderNo","采购订单号","采购订单号", 9,100, false, false },
        { "define1","自定义1","自定义1", 10,100, false, true },
        { "define2","自定义2","自定义2", 11,100, false, true },
        { "define3","自定义3","自定义3", 12,100, false, true },
        { "define4","自定义4","自定义4", 13,100, false, true },
        { "define5","自定义5","自定义5", 14,100, false, true },
        { "define6","自定义6","自定义6", 15,100, false, true },
        { "memo","备注","备注", 16,160, false, true }
    };
    //mChildItem << childItem[0] << childItem[1] << childItem[2] << childItem[3] << childItem[4] << childItem[5] << childItem[6] << childItem[7] << childItem[8] << childItem[9];
    int size = sizeof(childItem) / sizeof(childItem[0]);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(size);
    //qDebug() << size;
    for(int i =0 ; i < size ; i ++){
        mChildItem << childItem[i];
    }

    //是否使用自定义字段
    SystemSetBean *useDefineBean = SystemSetDAO::getBean("101");
    if(useDefineBean && useDefineBean->id().length() > 0){
        if(useDefineBean->yesNo()){
            QList<DefineBean *> defineList = CommonDAO::queryDefine();
            for(int i =9 ; i < size ; i ++){
                for(int j =0 ; j < defineList.size() ; j ++){
                    if(mChildItem.at(i).name.trimmed() ==   defineList.at(j)->code()){
                        mChildItem[i].cnName = defineList.at(j)->name();
                        mChildItem[i].title = defineList.at(j)->name();
                        mChildItem[i].visible = defineList.at(j)->isView();

                    }
                }
            }
        }
    }
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
    mFootModel->setItem(size - 1,new QStandardItem(""));
    mFootModel->setItem(size - 2,new QStandardItem(""));
    ui->verticalLayout_2->addWidget(mFootView);
    mFootModel->setItem(7,new QStandardItem(""));
    QObject::connect(ui->tableWidget->horizontalHeader(),SIGNAL(sectionResized(int,int,int)),this,SLOT(footResized(int,int,int)));
    refreshData();
    /*
    ui->tableWidget->horizontalHeaderItem(0)->setTextAlignment(Qt::AlignLeft);
    ui->tableWidget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    */
    mFootView->setDefaultAlignment (Qt::AlignLeft | Qt::AlignVCenter);
    mFootView->setTextElideMode (Qt::ElideLeft); //...效果

    //初始化表头数据
    //窗体ID号
    mWinId = HaoKeApp::saSubId()+ "004";

    QList<CustomerBean *> cusBeanList = CustomerDAO::queryCus();
    QStringList cusList ;
    for(int i =0 ; i < cusBeanList.size(); i++){
        cusList << cusBeanList.at(i)->cusCode() + " - " +cusBeanList.at(i)->cusName();
    }
    ui->venSearchEditbox->setListModel(true);
    ui->venSearchEditbox->setItems(cusList);
    ui->rdLabel->setText("");
    if(mVouchType == HaoKeApp::getVouchRdPuIn()){
        mWinId = HaoKeApp::puSubId()+ "004";
        QList<SupplieBean *> venBeanList = SupplieDAO::querySupplie();
        QStringList venList ;
        for(int i =0 ; i < venBeanList.size(); i++){
            venList << venBeanList.at(i)->supplieCode() + " - " +venBeanList.at(i)->supplieName();
        }
        ui->venSearchEditbox->setListModel(true);
        ui->venSearchEditbox->setItems(venList);
    }else if(mVouchType == HaoKeApp::getVouchRdPuRe()){
        //采购退货单
        mWinId = HaoKeApp::puSubId()+ "004";
        mWinTitle = "红字入库";
        ui->arrivalLabel->setText("退货单号");
        ui->rdLabel->setText("<html><head/><body><p><span style=\" color:#ff0000;\">红字入库</span></p></body></html>");
        ui->label_16->setText("<html><head/><body><p><span style=\" color:#ff0000;\">采购入库单</span></p></body></html>");

        QList<SupplieBean *> venBeanList = SupplieDAO::querySupplie();
        QStringList venList ;
        for(int i =0 ; i < venBeanList.size(); i++){
            venList << venBeanList.at(i)->supplieCode() + " - " +venBeanList.at(i)->supplieName();
        }
        ui->venSearchEditbox->setListModel(true);
        ui->venSearchEditbox->setItems(venList);
    }else if(mVouchType == HaoKeApp::getVouchRdSaOut()){
        //销售出库
        mWinTitle = "销售出库";
        ui->arrivalLabel->setText("发货单号");
        ui->dateLabel->setText("出库日期");
        ui->whLabel->setText("出库仓库");
        ui->idLabel->setText("出库单号");
        ui->busLabel->setText("客    户");
        //ui->rdLabel->setText("<html><head/><body><p><span style=\" color:#ff0000;\">红字入库</span></p></body></html>");
        ui->label_16->setText("销售出库单");
    }else if(mVouchType == HaoKeApp::getVouchRdSaRe()){
        mWinTitle = "红字出库";
        ui->arrivalLabel->setText("退货单号");
        ui->dateLabel->setText("出库日期");
        ui->whLabel->setText("出库仓库");
        ui->idLabel->setText("出库单号");
        ui->busLabel->setText("客    户");
        ui->rdLabel->setText("<html><head/><body><p><span style=\" color:#ff0000;\">红字出库</span></p></body></html>");
        ui->label_16->setText("<html><head/><body><p><span style=\" color:#ff0000;\">销售出库单</span></p></body></html>");

    }else if(mVouchType == HaoKeApp::getVouchRdCtOut()){
        mWinTitle = "委托代销出库";
        ui->arrivalLabel->setText("发货单号");
        ui->dateLabel->setText("出库日期");
        ui->whLabel->setText("出库仓库");
        ui->idLabel->setText("出库单号");
        ui->busLabel->setText("客    户");
        ui->label_16->setText("委托代销出库单");
    }else if(mVouchType == HaoKeApp::getVouchRdCtRe()){
        mWinTitle = "红字入库";
        ui->arrivalLabel->setText("退货单号");
        ui->dateLabel->setText("出库日期");
        ui->whLabel->setText("出库仓库");
        ui->idLabel->setText("出库单号");
        ui->busLabel->setText("客    户");
        ui->rdLabel->setText("<html><head/><body><p><span style=\" color:#ff0000;\">红字出库</span></p></body></html>");
        ui->label_16->setText("<html><head/><body><p><span style=\" color:#ff0000;\">委托代销出库单</span></p></body></html>");

    }
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::puSubId().toInt(),mWinId.toInt(),0,"");


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
    QkEditDelegate *delegate = new QkEditDelegate(model,this);
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(22);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setItemDelegateForColumn(0,delegate);

}

void StRdWin::footResized(int logicalIndex, int oldSize, int newSize){
    mFootView->resizeSection(logicalIndex + 1,newSize);
    mFootView->resizeSection(0,ui->tableWidget->verticalHeader()->width());
}

void StRdWin::refreshData(){

    QStringList headerLabels;
    for (int i = 0; i < mChildItem.size(); i++){
        headerLabels.append(mChildItem[i].cnName);
        ui->tableWidget->setColumnWidth(mChildItem[i].id,mChildItem[i].width);
        mFootView->resizeSection(mChildItem[i].id + 1,mChildItem[i].width);
        if(!mChildItem[i].visible)ui->tableWidget->hideColumn(mChildItem[i].id);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
}

void StRdWin::read(QString no){
    RdBean *bean = RdDAO::getRdByNo(no);
    mNo = no;
    if(bean != NULL && bean->rdNo().length() > 0){
        ui->noEdit->setText(bean->rdNo());
        ui->dateEdit->setDate(bean->busDate());
        if(mVouchType == HaoKeApp::getVouchRdPuIn() ||
                mVouchType == HaoKeApp::getVouchRdPuRe() ){
            SupplieBean *venBean = SupplieDAO::getSupplieByCode(bean->supplierId());
            ui->venSearchEditbox->setText(bean->supplierId() + " - " + venBean->supplieName());
        }else{
            CustomerBean *cusBean = CustomerDAO::getCusByCode(bean->cusCode());
            ui->venSearchEditbox->setText(bean->cusCode() + " - " + cusBean->cusName());
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

        ui->toolBar->actions().at(3)->setEnabled(false);
        ui->toolBar->actions().at(6)->setEnabled(false);
        ui->toolBar->actions().at(8)->setEnabled(false);


        QList<RdsBean *> pBeanList = RdDAO::queryRdsBy(no);
        mChildVouchsList = RdDAO::queryRdsBy(no);
        ui->tableWidget->setRowCount(pBeanList.size() + 1);
        mTotalQuantity = 0;
        mTotalSum = 0;
        for(int i =0; i < pBeanList.size(); i++){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget,i,mChildItem,pBeanList.at(i));
            mTotalQuantity = mTotalQuantity + pBeanList.at(i)->quantity();
            mTotalSum = mTotalSum + pBeanList.at(i)->money();
        }

        mFootModel->setItem(5,new QStandardItem(QString::number(mTotalQuantity,'f',2)));
        mFootModel->setItem(7,new QStandardItem(QString::number(mTotalSum,'f',2)));
        mFootView->resizeSection(0,ui->tableWidget->verticalHeader()->width());
        mFootView->reset();
        readAuthority();
    }
}

void StRdWin::inputClear(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->headGridLayout);


}

void StRdWin::setInputEnable(bool b){
     WidgetBeanUtil::setLayoutWidgetEnable(ui->headGridLayout,b);
     if(b){
         ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
     }else{
         ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     }
}

void StRdWin::addActionsTo(actionProperties acts[], unsigned int numElems){
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

        if(i<9){
            act->setEnabled(false);
            ui->toolBar->addAction(act);
            addAction(act);
            QString proceccId = mWinId + QString::number(i);
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::puSubId().toInt(),mWinId.toInt(),proceccId.toInt(),acts[i].toolTip,acts[i].actionName);

        }
        else
            baseToolBar->addAction(act);
    }

    connect(ui->toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(toolBarActTriggered(QAction*)));
}

void StRdWin::toolBarActTriggered(QAction *act){
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::stSubId().toInt(),mWinId.toInt(),act->objectName());

}

void StRdWin::sFirst(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
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
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,0,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
        mNo = rdBeanList.at(0)->rdNo();
    }
    baseToolBar->actions().at(0)->setEnabled(false);
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(2)->setEnabled(false);
    baseToolBar->actions().at(3)->setEnabled(true);
}
\
void StRdWin::sNext(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
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
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(0)->setEnabled(true);
}

void StRdWin::sPrevious(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
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
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(1)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(true);
}

void StRdWin::sEnd(){
    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            mIsEdit = false;
            ui->toolBar->actions().at(3)->setEnabled(false);
            ui->toolBar->actions().at(6)->setEnabled(false);
            setInputEnable(false);
        }else{
            return ;
        }
    }
    ui->tableWidget->clear();
    refreshData();
    mCountRecord = RdDAO::getRdCount(mVouchType) - 1;
    mRecord = mCountRecord;
    QList<RdBean *> rdBeanList = RdDAO::queryRdByPage(mVouchType,mCountRecord,1);
    if(rdBeanList.size()>0){
        read(rdBeanList.at(0)->rdNo());
    }
    baseToolBar->actions().at(0)->setEnabled(true);
    baseToolBar->actions().at(1)->setEnabled(false);
    baseToolBar->actions().at(2)->setEnabled(true);
    baseToolBar->actions().at(3)->setEnabled(false);
}

void StRdWin::sNew(){

}

void StRdWin::sEdit(){

}

void StRdWin::sSave(){


}

void StRdWin::sDelete(){

}

void StRdWin::sDelRow(){

}

void StRdWin::sAudit(){

}

void StRdWin::sAbAudit(){

}

void StRdWin::sChoose(){


}
void StRdWin::sPrint(){

    QString fileName = "ReportPuOrder.xml";
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

void StRdWin::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage){
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

void StRdWin::sCancel(){

    this->close();
}

void StRdWin::closeEvent(QCloseEvent *event){

    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            event->ignore();
            return ;
        }
    }

    event->accept();
    HaoKeApp::getInstance()->gui()->removeSubWin(this);


}

void StRdWin::setupContextMenu(){
    /*
    handleAct = new QAction(QIcon(":/images/connector.png"),tr("关联联赛"),this);

    connect(handleAct, SIGNAL(triggered()), this, SLOT(handleMatch()));
    */
    setContextMenuPolicy(Qt::ActionsContextMenu);
}
void StRdWin::on_tableWidget_itemChanged(QTableWidgetItem *item)
{

}


