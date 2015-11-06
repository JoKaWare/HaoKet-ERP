#include "cusdialog.h"
#include "ui_cusdialog.h"
#include <QMessageBox>
#include "bean/EmployeeBean.h"
#include "bean/DepBean.h"
#include "dao/employeedao.h"
#include "dao/depdao.h"
#include "common/qkstringutils.h"
#include "common/widgetbeanutil.h"
#include "haokeapp.h"
#include "baplugin.h"
CusDialog::CusDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CusDialog)
{
    ui->setupUi(this);
}

CusDialog::CusDialog(int status, QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CusDialog)
{
    ui->setupUi(this);
    pinying = new PinYinUtils();
    mEditStatus = status;
    mId = id;
    init();
    if(status == editFlag){
        this->setWindowTitle(tr("Edit Customer"));
        getCusotmer(id);
        ui->codeEdit->setEnabled(false);
        ui->uCodeButton->setEnabled(false);

    }else if(status == addFlag){
        this->setWindowTitle(tr("Add Customer"));

        //ui->codeEdit->setText(getCodeMaxId());
        mTypeId = id;
        ui->codeEdit->setText(getCodeByTypeId(mTypeId));
        CustomerTypeBean *type = new CustomerTypeBean;
        type = CustomerTypeDAO::getTypeById(mId);

        if(type){
            if(type->typeEnd())
                ui->typeQkSearchEditbox->setText(type->typeId()+" - "+type->typeName());
            else{
                QList<CustomerTypeBean *> listBean = CustomerTypeDAO::queryTypeBy(id);
                if(listBean.size() > 0){
                    ui->typeQkSearchEditbox->setText(listBean.at(0)->typeId()+" - "+listBean.at(0)->typeName());
                }
            }
        }

    }
}

