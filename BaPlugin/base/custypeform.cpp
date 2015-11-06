#include "custypeform.h"
#include "ui_custypeform.h"
#include "system/limitscommon.h"
#include <QMessageBox>
#include "haokeapp.h"
#include "baplugin.h"
CusTypeForm::CusTypeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CusTypeForm)
{
    ui->setupUi(this);
    //ui->splitter->setStretchFactor(0,1);
    //ui->splitter->setStretchFactor(1,6);
    init();
    ui->treeView->expandAll();
}

CusTypeForm::~CusTypeForm()
{
    delete ui;
}
void CusTypeForm::init(){
    setInputEnabled(false);
    setButtonEnabled(false);
    mId="";
    mWinId = HaoKeApp::baSubId() + BaPlugin::baCusTypeWinId();
    mWinTitle = "客户分类";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    refreshData();

}

void CusTypeForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->codeEdit->setEnabled(b);
    ui->endCheckBox->setEnabled(b);
    ui->memoEdit->setEnabled(b);
    ui->explianEdit->setEnabled(b);
    ui->sCodeEdit->setEnabled(b);
}

void CusTypeForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void CusTypeForm::setButtonEnabled(bool b){

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

void CusTypeForm::refreshData(){
    QList<CustomerTypeBean *> listFirstBean=CustomerTypeDAO::queryTypeByFirst();
    QList<CustomerTypeBean *> listBean=CustomerTypeDAO::queryType();
    QStandardItemModel *model;
    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Customer Type"));

    int j=0;
    for(int i=0;i<listBean.size();i++){
        if(listBean.at(i)->typeGrade()==1){
            QString str="("+listBean.at(i)->typeId()+") "+listBean.at(i)->typeName();
            QStandardItem *item = new QStandardItem();
            item->setText(str);
            for(int k=0;k<listBean.size();k++){
                if(listBean.at(k)->typeGrade()==2){
                    QString str1="("+listBean.at(k)->typeId()+") "+listBean.at(k)->typeName();
                    if(listBean.at(i)->typeId().contains(listBean.at(k)->typeSuperior())){
                        QStandardItem *childItem = new QStandardItem(str1);
                        for(int h = 0;h < listBean.size() ; h++ ){
                            if(listBean.at(h)->typeGrade()==3){
                                QString str2="("+listBean.at(h)->typeId()+") "+listBean.at(h)->typeName();
                                if(listBean.at(k)->typeId().contains(listBean.at(h)->typeSuperior())){
                                    QStandardItem *childItem3 = new QStandardItem(str2);
                                    childItem->appendRow(childItem3);
                                }

                            }
                        }
                        item->appendRow(childItem);
                    }
                }
            }
            model->setItem(j, 0, item);
            j = j + 1;
        }
    }

    ui->treeView->setModel(model);

}

void CusTypeForm::on_newButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    mEditStatus = addFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);

    ui->sCodeEdit->setEnabled(false);
    ui->nameEdit->clear();
    ui->explianEdit->clear();
    ui->endCheckBox->setCheckable(true);
    ui->memoEdit->clear();
    ui->sCodeEdit->setText(ui->codeEdit->text());

}

void CusTypeForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void CusTypeForm::on_editButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    mEditStatus = editFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->setEnabled(false);
    ui->sCodeEdit->setEnabled(false);
    ui->endCheckBox->setCheckable(true);
}

