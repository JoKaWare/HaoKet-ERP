#include <QMessageBox>
#include "dinnerform.h"
#include "ui_dinnerform.h"
#include "haokeapp.h"
#include "bean/DinnerBean.h"
#include "dao/dinnerdao.h"
#include "bean/AreaBean.h"

#include "dao/areadao.h"

#include "system/limitscommon.h"
#include "baplugin.h"

DinnerForm::DinnerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DinnerForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();

}

DinnerForm::~DinnerForm()
{
    delete ui;
}
void DinnerForm::init(){
    setInputEnabled(false);
    setButtonEnabled(false);
    ui->typeComboBox->addItem(tr("大厅桌"));
    ui->typeComboBox->addItem(tr("包厢桌"));
    QList<AreaBean *> listArea=AreaDAO::queryArea();
    for(int i=0;i<listArea.size();i++){
        ui->areaComboBox->addItem("["+QString::number(listArea.at(i)->areaId())+"] "+listArea.at(i)->areaName());
    }
    refreshData();
}

void DinnerForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void DinnerForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->codeEdit->setEnabled(b);
    ui->typeComboBox->setEnabled(b);
    ui->areaComboBox->setEnabled(b);
    ui->checkBox->setEnabled(b);
    ui->numberSpin->setEnabled(b);
    ui->memoEdit->setEnabled(b);
    ui->lostSpinBox->setEnabled(b);
}

void DinnerForm::clearInput(){
    ui->nameEdit->clear();
    ui->codeEdit->clear();
    ui->checkBox->clearMask();
    ui->lostSpinBox->clear();
    ui->memoEdit->clear();

}

void DinnerForm::refreshData(){
    QList<AreaBean *> listBean=AreaDAO::queryArea();
    QStandardItemModel *model;
    model = new QStandardItemModel(listBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Dinner"));
    QList<DinnerBean *> listDinnerBean=DinnerDAO::queryDinner();

    for(int i=0;i<listBean.size();i++){
        QStandardItem *itemName = new QStandardItem("("+QString::number(listBean.at(i)->areaId())+") "+listBean.at(i)->areaName());

        for(int j=0;j<listDinnerBean.size();j++){
            if(listBean.at(i)->areaId()==listDinnerBean.at(j)->areaId()){
                QString str1="("+listDinnerBean.at(j)->dinnerId()+") "+listDinnerBean.at(j)->dinnerName() + " "
                        + QString::number(listDinnerBean.at(j)->number()) + "人";
                QStandardItem *childItem = new QStandardItem(str1);
                itemName->appendRow(childItem);
            }
        }
        model->setItem(i,0,itemName);
    }
    ui->treeView->setModel(model);
    ui->treeView->expandAll();

}
void DinnerForm::setButtonEnabled(bool b){

    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);
        if(statusEdit == addFlag || statusEdit == editFlag)
            ui->saveButton->setEnabled(b);
        else
            ui->saveButton->setEnabled(false);
    }else{
        ui->editButton->setEnabled(false);
        ui->saveButton->setEnabled(false);
        ui->delButton->setEnabled(false);
    }
    limitsInit();
}

void DinnerForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void DinnerForm::on_newButton_clicked()
{
    statusEdit = addFlag;
    setInputEnabled(true);
    clearInput();
    ui->saveButton->setEnabled(true);

}

void DinnerForm::on_editButton_clicked()
{
    statusEdit = editFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);

}