CusDialog::~CusDialog()
{
    delete ui;
}
void CusDialog::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baCusWinId();
    mWinTitle = "客户资料";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    QIcon icon;
    icon.addFile(QString::fromUtf8(":/image/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->uCodeButton->setIcon(icon);
    QList<CustomerTypeBean *> listBean = CustomerTypeDAO::queryTypeByEnd();
    ui->typeQkSearchEditbox->setListModel(true);
    QStringList sList;
    for(int i=0;i<listBean.size();i++){
        sList<< listBean.at(i)->typeId()+" - "+ listBean.at(i)->typeName();

    }
    ui->typeQkSearchEditbox->setItems(sList);
    ui->addButton->setEnabled(false);

    QList<EmployeeBean *> employeeBeanList = EmployeeDAO::queryEmp();
    QStringList empList ;
    for(int i =0 ; i < employeeBeanList.size(); i++){
        empList << employeeBeanList.at(i)->empCode() + " - " +employeeBeanList.at(i)->empName();
    }
    ui->personQkSearchEditbox->setListModel(true);
    ui->personQkSearchEditbox->setItems(empList);

    QList<DepBean *> depBeanList = DepDAO::queryDepByEnd();
    QStringList depList ;
    for(int i =0 ; i < depBeanList.size(); i++){
        depList << depBeanList.at(i)->depId() + " - " +depBeanList.at(i)->depName();
    }
    ui->depQks->setListModel(true);
    ui->depQks->setItems(depList);
}

void CusDialog::setInputEnable(bool b){
    ui->codeEdit->setEnabled(b);
    WidgetBeanUtil::setLayoutWidgetEnable(ui->gridLayout,b);
    WidgetBeanUtil::setLayoutWidgetEnable(ui->gridLayout_2,b);
    if(mEditStatus == addFlag && b){
        ui->uCodeButton->setEnabled(true);
    }else ui->uCodeButton->setEnabled(false);
}

void CusDialog::clearInput(){
    WidgetBeanUtil::clearLayoutWidgetData(ui->gridLayout);
    WidgetBeanUtil::clearLayoutWidgetData(ui->gridLayout_2);
}

QString CusDialog::getCodeByTypeId(QString type){
    QString strCode = "";
    if(type.length() < 1){
        type = "01";
    }
    int maxId = CustomerDAO::getByTypeCount(type) + 1;
    if(type.length()>=5){
        strCode = type + QkStringUtils::numberToString(maxId,1);
    }else{
        strCode = type + QkStringUtils::numberToString(maxId,4);
    }
    return strCode;
}

QString CusDialog::getCodeMaxId(){
    int maxId = CustomerDAO::getMaxId().toInt() + 1;
    QString strCode = "";
    for(int i=0;i<5-QString::number(maxId).length();i++){
        strCode = strCode + "0";
    }
    strCode = strCode + QString::number(maxId);
    return strCode;
}

void CusDialog::getCusotmer(QString id){
    CustomerBean *bean = CustomerDAO::getCusById(id);

    if(bean && bean->cusCode().length() > 1){
        ui->codeEdit->setText(bean->cusCode());
        ui->codeEdit->setEnabled(false);
        ui->cusNameEdit->setText(bean->cusName());
        ui->cusAliasEdit->setText(bean->cusAlias());
        ui->pinyinEdit->setText(bean->pinyinCode());
        CustomerTypeBean *typeBean = CustomerTypeDAO::getTypeById(bean->cusType());
        if(typeBean)(ui->typeQkSearchEditbox->setText(bean->cusType() + " - " + typeBean->typeName()));
        ui->areaCityEdit->setText(bean->areaCity());
        ui->tradeEdit->setText(bean->trade());
        ui->faxEdit->setText(bean->fax());
        ui->contactsEdit->setText(bean->contacts());
        ui->telEdit->setText(bean->tel());
        ui->phoneEdit->setText(bean->phone());
        ui->emailEdit->setText(bean->email());
        ui->postEdit->setText(bean->post());
        DepBean *depBean = DepDAO::getDepById(bean->depCode());
        if(depBean)
            ui->depQks->setText(bean->depCode() + " - " + depBean->depName());
        EmployeeBean *eBean = EmployeeDAO::getEmpByCode(bean->cusPerson());
        if(eBean)
            ui->personQkSearchEditbox->setText(bean->cusPerson() + " - " + eBean->empName());
        ui->depQks->setText(bean->depCode());
        ui->devDateEdit->setDate(bean->devDate());
        ui->isShopCheckBox->setChecked(bean->isShop());
        ui->cusAddressEdit->setText(bean->cusAddress());
        ui->memoEdit->setText(bean->memo());
        //法人信用信息
        ui->regCodeEdit->setText(bean->cusRegCode());
        ui->bankEdit->setText(bean->cusBank());
        ui->accountEdit->setText(bean->cusAccount());
        ui->corporateEdit->setText(bean->corporate());
        ui->addressEdit->setText(bean->address());
        ui->sDteEdit->setDate(bean->licenceSdate());
        ui->eDateEdit->setDate(bean->licenceEdate());
        ui->creGradeEdit->setText(bean->cusCreGrade());
        ui->creDateSpinBox->setValue(bean->cusCreDate());
        ui->creLineSpinBox->setValue(bean->cusCreLine());
        ui->isCreditCheckBox->setChecked(bean->isCredit());

    }else{
        QMessageBox::critical(this,"提示","此客户" + id + " 不存在");
    }

}
void CusDialog::on_cancelButton_clicked()
{
    this->accept();
}

void CusDialog::on_addButton_clicked()
{
    mEditStatus = addFlag;
    mTypeId = ui->typeQkSearchEditbox->text();
    clearInput();
    setInputEnable(true);

    //ui->codeEdit->setText(getCodeMaxId());
    ui->codeEdit->setText(getCodeByTypeId(mTypeId));
    ui->saveButton->setEnabled(true);
}

void CusDialog::on_saveButton_clicked()
{
    if(ui->codeEdit->text().length()<1){
        QMessageBox::warning(this, "提示","请输入客户编码",QMessageBox::Ok );
        ui->codeEdit->setFocus();
        return ;
    }
    if(ui->cusNameEdit->text().length()<1){
        QMessageBox::warning(this, "提示","请输入客户名称",QMessageBox::Ok );
        ui->cusNameEdit->setFocus();
        return ;
    }
    if(ui->pinyinEdit->text().length()<1){
        QMessageBox::warning(this, "提示","请输入拼音简码",QMessageBox::Ok );
        ui->pinyinEdit->setFocus();
        return ;
    }
    if(ui->typeQkSearchEditbox->text().length() < 1){
        QMessageBox::warning(this, "提示","请输入客户类别",QMessageBox::Ok );
        ui->typeQkSearchEditbox->setFocus();
        return ;
    }
    if(mEditStatus == addFlag){
        if(CustomerDAO::getByCodeCount(ui->codeEdit->text().trimmed())>0){
            QMessageBox::critical(this, "错误","客户编码已存在，不能处理",QMessageBox::Ok );

            return ;
        }
        CustomerBean *bean = new CustomerBean;

        bean->setCusCode(ui->codeEdit->text().trimmed());
        bean->setCusName(ui->cusNameEdit->text().trimmed());
        bean->setCusAlias(ui->cusAliasEdit->text().trimmed());
        bean->setPinyinCode(ui->pinyinEdit->text().trimmed());
        bean->setCusType(ui->typeQkSearchEditbox->text());
        bean->setAreaCity(ui->areaCityEdit->text());
        bean->setTrade(ui->tradeEdit->text());
        bean->setDevDate(ui->devDateEdit->date());
        bean->setCusAddress(ui->cusAddressEdit->text());
        bean->setIsShop(ui->isShopCheckBox->isChecked());
        bean->setContacts(ui->contactsEdit->text());
        bean->setTel(ui->telEdit->text());
        bean->setFax(ui->faxEdit->text());
        bean->setPhone(ui->phoneEdit->text());
        bean->setEmail(ui->emailEdit->text());
        bean->setPost(ui->postEdit->text());
        bean->setCusPerson(ui->personQkSearchEditbox->text());
        bean->setDepCode(ui->depQks->text());
        bean->setMemo(ui->memoEdit->text());

        bean->setCusRegCode(ui->regCodeEdit->text());
        bean->setCusBank(ui->bankEdit->text());
        bean->setCusAccount(ui->accountEdit->text());
        bean->setCorporate(ui->corporateEdit->text());
        bean->setLicenceEdate(ui->eDateEdit->date());
        bean->setLicenceSdate(ui->sDteEdit->date());
        bean->setCusCreGrade(ui->creGradeEdit->text());
        bean->setAddress(ui->addressEdit->text());
        bean->setCusCreLine(ui->creLineSpinBox->value());
        bean->setCusCreDate(ui->creDateSpinBox->value());
        bean->setIsCredit(ui->isCreditCheckBox->isChecked());

        int result = CustomerDAO::createCus(bean);
        if(result > 0){
            setInputEnable(false);
            ui->addButton->setEnabled(true);
            ui->saveButton->setEnabled(false);

        }else{
            QMessageBox::critical(this, "错误","新建客户信息出错!",QMessageBox::Ok );
            return;
        }
    }else if(mEditStatus == editFlag){
        if(mId.length() < 1){
            QMessageBox::critical(this, "错误","无此客户信息,不能修改!",QMessageBox::Ok );
            return ;
        }
        CustomerBean *bean = CustomerDAO::getCusById(mId);
        if(bean == NULL){
            QMessageBox::critical(this, "错误","无此客户信息,不能修改!",QMessageBox::Ok );
            return ;
        }

        bean->setCusName(ui->cusNameEdit->text().trimmed());
        bean->setCusAlias(ui->cusAliasEdit->text().trimmed());
        bean->setPinyinCode(ui->pinyinEdit->text().trimmed());
        bean->setCusType(ui->typeQkSearchEditbox->text());
        bean->setAreaCity(ui->areaCityEdit->text());
        bean->setTrade(ui->tradeEdit->text());
        bean->setDevDate(ui->devDateEdit->date());
        bean->setCusAddress(ui->cusAddressEdit->text());
        bean->setIsShop(ui->isShopCheckBox->isChecked());
        bean->setContacts(ui->contactsEdit->text());
        bean->setTel(ui->telEdit->text());
        bean->setFax(ui->faxEdit->text());
        bean->setPhone(ui->phoneEdit->text());
        bean->setEmail(ui->emailEdit->text());
        bean->setPost(ui->postEdit->text());
        bean->setCusPerson(ui->personQkSearchEditbox->text());
        bean->setDepCode(ui->depQks->text());
        bean->setMemo(ui->memoEdit->text());

        bean->setCusRegCode(ui->regCodeEdit->text());
        bean->setCusBank(ui->bankEdit->text());
        bean->setCusAccount(ui->accountEdit->text());
        bean->setCorporate(ui->corporateEdit->text());
        bean->setLicenceEdate(ui->eDateEdit->date());
        bean->setLicenceSdate(ui->sDteEdit->date());
        bean->setCusCreGrade(ui->creGradeEdit->text());
        bean->setAddress(ui->addressEdit->text());
        bean->setCusCreLine(ui->creLineSpinBox->value());
        bean->setCusCreDate(ui->creDateSpinBox->value());
        bean->setIsCredit(ui->isCreditCheckBox->isChecked());

        int result = CustomerDAO::updateCus(bean);
        if(result > 0){
            setInputEnable(false);
            ui->addButton->setEnabled(true);
            ui->saveButton->setEnabled(false);

        }else{
            QMessageBox::critical(this, "错误","修改客户信息出错!",QMessageBox::Ok );
            return;
        }

    }
}

void CusDialog::on_uCodeButton_clicked()
{
    if(mEditStatus == addFlag){
        mTypeId = ui->typeQkSearchEditbox->text();
        ui->codeEdit->setText(getCodeByTypeId(mTypeId));
    }else
        ui->uCodeButton->setEnabled(false);
}

void CusDialog::on_cusNameEdit_textChanged(const QString &arg1)
{
    ui->pinyinEdit->setText(PinYinUtils::getAllFirstLetter(arg1));
}
