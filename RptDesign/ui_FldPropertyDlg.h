/********************************************************************************
** Form generated from reading UI file 'FldPropertyDlg.ui'
**
** Created: Thu Jul 10 16:17:56 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLDPROPERTYDLG_H
#define UI_FLDPROPERTYDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FldPropertyDlg
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOK;
    QPushButton *btnCancel;

    void setupUi(QDialog *FldPropertyDlg)
    {
        if (FldPropertyDlg->objectName().isEmpty())
            FldPropertyDlg->setObjectName(QString::fromUtf8("FldPropertyDlg"));
        FldPropertyDlg->resize(400, 300);
        verticalLayout = new QVBoxLayout(FldPropertyDlg);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(FldPropertyDlg);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(page);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        treeWidget->setHeaderHidden(true);
        treeWidget->header()->setVisible(false);

        verticalLayout_2->addWidget(treeWidget);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOK = new QPushButton(FldPropertyDlg);
        btnOK->setObjectName(QString::fromUtf8("btnOK"));

        horizontalLayout->addWidget(btnOK);

        btnCancel = new QPushButton(FldPropertyDlg);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        horizontalLayout->addWidget(btnCancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FldPropertyDlg);
        QObject::connect(btnCancel, SIGNAL(clicked()), FldPropertyDlg, SLOT(reject()));
        QObject::connect(btnOK, SIGNAL(clicked()), FldPropertyDlg, SLOT(accept()));

        QMetaObject::connectSlotsByName(FldPropertyDlg);
    } // setupUi

    void retranslateUi(QDialog *FldPropertyDlg)
    {
        FldPropertyDlg->setWindowTitle(QApplication::translate("FldPropertyDlg", "Expression editor", 0, QApplication::UnicodeUTF8));
        btnOK->setText(QApplication::translate("FldPropertyDlg", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("FldPropertyDlg", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FldPropertyDlg: public Ui_FldPropertyDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLDPROPERTYDLG_H
