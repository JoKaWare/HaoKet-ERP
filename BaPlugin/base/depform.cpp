#include "depform.h"
#include "ui_depform.h"
#include "haokeapp.h"
#include "system/limitscommon.h"
#include "bean/EmployeeBean.h"
#include "dao/employeedao.h"
#include "baplugin.h"
DepForm::DepForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
    reTreeData();


}

DepForm::~DepForm()
{
    delete ui;
}

void DepForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void DepForm::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baDepWinId();
    mWinTitle = "部门资料";
    //ui->newButton->setEnabled(true);
    setInputEnabled(false);
    setButtonEnabled(false);

    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

}

void DepForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void DepForm::reTreeData(){
    QList<DepBean *> listBean=DepDAO::queryDep();
    QList<DepBean *> listFirstBean=DepDAO::queryDepFirst();
    QStandardItemModel *model;
    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Department Information"));

    int j=0;
    int h=0;
    for(int i=0;i<listBean.size();i++){
        if(listBean.at(i)->depGrade()==1){
            QString str="("+listBean.at(i)->depId()+") "+listBean.at(i)->depName();
            QStandardItem *item = new QStandardItem();
            item->setText(str);
            for(int k=0;k<listBean.size();k++){
                if(listBean.at(k)->depGrade()==2){
                    QString str1="("+listBean.at(k)->depId()+") "+listBean.at(k)->depName();
                    if(listBean.at(i)->depId().contains(listBean.at(k)->depSuperior())){
                        QStandardItem *childItem = new QStandardItem(str1);
                        item->appendRow(childItem);
                    }
                }
            }
            model->setItem(j, 0, item);
            j=j+1;
        }
    }

    ui->treeView->setModel(model);
    ui->treeView->expandAll();

}
void DepForm::setInputEnabled(bool b){
    ui->codeEdit->setEnabled(b);
    ui->nameEdit->setEnabled(b);
    ui->personEdit->setEnabled(b);
    ui->endCheckBox->setEnabled(b);
    ui->telEdit->setEnabled(b);
    ui->addrEdit->setEnabled(b);
    ui->memoEdit->setEnabled(b);
}

void DepForm::setButtonEnabled(bool b){

    if(b){
        ui->editButton->setEnabled(b);
        ui->delButton->setEnabled(b);
        if(editStatus == addFlag || editStatus == editFlag)
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
void DepForm::on_newButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    editStatus = addFlag;
    setInputEnabled(true);
    ui->codeEdit->setText("");
    ui->nameEdit->setText("");
    ui->personEdit->setText("");
    ui->telEdit->setText("");
    ui->addrEdit->setText("");
    ui->memoEdit->setText("");
    ui->saveButton->setEnabled(true);
    ui->editButton->setEnabled(false);

    ui->delButton->setEnabled(false);

}

void DepForm::on_saveButton_clicked()
{

    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a department code"),QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a department name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(editStatus ==  addFlag){
        DepBean *dBean=new DepBean();
        dBean->setDepId(ui->codeEdit->text().trimmed());
        dBean->setDepName(ui->nameEdit->text().trimmed());
        dBean->setDepPerson(ui->personEdit->text().trimmed());
        dBean->setDepAddr(ui->addrEdit->text().trimmed());
        dBean->setDepTel(ui->telEdit->text().trimmed());
        dBean->setMemo(ui->memoEdit->text().trimmed());
        if(ui->codeEdit->text().trimmed().length()<3){
            dBean->setDepSuperior(ui->codeEdit->text().trimmed());
            dBean->setDepEnd(ui->endCheckBox->isChecked());
            dBean->setDepGrade(1);
        }else{
            dBean->setDepSuperior(ui->codeEdit->text().mid(0,2));
            dBean->setDepEnd(true);
            dBean->setDepGrade(2);
            DepBean *sBean=new DepBean;
            sBean=DepDAO::getDepById(dBean->depSuperior().trimmed());
            if(sBean->depId().length()<1){
                QMessageBox::warning(this, tr("Prompt"),tr("No parent type"),QMessageBox::Ok );
                ui->codeEdit->setFocus();
                return ;
            }
        }

        int status=DepDAO::createDep(dBean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("New departments error"),QMessageBox::Ok );
        }
    }else if(editStatus == editFlag){
        DepBean *dBean=new DepBean();
        dBean->setDepId(ui->codeEdit->text().trimmed());
        dBean->setDepName(ui->nameEdit->text().trimmed());
        dBean->setDepPerson(ui->personEdit->text().trimmed());
        dBean->setDepAddr(ui->addrEdit->text().trimmed());
        dBean->setDepTel(ui->telEdit->text().trimmed());
        dBean->setMemo(ui->memoEdit->text().trimmed());
        if(ui->codeEdit->text().trimmed().length()<3){
            dBean->setDepSuperior(ui->codeEdit->text().trimmed());
            dBean->setDepEnd(ui->endCheckBox->isChecked());
            dBean->setDepGrade(1);
        }else{
            dBean->setDepSuperior(ui->codeEdit->text().mid(0,2));
            dBean->setDepEnd(true);
            dBean->setDepGrade(2);
        }
        int status=DepDAO::updateDep(dBean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Edit departments error"),QMessageBox::Ok );
        }
    }
    reTreeData();
    limitsInit();
}

void DepForm::on_editButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    editStatus = editFlag;
    setInputEnabled(true);
    ui->codeEdit->setEnabled(false);
    ui->saveButton->setEnabled(true);
}

void DepForm::on_treeView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str=ui->treeView->model()->data(index).toString();
    QString id=str.mid(1,str.indexOf(")")-1);

    DepBean *dBean=DepDAO::getDepById(id);
    ui->codeEdit->setText(dBean->depId());
    ui->nameEdit->setText(dBean->depName());
    ui->personEdit->setText(dBean->depPerson());
    ui->telEdit->setText(dBean->depTel());
    ui->addrEdit->setText(dBean->depAddr());
    ui->memoEdit->setText(dBean->memo());
    ui->endCheckBox->setChecked(dBean->depEnd());
    limitsInit();
}

void DepForm::on_delButton_clicked()
{
    QString id=ui->codeEdit->text().trimmed();
    DepBean *dBean=DepDAO::getDepById(id);
    QList<EmployeeBean *> eBeanList =  EmployeeDAO::queryEmpBy(id);

    if(eBeanList.size()>0){
        QMessageBox::critical(this, tr("Error"),"此部门下存在职员资料,不能删除此部门",QMessageBox::Ok );
        return ;
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

    if(dBean->depGrade()==1){
        QList<DepBean *> listBean=DepDAO::queryDepBy(id);
        if(listBean.size()>0){
            QMessageBox::critical(this, tr("Error"),tr("This department subordinate departments, there can not be deleted"),QMessageBox::Ok );
            return ;
        }
    }
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){

        int status = DepDAO::delDep(dBean);
        if(status > 0){
            ui->codeEdit->setText("");
            ui->nameEdit->setText("");
            ui->personEdit->setText("");
            ui->telEdit->setText("");
            ui->addrEdit->setText("");
            ui->memoEdit->setText("");
            reTreeData();
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);
        }
    }

}
