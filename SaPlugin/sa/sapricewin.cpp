#include "sapricewin.h"
#include "ui_sapricewin.h"
#include "bean/ProductBean.h"
#include "dao/productdao.h"
#include "dao/sapricedao.h"
#include "haokeapp.h"
#include "saplugin.h"
#include "widget/optinvdialog.h"

SaPriceWin::SaPriceWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SaPriceWin)
{
    ui->setupUi(this);
    init();
    //qApp->setStyle("Plastique");
    setupContextMenu();


    ui->toolBar->actions().at(0)->setEnabled(true);
    ui->toolBar->actions().at(1)->setEnabled(true);
    ui->toolBar->actions().at(4)->setEnabled(true);
    read("");
    readAuthority();
}

SaPriceWin::~SaPriceWin()
{
    delete ui;
}
void SaPriceWin::init(){
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //窗体ID号
    mWinId = HaoKeApp::saSubId()+ SaPlugin::priceWinId();
    mWinTitle = "销售报价";

    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::saSubId().toInt(),mWinId.toInt(),0,"");

    //功能菜单
    actionProperties actsBase[]= {
        { "saRd.new",tr("&New"),SLOT(sNew()), NULL, "New", QPixmap(":/image/Add.png"), NULL,  true, tr("New") },
        { "saRd.edit",tr("&Edit"),SLOT(sEdit()), NULL, "Edit", QPixmap(":/image/edit.png"), NULL,  true, tr("Edit") },
        { "saRd.save",tr("&Save"),SLOT(sSave()), NULL, "Save", QPixmap(":/image/save.png"), NULL,  true, tr("Save") },
        { "saRd.delRow",tr("&DelRow"),SLOT(sDelRow()), NULL, "DelRow", QPixmap(":/image/minus.png"), NULL,  true, tr("DelRow") },
        { "saRd.print",tr("&Print"),SLOT(sPrint()), NULL, "Print", QPixmap(":/image/printer.png"), NULL,  true, tr("Print") },
        { "saRd.cancel",tr("&Cancel"),SLOT(sCancel()), NULL, "Cancel", QPixmap(":/image/cancel.png"), NULL,  true, tr("Cancel") }

    };
    addActionsTo(actsBase,sizeof(actsBase) / sizeof(actsBase[0]));

    mIsEdit =false;
    //初始化表体格式
    setInputEnable(false);

    childItemProperties childItem[] = {
            { "productCode","商品编码","商品编码", 0,180, true, true },
            { "productName","商品名称","商品名称", 1,120, true, true },
            { "style","商品规格","商品规格", 2,80, true, false },
            { "unit","单位","单位", 3,80, true, false },
            { "price","销售报价","销售报价", 4, 80,true, true },
            { "uprice1","一级批发价","一级批发价", 5,80, true, true },
            { "uprice2","二级批发价","二级批发价", 6,80, true, true },
            { "uprice3","三级批发价","三级批发价", 7,80, true, true },
            { "salesCost","零售价","零售价", 8,80, true, true },\
            { "description","描述","描述", 9,180, true, true },
            { "id","ID","ID", 10,60, true, false }
    };

    int size = sizeof(childItem) / sizeof(childItem[0]);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(size);
    //qDebug() << size;
    for(int i =0 ; i < size ; i ++){
        mChildItem << childItem[i];
    }
    refreshData();

    QList<ProductBean *> proBeanList = ProductDAO::queryProduct();
    QStandardItemModel *model = new QStandardItemModel(proBeanList.size(),1);
    for(int i=0;i < proBeanList.size();i++){
        QStandardItem *itemName = new QStandardItem(proBeanList.at(i)->productCode() + " - " +proBeanList.at(i)->productName());
        model->setItem(i,0,itemName);
    }
    QkEditDelegate *delegate = new QkEditDelegate(model,this);
    connect(delegate,SIGNAL(btnClicked()),this,SLOT(sInvClick()));
    ui->tableWidget->verticalHeader()->setDefaultSectionSize(22);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setItemDelegateForColumn(0,delegate);
    QApplication::restoreOverrideCursor();
}

