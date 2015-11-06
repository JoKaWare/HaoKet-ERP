#include "fawaydialog.h"
#include "ui_fawaydialog.h"
#include "bean/FaWayBean.h"
#include "dao/faaccntdao.h"
#include <QMessageBox>

FaWayDialog::FaWayDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FaWayDialog)
{
    ui->setupUi(this);
    init();
}

FaWayDialog::~FaWayDialog()
{
    delete ui;
}

void FaWayDialog::init(){
    QIcon icon1;
    icon1.addFile(QString::fromUtf8(":/image/cancel_48.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->cancelBtn->setIcon(icon1);
    ui->cancelBtn->setIconSize(QSize(24, 24));
    ui->cancelBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    QIcon icon2;
    icon2.addFile(QString::fromUtf8(":/image/ok.png"), QSize(), QIcon::Normal, QIcon::Off);
    ui->okBtn->setIcon(icon2);
    ui->okBtn->setIconSize(QSize(24, 24));
    ui->okBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    FaWayBean *bean = FaAccntDAO::getFayWay();
    if(bean->wayId() == 1){
        ui->rBtn1->setChecked(true);
    }else if(bean->wayId() == 2){
        ui->rBtn2->setChecked(true);
    }
}

void FaWayDialog::on_okBtn_clicked()
{
    QString sql = "SELECT count(*) FROM fa_subsidiary";
    if(FaAccntDAO::getSqlCount(sql) > 0){
        QMessageBox::information(this,"提示","存货明细帐已有数据，不能修改记价方式！");
        return ;
    }
    if(ui->rBtn1->isChecked()){
        FaAccntDAO::updateFaWayStatus(1);
    }else if(ui->rBtn2->isChecked()){
        FaAccntDAO::updateFaWayStatus(2);
    }
    this->accept();
}

void FaWayDialog::on_cancelBtn_clicked()
{
    this->close();
}

