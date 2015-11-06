#include "supplietypeform.h"
#include "ui_supplietypeform.h"
#include "system/limitscommon.h"
#include <QMessageBox>
#include "haokeapp.h"
#include "baplugin.h"
SupplieTypeForm::SupplieTypeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SupplieTypeForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
    ui->treeView->expandAll();
}

SupplieTypeForm::~SupplieTypeForm()
{
    delete ui;
}

void SupplieTypeForm::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baSupTypeWinId();
    mWinTitle = "供应商分类";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");
    HaoKeApp::writeProcess(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"打开",mWinTitle);

    setInputEnabled(false);
    setButtonEnabled(false);
    mId="";
    refreshData();

}

void SupplieTypeForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->codeEdit->setEnabled(b);
    ui->endCheckBox->setEnabled(b);
    ui->memoEdit->setEnabled(b);
    ui->explianEdit->setEnabled(b);
}

void SupplieTypeForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void SupplieTypeForm::setButtonEnabled(bool b){

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

void SupplieTypeForm::refreshData(){
    QList<SupplieTypeBean *> listFirstBean=SupplieTypeDAO::queryTypeByFirst();
    QList<SupplieTypeBean *> listBean=SupplieTypeDAO::queryType();
    QStandardItemModel *model;
    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Supplie Type"));

    int j=0;
    int h=0;
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
                        item->appendRow(childItem);
                    }
                }
            }
            model->setItem(j, 0, item);
            j=j+1;
        }
    }

    ui->treeView->setModel(model);

}

void SupplieTypeForm::on_newButton_clicked()
{
    mEditStatus = addFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    ui->explianEdit->clear();
    ui->endCheckBox->setCheckable(true);
    ui->memoEdit->clear();
}

void SupplieTypeForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void SupplieTypeForm::on_editButton_clicked()
{
    mEditStatus = editFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->setEnabled(false);
    ui->endCheckBox->setCheckable(true);
}

void SupplieTypeForm::on_saveButton_clicked()
{
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Supplie Type name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;

    }
    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Supplie Type Code"),QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;

    }
    if(mEditStatus == addFlag){
        SupplieTypeBean *bean=new SupplieTypeBean;
        bean->setTypeId(ui->codeEdit->text().trimmed());
        bean->setTypeName(ui->nameEdit->text().trimmed());
        bean->setExplian(ui->explianEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->text().trimmed());
        bean->setTypeEnd(ui->endCheckBox->isChecked());
        if(ui->codeEdit->text().trimmed().length()<3){
            bean->setTypeSuperior(ui->codeEdit->text().trimmed());
            bean->setTypeGrade(1);
        }else{
            bean->setTypeSuperior(ui->codeEdit->text().trimmed().mid(0,2));
            bean->setTypeGrade(2);
            SupplieTypeBean *sBean = new SupplieTypeBean;
            sBean = SupplieTypeDAO::getTypeById(bean->typeSuperior().trimmed());
            if(sBean->typeId().length()<1){
                QMessageBox::warning(this, tr("Prompt"),tr("No parent type"),QMessageBox::Ok );
                ui->codeEdit->setFocus();
                return ;
            }

        }
        int status = SupplieTypeDAO::createType(bean);
        if(status > 0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);

        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Supplie Type error"),QMessageBox::Ok );
        }

    }else if(mEditStatus == editFlag){
        SupplieTypeBean *bean=new SupplieTypeBean;
        bean->setTypeId(ui->codeEdit->text().trimmed());
        bean->setTypeName(ui->nameEdit->text().trimmed());
        bean->setExplian(ui->explianEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->text().trimmed());
        bean->setTypeEnd(ui->endCheckBox->isChecked());
        if(ui->codeEdit->text().trimmed().length()<3){
            bean->setTypeSuperior(ui->codeEdit->text().trimmed());
            bean->setTypeGrade(1);
        }else{
            bean->setTypeSuperior(ui->codeEdit->text().trimmed().mid(0,2));
            bean->setTypeGrade(2);
        }
        int status=SupplieTypeDAO::updateType(bean);
        if(status>0){
            setInputEnabled(false);
            setButtonEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Update Supplie Type error"),QMessageBox::Ok );
        }
    }
    refreshData();
    ui->treeView->expandAll();
    limitsInit();
}

void SupplieTypeForm::on_delButton_clicked()
{
    QList<SupplieTypeBean *> listBean = SupplieTypeDAO::queryTypeBy(ui->codeEdit->text().trimmed());
    if(listBean.size()>0){
        QMessageBox::warning(this, tr("Prompt"),"此类别下存在下级类别,不能删除",QMessageBox::Ok );
        return ;
    }

    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){


        SupplieTypeBean *bean=new SupplieTypeBean;

        bean->setTypeId(ui->codeEdit->text().trimmed());
        int status = SupplieTypeDAO::delType(bean);
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
        }
    }
}

void SupplieTypeForm::on_treeView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str = ui->treeView->model()->data(index).toString();
    mId = str.mid(1,str.indexOf(")")-1);

    SupplieTypeBean *dBean = SupplieTypeDAO::getTypeById(mId);
    ui->codeEdit->setText(dBean->typeId());
    ui->nameEdit->setText(dBean->typeName());
    ui->explianEdit->setText(dBean->explian());
    ui->memoEdit->setText(dBean->memo());
    ui->endCheckBox->setChecked(dBean->typeEnd());
    limitsInit();
}
