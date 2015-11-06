#include "rdqueryform.h"
#include "ui_rdqueryform.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include "common/dbmanager.h"
RdQueryForm::RdQueryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RdQueryForm)
{
    ui->setupUi(this);
}

RdQueryForm::~RdQueryForm()
{
    delete ui;
}

void RdQueryForm::on_toolButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel(ui->tableView);
    QString sql = "SELECT * FROM inware WHERE out_date>='2013-03-01' AND out_date<='2013-03-31'";
    model->setQuery(QSqlQuery(sql,DBManager::getDBManager()->getGoinDBConnection()));
    ui->tableView->setModel(model);
}
