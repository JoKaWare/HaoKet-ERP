/********************************************************************************
** Form generated from reading UI file 'importdialog.ui'
**
** Created: Fri Nov 6 10:51:11 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTDIALOG_H
#define UI_IMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableView>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImportDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QTableView *tableView;
    QGridLayout *gridLayout;
    QToolButton *okBtn;
    QToolButton *cancelBtn;
    QSpacerItem *horizontalSpacer;
    QToolButton *openBtn;

    void setupUi(QDialog *ImportDialog)
    {
        if (ImportDialog->objectName().isEmpty())
            ImportDialog->setObjectName(QString::fromUtf8("ImportDialog"));
        ImportDialog->resize(768, 508);
        verticalLayout = new QVBoxLayout(ImportDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(ImportDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(ImportDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        okBtn = new QToolButton(ImportDialog);
        okBtn->setObjectName(QString::fromUtf8("okBtn"));
        okBtn->setIconSize(QSize(24, 24));
        okBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(okBtn, 1, 3, 1, 1);

        cancelBtn = new QToolButton(ImportDialog);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));
        cancelBtn->setIconSize(QSize(24, 24));
        cancelBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(cancelBtn, 1, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 1, 1, 1);

        openBtn = new QToolButton(ImportDialog);
        openBtn->setObjectName(QString::fromUtf8("openBtn"));
        openBtn->setIconSize(QSize(24, 24));
        openBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout->addWidget(openBtn, 1, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ImportDialog);

        QMetaObject::connectSlotsByName(ImportDialog);
    } // setupUi

    void retranslateUi(QDialog *ImportDialog)
    {
        ImportDialog->setWindowTitle(QApplication::translate("ImportDialog", "\345\257\274\345\205\245", 0, QApplication::UnicodeUTF8));
        label->setText(QString());
        okBtn->setText(QApplication::translate("ImportDialog", "\347\241\256\345\256\232", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("ImportDialog", "\345\217\226\346\266\210", 0, QApplication::UnicodeUTF8));
        openBtn->setText(QApplication::translate("ImportDialog", "\346\211\223\345\274\200", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImportDialog: public Ui_ImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTDIALOG_H
