#include "employeeform.h"
#include "ui_employeeform.h"
#include "haokeapp.h"
#include "system/limitscommon.h"
#include "dao/basedao.h"
#include "baplugin.h"
EmployeeForm::EmployeeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EmployeeForm)
{
    ui->setupUi(this);
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,6);
    init();
}

EmployeeForm::~EmployeeForm()
{
    delete ui;
}

void EmployeeForm::on_cancelButton_clicked()
{
    HaoKeApp::getInstance()->gui()->removeSubWin(this);
    this->close();
}

void EmployeeForm::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baEmpWinId();
    mWinTitle = "职员资料";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");
    QStringList sexList;
    QStringList nationList;
    QStringList relationList;
    sexList<<tr("男")<<tr("女");
    nationList<<tr("汉族")<<tr("少数民族");
    relationList<<tr("父母")<<tr("兄弟姐妹")<<tr("配偶")<<tr("朋友")<<tr("同学")<<tr("其他");
    ui->sexComBox->addItems(sexList);
    ui->nationComBox->addItems(nationList);
    ui->relationComboBox->addItems(relationList);
    QDate newDate=QDate::currentDate();
    ui->dateEdit->setDate(newDate);
    QList<DepBean *> listDep=DepDAO::queryDepByEnd();
    for(int i=0;i<listDep.size();i++){
        ui->depComboBox->addItem("["+listDep.at(i)->depId()+"] "+listDep.at(i)->depName());
    }
    refreshData();
    setInputEnabled(false);
    setButtonEnabled(false);
}

void EmployeeForm::limitsInit(){
    BaPlugin::authority(ui->gridLayout_2,mWinId.toInt(),mWinTitle);
}

void EmployeeForm::setInputEnabled(bool b){
    ui->codeEdit->setEnabled(b);
    ui->nameEdit->setEnabled(b);
    ui->propertyEdit->setEnabled(b);
    ui->depComboBox->setEnabled(b);
    ui->dateEdit->setEnabled(b);
    ui->sexComBox->setEnabled(b);
    ui->birthEdit->setEnabled(b);
    ui->weightEdit->setEnabled(b);
    ui->heightEdit->setEnabled(b);
    ui->addrEdit->setEnabled(b);
    ui->telEdit->setEnabled(b);
    ui->cNumberEdit->setEnabled(b);
    ui->homeEdit->setEnabled(b);
    ui->nationComBox->setEnabled(b);
    ui->memoEdit->setEnabled(b);
    ui->statusCheckBox->setEnabled(b);
    ui->rAddrEdit->setEnabled(b);
    ui->relationComboBox->setEnabled(b);
    ui->eduEdit->setEnabled(b);
    ui->shcoolEdit->setEnabled(b);
    ui->graduaDateEdit->setEnabled(b);
    ui->phoneEdit->setEnabled(b);
    ui->guarantorTelEdit->setEnabled(b);
    ui->guarantorAddrEdit->setEnabled(b);
    ui->guarantorEdit->setEnabled(b);
    ui->guarantorNumberEdit->setEnabled(b);
    ui->zipEdit->setEnabled(b);


}
void EmployeeForm::clearInput(){
    ui->codeEdit->clear();
    ui->nameEdit->clear();
    ui->propertyEdit->clear();
    ui->dateEdit->clear();
    ui->birthEdit->clear();
    ui->weightEdit->clear();
    ui->heightEdit->clear();
    ui->addrEdit->clear();
    ui->telEdit->clear();
    ui->cNumberEdit->clear();
    ui->homeEdit->clear();

    ui->memoEdit->clear();

    ui->rAddrEdit->clear();
    ui->eduEdit->clear();
    ui->shcoolEdit->clear();
    ui->graduaDateEdit->clear();
    ui->phoneEdit->clear();
    ui->guarantorTelEdit->clear();
    ui->guarantorAddrEdit->clear();
    ui->guarantorEdit->clear();
    ui->guarantorNumberEdit->clear();
    ui->zipEdit->clear();
}

