#include "pusetdialog.h"
#include "ui_pusetdialog.h"
#include "bean/SystemSetBean.h"
#include "dao/SystemSetdao.h"
#include "QMessageBox"
#include "haokeapp.h"
#include "cgplugin.h"
PuSetDialog::PuSetDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PuSetDialog)
{
    ui->setupUi(this);
    init();
}

PuSetDialog::~PuSetDialog()
{
    delete ui;
}

void PuSetDialog::init(){
    mWinId = HaoKeApp::puSubId() + CgPlugin::systemSetWinId();
    mWinTitle = "采购设置";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::puSubId().toInt(),mWinId.toInt(),0,"");

    SystemSetBean *hathOrderBean = SystemSetDAO::getBean("001");
    if(hathOrderBean && hathOrderBean->id().length() > 0){
        ui->hathOrderChk->setChecked(hathOrderBean->yesNo());
    }else{
        SystemSetBean *bean = new SystemSetBean();
        bean->setId("001");
        bean->setName("采购业务必有订单");
        bean->setCaption(bean->name());
        bean->setYesNo(false);
        bean->setValue("");
        bean->setSubId(5);
        SystemSetDAO::createSystemSet(bean);
    }

    SystemSetBean *arrivalMrdBean = SystemSetDAO::getBean("002");
    if(arrivalMrdBean && arrivalMrdBean->id().length() > 0){
        ui->arrivalMrdChk->setChecked(arrivalMrdBean->yesNo());
    }else{
        SystemSetBean *bean = new SystemSetBean();
        bean->setId("002");
        bean->setName("到货审核生成入库");
        bean->setCaption(bean->name());
        bean->setYesNo(false);
        bean->setValue("");
        bean->setSubId(5);
        SystemSetDAO::createSystemSet(bean);
    }

    SystemSetBean *useDefineBean = SystemSetDAO::getBean("101");
    if(useDefineBean && useDefineBean->id().length() > 0){
        ui->useDefineChk->setChecked(useDefineBean->yesNo());
    }else{
        SystemSetBean *bean = new SystemSetBean();
        bean->setId("101");
        bean->setName("是否使用自定义字段");
        bean->setCaption(bean->name());
        bean->setYesNo(false);
        bean->setValue("");
        bean->setSubId(5);
        SystemSetDAO::createSystemSet(bean);
    }
}
void PuSetDialog::on_cancelButton_clicked()
{
    this->close();
}

void PuSetDialog::on_okButton_clicked()
{
    SystemSetBean *hathOrderBean = SystemSetDAO::getBean("001");
    if(hathOrderBean && hathOrderBean->id().length() > 0){
        hathOrderBean->setYesNo(ui->hathOrderChk->isChecked());
        int result = SystemSetDAO::updateSystemSet(hathOrderBean);
        if(result < 1){
            QMessageBox::critical(this,"提示","采购业务必有订单保存出错！");
            return ;
        }
    }

    SystemSetBean *arrivalMrdBean = SystemSetDAO::getBean("002");
    if(arrivalMrdBean && arrivalMrdBean->id().length() > 0){
        arrivalMrdBean->setYesNo(ui->arrivalMrdChk->isChecked());
        int result = SystemSetDAO::updateSystemSet(arrivalMrdBean);
        if(result < 1){
            QMessageBox::critical(this,"提示","到货审核生成入库保存出错！");
            return ;
        }
    }
    SystemSetBean *useDefineBean = SystemSetDAO::getBean("101");
    if(useDefineBean && useDefineBean->id().length() > 0){
        useDefineBean->setYesNo(ui->useDefineChk->isChecked());
        int result = SystemSetDAO::updateSystemSet(useDefineBean);
        if(result < 1){
            QMessageBox::critical(this,"提示","是否使用自定义字段保存出错！");
            return ;
        }
    }
    this->accept();
}
