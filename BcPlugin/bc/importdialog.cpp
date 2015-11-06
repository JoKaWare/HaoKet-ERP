#include "importdialog.h"
#include "ui_importdialog.h"
#include <QSqlResult>

ImportDialog::ImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportDialog)
{
    ui->setupUi(this);
    init();
}

ImportDialog::~ImportDialog()
{
    delete ui;
    if(mExcelDb.isOpen())mExcelDb.close();

}

void ImportDialog::init(){
    ui->label->setText("记录数:0");
    QIcon icon;
    icon.addPixmap(QPixmap(":/image/page_add.png"),  QIcon::Normal, QIcon::Off);
    ui->openBtn->setIcon(icon);
    QIcon icon1;
    icon1.addPixmap(QPixmap(":/image/ok.png"),  QIcon::Normal, QIcon::Off);
    ui->okBtn->setIcon(icon1);
    QIcon icon2;
    icon2.addPixmap(QPixmap(":/image/cancel_48.png"),  QIcon::Normal, QIcon::Off);
    ui->cancelBtn->setIcon(icon2);
}

void ImportDialog::on_openBtn_clicked()
{
    QString excelFileName = QFileDialog::getOpenFileName(this,tr("Open Excel Files"),"","Excel Files (*.xls *.xlsx)");
    QFile file(excelFileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    file.close();
    QSqlDatabase::removeDatabase("QODBCExcel");

    mExcelDb = QSqlDatabase::addDatabase("QODBC3", "QODBCExcel");
    mExcelDb.setDatabaseName("Driver={Microsoft Excel Driver (*.xls, *.xlsx, *.xlsm, *.xlsb)};Readonly=0;Dbq=" + excelFileName +";DefaultDir=D:\\");
    if (!mExcelDb.open())
    {
        QSqlError sqlErr = mExcelDb.lastError();
        QString error = sqlErr.text();
        if(mExcelDb.isOpen())mExcelDb.close();
        QMessageBox::information(this,"","Database Error " + error);
        return ;
    }
    int iMaxCount = 0;

    QApplication::setOverrideCursor(Qt::WaitCursor);
    mSqlQuery = NULL;

    mSqlQuery = new QSqlQuery(mExcelDb);
    mSqlQuery->clear();
    QString sqlCount="SELECT count(*) FROM [Sheet1$]";
    if(!mSqlQuery->exec(sqlCount)){
        QSqlError sqlErr = mSqlQuery->lastError();
        QString error = sqlErr.text();
        QApplication::restoreOverrideCursor();
        logger()->error(error);
        logger()->error(sqlCount);

        ui->tableView->setModel(NULL);
        mSqlQuery = NULL;
        mExcelDb.close();
        QMessageBox::information(this,"","打开表出错 " + error);
        return ;
    }else{
        if(mSqlQuery->next() ){
            iMaxCount = mSqlQuery->value(0).toInt();
        }
    }
    mCountNum = iMaxCount;
    ui->label->setText("记录数:" + QString::number(iMaxCount));
    QString strSql="SELECT DISTINCT * FROM [Sheet1$]";
    mSqlQuery->clear();
    if(!mSqlQuery->exec(strSql)){
        QSqlError sqlErr = mSqlQuery->lastError();
        QString error = sqlErr.text();
        logger()->error(error);
        logger()->error(strSql);
        QApplication::restoreOverrideCursor();

        ui->tableView->setModel(NULL);
        mSqlQuery = NULL;
        mExcelDb.close();
        QMessageBox::information(this,"","打开表出错 " + error);
        return ;
    }else{
        mModel = new QSqlQueryModel(this);
        mModel->setQuery(*mSqlQuery);
        QApplication::processEvents();
        ui->tableView->setModel(NULL);
        ui->tableView->setModel(mModel);
    }
    QApplication::restoreOverrideCursor();

}

void ImportDialog::on_okBtn_clicked()
{
    if(!ui->tableView->model() || (ui->tableView->model() && ui->tableView->model()->rowCount() < 1) ){
        QMessageBox::information(this,"提示","无数据,不能导入");
        return ;
    }
    this->accept();
}

void ImportDialog::on_cancelBtn_clicked()
{
    mSqlQuery = NULL;
    this->close();
}