void SaPriceWin::sInvClick(){

    QString sql = " SELECT b.wh_name,a.*,a.sum-a.c_sum+a.r_sum as k_sum,c.style FROM st_stock_query a, ba_ware_house b , ba_product c"
            " WHERE a.wh_code=b.wh_code AND a.product_code=c.product_code "
            " AND a.wh_code LIKE ? AND a.product_code LIKE ? AND c.type_id LIKE ? ";
    childItemProperties childItem[] = {
            { "product_code","编码商品","商品", 0,60, true, true },
            { "product_name","商品名称","商品", 1,100, true, true },
            { "style","商品规格","商品", 2,100, true, true },
            { "wh_name","名称仓库","仓库", 3,80, true, true },
            { "sum","现存量","现存量", 4, 60,true, true },
            { "r_sum","待入库","待入库", 5, 60,true, true },
            { "c_sum","待出库","待出库", 6, 60,true, true },
            { "k_sum","可发量","可发量", 7,60, true, true }
    };

    QList<struct childItemProperties > dItem;
    int size = sizeof(childItem) / sizeof(childItem[0]);
    for(int i = 0 ; i < size ; i++){
        dItem << childItem[i];
    }
    QString whCode = "";
    QString invCode = "";
    OptInvDialog *invDlg = new OptInvDialog(dItem,sql,whCode,invCode,this);
    if(invDlg->exec() == QDialog::Accepted){
        QItemSelectionModel *selectionModel = invDlg->getTableView()->selectionModel();
        QModelIndexList selected= selectionModel->selectedIndexes();
        if(selected.size() < 1){
            QMessageBox::information(this,"提示","末选择商品!");

        }else{
            invCode = invDlg->getTableView()->model()->data(invDlg->getTableView()->model()->index(selected.at(0).row(),0)).toString();
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,ui->tableWidget->currentRow(),mChildItem,"productCode",invCode);
        }
    }
    delete invDlg;

}

void SaPriceWin::read(QString no){
    QList<SaPriceBean *> beanList = SaPriceDAO::querySaPricee();
    mChildVouchsList = SaPriceDAO::querySaPricee();
    ui->tableWidget->setRowCount(beanList.size() + 1);
    if(beanList.size()>0){
        mNo = beanList.at(0)->no();
        for(int i = 0; i < beanList.size(); i ++ ){
            WidgetBeanUtil::setBeanToTableWidget(ui->tableWidget,i,mChildItem,beanList.at(i));
        }
    }
}


void SaPriceWin::refreshData(){
    QStringList headerLabels;
    for (int i = 0; i < mChildItem.size(); i++){
        headerLabels.append(mChildItem[i].cnName);
        ui->tableWidget->setColumnWidth(mChildItem[i].id,mChildItem[i].width);
        if(!mChildItem[i].visible)ui->tableWidget->hideColumn(mChildItem[i].id);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
}

void SaPriceWin::inputClear(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->headGridLayout);


}

void SaPriceWin::setInputEnable(bool b){
     WidgetBeanUtil::setLayoutWidgetEnable(ui->headGridLayout,b);
     if(b){
         ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
     }else{
         ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
     }
}

void SaPriceWin::addActionsTo(actionProperties acts[], unsigned int numElems){
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

        if(i<5){
            act->setEnabled(false);
            ui->toolBar->addAction(act);
            addAction(act);
            QString proceccId = mWinId + QString::number(i);
            HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::saSubId().toInt(),mWinId.toInt(),proceccId.toInt(),acts[i].toolTip,acts[i].actionName);

        }else
            baseToolBar->addAction(act);

    }
    connect(ui->toolBar, SIGNAL(actionTriggered(QAction*)), this, SLOT(toolBarActTriggered(QAction*)));
}

void SaPriceWin::toolBarActTriggered(QAction *act){
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::saSubId().toInt(),mWinId.toInt(),act->objectName());

}

void SaPriceWin::sNew(){
    inputClear();

    mEditStatus = addFlag;
    setInputEnable(true);
    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(false);
    ui->toolBar->actions().at(2)->setEnabled(true);
    ui->toolBar->actions().at(3)->setEnabled(true);
    ui->toolBar->actions().at(4)->setEnabled(true);
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);

    refreshData();
    readAuthority();
    mIsEdit = false;
    if(QMessageBox::warning(this, "提示","是否重建报价表",
                            QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        QList<ProductBean *> proBeanList = ProductDAO::queryProduct();
        ui->tableWidget->setRowCount(proBeanList.size() + 1 );
        for(int i=0;i < proBeanList.size();i++){
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"productCode",proBeanList.at(i)->productCode());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"productName",proBeanList.at(i)->productName());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"productStyle",proBeanList.at(i)->style());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"unit",proBeanList.at(i)->stockUnit());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"price",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"uprice1",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"uprice2",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"uprice3",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,i,mChildItem,"salesCost",0);

        }

    }
    mIsEdit = true;
}