void DinnerForm::on_saveButton_clicked()
{
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dinner name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;
    }
    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dinner Code"),QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    DinnerBean *nBean = DinnerDAO::getDinnerById(ui->codeEdit->text().trimmed());
    if(nBean->dinnerId().length() > 0){
        if(statusEdit ==  addFlag){
            QMessageBox::critical(this, tr("Error"),"此餐桌ID号重复，不能添加",QMessageBox::Ok );
            return ;
        }else if(statusEdit ==  editFlag && m_id.toInt() != nBean->id()){
            QMessageBox::critical(this, tr("Error"),"此餐桌ID号重复，不能修改",QMessageBox::Ok );
            return ;
        }
    }
    if(statusEdit ==  addFlag){
        DinnerBean *bean = new DinnerBean;
        bean->setDinnerId(ui->codeEdit->text().trimmed());
        bean->setDinnerName(ui->nameEdit->text().trimmed());
        bean->setDinnerType(ui->typeComboBox->currentText().trimmed());
        QString area = ui->areaComboBox->currentText().trimmed();
        area = area.mid(1,area.indexOf("]")-1);
        bean->setAreaId(area.toInt());
        bean->setNumber(ui->numberSpin->text().toInt());
        bean->setIsService(ui->checkBox->isChecked());
        bean->setLostConsumption(ui->lostSpinBox->value());
        bean->setMemo(ui->memoEdit->text());

        int status=DinnerDAO::createDinner(bean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Dinner error"),QMessageBox::Ok );
        }

    }else if(statusEdit == editFlag){
        DinnerBean *bean=new DinnerBean;
        bean->setDinnerId(ui->codeEdit->text().trimmed());
        bean->setDinnerName(ui->nameEdit->text().trimmed());
        bean->setDinnerType(ui->typeComboBox->currentText().trimmed());
        QString area=ui->areaComboBox->currentText().trimmed();
        area=area.mid(1,area.indexOf("]")-1);
        bean->setAreaId(area.toInt());
        bean->setNumber(ui->numberSpin->text().toInt());
        bean->setIsService(ui->checkBox->isChecked());
        bean->setId(m_id.toInt());
        bean->setLostConsumption(ui->lostSpinBox->value());
        bean->setMemo(ui->memoEdit->text());
        int status=DinnerDAO::updateDinner(bean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Update Dinner error"),QMessageBox::Ok );
        }

    }
    refreshData();
    limitsInit();
}

void DinnerForm::on_delButton_clicked()
{
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        /*
        QList<SaleBean *> sBeanList = SaleDAO::querySaleByDinner(ui->codeEdit->text().trimmed());

        if(sBeanList.size() > 0 ){
            QMessageBox::critical(this, tr("Error"),tr("此餐桌已使用,不能删除"),QMessageBox::Ok );
            return;
        }
        */
        DinnerBean *bean=new DinnerBean(0);

        bean->setDinnerId(ui->codeEdit->text().trimmed());
        bean->setId(m_id.toInt());
        int status = DinnerDAO::delDinner(bean);
        if(status>0){
            m_id = "";
            clearInput();
            refreshData();
            setInputEnabled(false);
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);
        }
    }
}

void DinnerForm::on_treeView_clicked(const QModelIndex &index)
{
    QString str=ui->treeView->model()->data(index).toString();
    QString id=str.mid(1,str.indexOf(")")-1);
    DinnerBean *bean = DinnerDAO::getDinnerById(id);
    if(bean->dinnerName().length()>1){
        m_id=QString::number(bean->id());
        ui->editButton->setEnabled(true);
        ui->delButton->setEnabled(true);
        setInputEnabled(false);
        ui->codeEdit->setText(bean->dinnerId());
        ui->nameEdit->setText(bean->dinnerName());
        for(int i=0;i<ui->typeComboBox->count();i++){
            if(ui->typeComboBox->itemText(i).contains(bean->dinnerType())){
                ui->typeComboBox->setCurrentIndex(i);
            }
        }
        for(int i=0;i<ui->areaComboBox->count();i++){
            if(ui->areaComboBox->itemText(i).contains(QString::number(bean->areaId()))){
                ui->areaComboBox->setCurrentIndex(i);
            }
        }
        ui->numberSpin->setValue(bean->number());
        ui->checkBox->setChecked(bean->isService());
        ui->lostSpinBox->setValue(bean->lostConsumption());

        ui->memoEdit->setText(bean->memo());


    }else{

        setButtonEnabled(false);
        setInputEnabled(false);
        for(int i=0;i<ui->areaComboBox->count();i++){
            if(ui->areaComboBox->itemText(i).contains(id)){
                ui->areaComboBox->setCurrentIndex(i);
            }
        }
    }
    limitsInit();

}