void CusTypeForm::on_saveButton_clicked()
{
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Customer Type name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;

    }
    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Customer Type Code"),QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;

    }
    if(ui->codeEdit->text().trimmed().length()>2 && ui->codeEdit->text().trimmed().length() <= ui->sCodeEdit->text().trimmed().length()){
        QMessageBox::warning(this,"提示","编码长度不能小于或等于上级编码长度",QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(mEditStatus == addFlag){
        CustomerTypeBean *bean=new CustomerTypeBean;
        bean->setTypeId(ui->codeEdit->text().trimmed());
        bean->setTypeName(ui->nameEdit->text().trimmed());
        bean->setExplian(ui->explianEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->text().trimmed());
        bean->setTypeEnd(ui->endCheckBox->isChecked());
        if(ui->codeEdit->text().trimmed().length()<3){
            bean->setTypeSuperior(ui->codeEdit->text().trimmed());
            bean->setTypeGrade(1);
        }else{
            if(ui->sCodeEdit->text().trimmed().length() < 1)
                bean->setTypeSuperior(ui->codeEdit->text().trimmed().mid(0,2));
            else
                bean->setTypeSuperior(ui->sCodeEdit->text());
            if(ui->codeEdit->text().trimmed().length() < 6)bean->setTypeGrade(2);
            else if (ui->codeEdit->text().trimmed().length() < 9){
                if(ui->sCodeEdit->text().length()<3){
                    QMessageBox::warning(this, tr("Prompt"),tr("Code Length error"),QMessageBox::Ok );
                    ui->codeEdit->setFocus();
                    return ;
                }else{
                    bean->setTypeGrade(3);
                }
            }
            else bean->setTypeGrade(4);
            CustomerTypeBean *sBean = new CustomerTypeBean;
            sBean = CustomerTypeDAO::getTypeById(bean->typeSuperior().trimmed());
            if(sBean->typeId().length()<1){
                QMessageBox::warning(this, tr("Prompt"),tr("No parent type"),QMessageBox::Ok );
                ui->codeEdit->setFocus();
                return ;
            }

        }
        int status = CustomerTypeDAO::createType(bean);
        if(status > 0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);

        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Customer Type error"),QMessageBox::Ok );
        }

    }else if(mEditStatus == editFlag){
        CustomerTypeBean *bean=new CustomerTypeBean;
        bean->setTypeId(ui->codeEdit->text().trimmed());
        bean->setTypeName(ui->nameEdit->text().trimmed());
        bean->setExplian(ui->explianEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->text().trimmed());
        bean->setTypeEnd(ui->endCheckBox->isChecked());
        if(ui->sCodeEdit->text().trimmed().length() < 1)
            bean->setTypeSuperior(ui->codeEdit->text().trimmed().mid(0,2));
        else
            bean->setTypeSuperior(ui->sCodeEdit->text());
        if(ui->codeEdit->text().trimmed().length() < 3)bean->setTypeGrade(1);
        else if(ui->codeEdit->text().trimmed().length() < 6)bean->setTypeGrade(2);
        else if (ui->codeEdit->text().trimmed().length() < 9)bean->setTypeGrade(3);
        else bean->setTypeGrade(4);

        int status=CustomerTypeDAO::updateType(bean);
        if(status>0){
            setInputEnabled(false);
            setButtonEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Update Customer Type error"),QMessageBox::Ok );
        }
    }
    refreshData();
    ui->treeView->expandAll();
    limitsInit();
}

void CusTypeForm::on_delButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

    QList<CustomerTypeBean *> listBean = CustomerTypeDAO::queryTypeBy(ui->codeEdit->text().trimmed());
    if(listBean.size()>0){
        QMessageBox::warning(this, tr("Prompt"),"此类别下存在下级类别,不能删除",QMessageBox::Ok );
        return ;
    }

    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){


        CustomerTypeBean *bean=new CustomerTypeBean;

        bean->setTypeId(ui->codeEdit->text().trimmed());
        int status = CustomerTypeDAO::delType(bean);
        if(status>0){
            mId = "";
            ui->explianEdit->setText("");
            ui->nameEdit->setText("");
            ui->codeEdit->clear();
            ui->memoEdit->clear();
            ui->endCheckBox->setChecked(false);
            refreshData();
            setInputEnabled(false);
            ui->delButton->setEnabled(false);
            ui->treeView->expandAll();
        }
    }
}

void CusTypeForm::on_treeView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str = ui->treeView->model()->data(index).toString();
    mId = str.mid(1,str.indexOf(")")-1);

    CustomerTypeBean *dBean = CustomerTypeDAO::getTypeById(mId);
    ui->sCodeEdit->setText(dBean->typeSuperior());
    ui->codeEdit->setText(dBean->typeId());
    ui->nameEdit->setText(dBean->typeName());
    ui->explianEdit->setText(dBean->explian());
    ui->memoEdit->setText(dBean->memo());
    ui->endCheckBox->setChecked(dBean->typeEnd());
    limitsInit();
}
