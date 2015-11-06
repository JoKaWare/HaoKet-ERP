#include <QMessageBox>
#include "typeform.h"
#include "ui_typeform.h"
#include "haokeapp.h"
#include "system/limitscommon.h"
#include "bean/DishesBean.h"
#include "dao/dishesdao.h"
#include "baplugin.h"
TypeForm::TypeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TypeForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
    ui->treeView->expandAll();
}

TypeForm::~TypeForm()
{
    delete ui;
}

void TypeForm::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baTypeWinId();
    mWinTitle = "菜品分类";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    setInputEnabled(false);
    setButtonEnabled(false);
    m_id="";
    refreshData();

}

void TypeForm::setInputEnabled(bool b){
    ui->nameEdit->setEnabled(b);
    ui->codeEdit->setEnabled(b);
    ui->endCheckBox->setEnabled(b);
    ui->memoEdit->setEnabled(b);
    ui->explianEdit->setEnabled(b);
    ui->discCheckBox->setEnabled(b);
    ui->discSpinBox->setEnabled(b);
}

void TypeForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}
void TypeForm::setButtonEnabled(bool b){

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

void TypeForm::refreshData(){
    QList<TypeBean *> listFirstBean=TypeDAO::queryTypeByFirst();
    QList<TypeBean *> listBean=TypeDAO::queryType();
    QStandardItemModel *model;
    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Dishes Type"));

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
void TypeForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void TypeForm::on_newButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    statusEdit = addFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    ui->explianEdit->clear();
    ui->endCheckBox->setCheckable(true);
    ui->memoEdit->clear();
}

void TypeForm::on_saveButton_clicked()
{
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dishes Type name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;

    }
    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Dishes Type Code"),QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;

    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(statusEdit == addFlag){
        TypeBean *bean=new TypeBean;
        bean->setTypeId(ui->codeEdit->text().trimmed());
        bean->setTypeName(ui->nameEdit->text().trimmed());
        bean->setExplian(ui->explianEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->text().trimmed());
        bean->setTypeEnd(ui->endCheckBox->isChecked());
        bean->setIsDisc(ui->discCheckBox->isChecked());
        bean->setLowDiscount(ui->discSpinBox->value());
        if(ui->codeEdit->text().trimmed().length()<3){
            bean->setTypeSuperior(ui->codeEdit->text().trimmed());
            bean->setTypeGrade(1);
        }else{
            bean->setTypeSuperior(ui->codeEdit->text().trimmed().mid(0,2));
            bean->setTypeGrade(2);
            TypeBean *sBean=new TypeBean;
            sBean=TypeDAO::getTypeById(bean->typeSuperior().trimmed());
            if(sBean->typeId().length()<1){
                QMessageBox::warning(this, tr("Prompt"),tr("No parent type"),QMessageBox::Ok );
                ui->codeEdit->setFocus();
                return ;
            }

        }
        int status=TypeDAO::createType(bean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);

        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Dishes Type error"),QMessageBox::Ok );
        }

    }else if(statusEdit == editFlag){
        TypeBean *bean=new TypeBean;
        bean->setTypeId(ui->codeEdit->text().trimmed());
        bean->setTypeName(ui->nameEdit->text().trimmed());
        bean->setExplian(ui->explianEdit->text().trimmed());
        bean->setMemo(ui->memoEdit->text().trimmed());
        bean->setTypeEnd(ui->endCheckBox->isChecked());
        bean->setIsDisc(ui->discCheckBox->isChecked());
        bean->setLowDiscount(ui->discSpinBox->value());
        if(ui->codeEdit->text().trimmed().length()<3){
            bean->setTypeSuperior(ui->codeEdit->text().trimmed());
            bean->setTypeGrade(1);
        }else{
            bean->setTypeSuperior(ui->codeEdit->text().trimmed().mid(0,2));
            bean->setTypeGrade(2);
        }
        int status=TypeDAO::updateType(bean);
        if(status>0){
            setInputEnabled(false);
            setButtonEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Update Dishes Type error"),QMessageBox::Ok );
        }
    }
    refreshData();
    ui->treeView->expandAll();
    limitsInit();
}

void TypeForm::on_editButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    statusEdit = editFlag;
    setInputEnabled(true);
    ui->saveButton->setEnabled(true);
    ui->codeEdit->setEnabled(false);
    ui->endCheckBox->setCheckable(true);
}

void TypeForm::on_treeView_activated(const QModelIndex &index)
{

}

void TypeForm::on_treeView_clicked(const QModelIndex &index)
{
    setInputEnabled(false);
    ui->editButton->setEnabled(true);
    ui->delButton->setEnabled(true);
    ui->saveButton->setEnabled(false);
    QString str=ui->treeView->model()->data(index).toString();
    QString id=str.mid(1,str.indexOf(")")-1);

    TypeBean *dBean=TypeDAO::getTypeById(id);
    ui->codeEdit->setText(dBean->typeId());
    ui->nameEdit->setText(dBean->typeName());
    ui->explianEdit->setText(dBean->explian());
    ui->memoEdit->setText(dBean->memo());
    ui->endCheckBox->setChecked(dBean->typeEnd());
    ui->discCheckBox->setChecked(dBean->isDisc());
    ui->discSpinBox->setValue(dBean->lowDiscount());
    limitsInit();
}

void TypeForm::on_delButton_clicked()
{
    QList<TypeBean *> listBean=TypeDAO::queryTypeBy(ui->codeEdit->text().trimmed());
    if(listBean.size()>0){
        QMessageBox::warning(this, tr("Prompt"),tr("此类别下存在下级类别,不能删除"),QMessageBox::Ok );
        return ;
    }

    QList<DishesBean *> dBeanList = DishesDAO::queryDishesByType(ui->codeEdit->text().trimmed());
    if(dBeanList.size() > 0 ){
        QMessageBox::critical(this, tr("Prompt"),tr("此类别已在菜品资料中使用,不能删除"),QMessageBox::Ok );
        return ;
    }
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){

        //写入操作日志
        HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

        TypeBean *bean=new TypeBean(0);

        bean->setTypeId(ui->codeEdit->text().trimmed());
        int status = TypeDAO::delType(bean);
        if(status > 0){
            m_id = "";
            ui->explianEdit->setText("");
            ui->nameEdit->setText("");
            ui->codeEdit->clear();
            ui->memoEdit->clear();
            ui->endCheckBox->setChecked(false);
            refreshData();
            setInputEnabled(false);
            ui->delButton->setEnabled(false);
            ui->editButton->setEnabled(false);
        }
    }
}
