/*
Name: QtRptDesigner
Version: 1.3.0
Programmer: Aleksey Osipov
e-mail: aliks-os@yandex.ru
2012-2013
*/

#include "FldPropertyDlg.h"
#include "ui_FldPropertyDlg.h"

FldPropertyDlg::FldPropertyDlg(QWidget *parent) : QDialog(parent), ui(new Ui::FldPropertyDlg) {
    ui->setupUi(this);
}

QString FldPropertyDlg::showThis(int index) {
    QIcon iconFolder(QPixmap(QString::fromUtf8(":/new/prefix1/images/folder.png")));
    QIcon iconVariable(QPixmap(QString::fromUtf8(":/new/prefix1/images/variable.png")));
    ui->stackedWidget->setCurrentIndex(index);

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget,0);
    rootItem->setIcon(0,iconFolder);
    rootItem->setExpanded(true);

    QTreeWidgetItem *f1 = new QTreeWidgetItem(rootItem);
    f1->setIcon(0,iconFolder);
    f1->setExpanded(true);
    rootItem->addChild(f1);

    QTreeWidgetItem *item;

    switch(index) {
        case 0: {
            rootItem->setText(0,tr("Variables"));
            f1->setText(0,tr("System variables"));

            item = new QTreeWidgetItem(f1);
            item->setIcon(0,iconVariable);
            item->setText(0,"Date");
            item->setData(0,Qt::UserRole,"<Date>");
            f1->addChild(item);

            item = new QTreeWidgetItem(f1);
            item->setIcon(0,iconVariable);
            item->setText(0,"Time");
            item->setData(0,Qt::UserRole,"<Time>");
            f1->addChild(item);

            item = new QTreeWidgetItem(f1);
            item->setIcon(0,iconVariable);
            item->setText(0,"Page");
            item->setData(0,Qt::UserRole,"<Page>");
            f1->addChild(item);

            item = new QTreeWidgetItem(f1);
            item->setIcon(0,iconVariable);
            item->setText(0,"TotalPages");
            item->setData(0,Qt::UserRole,"<TotalPages>");
            f1->addChild(item);

            this->setWindowIcon(iconVariable);
            break;
        }
    }

    if (this->exec())
        return ui->treeWidget->selectedItems().at(0)->data(0,Qt::UserRole).toString();
    else return "";
}

FldPropertyDlg::~FldPropertyDlg() {
    delete ui;
}