void EmployeeForm::setButtonEnabled(bool b){

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

void EmployeeForm::refreshData(){
    QList<DepBean *> listBean=DepDAO::queryDepByEnd();
    QList<DepBean *> listFirstBean=DepDAO::queryDepFirst();
    QStandardItemModel *model;
    model = new QStandardItemModel(listFirstBean.size(),1);
    model->setHeaderData(0, Qt::Horizontal, tr("Employee"));
    QList<EmployeeBean *> listEmpBean=EmployeeDAO::queryEmpAll();

    int j=0;
    int h=0;
    QIcon empIcon;
    QIcon depIcon;
    empIcon.addFile(QString::fromUtf8(":/image/user_add.png"), QSize(), QIcon::Normal, QIcon::Off);
    depIcon.addFile(QString::fromUtf8(":/image/dep_48.png"), QSize(), QIcon::Normal, QIcon::Off);
    for(int i=0;i<listBean.size();i++){

        QString str="("+listBean.at(i)->depId()+") "+listBean.at(i)->depName();
        QStandardItem *item = new QStandardItem(depIcon,str);
        item->setText(str);

        if(listBean.at(i)->depEnd()){
            for(int l=0;l<listEmpBean.size();l++){
                if(listBean.at(i)->depId()==listEmpBean.at(l)->depId()){
                    QString s="(" + listEmpBean.at(l)->empCode()+") "+listEmpBean.at(l)->empName();
                    QStandardItem *childEmpItem = new QStandardItem(empIcon,s);
                    item->appendRow(childEmpItem);
                }
            }
        }
        model->setItem(j, 0, item);
        j=j+1;

    }

    ui->treeView->setModel(model);
    ui->treeView->expandAll();
}
void EmployeeForm::on_newButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"newButton");

    setInputEnabled(true);
    clearInput();
    ui->saveButton->setEnabled(true);
    statusEdit = addFlag;
}

void EmployeeForm::on_editButton_clicked()
{
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"editButton");

    setInputEnabled(true);
    ui->codeEdit->setEnabled(false);
    ui->saveButton->setEnabled(true);
    statusEdit = editFlag;
}

