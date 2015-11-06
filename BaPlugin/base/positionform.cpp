#include "positionform.h"
#include "ui_positionform.h"
#include "haokeapp.h"
#include "system/limitscommon.h"
#include "bean/PositionBean.h"
#include "bean/WareHouseBean.h"
#include "bean/UnitBean.h"
#include "dao/positiondao.h"
#include "dao/waredao.h"
#include "dao/commondao.h"

#include <QMessageBox>
#include "baplugin.h"
PositionForm::PositionForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PositionForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
    refreshData();
}

PositionForm::~PositionForm()
{
    delete ui;
}

void PositionForm::init(){
    setInputEnabled(false);
    setButtonEnabled(false);
    QList<UnitBean *> uListBean = CommonDAO::queryUnit();
    for(int i = 0; i< uListBean.size(); i++){
        ui->unitComboBox->addItem(uListBean.at(i)->unitName());
    }
    QList<WareHouseBean *> wareListBean = WareDAO::queryWarehouse();
    QStringList wareList;
    for(int i = 0;i<wareListBean.size();i++){
        wareList<< wareListBean.at(i)->whCode() + " - " + wareListBean.at(i)->whName();

    }
    ui->qksearcheditbox->setListModel(true);
    ui->qksearcheditbox->setItems(wareList);
}

void PositionForm::refreshData(){
    QList<PositionBean *> listBean = PositionDAO::queryPosition();
    QStandardItemModel *model;
    model = new QStandardItemModel(listBean.size(),2);
    model->setHeaderData(0, Qt::Horizontal, tr("Position Code"));
    model->setHeaderData(1, Qt::Horizontal, tr("Position Name"));


    for(int i=0;i<listBean.size();i++){
        QStandardItem *itemId = new QStandardItem(listBean.at(i)->positionCode());
        QStandardItem *itemName = new QStandardItem(listBean.at(i)->positionName());

        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);
    }
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(0,80);
    ui->tableView->setColumnWidth(1,120);
}

void PositionForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->codeEdit->setEnabled(b);
    ui->areaEdit->setEnabled(b);
    ui->unitComboBox->setEnabled(b);
    ui->qksearcheditbox->setEnabled(b);
    ui->descEdit->setEnabled(b);
    ui->levelSpinBox->setEnabled(b);
    ui->sumSpinBox->setEnabled(b);
    ui->statusCheckBox->setEnabled(b);
    ui->memoEdit->setEnabled(b);
}

void PositionForm::setButtonEnabled(bool b){
    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);
        if(mEditStatus == addFlag || mEditStatus == editFlag)
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

void PositionForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}
void PositionForm::on_newButton_clicked()
{
    mEditStatus = addFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    ui->descEdit->clear();
    ui->levelSpinBox->clear();
    ui->sumSpinBox->clear();
    ui->memoEdit->clear();
    ui->areaEdit->clear();
    ui->qksearcheditbox->clear();
}

void PositionForm::on_editButton_clicked()
{
    mEditStatus = editFlag;
    setInputEnabled(true);
    ui->codeEdit->setEnabled(false);
    ui->saveButton->setEnabled(true);
}

