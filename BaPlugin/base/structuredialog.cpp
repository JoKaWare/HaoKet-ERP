#include "structuredialog.h"
#include "ui_structuredialog.h"
#include "business/businessno.h"
#include <QMessageBox>
#include "haokeapp.h"
#include "baplugin.h"
StructureDialog::StructureDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StructureDialog)
{
    ui->setupUi(this);
    init();
    sNew();
}

StructureDialog::StructureDialog(QString no,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StructureDialog)
{
    ui->setupUi(this);
    init();
    mId = no;
    read(no);
    setInputEnable(true);
    ui->productSearchEditbox->setEnabled(false);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);
    mEditStatus = editFlag;
    mIsEdit = true;
}
StructureDialog::~StructureDialog()
{
    delete ui;
}

void StructureDialog::init(){
    setInputEnable(false);
    QList<DepBean *> depBeanList = DepDAO::queryDepByEnd();
    QStringList depList ;
    for(int i =0 ; i < depBeanList.size(); i++){
        depList << depBeanList.at(i)->depId() + " - " +depBeanList.at(i)->depName();
    }
    ui->depSearchEditbox->setListModel(true);
    ui->depSearchEditbox->setItems(depList);

    QList<DishesBean *> dishesBeanList = DishesDAO::queryDishes();
    QStringList dishesList ;
    for(int i =0 ; i < dishesBeanList.size(); i++){
        dishesList << dishesBeanList.at(i)->productCode() + " - " +dishesBeanList.at(i)->productName();
    }
    ui->productSearchEditbox->setListModel(true);
    ui->productSearchEditbox->setItems(dishesList);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(8);
    refreshData();
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

void StructureDialog::refreshData(){
    QStringList headerLabels;
    headerLabels << "原料编码" << "原料名称" << "原料规格" << "单位" <<"定额数量" <<"损耗数量" <<"损耗率" <<"ID";
    ui->tableWidget->setHorizontalHeaderLabels(headerLabels);
    ui->tableWidget->setColumnWidth(0,180);
    ui->tableWidget->setColumnWidth(1,120);
    ui->tableWidget->setColumnWidth(2,80);
    ui->tableWidget->setColumnWidth(3,60);
    ui->tableWidget->setColumnWidth(4,80);
    ui->tableWidget->setColumnWidth(5,60);
    ui->tableWidget->setColumnWidth(6,80);
    ui->tableWidget->setColumnWidth(7,80);
    ui->tableWidget->hideColumn(7);
}

void StructureDialog::read(QString code){
    StructureBean *bean = StructureDAO::getStructureByPsCode(code);
    DishesBean *dBean = DishesDAO::getDishesByCode(code);
    QString pStr = code + " - " + dBean->productName();
    ui->productSearchEditbox->setText(pStr);
    ui->styleEdit->setText(bean->style());
    ui->unitEdit->setText(bean->unit());
    ui->makeEdit->setText(BusinessNo::userToName(bean->createdBy(),1));
    ui->reckonCheckBox->setChecked(bean->isReckon());
    DepBean *depBean = DepDAO::getDepById(bean->depCode());
    ui->depSearchEditbox->setText(bean->depCode() + " - " + depBean->depName());

    QList<StructuresBean *> pBeanList = StructureDAO::queryStructuresByPspCode(code);
    mChildList = StructureDAO::queryStructuresByPspCode(code);
    ui->tableWidget->setRowCount(pBeanList.size() + 1);
    for(int i =0; i < pBeanList.size(); i++){
        QTableWidgetItem *codeItem = new QTableWidgetItem();
        QTableWidgetItem *nameItem = new QTableWidgetItem();
        QTableWidgetItem *styleItem = new QTableWidgetItem();
        QTableWidgetItem *unitItem = new QTableWidgetItem();
        QTableWidgetItem *quantityItem = new QTableWidgetItem();
        QTableWidgetItem *rQuantityItem = new QTableWidgetItem();
        QTableWidgetItem *rateItem = new QTableWidgetItem();
        QTableWidgetItem *idItem = new QTableWidgetItem();
        codeItem->setData(Qt::EditRole,pBeanList.at(i)->psCode());
        nameItem->setFlags(Qt::ItemIsEnabled);
        nameItem->setData(Qt::EditRole,pBeanList.at(i)->productName());
        styleItem->setFlags(Qt::ItemIsEnabled);
        styleItem->setData(Qt::EditRole,pBeanList.at(i)->style());
        unitItem->setFlags(Qt::ItemIsEnabled);
        unitItem->setData(Qt::EditRole,pBeanList.at(i)->wasteUnit());
        //priceItem->setFlags(Qt::ItemIsEnabled);
        rQuantityItem->setData(Qt::EditRole,pBeanList.at(i)->realityQuantity());
        //quantityItem->setFlags(Qt::ItemIsEnabled);
        quantityItem->setData(Qt::EditRole,pBeanList.at(i)->quantity());
        rateItem->setFlags(Qt::ItemIsEnabled);
        rateItem->setData(Qt::EditRole,pBeanList.at(i)->wasteRate());
        idItem->setFlags(Qt::ItemIsEnabled);
        idItem->setData(Qt::EditRole,pBeanList.at(i)->id());
        ui->tableWidget->setItem(i,0,codeItem);
        ui->tableWidget->setItem(i,1,nameItem);
        ui->tableWidget->setItem(i,2,styleItem);
        ui->tableWidget->setItem(i,3,unitItem);
        ui->tableWidget->setItem(i,4,quantityItem);
        ui->tableWidget->setItem(i,5,rQuantityItem);
        ui->tableWidget->setItem(i,6,rateItem);
        ui->tableWidget->setItem(i,7,idItem);

    }

}

void StructureDialog::setInputEnable(bool b){
    ui->productSearchEditbox->setEnabled(b);
    ui->depSearchEditbox->setEnabled(b);
    ui->styleEdit->setEnabled(b);
    ui->unitEdit->setEnabled(b);
    ui->makeEdit->setEnabled(b);
    ui->reckonCheckBox->setEnabled(b);
}

void StructureDialog::inputClear(){

    ui->productSearchEditbox->clear();
    ui->depSearchEditbox->clear();
    ui->styleEdit->clear();
    ui->unitEdit->clear();
    ui->makeEdit->clear();
}
void StructureDialog::sNew(){

    inputClear();
    mIsEdit = true;
    mEditStatus = addFlag;
    setInputEnable(true);

    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::EditKeyPressed | QAbstractItemView::AnyKeyPressed);

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    ui->newButton->setEnabled(false);
    ui->delRowButton->setEnabled(true);
    ui->saveButton->setEnabled(true);
    refreshData();
}
void StructureDialog::on_newButton_clicked()
{
    if(mIsEdit){

        if(QMessageBox::warning(this,"提示","是否放弃保存",QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
            sNew();
        }else{
            return ;
        }

    }

}

void StructureDialog::on_saveButton_clicked()
{
    if(mIsEdit){
        if(ui->productSearchEditbox->text().length()< 1){
            QMessageBox::warning(this,"提示","出错，此菜品为空，不能保存");
            return ;
        }
        QAbstractItemModel *model = ui->tableWidget->model();
        int rowNum = model->rowCount() -1;
        if(rowNum <= 0){
            QMessageBox::warning(this,"提示","子项目无数据，不能保存");
            return;
        }
        for(int i = 0;i < rowNum; i++){
            QString pCode = model->data(model->index(i,0)).toString();
            ProductBean *pBean = ProductDAO::getProductByCode(pCode);
            if(pBean != NULL && pBean->productCode().length() > 0){
                for(int j = 0; j < ui->tableWidget->rowCount(); j ++){
                    if(i != j && ui->tableWidget->model()->data(ui->tableWidget->model()->index(j,0)).toString().trimmed() == pCode){
                        QMessageBox::information(this,"提示","此原料" + pCode + " 重复！");
                        ui->tableWidget->model()->setData(ui->tableWidget->model()->index(j,0),"");
                        return;
                    }
                }
            }else{
                QMessageBox::warning(this,"提示","此原料编码，不存在，不能保存");
                return ;
            }
        }
        if(mEditStatus == addFlag){
            if(StructureDAO::getByCodeCount(ui->productSearchEditbox->text()) > 0){
                QMessageBox::warning(this,"提示","出错，此菜品已存在，不能保存");
                return ;
            }

            QDateTime time = QDateTime::currentDateTime();
            StructureBean *bean = new StructureBean;
            bean->setPspCode(ui->productSearchEditbox->text());
            bean->setDepCode(ui->depSearchEditbox->text());

            bean->setHandler("");
            bean->setStatus(0);
            bean->setStyle(ui->styleEdit->text());
            bean->setUnit(ui->unitEdit->text());
            bean->setCreated(time);
            bean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
            bean->setUpdated(time);
            bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
            bean->setIsExpand(false);
            bean->setIsReckon(ui->reckonCheckBox->isChecked());
            DBManager::getDBManager()->getGoinDBConnection().transaction();
            int mResult = 0;
            mResult = StructureDAO::createStructure(bean);
            int cResult = 0;

            for(int i = 0;i < rowNum; i++){
                StructuresBean *sBean = new StructuresBean();


                QString pCode = model->data(model->index(i,0)).toString();
                QString style = model->data(model->index(i,2)).toString();
                QString unit = model->data(model->index(i,3)).toString();
                double quantity = model->data(model->index(i,4)).toDouble();
                double realityQuantity = model->data(model->index(i,5)).toDouble();
                double rate = model->data(model->index(i,6)).toDouble();
                sBean->setPspCode(ui->productSearchEditbox->text());
                sBean->setPsCode(pCode);
                sBean->setStyle(style);
                sBean->setWasteUnit(unit);
                sBean->setQuantity(quantity);
                sBean->setRealityQuantity(realityQuantity);
                sBean->setWasteRate(rate);
                sBean->setChangRate(rate);
                int c = StructureDAO::createStructures(sBean);
                if(c < 1){
                    DBManager::getDBManager()->getGoinDBConnection().rollback();
                    QMessageBox::information(this,"提示","此" + pCode + " 数据提交出错,不能保存");
                    return ;
                }
                cResult = cResult + c;
            }
            if(mResult > 0 && cResult > 0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
                mIsEdit = false;
                ui->saveButton->setEnabled(false);
                ui->newButton->setEnabled(true);
                setInputEnable(false);

                mDelChildList.clear();
                mAddChildList.clear();
                mChildList.clear();
                refreshData();

                ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"Prompt","数据提交出错");
                return ;
            }


        }else if(mEditStatus == editFlag){
            StructureBean *bean = StructureDAO::getStructureByPsCode(ui->productSearchEditbox->text());
            bean->setPspCode(ui->productSearchEditbox->text());
            bean->setStyle(ui->styleEdit->text());
            bean->setUnit(ui->unitEdit->text());
            bean->setDepCode(ui->depSearchEditbox->text());
            bean->setIsReckon(ui->reckonCheckBox->isChecked());
            bean->setUpdated(QDateTime::currentDateTime());
            bean->setUpdatedBy(HaoKeApp::getInstance()->getUserId());
            DBManager::getDBManager()->getGoinDBConnection().transaction();
            int mResult = 0;
            int cResult = 0;
            mResult = StructureDAO::updateStructure(bean);
            //删除
            for(int i = 0; i < mDelChildList.size(); i++){
                StructuresBean *delBean = new StructuresBean;
                delBean->setId(mDelChildList.at(i));
                int c = StructureDAO::delStructures(delBean);
                cResult = cResult + c;
            }
            //更新
            for(int i = 0; i < mChildList.size(); i++){
                int c = StructureDAO::updateStructures(mChildList.at(i));
                cResult = cResult + c;
            }
            //添加
            for(int i = 0; i < mAddChildList.size(); i++){
                int c = StructureDAO::createStructures(mAddChildList.at(i));
                cResult = cResult + c;
            }

            if(mResult > 0 && cResult>0 && DBManager::getDBManager()->getGoinDBConnection().commit()){
                mIsEdit = false;
                ui->newButton->setEnabled(true);
                ui->saveButton->setEnabled(false);
                ui->delRowButton->setEnabled(false);
                ui->makeEdit->setText(BusinessNo::userToName(HaoKeApp::getInstance()->getUserId(),1));
                mDelChildList.clear();
                mAddChildList.clear();
                mChildList.clear();
                refreshData();
                setInputEnable(false);
                ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
            }else{
                DBManager::getDBManager()->getGoinDBConnection().rollback();
                QMessageBox::information(this,"Prompt","数据提交出错");
                return ;
            }
        }
    }
}