void EmployeeForm::on_saveButton_clicked()
{
    if(ui->codeEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),"请输入职员编码",QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    if(ui->nameEdit->text().trimmed().length()<1){
        QMessageBox::warning(this, tr("Prompt"),tr("Please enter a Employee name"),QMessageBox::Ok );
        ui->nameEdit->setFocus();
        return ;
    }
    //写入操作日志
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"saveButton");

    if(statusEdit == addFlag){
        EmployeeBean *eBean=new EmployeeBean;
        eBean->setEmpCode(ui->codeEdit->text().trimmed());
        eBean->setEmpName(ui->nameEdit->text().trimmed());
        eBean->setEmpAttr(ui->propertyEdit->text().trimmed());

        QString depStr=ui->depComboBox->currentText();
        depStr=depStr.mid(1,depStr.indexOf("]")-1);
        eBean->setDepId(depStr);
        eBean->setBirth(ui->birthEdit->dateTime());
        eBean->setSex(ui->sexComBox->currentText());
        eBean->setWeight(ui->weightEdit->text().trimmed());
        eBean->setHeight(ui->heightEdit->text().trimmed());
        eBean->setNation(ui->nationComBox->currentText().trimmed());
        eBean->setHometown(ui->homeEdit->text().trimmed());
        eBean->setEntryDate(ui->dateEdit->dateTime());
        eBean->setCreatedBy(HaoKeApp::getInstance()->getUserId());
        if(ui->statusCheckBox->isChecked()){
            eBean->setStatus(0);
        }else eBean->setStatus(1);
        QDateTime t=QDateTime::currentDateTime();
        eBean->setCreated(t);
        eBean->setMemo(ui->memoEdit->text().trimmed());
        eBean->setAddr(ui->addrEdit->text().trimmed());
        eBean->setPhone(ui->phoneEdit->text().trimmed());
        eBean->setZip(ui->zipEdit->text().trimmed());
        eBean->setEducational(ui->eduEdit->text().trimmed());
        eBean->setGraduationDate(ui->graduaDateEdit->dateTime());
        eBean->setGraduationShcool(ui->shcoolEdit->text().trimmed());
        eBean->setGuarantor(ui->guarantorEdit->text().trimmed());
        eBean->setGuarantorAddr(ui->guarantorAddrEdit->text().trimmed());
        eBean->setGuarantorNumber(ui->guarantorNumberEdit->text().trimmed());
        eBean->setGuarantorTel(ui->guarantorTelEdit->text().trimmed());
        eBean->setGuarantorRelation(ui->relationComboBox->currentText());
        eBean->setResidenceAddr(ui->rAddrEdit->text().trimmed());
        int status=EmployeeDAO::createEmp(eBean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("New Employee error"),QMessageBox::Ok );
            return;
        }


    }else if(statusEdit == editFlag){
        EmployeeBean *eBean=new EmployeeBean;

        eBean->setEmpId(m_id.toInt());
        eBean->setEmpCode(ui->codeEdit->text().trimmed());
        eBean->setEmpName(ui->nameEdit->text().trimmed());
        eBean->setEmpAttr(ui->propertyEdit->text().trimmed());
        if(ui->statusCheckBox->isChecked()){
            eBean->setStatus(0);
        }else eBean->setStatus(1);
        QString depStr=ui->depComboBox->currentText();

        depStr=depStr.mid(1,depStr.indexOf("]")-1);
        eBean->setDepId(depStr);
        eBean->setBirth(ui->birthEdit->dateTime());
        eBean->setSex(ui->sexComBox->currentText());
        eBean->setWeight(ui->weightEdit->text().trimmed());
        eBean->setHeight(ui->heightEdit->text().trimmed());
        eBean->setNation(ui->nationComBox->currentText().trimmed());
        eBean->setHometown(ui->homeEdit->text().trimmed());
        eBean->setEntryDate(ui->dateEdit->dateTime());
        eBean->setMemo(ui->memoEdit->text().trimmed());
        eBean->setAddr(ui->addrEdit->text().trimmed());
        eBean->setPhone(ui->phoneEdit->text().trimmed());
        eBean->setZip(ui->zipEdit->text().trimmed());
        eBean->setEducational(ui->eduEdit->text().trimmed());
        eBean->setGraduationDate(ui->graduaDateEdit->dateTime());
        eBean->setGraduationShcool(ui->shcoolEdit->text().trimmed());
        eBean->setGuarantor(ui->guarantorEdit->text().trimmed());
        eBean->setGuarantorAddr(ui->guarantorAddrEdit->text().trimmed());
        eBean->setGuarantorNumber(ui->guarantorNumberEdit->text().trimmed());
        eBean->setGuarantorTel(ui->guarantorTelEdit->text().trimmed());
        eBean->setGuarantorRelation(ui->relationComboBox->currentText());
        eBean->setResidenceAddr(ui->rAddrEdit->text().trimmed());

        int status=EmployeeDAO::updateEmp(eBean);
        if(status>0){
            setInputEnabled(false);
            ui->saveButton->setEnabled(false);
        }else{
            QMessageBox::critical(this, tr("Error"),tr("Update Employee error"),QMessageBox::Ok );
            return;
        }
    }
    refreshData();
    limitsInit();
}