void SaPriceWin::sEdit(){
    mIsEdit = true;
    setInputEnable(true);
    mEditStatus = editFlag;

    ui->toolBar->actions().at(0)->setEnabled(false);
    ui->toolBar->actions().at(1)->setEnabled(false);
    ui->toolBar->actions().at(2)->setEnabled(true);
    ui->toolBar->actions().at(3)->setEnabled(true);
    ui->toolBar->actions().at(4)->setEnabled(true);

    readAuthority();
}

void SaPriceWin::sDelRow(){
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
                    if(code == mChildVouchsList.at(i)->productCode()){
                        mDelChildList.append(mChildVouchsList.at(i)->id());
                        mChildVouchsList.removeAt(i);

                    }
                }
                for(int i =0 ; i < mAddChildVouchsList.size(); i++){
                    if(code == mAddChildVouchsList.at(i)->productCode()){
                        mAddChildVouchsList.removeAt(i);
                    }
                }
                modelTotal->removeRow(row);
            }
            if(mIsEdit){


            }


        }
    }else{
        QMessageBox::information(this,"Prompt","请选择要删除的行!");
    }
}

void SaPriceWin::sSave(){
    QAbstractItemModel *model = ui->tableWidget->model();
    int rowNum = model->rowCount() -1;
    if(rowNum == 0){
        QMessageBox::warning(this,"提示","无数据，不能保存");
        return;
    }

    for(int i = 0;i < rowNum; i++){
        QString pCode = model->data(model->index(i,0)).toString();
        ProductBean *pBean = ProductDAO::getProductByCode(pCode);
        if(pBean != NULL && pBean->productCode().length() > 0){
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
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int cResult = 0;
        double d_val = 0;
        //备份到历史表 再删除

        QList<SaPriceBean *> beanList = SaPriceDAO::querySaPricee();
        for(int i = 0; i < beanList.size(); i ++ ){
            SaPriceDAO::createSaPriceHis(beanList.at(i));
        }
        SaPriceDAO::delSaPrice(mNo);

        QString no = QDate::currentDate().toString("yyyyMMdd");
        QDateTime time = QDateTime::currentDateTime();
        for(int i = 0;i < rowNum; i++){
            SaPriceBean *priceBean = new SaPriceBean();
            priceBean->setNo(no);
            WidgetBeanUtil::setItemModelToBean(model,i,mChildItem,priceBean);
            priceBean->setLowSum(d_val);
            priceBean->setUpdated(time);
            priceBean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
            int c = SaPriceDAO::createSaPrice(priceBean);
            if(c < 1){
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"提示","此" + priceBean->productCode() + " 数据提交出错,不能保存");
                return ;
            }
            cResult = cResult + c;
        }
        if(cResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(false);
            ui->toolBar->actions().at(3)->setEnabled(false);
            setInputEnable(false);
            mDelChildList.clear();
            mAddChildVouchsList.clear();
            mChildVouchsList.clear();

            ui->tableWidget->clear();
            refreshData();
            read("");

            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"Prompt","数据提交出错");
            return ;
        }
        readAuthority();
    }

    if(mEditStatus == editFlag){
        DBManager::getDBManager()->getGoinDBConnection().transaction();
        int cResult = 0;
        //删除
        for(int i = 0; i < mDelChildList.size(); i++){
            SaPriceBean *delBean = new SaPriceBean;
            delBean->setId(mDelChildList.at(i));
            int c = SaPriceDAO::delSaPrice(delBean);
            cResult = cResult + c;
        }
        //更新
        for(int i = 0; i < mChildVouchsList.size(); i++){
            int c = SaPriceDAO::updateSaPrice(mChildVouchsList.at(i));
            cResult = cResult + c;
        }
        //添加
        QDateTime time = QDateTime::currentDateTime();
        for(int i = 0; i < mAddChildVouchsList.size(); i++){
            mAddChildVouchsList.at(i)->setUpdated(time);
            mAddChildVouchsList.at(i)->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
            int c = SaPriceDAO::createSaPrice(mAddChildVouchsList.at(i));
            cResult = cResult + c;
        }

        if(cResult>0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
            mIsEdit = false;
            ui->toolBar->actions().at(0)->setEnabled(true);
            ui->toolBar->actions().at(1)->setEnabled(true);
            ui->toolBar->actions().at(2)->setEnabled(false);
            ui->toolBar->actions().at(3)->setEnabled(false);
            setInputEnable(false);
            mDelChildList.clear();
            mAddChildVouchsList.clear();
            mChildVouchsList.clear();

            ui->tableWidget->clear();
            refreshData();
            read("");
            ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }else{
            DBManager::getDBManager()->getGoinDBConnection().rollback();
            QMessageBox::information(this,"Prompt","数据提交出错");
            return ;
        }
        readAuthority();
    }
}