void PositionForm::on_saveButton_clicked()
{
    if(ui->codeEdit->text().length() < 1){
        QMessageBox::information(this,"提示","请输入货位编码",QMessageBox::Ok);
        return ;
    }
    if(ui->nameEdit->text().length() < 1){
        QMessageBox::information(this,"提示","请输入货位名称",QMessageBox::Ok);
        return ;
    }
    if(ui->qksearcheditbox->text().trimmed().length() < 1){
        QMessageBox::information(this,"提示","请选择所属仓库",QMessageBox::Ok);
        return ;
    }
    if(mEditStatus == addFlag){
        PositionBean *bean = new PositionBean;
        bean->setPositionCode(ui->codeEdit->text());
        bean->setPositionName(ui->nameEdit->text());
        bean->setPositionArea(ui->areaEdit->text());
        bean->setPositionDesc(ui->descEdit->text());
        bean->setPositionUnit(ui->unitComboBox->currentText());
        bean->setPositionLevel(ui->levelSpinBox->value());
        bean->setMemo(ui->memoEdit->text());
        bean->setWhCode(ui->qksearcheditbox->text());
        bean->setTopSum(ui->sumSpinBox->value());
        if(ui->statusCheckBox->isChecked()){
            bean->setStatus(1);
        }else bean->setStatus(0);
        int result = PositionDAO::createPosition(bean);
        if(result > 0 ){
            refreshData();
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
            ui->delButton->setEnabled(false);
        }else{
            QMessageBox::critical(this,"错误","新建货位出错,保存不成功");

        }
        delete bean;

    }else if(mEditStatus == editFlag){
        PositionBean *bean = PositionDAO::getPositionById(ui->codeEdit->text());
        if(bean == NULL){
            QMessageBox::critical(this,"错误","修改货位出错,此货位不存在");
            return ;
        }
        bean->setPositionName(ui->nameEdit->text());
        bean->setPositionArea(ui->areaEdit->text());
        bean->setPositionDesc(ui->descEdit->text());
        bean->setPositionUnit(ui->unitComboBox->currentText());
        bean->setPositionLevel(ui->levelSpinBox->value());
        bean->setMemo(ui->memoEdit->text());
        bean->setWhCode(ui->qksearcheditbox->text());
        bean->setTopSum(ui->sumSpinBox->value());
        if(ui->statusCheckBox->isChecked()){
            bean->setStatus(1);
        }else bean->setStatus(0);
        int result = PositionDAO::updatePosition(bean);
        if(result > 0 ){
            refreshData();
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
            ui->delButton->setEnabled(false);
        }else{
            QMessageBox::critical(this,"错误","修改货位出错,保存不成功");

        }
        delete bean;

    }
}

void PositionForm::on_delButton_clicked()
{
    mId = ui->codeEdit->text().trimmed();
    if(mId.length() < 1){
        QMessageBox::information(this,"提示","未选择行,不能删除");
        return ;
    }
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        PositionBean *bean = PositionDAO::getPositionById(mId);
        if(bean != NULL){
            int result = PositionDAO::delPosition(bean);
            if(result > 0 ){
                refreshData();
                setInputEnabled(false);
                ui->saveButton->setEnabled(false);
                ui->delButton->setEnabled(false);
                ui->codeEdit->clear();
                ui->nameEdit->clear();
                ui->descEdit->clear();
                ui->levelSpinBox->clear();
                ui->sumSpinBox->clear();
                ui->memoEdit->clear();
                ui->areaEdit->clear();
            }else{
                QMessageBox::critical(this,"错误","删除货位出错,此货位不存在");
            }
            delete bean;
        }
    }
}

void PositionForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void PositionForm::on_tableView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str = ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    mId = str;
    PositionBean *bean = PositionDAO::getPositionById(mId);
    if(bean == NULL){
        QMessageBox::critical(this,"错误","此货位不存在");
        return ;
    }
    ui->codeEdit->setText(bean->positionCode());
    ui->nameEdit->setText(bean->positionName());
    ui->descEdit->setText(bean->positionDesc());
    ui->areaEdit->setText(bean->positionArea());
    ui->memoEdit->setText(bean->memo());
    ui->sumSpinBox->setValue(bean->topSum());
    ui->levelSpinBox->setValue(bean->positionLevel());
    for(int i = 0 ; i < ui->unitComboBox->count(); i++ ){
        if(ui->unitComboBox->itemText(i) == bean->positionUnit()){
            ui->unitComboBox->setCurrentIndex(i);
        }
    }
    WareHouseBean *wBean = WareDAO::getWarehouseById(bean->whCode());
    if(wBean != NULL ){
        ui->qksearcheditbox->setText(bean->whCode() + " - " + wBean->whName());
    }
    if(bean->status() == 1){
        ui->statusCheckBox->setChecked(true);
    }else ui->statusCheckBox->setChecked(false);
    limitsInit();

}