void EmployeeForm::on_delButton_clicked()
{
    if(QMessageBox::warning(this, tr("Prompt"),tr("Do you want to delete"),QMessageBox::Yes | QMessageBox::No)==QMessageBox::Yes){
        /*
        QList<SaleBean *> sBeanList = SaleDAO::querySaleByEmp(m_id.toInt());
        if(sBeanList.size() > 0){
            QMessageBox::critical(this, tr("Error"),tr("此职员已使用,不能删除"),QMessageBox::Ok );
            return;
        }
        */
        //写入操作日志
        HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),"delButton");

        if(BaseDAO::getRdByEmp(m_id)>0){
            QMessageBox::information(this,"提示","已产生业务数据,不能删除",QMessageBox::Ok);
            ui->delButton->setEnabled(false);
            return ;
        }
        EmployeeBean *bean=new EmployeeBean(0);
        bean->setEmpCode(m_id);

        int status=EmployeeDAO::delEmp(bean);
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

void EmployeeForm::on_treeView_clicked(const QModelIndex &index)
{
    QString str=ui->treeView->model()->data(index).toString();
    QString id=str.mid(1,str.indexOf(")")-1);
    EmployeeBean *bean = EmployeeDAO::getEmpByCode(id);
    ui->editButton->setEnabled(true);
    //QMessageBox::warning(this,tr("Prompt"),QString::number(index.row())+" column:"+QString::number(index.column()),QMessageBox::Ok);
    if(bean->empName().length()>0 && index.parent().isValid()){
        m_id = id;

        ui->codeEdit->setText(bean->empCode());

        ui->nameEdit->setText(bean->empName());
        ui->propertyEdit->setText(bean->empAttr());
        for(int i=0;i<ui->depComboBox->count();i++){
            if(ui->depComboBox->itemText(i).contains(bean->depId())){
                ui->depComboBox->setCurrentIndex(i);
            }
        }
        if(bean->status() == 0){
            ui->statusCheckBox->setChecked(true);
        }else
            ui->statusCheckBox->setChecked(false);
        ui->heightEdit->setText(bean->height());
        ui->weightEdit->setText(bean->weight());
        ui->dateEdit->setDate(bean->entryDate().date());
        ui->birthEdit->setDate(bean->birth().date());
        for(int i=0;i<ui->sexComBox->count();i++){
            if(ui->sexComBox->itemText(i).contains(bean->sex())){
                ui->sexComBox->setCurrentIndex(i);
            }
        }
        ui->homeEdit->setText(bean->hometown());
        for(int i=0;i<ui->nationComBox->count();i++){
            if(ui->nationComBox->itemText(i).contains(bean->nation())){
                ui->nationComBox->setCurrentIndex(i);
            }
        }
        ui->memoEdit->setText(bean->memo());
        ui->graduaDateEdit->setDate(bean->graduationDate().date());
        ui->eduEdit->setText(bean->educational());
        ui->shcoolEdit->setText(bean->graduationShcool());
        ui->addrEdit->setText(bean->addr());
        ui->telEdit->setText(bean->tel());
        ui->zipEdit->setText(bean->zip());
        ui->cNumberEdit->setText(bean->cardNumber());
        ui->rAddrEdit->setText(bean->residenceAddr());
        ui->guarantorEdit->setText(bean->guarantor());
        ui->guarantorAddrEdit->setText(bean->guarantorAddr());
        ui->guarantorNumberEdit->setText(bean->guarantorNumber());
        ui->guarantorTelEdit->setText(bean->guarantorTel());
        for(int i=0;i<ui->relationComboBox->count();i++){
            if(ui->relationComboBox->itemText(i).contains(bean->guarantorRelation())){
                ui->relationComboBox->setCurrentIndex(i);
            }
        }

        if(ui->codeEdit->text().length() < 1){
            ui->editButton->setEnabled(false);
            ui->delButton->setEnabled(false);
        }
        limitsInit();

    }else{
        clearInput();
        setButtonEnabled(false);
        setInputEnabled(false);
        for(int i=0;i<ui->depComboBox->count();i++){
            if(ui->depComboBox->itemText(i).contains(id)){
                ui->depComboBox->setCurrentIndex(i);
            }
        }
        if(ui->codeEdit->text().length() < 1){
            ui->editButton->setEnabled(false);
            ui->delButton->setEnabled(false);
        }
    }

}