void StructureDialog::on_printButton_clicked()
{

}

void StructureDialog::on_cancelButton_clicked()
{
    this->close();
}

void StructureDialog::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    if(item->column() == 0 && mIsEdit){
        QString id = item->data(Qt::EditRole).toString().trimmed();
        if(id.length() < 1){
            return ;
        }
        //重复判断
        for(int i = 0; i < ui->tableWidget->rowCount(); i ++){
            if(i != item->row() && ui->tableWidget->model()->data(ui->tableWidget->model()->index(i,0)).toString().trimmed() == id){
                QMessageBox::information(this,"提示","此原料" + id + " 已输入！");
                ui->tableWidget->model()->setData(ui->tableWidget->model()->index(item->row(),0),"");
                return;
            }
        }
        //根据ID查询原料信息
        ProductBean *bean = ProductDAO::getProductByCode(id);
        if(id.length() > 0 && bean != NULL && bean->productCode() == id ){
            QTableWidgetItem *nameItem = new QTableWidgetItem();
            QTableWidgetItem *styleItem = new QTableWidgetItem();
            QTableWidgetItem *unitItem = new QTableWidgetItem();
            QTableWidgetItem *rQuantityItem = new QTableWidgetItem();
            QTableWidgetItem *quantityItem = new QTableWidgetItem();
            QTableWidgetItem *rateItem = new QTableWidgetItem();
            nameItem->setFlags(Qt::ItemIsEnabled);
            nameItem->setData(Qt::DisplayRole,bean->productName());
            styleItem->setFlags(Qt::ItemIsEnabled);
            styleItem->setData(Qt::EditRole,bean->style());
            unitItem->setFlags(Qt::ItemIsEnabled);
            unitItem->setData(Qt::EditRole,bean->doseUnit());
            //priceItem->setFlags(Qt::ItemIsEnabled);
            quantityItem->setData(Qt::EditRole,1.0);
            //quantityItem->setFlags(Qt::ItemIsEnabled);
            rQuantityItem->setData(Qt::EditRole,1.0);
            //rateItem->setFlags(Qt::ItemIsEnabled);
            rateItem->setData(Qt::EditRole,1.0);
            ui->tableWidget->setItem(item->row(),1,nameItem);
            ui->tableWidget->setItem(item->row(),2,styleItem);
            ui->tableWidget->setItem(item->row(),3,unitItem);
            ui->tableWidget->setItem(item->row(),4,quantityItem);
            ui->tableWidget->setItem(item->row(),5,rQuantityItem);
            ui->tableWidget->setItem(item->row(),6,rateItem);

            if((ui->tableWidget->rowCount()-1) == item->row()){
                QAbstractItemModel *model = ui->tableWidget->model();
                int id = model->data(model->index(item->row(),7)).toInt();
                if(mEditStatus == editFlag && id < 1){
                    //单据修改 增加数据

                    StructuresBean *sBean = new StructuresBean();
                    sBean->setPspCode(ui->productSearchEditbox->text());
                    QString pCode = model->data(model->index(item->row(),0)).toString();
                    double quantity = model->data(model->index(item->row(),4)).toDouble();
                    double realityQuantity = model->data(model->index(item->row(),5)).toDouble();
                    double rate = model->data(model->index(item->row(),6)).toDouble();
                    sBean->setPsCode(pCode);
                    sBean->setStyle(model->data(model->index(item->row(),2)).toString());
                    sBean->setWasteUnit(model->data(model->index(item->row(),3)).toString());
                    sBean->setQuantity(quantity);
                    sBean->setRealityQuantity(realityQuantity);
                    sBean->setWasteRate(rate);
                    sBean->setChangRate(0);

                    mAddChildList.append(sBean);
                }
                ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
            }
        }else{
            QMessageBox::information(this,"提示","不存在此原料");

            return ;
        }

    }else if(item->column() == 4 || item->column()==5){



    }

    //单据修改
    if(mEditStatus == editFlag){
        QAbstractItemModel *model = ui->tableWidget->model();
        int id = model->data(model->index(item->row(),7)).toInt();
        QString pCode = model->data(model->index(item->row(),0)).toString();
        double quantity = model->data(model->index(item->row(),4)).toDouble();
        double realityQuantity = model->data(model->index(item->row(),5)).toDouble();
        double rate = model->data(model->index(item->row(),6)).toDouble();
        if(item->column() == 4 || item->column()==5){
            if(id < 1 ){
                for(int i =0; i < mAddChildList.size(); i++){
                    if(mAddChildList.at(i)->psCode() == pCode){

                        mAddChildList.at(i)->setQuantity(quantity);
                        mAddChildList.at(i)->setRealityQuantity(realityQuantity);
                        mAddChildList.at(i)->setWasteRate(rate);
                    }

                }
            }
        }
        QString name = model->data(model->index(item->row(),1)).toString();
        //单据修改 更新数据
        for(int i =0; i < mChildList.size(); i++){
            if(mChildList.at(i)->id() == id){


                mChildList.at(i)->setPsCode(pCode);
                mChildList.at(i)->setStyle(model->data(model->index(item->row(),2)).toString());
                mChildList.at(i)->setWasteUnit(model->data(model->index(item->row(),3)).toString());

                mChildList.at(i)->setQuantity(quantity);
                mChildList.at(i)->setRealityQuantity(realityQuantity);
                mChildList.at(i)->setWasteRate(rate);

            }
        }

    }
}


void StructureDialog::on_delRowButton_clicked()
{
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
               for(int i =0 ; i < mChildList.size(); i++){
                   if(code == mChildList.at(i)->psCode()){
                       mDelChildList.append(mChildList.at(i)->id());
                       mChildList.removeAt(i);

                   }
               }
               for(int i =0 ; i < mAddChildList.size(); i++){
                   if(code == mAddChildList.at(i)->psCode()){
                       mAddChildList.removeAt(i);
                   }
               }
               modelTotal->removeRow(row);
           }


       }
    }else{
       QMessageBox::information(this,"Prompt","请选择要删除的行!");
    }
}

void StructureDialog::on_productSearchEditbox_editChanged(const QString &arg1)
{
    DishesBean *bean = DishesDAO::getDishesByCode(arg1);
    if(bean != NULL && bean->productName().length() > 0){
        ui->unitEdit->setText(bean->unit());
        ui->styleEdit->setText(bean->style());

    }

}
