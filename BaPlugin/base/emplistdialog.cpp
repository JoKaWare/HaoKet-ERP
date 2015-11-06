#include <QMessageBox>
#include "emplistdialog.h"
#include "ui_emplistdialog.h"
#include "bean/DepBean.h"
#include "bean/EmployeeBean.h"
#include "dao/depdao.h"
#include "dao/employeedao.h"
#include "system/limitscommon.h"
#include <QStandardItemModel>
#include "haokeapp.h"
#include "baplugin.h"
EmpListDialog::EmpListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmpListDialog)
{
    ui->setupUi(this);
    init();
}

EmpListDialog::~EmpListDialog()
{
    delete ui;
}

void EmpListDialog::on_cancleButton_clicked()
{
    this->reject();
}

void EmpListDialog::init(){
    mWinId = HaoKeApp::baSubId() + BaPlugin::baEmpWinId();
    mWinTitle = "职员资料";
    HaoKeApp::writeSysLog(HaoKeApp::getInstance()->getAccountId() ,mWinTitle,HaoKeApp::baSubId().toInt(),mWinId.toInt(),0,"");

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QStringList depStringList ;
    QList<DepBean *> depBeanList = DepDAO::queryDepByEnd();

    ui->qksearcheditbox->setListModel(true);
    for(int i = 0;i<depBeanList.size();i++){
        depStringList << depBeanList.at(i)->depId() + " - " + depBeanList.at(i)->depName();
    }
    ui->qksearcheditbox->setItems(depStringList);

    QStandardItemModel *model = new QStandardItemModel(0, 2, ui->tableView);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("职员编码"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
    QList<EmployeeBean *> employeeBeanList = EmployeeDAO::queryEmp();
    for(int i=0;i<employeeBeanList.size();i++){
        QStandardItem *itemId = new QStandardItem(employeeBeanList.at(i)->empCode());
        QStandardItem *itemName = new QStandardItem(employeeBeanList.at(i)->empName());

        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);
    }
    ui->tableView->setModel(model);
    //ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnWidth(0,150);
    ui->tableView->setColumnWidth(1,150);
}

void EmpListDialog::on_okButton_clicked()
{
    this->setWindowIconText(m_id);
    this->accept();
}

void EmpListDialog::on_tableView_clicked(const QModelIndex &index)
{
    m_id=ui->tableView->model()->data(ui->tableView->model()->index(index.row(),0)).toString();
    //QMessageBox::information(this,"提示",m_id);
    //this->setWindowTitle(m_id);
}

void EmpListDialog::on_qksearcheditbox_editChanged(const QString &arg1)
{
    QStandardItemModel *model = new QStandardItemModel(0, 2, ui->tableView);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("职员编码"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("姓名"));
    //QString depId = ui->qksearcheditbox->text().trimmed();

    QList<EmployeeBean *> employeeBeanList = EmployeeDAO::queryEmpBy(arg1.trimmed());
    for(int i=0;i<employeeBeanList.size();i++){
        QStandardItem *itemId = new QStandardItem(employeeBeanList.at(i)->empCode());
        QStandardItem *itemName = new QStandardItem(employeeBeanList.at(i)->empName());

        model->setItem(i,0,itemId);
        model->setItem(i,1,itemName);
    }
    ui->tableView->setModel(model);
    //ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnWidth(0,150);
    ui->tableView->setColumnWidth(1,150);

}