void SaPriceWin::sPrint(){

}


void SaPriceWin::sCancel(){

    this->close();
}
void SaPriceWin::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if(item->column() == 0 && mIsEdit){
        QString code = item->data(Qt::EditRole).toString().trimmed();
        if(code.length() < 1){
            return ;
        }
        //重复判断
        for(int i = 0; i < ui->tableWidget->rowCount(); i ++){
            if(i != item->row() && ui->tableWidget->model()->data(ui->tableWidget->model()->index(i,0)).toString().trimmed() == code){
                QMessageBox::information(this,"提示","此商品,编码：" + code + " 已输入！");
                ui->tableWidget->model()->setData(ui->tableWidget->model()->index(item->row(),0),"");
                return;
            }
        }

        //根据ID查询原料信息
        ProductBean *bean = ProductDAO::getProductByCode(code);
        if(code.length() > 0 && bean != NULL && bean->productCode() == code ){
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"productName",bean->productName());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"style",bean->style());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"unit",bean->stockUnit());
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"price",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"uprice1",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"uprice2",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"uprice3",0);
            WidgetBeanUtil::setValueToTableWidget(ui->tableWidget,item->row(),mChildItem,"salesCost",0);

            if((ui->tableWidget->rowCount()-1) == item->row()){
                QAbstractItemModel *model = ui->tableWidget->model();
                int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
                if(mEditStatus == editFlag && id < 1){

                    //单据修改 增加数据
                    SaPriceBean *sBean = new SaPriceBean();
                    WidgetBeanUtil::setItemModelToBean(model,item->row(),mChildItem,sBean);
                    sBean->setNo(mNo);
                    mAddChildVouchsList.append(sBean);
                }
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            }
        }else{
            QMessageBox::information(this,"提示","不存在此商品");

            return ;
        }

    }else if(item->column() >= 4 ){

    }

    //单据修改
    if(mEditStatus == editFlag){

        QAbstractItemModel *model = ui->tableWidget->model();
        int id = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"id"))).toInt();
        QString pCode = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"productCode"))).toString();
        double price = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"price"))).toDouble();
        double uprice1 = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"uprice1"))).toDouble();
        double uprice2 = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"uprice2"))).toDouble();
        double uprice3 = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"uprice3"))).toDouble();
        double salesCost = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"salesCost"))).toDouble();
        QString desc = model->data(model->index(item->row(),WidgetBeanUtil::getChildItemId(mChildItem,"description"))).toString();
        if(item->column() >= 4 ){
            if(id < 1 ){
                for(int i =0; i < mAddChildVouchsList.size(); i++){
                    if(mAddChildVouchsList.at(i)->productCode() == pCode){
                        mAddChildVouchsList.at(i)->setPrice(price);
                        mAddChildVouchsList.at(i)->setUprice1(uprice1);
                        mAddChildVouchsList.at(i)->setUprice2(uprice2);
                        mAddChildVouchsList.at(i)->setUprice3(uprice3);
                        mAddChildVouchsList.at(i)->setUprice3(salesCost);
                        mAddChildVouchsList.at(i)->setDescription(desc);
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

void SaPriceWin::closeEvent(QCloseEvent *event){

    if(mIsEdit){
        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::No){
            event->ignore();
            return ;
        }
    }

    event->accept();
    HaoKeApp::getInstance()->gui()->removeSubWin(this);


}

void SaPriceWin::setupContextMenu(){
    /*
    handleAct = new QAction(QIcon(":/images/connector.png"),tr("关联联赛"),this);

    connect(handleAct, SIGNAL(triggered()), this, SLOT(handleMatch()));
    */
    setContextMenuPolicy(Qt::ActionsContextMenu);
}

void SaPriceWin::readAuthority(){
    LimitsCommon::authority(ui->toolBar,mWinId.toInt());
}

void SaPriceWin::setValue(int &recNo, QString &paramName, QVariant &paramValue, int reportPage){
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


